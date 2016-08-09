#include "khutils/memoryhandler.hpp"

#include <bandit/bandit.h>
#include <boost/filesystem.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

#include <fstream>
#include <string>

#include <array>
#include <deque>
#include <list>
#include <set>
#include <vector>

// include last
#include "handler.ut.hpp"

using namespace bandit;
using namespace khutils;


static std::string ut_temp("ut.temp");

auto desc_containerGroup = [](auto desc, auto startIt, auto endIt) {
	return describe(desc, [&]() {

		before_each([&]() { std::for_each(startIt, endIt, [](auto& elem) { elem = 0x0; }); });

		desc_testGroup("native endian",	//
					   [&]() {
						   return memorywriter<decltype(startIt)>{startIt, endIt};
					   },
					   [&]() {
						   return memoryreader<decltype(startIt)>{startIt, endIt};
					   });

		desc_testGroup("little endian",
					   [&]() {
						   return little_endian_memorywriter<decltype(startIt)>{startIt, endIt};
					   },
					   [&]() {
						   return little_endian_memoryreader<decltype(startIt)>{startIt, endIt};
					   });

		desc_testGroup("big endian",
					   [&]() {
						   return big_endian_memorywriter<decltype(startIt)>{startIt, endIt};
					   },
					   [&]() {
						   return big_endian_memoryreader<decltype(startIt)>{startIt, endIt};
					   });
	});
};

go_bandit([]() {
	describe(__FILE__, []() {

		//////////////////////////////////////////////////////////////////////////
		// container-based tests

		describe("container", []() {
			std::array<uint8_t, 1024> a_array;
			desc_containerGroup("array, fwd", a_array.begin(), a_array.end());
			desc_containerGroup("array, bwd", a_array.rbegin(), a_array.rend());

			std::vector<uint8_t> a_vector(1024);
			desc_containerGroup("vector, fwd", a_vector.begin(), a_vector.end());
			desc_containerGroup("vector, bwd", a_vector.rbegin(), a_vector.rend());

			std::list<uint8_t> a_list(1024);
			desc_containerGroup("list, fwd", a_list.begin(), a_list.end());
			desc_containerGroup("list, bwd", a_list.rbegin(), a_list.rend());

			std::deque<uint8_t> a_deque(1024);
			desc_containerGroup("deque, fwd", a_deque.begin(), a_deque.end());
			desc_containerGroup("deque, bwd", a_deque.rbegin(), a_deque.rend());

			std::string a_string(1024, '\0');
			desc_containerGroup("set, fwd", a_string.begin(), a_string.end());
			desc_containerGroup("set, bwd", a_string.rbegin(), a_string.rend());

			uint8_t a_rawArray[1024];
			desc_containerGroup("raw array, fwd", &a_rawArray[0], &a_rawArray[1024]);
		});

		//////////////////////////////////////////////////////////////////////////
		// memory mapped file-based tests

		describe("memory mapped file", []() {
			namespace fs = boost::filesystem;
			namespace io = boost::iostreams;

			io::mapped_file_params params{ut_temp};
			io::mapped_file_sink   ofs;
			io::mapped_file_source ifs;

			params.new_file_size = 1024;

			before_each([&]() {

			});

			after_each([&]() {
				if (ofs.is_open())
				{
					ofs.close();
				}
				if (ifs.is_open())
				{
					ifs.close();
				}

				fs::path testFile(ut_temp);
				if (fs::exists(testFile))
				{
					fs::remove(testFile);
				}
			});

			desc_testGroup(	//
			  "native endian",
			  [&]() {
				  if (ifs.is_open())
				  {
					  ifs.close();
				  }
				  ofs = io::mapped_file_sink{params};
				  return memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			  },
			  [&]() {
				  if (ofs.is_open())
				  {
					  ofs.close();
				  }
				  ifs = io::mapped_file_source{params};
				  return memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			  });

			desc_testGroup(
			  "little endian",
			  [&]() {
				  if (ifs.is_open())
				  {
					  ifs.close();
				  }
				  ofs = io::mapped_file_sink{params};
				  return little_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			  },
			  [&]() {
				  if (ofs.is_open())
				  {
					  ofs.close();
				  }
				  ifs = io::mapped_file_source{params};
				  return little_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			  });

			desc_testGroup(
			  "big endian",
			  [&]() {
				  if (ifs.is_open())
				  {
					  ifs.close();
				  }
				  ofs = io::mapped_file_sink{params};
				  return big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			  },
			  [&]() {
				  if (ofs.is_open())
				  {
					  ofs.close();
				  }
				  ifs = io::mapped_file_source{params};
				  return big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			  });
		});
	});
});
