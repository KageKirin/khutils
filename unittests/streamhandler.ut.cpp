#include "khutils/streamhandler.hpp"

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

		desc_testGroup("native endian",	//
					   [&]() { return streamwriter{get_oss()}; },
					   [&]() { return streamreader{get_iss()}; });

		desc_testGroup("little endian",	//
					   [&]() { return little_endian_streamwriter{get_oss()}; },
					   [&]() { return little_endian_streamreader{get_iss()}; });

		desc_testGroup("big endian",	//
					   [&]() { return big_endian_streamwriter{get_oss()}; },
					   [&]() { return big_endian_streamreader{get_iss()}; });
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
