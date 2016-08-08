#include "khutils/memoryhandler.hpp"

#include <bandit/bandit.h>
#include <boost/iostreams/device/mapped_file.hpp>

#include <fstream>
#include <sstream>
#include <string>

using namespace bandit;
using namespace khutils;


static std::string ut_temp("ut.temp");

go_bandit([]() {
	//////////////////////////////////////////////////////////////////////////
	// stringstream-based tests
	describe("writing once, reading once", []() {
		it("int", []() {

			int write = 42;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);

			auto sr   = memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int  read = sr.read<int>();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);

			auto  sr   = memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read = sr.read<float, int>();

			AssertThat(read, Equals(write));
		});
	});

	describe("writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);
			sw.write<int>(write2);

			auto sr	= memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);

			auto  sr	= memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read  = sr.read<float, int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);
			sw.write<int, float>(write2);

			auto  sr	= memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);
			sw.write<int>(write2);

			auto  sr	= memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read  = sr.read<float, int>();
			int   read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("little endian: writing once, reading once", []() {
		it("int", []() {

			int write = 42;

			std::vector<uint8_t> s(1024);
			auto				 sw = little_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);

			auto sr   = little_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int  read = sr.read<int>();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::vector<uint8_t> s(1024);
			auto				 sw = little_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);

			auto  sr   = little_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read = sr.read<float, int>();

			AssertThat(read, Equals(write));
		});
	});

	describe("little endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::vector<uint8_t> s(1024);
			auto				 sw = little_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);
			sw.write<int>(write2);

			auto sr	= little_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::vector<uint8_t> s(1024);
			auto				 sw = little_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);

			auto  sr	= little_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read  = sr.read<float, int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("little endian: writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			std::vector<uint8_t> s(1024);
			auto				 sw = little_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);
			sw.write<int, float>(write2);

			auto  sr	= little_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::vector<uint8_t> s(1024);
			auto				 sw = little_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);
			sw.write<int>(write2);

			auto  sr	= little_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read  = sr.read<float, int>();
			int   read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("big endian: writing once, reading once", []() {
		it("int", []() {

			int write = 42;

			std::vector<uint8_t> s(1024);
			auto				 sw = big_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);

			auto sr   = big_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int  read = sr.read<int>();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::vector<uint8_t> s(1024);
			auto				 sw = big_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);

			auto  sr   = big_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read = sr.read<float, int>();

			AssertThat(read, Equals(write));
		});
	});

	describe("big endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::vector<uint8_t> s(1024);
			auto				 sw = big_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);
			sw.write<int>(write2);

			auto sr	= big_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::vector<uint8_t> s(1024);
			auto				 sw = big_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);

			auto  sr	= big_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read  = sr.read<float, int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("big endian: writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			std::vector<uint8_t> s(1024);
			auto				 sw = big_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);
			sw.write<int, float>(write2);

			auto  sr	= big_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::vector<uint8_t> s(1024);
			auto				 sw = big_endian_memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);
			sw.write<int>(write2);

			auto  sr	= big_endian_memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float read  = sr.read<float, int>();
			int   read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("fetching", []() {
		it("int", []() {

			int write = 42;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int>(write);

			auto sr	= memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			int  fetch = sr.fetch<int>();
			int  read  = sr.read<int>();

			AssertThat(fetch, Equals(write));
			AssertThat(read, Equals(write));
			AssertThat(fetch, Equals(read));
		});

		it("float", []() {

			float write = 0.65;

			std::vector<uint8_t> s(1024);
			auto				 sw = memorywriter<decltype(s.begin())>{s.begin(), s.end()};
			sw.write<int, float>(write);

			auto  sr	= memoryreader<decltype(s.begin())>{s.begin(), s.end()};
			float fetch = sr.fetch<float, int>();
			float read  = sr.read<float, int>();

			AssertThat(fetch, Equals(write));
			AssertThat(read, Equals(write));
			AssertThat(fetch, Equals(read));
		});
	});

	describe("skip and alignment", []() {
		it("int", []() {

			int write = 42;

			std::vector<uint8_t> oss(1024);
			auto				 sw = memorywriter<decltype(oss.begin())>{oss.begin(), oss.end()};
			sw.write<int>(write);
			sw.skip<int>();
			sw.write<int>(write);
			sw.alignToNext<16>();
			sw.write<int>(write);

			std::vector<uint8_t> iss(oss);
			auto				 sr   = memoryreader<decltype(iss.begin())>{iss.begin(), iss.end()};
			int					 read = sr.read<int>();
			sr.skip<int>();
			int read2 = sr.read<int>();
			sr.alignToNext<16>();
			int read3 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write));
			AssertThat(read3, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::vector<uint8_t> oss(1024);
			auto				 sw = memorywriter<decltype(oss.begin())>{oss.begin(), oss.end()};
			sw.write<int, float>(write);
			sw.skip<int>();
			sw.write<int, float>(write);
			sw.alignToNext<16>();
			sw.write<int, float>(write);

			std::vector<uint8_t> iss(oss);
			auto				 sr   = memoryreader<decltype(iss.begin())>{iss.begin(), iss.end()};
			float				 read = sr.read<float, int>();
			sr.skip<int>();
			float read2 = sr.read<float, int>();
			sr.alignToNext<16>();
			float read3 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write));
			AssertThat(read3, Equals(write));
		});
	});

	//////////////////////////////////////////////////////////////////////////
	// filestream-based tests

	describe("fstream - writing once, reading once", []() {
		it("int", []() {

			int								   write = 42;
			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr   = memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  read = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr   = memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			sw.write<int>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr	= memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read  = sr.read<float, int>();
			float read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			sw.write<int, float>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			sw.write<int>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read  = sr.read<float, int>();
			int   read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("fstream - little endian: writing once, reading once", []() {
		it("int", []() {

			int write = 42;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = little_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr   = little_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  read = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = little_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr   = little_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - little endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = little_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			sw.write<int>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr	= little_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = little_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= little_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read  = sr.read<float, int>();
			float read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - little endian: writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = little_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			sw.write<int, float>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= little_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = little_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			sw.write<int>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= little_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read  = sr.read<float, int>();
			int   read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("fstream - big endian: writing once, reading once", []() {
		it("int", []() {

			int write = 42;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr   = big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  read = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr   = big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - big endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			sw.write<int>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr	= big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read  = sr.read<float, int>();
			float read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - big endian: writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			sw.write<int, float>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			sw.write<int>(write2);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read  = sr.read<float, int>();
			int   read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fetching", []() {
		it("int", []() {

			int write = 42;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr	= big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  fetch = sr.fetch<int>();
			int  read  = sr.read<int>();
			ifs.close();

			AssertThat(fetch, Equals(write));
			AssertThat(read, Equals(write));
			AssertThat(fetch, Equals(read));
		});

		it("float", []() {

			float write = 0.65;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr	= big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float fetch = sr.fetch<float, int>();
			float read  = sr.read<float, int>();
			ifs.close();

			AssertThat(fetch, Equals(write));
			AssertThat(read, Equals(write));
			AssertThat(fetch, Equals(read));
		});
	});

	describe("skip and alignment", []() {
		it("int", []() {

			int write = 42;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int>(write);
			sw.skip<int>();
			sw.write<int>(write);
			sw.alignToNext<16>();
			sw.write<int>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto sr   = big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			int  read = sr.read<int>();
			sr.skip<int>();
			int read2 = sr.read<int>();
			sr.alignToNext<16>();
			int read3 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write));
			AssertThat(read3, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			boost::iostreams::mapped_file_sink ofs(ut_temp);
			auto sw = big_endian_memorywriter<decltype(ofs.data())>{ofs.data(), ofs.data() + ofs.size()};
			sw.write<int, float>(write);
			sw.skip<int>();
			sw.write<int, float>(write);
			sw.alignToNext<16>();
			sw.write<int, float>(write);
			ofs.close();

			boost::iostreams::mapped_file_source ifs(ut_temp);
			auto  sr   = big_endian_memoryreader<decltype(ifs.data())>{ifs.data(), ifs.data() + ifs.size()};
			float read = sr.read<float, int>();
			sr.skip<int>();
			float read2 = sr.read<float, int>();
			sr.alignToNext<16>();
			float read3 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write));
			AssertThat(read3, Equals(write));
		});
	});
});
