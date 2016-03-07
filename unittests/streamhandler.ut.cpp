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
			std::stringstream s;
			int				  write = 42;
			streamhandler::write<int>(s, write);
			int read = streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
		});

		it("float", []() {
			std::stringstream s;
			float			  write = 0.65;
			streamhandler::write<int, float>(s, write);
			float read = streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
		});
	});

	describe("writing twice, reading twice", []() {
		it("int", []() {
			std::stringstream s;
			int				  write = 42;
			streamhandler::write<int>(s, write);
			int write2 = 87;
			streamhandler::write<int>(s, write2);

			int read  = streamhandler::read<int>(s);
			int read2 = streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {
			std::stringstream s;
			float			  write = 0.65;
			streamhandler::write<int, float>(s, write);
			float write2 = 1.12;
			streamhandler::write<int, float>(s, write2);

			float read  = streamhandler::read<float, int>(s);
			float read2 = streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("writing mixed, reading mixed", []() {
		it("int, float", []() {
			std::stringstream s;
			int				  write = 42;
			streamhandler::write<int>(s, write);
			float write2 = 1.12;
			streamhandler::write<int, float>(s, write2);

			int   read  = streamhandler::read<int>(s);
			float read2 = streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {
			std::stringstream s;
			float			  write = 0.65;
			streamhandler::write<int, float>(s, write);
			int write2 = 42;
			streamhandler::write<int>(s, write2);

			float read  = streamhandler::read<float, int>(s);
			int   read2 = streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("little endian: writing once, reading once", []() {
		it("int", []() {
			std::stringstream s;
			int				  write = 42;
			little_endian_streamhandler::write<int>(s, write);
			int read = little_endian_streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
		});

		it("float", []() {
			std::stringstream s;
			float			  write = 0.65;
			little_endian_streamhandler::write<int, float>(s, write);
			float read = little_endian_streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
		});
	});

	describe("little endian: writing twice, reading twice", []() {
		it("int", []() {
			std::stringstream s;
			int				  write = 42;
			little_endian_streamhandler::write<int>(s, write);
			int write2 = 87;
			little_endian_streamhandler::write<int>(s, write2);

			int read  = little_endian_streamhandler::read<int>(s);
			int read2 = little_endian_streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {
			std::stringstream s;
			float			  write = 0.65;
			little_endian_streamhandler::write<int, float>(s, write);
			float write2 = 1.12;
			little_endian_streamhandler::write<int, float>(s, write2);

			float read  = little_endian_streamhandler::read<float, int>(s);
			float read2 = little_endian_streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("little endian: writing mixed, reading mixed", []() {
		it("int, float", []() {
			std::stringstream s;
			int				  write = 42;
			little_endian_streamhandler::write<int>(s, write);
			float write2 = 1.12;
			little_endian_streamhandler::write<int, float>(s, write2);

			int   read  = little_endian_streamhandler::read<int>(s);
			float read2 = little_endian_streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {
			std::stringstream s;
			float			  write = 0.65;
			little_endian_streamhandler::write<int, float>(s, write);
			int write2 = 42;
			little_endian_streamhandler::write<int>(s, write2);

			float read  = little_endian_streamhandler::read<float, int>(s);
			int   read2 = little_endian_streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("big endian: writing once, reading once", []() {
		it("int", []() {
			std::stringstream s;
			int				  write = 42;
			big_endian_streamhandler::write<int>(s, write);
			int read = big_endian_streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
		});

		it("float", []() {
			std::stringstream s;
			float			  write = 0.65;
			big_endian_streamhandler::write<int, float>(s, write);
			float read = big_endian_streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
		});
	});

	describe("big endian: writing twice, reading twice", []() {
		it("int", []() {
			std::stringstream s;
			int				  write = 42;
			big_endian_streamhandler::write<int>(s, write);
			int write2 = 87;
			big_endian_streamhandler::write<int>(s, write2);

			int read  = big_endian_streamhandler::read<int>(s);
			int read2 = big_endian_streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {
			std::stringstream s;
			float			  write = 0.65;
			big_endian_streamhandler::write<int, float>(s, write);
			float write2 = 1.12;
			big_endian_streamhandler::write<int, float>(s, write2);

			float read  = big_endian_streamhandler::read<float, int>(s);
			float read2 = big_endian_streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("big endian: writing mixed, reading mixed", []() {
		it("int, float", []() {
			std::stringstream s;
			int				  write = 42;
			big_endian_streamhandler::write<int>(s, write);
			float write2 = 1.12;
			big_endian_streamhandler::write<int, float>(s, write2);

			int   read  = big_endian_streamhandler::read<int>(s);
			float read2 = big_endian_streamhandler::read<float, int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {
			std::stringstream s;
			float			  write = 0.65;
			big_endian_streamhandler::write<int, float>(s, write);
			int write2 = 42;
			big_endian_streamhandler::write<int>(s, write2);

			float read  = big_endian_streamhandler::read<float, int>(s);
			int   read2 = big_endian_streamhandler::read<int>(s);

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	//////////////////////////////////////////////////////////////////////////
	// filestream-based tests

	describe("fstream - writing once, reading once", []() {
		it("int", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			streamhandler::write<int>(ofs, write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read = streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			streamhandler::write<int, float>(ofs, write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read = streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - writing twice, reading twice", []() {
		it("int", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			streamhandler::write<int>(ofs, write);
			int write2 = 87;
			streamhandler::write<int>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read  = streamhandler::read<int>(ifs);
			int			  read2 = streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			streamhandler::write<int, float>(ofs, write);
			float write2 = 1.12;
			streamhandler::write<int, float>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read  = streamhandler::read<float, int>(ifs);
			float		  read2 = streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - writing mixed, reading mixed", []() {
		it("int, float", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			streamhandler::write<int>(ofs, write);
			float write2 = 1.12;
			streamhandler::write<int, float>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read  = streamhandler::read<int>(ifs);
			float		  read2 = streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			streamhandler::write<int, float>(ofs, write);
			int write2 = 42;
			streamhandler::write<int>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read  = streamhandler::read<float, int>(ifs);
			int			  read2 = streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("fstream - little endian: writing once, reading once", []() {
		it("int", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			little_endian_streamhandler::write<int>(ofs, write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read = little_endian_streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			little_endian_streamhandler::write<int, float>(ofs, write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read = little_endian_streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - little endian: writing twice, reading twice", []() {
		it("int", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			little_endian_streamhandler::write<int>(ofs, write);
			int write2 = 87;
			little_endian_streamhandler::write<int>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read  = little_endian_streamhandler::read<int>(ifs);
			int			  read2 = little_endian_streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			little_endian_streamhandler::write<int, float>(ofs, write);
			float write2 = 1.12;
			little_endian_streamhandler::write<int, float>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read  = little_endian_streamhandler::read<float, int>(ifs);
			float		  read2 = little_endian_streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - little endian: writing mixed, reading mixed", []() {
		it("int, float", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			little_endian_streamhandler::write<int>(ofs, write);
			float write2 = 1.12;
			little_endian_streamhandler::write<int, float>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read  = little_endian_streamhandler::read<int>(ifs);
			float		  read2 = little_endian_streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			little_endian_streamhandler::write<int, float>(ofs, write);
			int write2 = 42;
			little_endian_streamhandler::write<int>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read  = little_endian_streamhandler::read<float, int>(ifs);
			int			  read2 = little_endian_streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	////

	describe("fstream - big endian: writing once, reading once", []() {
		it("int", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			big_endian_streamhandler::write<int>(ofs, write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read = big_endian_streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
		});

		it("float", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			big_endian_streamhandler::write<int, float>(ofs, write);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read = big_endian_streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
		});
	});

	describe("fstream - big endian: writing twice, reading twice", []() {
		it("int", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			big_endian_streamhandler::write<int>(ofs, write);
			int write2 = 87;
			big_endian_streamhandler::write<int>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read  = big_endian_streamhandler::read<int>(ifs);
			int			  read2 = big_endian_streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			big_endian_streamhandler::write<int, float>(ofs, write);
			float write2 = 1.12;
			big_endian_streamhandler::write<int, float>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read  = big_endian_streamhandler::read<float, int>(ifs);
			float		  read2 = big_endian_streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});

	describe("fstream - big endian: writing mixed, reading mixed", []() {
		it("int, float", []() {
			std::ofstream ofs(ut_temp);
			int			  write = 42;
			big_endian_streamhandler::write<int>(ofs, write);
			float write2 = 1.12;
			big_endian_streamhandler::write<int, float>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			int			  read  = big_endian_streamhandler::read<int>(ifs);
			float		  read2 = big_endian_streamhandler::read<float, int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});

		it("float, int", []() {
			std::ofstream ofs(ut_temp);
			float		  write = 0.65;
			big_endian_streamhandler::write<int, float>(ofs, write);
			int write2 = 42;
			big_endian_streamhandler::write<int>(ofs, write2);
			ofs.close();

			std::ifstream ifs(ut_temp);
			float		  read  = big_endian_streamhandler::read<float, int>(ifs);
			int			  read2 = big_endian_streamhandler::read<int>(ifs);
			ifs.close();

			AssertThat(read, Equals(write));
			AssertThat(read2, Equals(write2));
		});
	});
});
