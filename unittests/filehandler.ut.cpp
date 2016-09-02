#include "khutils/glm/glm_reader.hpp"
#include "khutils/glm/glm_writer.hpp"

#include <bandit/bandit.h>
#include <boost/filesystem.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

#include <cstdio>
#include <memory>
#include <string>

// include last
#include "handler.ut.hpp"

using namespace bandit;
using namespace khutils;


static std::string ut_temp("ut.temp");

auto desc_fileGroup = [](auto desc, auto get_oss, auto get_iss) {
	return describe(desc, [&]() {

		auto get_filewriter = [&]() { return filewriter{get_oss()}; };
		auto get_filereader = [&]() { return filereader{get_iss()}; };

		desc_testGroup<filewriter,
					   filereader,
					   decltype(get_filewriter),
					   decltype(get_filereader)>("native endian",	//
												 get_filewriter,
												 get_filereader);

		auto get_little_endian_filewriter = [&]() { return little_endian_filewriter{get_oss()}; };
		auto get_little_endian_filereader = [&]() { return little_endian_filereader{get_iss()}; };

		desc_testGroup<little_endian_filewriter,
					   little_endian_filereader,
					   decltype(get_little_endian_filewriter),
					   decltype(get_little_endian_filereader)>("little endian",	//
															   get_little_endian_filewriter,
															   get_little_endian_filereader);

		auto get_big_endian_filewriter = [&]() { return big_endian_filewriter{get_oss()}; };
		auto get_big_endian_filereader = [&]() { return big_endian_filereader{get_iss()}; };

		desc_testGroup<big_endian_filewriter,
					   big_endian_filereader,
					   decltype(get_big_endian_filewriter),
					   decltype(get_big_endian_filereader)>("big endian",	//
															get_big_endian_filewriter,
															get_big_endian_filereader);
	});
};

go_bandit([]() {
	describe(__FILE__, []() {

		//////////////////////////////////////////////////////////////////////////
		// FILE-based tests
		describe("temp FILE-based tests", []() {
			std::shared_ptr<FILE> s;

			before_each([&]() {
				s = std::shared_ptr<FILE>(std::tmpfile(), [](auto& fp) {
					fflush(fp);
					fclose(fp);
				});
			});

			desc_fileGroup("tmpfile",
						   [&]() -> std::shared_ptr<FILE>& { return (s); },
						   [&]() -> std::shared_ptr<FILE>& {
							   fflush(s.get());
							   rewind(s.get());
							   return (s);
						   });

		});

		//////////////////////////////////////////////////////////////////////////
		// filestream-based tests
		describe("FILE-based tests", []() {
			namespace fs = boost::filesystem;
			namespace io = boost::iostreams;

			std::shared_ptr<FILE> s;

			before_each([&]() {
				s = std::shared_ptr<FILE>(std::fopen(ut_temp.c_str(), "w+b"), [](auto& fp) {
					fflush(fp);
					fclose(fp);
				});
			});

			desc_fileGroup("FILE",
						   [&]() -> std::shared_ptr<FILE>& { return (s); },
						   [&]() -> std::shared_ptr<FILE>& {
							   fflush(s.get());
							   rewind(s.get());
							   return (s);
						   });
		});
	});
});
