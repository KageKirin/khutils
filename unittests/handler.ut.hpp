#ifndef KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC
#define KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC

#include <bandit/bandit.h>

auto it_singleWriteAndRead = [](auto name, auto write, auto writer, auto reader) {
	using namespace bandit;

	return it(name, [&]() {
		writer.template write<decltype(write)>(write);
		auto read = reader.template read<decltype(write)>();

		AssertThat(read, Equals(write));
	});
};

auto it_doubleWriteAndRead = [](auto name, auto write, auto write2, auto writer, auto reader) {
	using namespace bandit;

	return it(name, [&]() {
		writer.template write<decltype(write)>(write);
		writer.template write<decltype(write2)>(write2);

		auto read  = reader.template read<decltype(write)>();
		auto read2 = reader.template read<decltype(write2)>();

		AssertThat(read, Equals(write));
		AssertThat(read2, Equals(write2));
	});
};

auto it_writeFetchAndRead = [](auto name, auto write, auto writer, auto reader) {
	using namespace bandit;

	return it(name, [&]() {
		writer.template write<decltype(write)>(write);

		auto fetch = reader.template fetch<decltype(write)>();
		auto read  = reader.template read<decltype(write)>();

		AssertThat(fetch, Equals(write));
		AssertThat(read, Equals(write));
		AssertThat(fetch, Equals(read));
	});
};

auto it_skipAndAlign = [](auto name, auto write, auto write2, auto write3, auto writer, auto reader) {
	using namespace bandit;

	return it(name, [&]() {
		writer.template write<decltype(write)>(write);
		writer.template skip<decltype(write)>();
		writer.template write<decltype(write2)>(write2);
		writer.template alignToNext<16>();
		writer.template write<decltype(write3)>(write3);

		auto read = reader.template read<decltype(write)>();
		reader.template skip<decltype(write)>();
		auto read2 = reader.template read<decltype(write2)>();
		reader.template alignToNext<16>();
		auto read3 = reader.template read<decltype(write3)>();

		AssertThat(read, Equals(write));
		AssertThat(read2, Equals(write2));
		AssertThat(read3, Equals(write3));
	});
};

#endif	// ! KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC
