#include "khutils/streamhandler.hpp"

#include <bandit/bandit.h>
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

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int>(write);

			auto sr   = streamreader{s};
			int  read = sr.read<int>();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int, float>(write);

			auto  sr   = streamreader{s};
			float read = sr.read<float, int>();

			AssertThat(read, Equals(write));
		});
	});

	describe("writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int>(write);
			sw.write<int>(write2);

			auto sr	= streamreader{s};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);

			auto  sr	= streamreader{s};
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

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int>(write);
			sw.write<int, float>(write2);

			auto  sr	= streamreader{s};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int, float>(write);
			sw.write<int>(write2);

			auto  sr	= streamreader{s};
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

			std::stringstream s;
			auto			  sw = little_endian_streamwriter{s};
			sw.write<int>(write);

			auto sr   = little_endian_streamreader{s};
			int  read = sr.read<int>();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::stringstream s;
			auto			  sw = little_endian_streamwriter{s};
			sw.write<int, float>(write);

			auto  sr   = little_endian_streamreader{s};
			float read = sr.read<float, int>();

			AssertThat(read, Equals(write));
		});
	});

	describe("little endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::stringstream s;
			auto			  sw = little_endian_streamwriter{s};
			sw.write<int>(write);
			sw.write<int>(write2);

			auto sr	= little_endian_streamreader{s};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::stringstream s;
			auto			  sw = little_endian_streamwriter{s};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);

			auto  sr	= little_endian_streamreader{s};
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

			std::stringstream s;
			auto			  sw = little_endian_streamwriter{s};
			sw.write<int>(write);
			sw.write<int, float>(write2);

			auto  sr	= little_endian_streamreader{s};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::stringstream s;
			auto			  sw = little_endian_streamwriter{s};
			sw.write<int, float>(write);
			sw.write<int>(write2);

			auto  sr	= little_endian_streamreader{s};
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

			std::stringstream s;
			auto			  sw = big_endian_streamwriter{s};
			sw.write<int>(write);

			auto sr   = big_endian_streamreader{s};
			int  read = sr.read<int>();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::stringstream s;
			auto			  sw = big_endian_streamwriter{s};
			sw.write<int, float>(write);

			auto  sr   = big_endian_streamreader{s};
			float read = sr.read<float, int>();

			AssertThat(read, Equals(write));
		});
	});

	describe("big endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::stringstream s;
			auto			  sw = big_endian_streamwriter{s};
			sw.write<int>(write);
			sw.write<int>(write2);

			auto sr	= big_endian_streamreader{s};
			int  read  = sr.read<int>();
			int  read2 = sr.read<int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::stringstream s;
			auto			  sw = big_endian_streamwriter{s};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);

			auto  sr	= big_endian_streamreader{s};
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

			std::stringstream s;
			auto			  sw = big_endian_streamwriter{s};
			sw.write<int>(write);
			sw.write<int, float>(write2);

			auto  sr	= big_endian_streamreader{s};
			int   read  = sr.read<int>();
			float read2 = sr.read<float, int>();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::stringstream s;
			auto			  sw = big_endian_streamwriter{s};
			sw.write<int, float>(write);
			sw.write<int>(write2);

			auto  sr	= big_endian_streamreader{s};
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

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int>(write);

			auto sr	= streamreader{s};
			int  fetch = sr.fetch<int>();
			int  read  = sr.read<int>();

			AssertThat(fetch, Equals(write));
			AssertThat(read, Equals(write));
			AssertThat(fetch, Equals(read));
		});

		it("float", []() {

			float write = 0.65;

			std::stringstream s;
			auto			  sw = streamwriter{s};
			sw.write<int, float>(write);

			auto  sr	= streamreader{s};
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

			std::ostringstream oss;
			auto			   sw = streamwriter{oss};
			sw.write<int>(write);
			sw.skip<int>();
			sw.write<int>(write);
			sw.alignToNext<16>();
			sw.write<int>(write);

			std::istringstream iss(oss.str());
			auto			   sr   = streamreader{iss};
			int				   read = sr.read<int>();
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

			std::ostringstream oss;
			auto			   sw = streamwriter{oss};
			sw.write<int, float>(write);
			sw.skip<int>();
			sw.write<int, float>(write);
			sw.alignToNext<16>();
			sw.write<int, float>(write);

			std::istringstream iss(oss.str());
			auto			   sr   = streamreader{iss};
			float			   read = sr.read<float, int>();
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

			int write = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = streamwriter{ofs};
			sw.write<int>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = streamreader{ifs};
			int			  read = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::ofstream ofs(ut_temp);
			auto		  sw = streamwriter{ofs};
			sw.write<int, float>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = streamreader{ifs};
			float		  read = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::ofstream ofs(ut_temp);
			auto		  sw = streamwriter{ofs};
			sw.write<int>(write);
			sw.write<int>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= streamreader{ifs};
			int			  read  = sr.read<int>();
			int			  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::ofstream ofs(ut_temp);
			auto		  sw = streamwriter{ofs};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= streamreader{ifs};
			float		  read  = sr.read<float, int>();
			float		  read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			std::ofstream ofs(ut_temp);
			auto		  sw = streamwriter{ofs};
			sw.write<int>(write);
			sw.write<int, float>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= streamreader{ifs};
			int			  read  = sr.read<int>();
			float		  read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = streamwriter{ofs};
			sw.write<int, float>(write);
			sw.write<int>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= streamreader{ifs};
			float		  read  = sr.read<float, int>();
			int			  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("fstream - little endian: writing once, reading once", []() {
		it("int", []() {

			int write = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = little_endian_streamwriter{ofs};
			sw.write<int>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = little_endian_streamreader{ifs};
			int			  read = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::ofstream ofs(ut_temp);
			auto		  sw = little_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = little_endian_streamreader{ifs};
			float		  read = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - little endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::ofstream ofs(ut_temp);
			auto		  sw = little_endian_streamwriter{ofs};
			sw.write<int>(write);
			sw.write<int>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= little_endian_streamreader{ifs};
			int			  read  = sr.read<int>();
			int			  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::ofstream ofs(ut_temp);
			auto		  sw = little_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= little_endian_streamreader{ifs};
			float		  read  = sr.read<float, int>();
			float		  read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - little endian: writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			std::ofstream ofs(ut_temp);
			auto		  sw = little_endian_streamwriter{ofs};
			sw.write<int>(write);
			sw.write<int, float>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= little_endian_streamreader{ifs};
			int			  read  = sr.read<int>();
			float		  read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = little_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			sw.write<int>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= little_endian_streamreader{ifs};
			float		  read  = sr.read<float, int>();
			int			  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("fstream - big endian: writing once, reading once", []() {
		it("int", []() {

			int write = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = big_endian_streamreader{ifs};
			int			  read = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {

			float write = 0.65;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = big_endian_streamreader{ifs};
			float		  read = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - big endian: writing twice, reading twice", []() {
		it("int", []() {

			int write  = 42;
			int write2 = 87;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int>(write);
			sw.write<int>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= big_endian_streamreader{ifs};
			int			  read  = sr.read<int>();
			int			  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {

			float write  = 0.65;
			float write2 = 1.12;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			sw.write<int, float>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= big_endian_streamreader{ifs};
			float		  read  = sr.read<float, int>();
			float		  read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - big endian: writing mixed, reading mixed", []() {
		it("int, float", []() {

			int   write  = 42;
			float write2 = 1.12;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int>(write);
			sw.write<int, float>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= big_endian_streamreader{ifs};
			int			  read  = sr.read<int>();
			float		  read2 = sr.read<float, int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {

			float write  = 0.65;
			int   write2 = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			sw.write<int>(write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= big_endian_streamreader{ifs};
			float		  read  = sr.read<float, int>();
			int			  read2 = sr.read<int>();
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fetching", []() {
		it("int", []() {

			int write = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= big_endian_streamreader{ifs};
			int			  fetch = sr.fetch<int>();
			int			  read  = sr.read<int>();
			ifs.close();

			AssertThat(fetch, Equals(write));
			AssertThat(read, Equals(write));
			AssertThat(fetch, Equals(read));
		});

		it("float", []() {

			float write = 0.65;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr	= big_endian_streamreader{ifs};
			float		  fetch = sr.fetch<float, int>();
			float		  read  = sr.read<float, int>();
			ifs.close();

			AssertThat(fetch, Equals(write));
			AssertThat(read, Equals(write));
			AssertThat(fetch, Equals(read));
		});
	});

	describe("skip and alignment", []() {
		it("int", []() {

			int write = 42;

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int>(write);
			sw.skip<int>();
			sw.write<int>(write);
			sw.alignToNext<16>();
			sw.write<int>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = big_endian_streamreader{ifs};
			int			  read = sr.read<int>();
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

			std::ofstream ofs(ut_temp);
			auto		  sw = big_endian_streamwriter{ofs};
			sw.write<int, float>(write);
			sw.skip<int>();
			sw.write<int, float>(write);
			sw.alignToNext<16>();
			sw.write<int, float>(write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			auto		  sr   = big_endian_streamreader{ifs};
			float		  read = sr.read<float, int>();
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
