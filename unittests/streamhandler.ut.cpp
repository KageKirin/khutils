#include "khutils/glm/glm_reader.hpp"
#include "khutils/glm/glm_writer.hpp"

#include <bandit/bandit.h>
#include <boost/filesystem.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

#include <fstream>
#include <sstream>
#include <string>

// include last
#include "handler.ut.hpp"

using namespace bandit;
using namespace khutils;


static std::string ut_temp("ut.temp");

auto desc_streamGroup = [](auto desc, auto get_oss, auto get_iss) {
	return describe(desc, [&]() {

		auto get_streamwriter = [&]() { return streamwriter{get_oss()}; };
		auto get_streamreader = [&]() { return streamreader{get_iss()}; };

		desc_testGroup<streamwriter,
					   streamreader,
					   decltype(get_streamwriter),
					   decltype(get_streamreader)>("native endian",	//
												   get_streamwriter,
												   get_streamreader);

		auto get_little_endian_streamwriter = [&]() { return little_endian_streamwriter{get_oss()}; };
		auto get_little_endian_streamreader = [&]() { return little_endian_streamreader{get_iss()}; };

		desc_testGroup<little_endian_streamwriter,
					   little_endian_streamreader,
					   decltype(get_little_endian_streamwriter),
					   decltype(get_little_endian_streamreader)>("little endian",	//
																 get_little_endian_streamwriter,
																 get_little_endian_streamreader);

		auto get_big_endian_streamwriter = [&]() { return big_endian_streamwriter{get_oss()}; };
		auto get_big_endian_streamreader = [&]() { return big_endian_streamreader{get_iss()}; };

		desc_testGroup<big_endian_streamwriter,
					   big_endian_streamreader,
					   decltype(get_big_endian_streamwriter),
					   decltype(get_big_endian_streamreader)>("big endian",	//
															  get_big_endian_streamwriter,
															  get_big_endian_streamreader);
	});
};

go_bandit([]() {
	describe(__FILE__, []() {

		//////////////////////////////////////////////////////////////////////////
		// stringstream-based tests
		describe("stringstream-based tests", []() {
			std::stringstream s;
			desc_streamGroup("sstream",
							 [&]() -> std::stringstream& { return (s); },
							 [&]() -> std::stringstream& { return (s); });

			std::ostringstream oss;
			std::istringstream iss;

			before_each([&]() {
				oss = std::ostringstream();
				iss = std::istringstream();
			});

			desc_streamGroup("osstream, isstream",
							 [&]() -> std::ostringstream& {
								 oss = std::ostringstream();
								 return (oss);
							 },
							 [&]() -> std::istringstream& {
								 oss.flush();
								 iss = std::istringstream(oss.str());
								 return (iss);
							 });

		});

		//////////////////////////////////////////////////////////////////////////
		// filestream-based tests
		describe("filestream-based tests", []() {
			namespace fs = boost::filesystem;
			namespace io = boost::iostreams;

			io::mapped_file_params params{ut_temp};
			params.new_file_size = 1024;

			std::ofstream ofs;
			std::ifstream ifs;

			before_each([&]() {
				if (ofs.is_open())
				{
					ofs.close();
				}
				if (ifs.is_open())
				{
					ifs.close();
				}
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

			desc_streamGroup("fstream",
							 [&]() -> std::ofstream& {
								 if (ifs.is_open())
								 {
									 ifs.close();
								 }

								 ofs.open(ut_temp);
								 return ofs;
							 },
							 [&]() -> std::ifstream& {
								 if (ofs.is_open())
								 {
									 ofs.close();
								 }

								 ifs.open(ut_temp);
								 return ifs;
							 });
		});
	});
});
