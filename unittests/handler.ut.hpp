#ifndef KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC
#define KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC

#include <bandit/bandit.h>

auto it_singleWriteAndRead = [](auto name, auto write, auto get_writer, auto get_reader) {
	using namespace bandit;

	return it(name, [&]() {
		auto writer = get_writer();
		writer.template write<decltype(write)>(write);

		auto reader = get_reader();
		auto read   = reader.template read<decltype(write)>();

		AssertThat(read, Equals(write));
	});
};

auto it_doubleWriteAndRead = [](auto name, auto write, auto write2, auto get_writer, auto get_reader) {
	using namespace bandit;

	return it(name, [&]() {
		auto writer = get_writer();
		writer.template write<decltype(write)>(write);
		writer.template write<decltype(write2)>(write2);

		auto reader = get_reader();
		auto read   = reader.template read<decltype(write)>();
		auto read2  = reader.template read<decltype(write2)>();

		AssertThat(read, Equals(write));
		AssertThat(read2, Equals(write2));
	});
};

auto it_writeFetchAndRead = [](auto name, auto write, auto get_writer, auto get_reader) {
	using namespace bandit;

	return it(name, [&]() {
		auto writer = get_writer();
		writer.template write<decltype(write)>(write);

		auto reader = get_reader();
		auto fetch  = reader.template fetch<decltype(write)>();
		auto read   = reader.template read<decltype(write)>();

		AssertThat(fetch, Equals(write));
		AssertThat(read, Equals(write));
		AssertThat(fetch, Equals(read));
	});
};

auto it_skipAndAlign = [](auto name, auto write, auto write2, auto write3, auto get_writer, auto get_reader) {
	using namespace bandit;

	return it(name, [&]() {
		auto writer = get_writer();
		writer.template write<decltype(write)>(write);
		writer.template skip<decltype(write)>();
		writer.template write<decltype(write2)>(write2);
		writer.template alignToNext<16>();
		writer.template write<decltype(write3)>(write3);

		auto reader = get_reader();
		auto read   = reader.template read<decltype(write)>();
		reader.template skip<decltype(write)>();
		auto read2 = reader.template read<decltype(write2)>();
		reader.template alignToNext<16>();
		auto read3 = reader.template read<decltype(write3)>();

		AssertThat(read, Equals(write));
		AssertThat(read2, Equals(write2));
		AssertThat(read3, Equals(write3));
	});
};

///

auto desc_singleWriteAndRead = [](auto desc, auto get_writer, auto get_reader) {
	using namespace bandit;

	return describe(desc, [&]() {
		it_singleWriteAndRead("int", 42, get_writer, get_reader);
		// it_singleWriteAndRead("float", 0.65f, get_writer, get_reader);
		// it_singleWriteAndRead("double", 2.56094, get_writer, get_reader);
	});
};

auto desc_doubleWriteAndRead = [](auto desc, auto get_writer, auto get_reader) {
	using namespace bandit;

	return describe(desc, [&]() {
		it_doubleWriteAndRead("int, int", 42, 87, get_writer, get_reader);
		// it_doubleWriteAndRead("float, float", 0.65f, 1.12f, get_writer,
		// get_reader);
		// it_doubleWriteAndRead("double, double", 0.654245, 1.128745, get_writer,
		// get_reader);
	});
};

auto desc_mixedWriteAndRead = [](auto desc, auto get_writer, auto get_reader) {
	using namespace bandit;

	return describe(desc, [&]() {
		// it_doubleWriteAndRead("int, float", 42, 1.12f, get_writer, get_reader);
		// it_doubleWriteAndRead("float, int", 0.65f, 87, get_writer, get_reader);
		// it_doubleWriteAndRead("float, double", 0.65f, 1.128745, get_writer,
		// get_reader);
	});
};

auto desc_writeFetchAndRead = [](auto desc, auto get_writer, auto get_reader) {
	using namespace bandit;

	return describe(desc, [&]() {
		it_writeFetchAndRead("int", 42, get_writer, get_reader);
		// it_writeFetchAndRead("float", 0.65f, get_writer, get_reader);
		// it_writeFetchAndRead("double", 2.56094, get_writer, get_reader);
	});
};

auto desc_skipAndAlign = [](auto desc, auto get_writer, auto get_reader) {
	using namespace bandit;

	return describe(desc, [&]() {
		it_skipAndAlign("int, int, int", 42, 87, 456, get_writer, get_reader);
		// it_skipAndAlign("float, float, float", 0.65f, 1.12f, 75.545f, get_writer,
		// get_reader);
		// it_skipAndAlign("double, double, double", 0.654245, 1.128745, 345.54509,
		// get_writer, get_reader);

		// it_skipAndAlign("int, float, double", 42, 1.12f, 345.54509, get_writer,
		// get_reader);
		// it_skipAndAlign("float, int, double", 0.65f, 87, 345.54509, get_writer,
		// get_reader);
		// it_skipAndAlign("double, float, int", 0.654245, 1.12f, 345.54509,
		// get_writer, get_reader);
	});
};

///

auto desc_testGroup = [](auto desc, auto get_writer, auto get_reader) {
	using namespace bandit;

	return describe(desc, [&]() {
		desc_singleWriteAndRead("writing once, reading once", get_writer, get_reader);
		desc_doubleWriteAndRead("writing twice, reading twice", get_writer, get_reader);
		desc_mixedWriteAndRead("writing mixed, reading mixed", get_writer, get_reader);
		desc_writeFetchAndRead("fetching", get_writer, get_reader);
		desc_skipAndAlign("skip and alignment", get_writer, get_reader);
	});
};

#endif	// ! KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC
