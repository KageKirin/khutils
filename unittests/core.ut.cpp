#include "khutils/assertion.hpp"
#include "khutils/logging.hpp"
#include "khutils/runtime_exceptions.hpp"
#include "khutils/spiritual_cast.hpp"

#include <bandit/bandit.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace bandit;
using namespace khutils;


#define IT_TEST_SPIRITUAL_CAST(type, str, expect)                                                                      \
	it(#type " from " str, []() {                                                                                      \
		type val = khutils::spiritual_cast<type>(str);                                                                 \
		AssertThat(val, Equals((type)expect));                                                                         \
                                                                                                                       \
	})

#define IT_TEST_SPIRITUAL_CAST_EXCEPTION(type, str, expect)                                                            \
	it(#type " from " str, []() {                                                                                      \
		bool hasExcepted = false;                                                                                      \
		try                                                                                                            \
		{                                                                                                              \
			type val = khutils::spiritual_cast<type>(str);                                                             \
		}                                                                                                              \
		catch (const khutils::SpiritualCastException& e)                                                               \
		{                                                                                                              \
			hasExcepted = true;                                                                                        \
		}                                                                                                              \
		AssertThat(hasExcepted, Equals(expect));                                                                       \
                                                                                                                       \
	})

go_bandit([]() {
	//////////////////////////////////////////////////////////////////////////
	// logger
	describe("logging styles", []() {
		it("log", []() {
			khutils::logger::debug() << "Debug message" << std::endl;
			khutils::logger::log() << "Log message" << std::endl;
			khutils::logger::warn() << "Warning message" << std::endl;
			khutils::logger::error() << "Error message" << std::endl;
			AssertThat(true, Equals(true));
		});
	});

	//////////////////////////////////////////////////////////////////////////
	// spiritual cast
	describe("spiritual cast", []() {
		IT_TEST_SPIRITUAL_CAST(bool, "true", true);
		IT_TEST_SPIRITUAL_CAST(bool, "false", false);

		IT_TEST_SPIRITUAL_CAST(char, "1", 1);
		IT_TEST_SPIRITUAL_CAST(short, "1", 1);
		IT_TEST_SPIRITUAL_CAST(int, "1", 1);
		IT_TEST_SPIRITUAL_CAST(long, "1", 1);
		IT_TEST_SPIRITUAL_CAST(long long, "1", 1);
		IT_TEST_SPIRITUAL_CAST(unsigned char, "1", 1);
		IT_TEST_SPIRITUAL_CAST(unsigned short, "1", 1);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "1", 1);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "1", 1);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "1", 1);
		IT_TEST_SPIRITUAL_CAST(float, "1", 1);
		IT_TEST_SPIRITUAL_CAST(double, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::int8_t, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::uint8_t, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::uint16_t, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "1", 1);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "1", 1);

		IT_TEST_SPIRITUAL_CAST(char, "12", 12);
		IT_TEST_SPIRITUAL_CAST(short, "12", 12);
		IT_TEST_SPIRITUAL_CAST(int, "12", 12);
		IT_TEST_SPIRITUAL_CAST(long, "12", 12);
		IT_TEST_SPIRITUAL_CAST(long long, "12", 12);
		IT_TEST_SPIRITUAL_CAST(unsigned char, "12", 12);
		IT_TEST_SPIRITUAL_CAST(unsigned short, "12", 12);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "12", 12);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "12", 12);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "12", 12);
		IT_TEST_SPIRITUAL_CAST(float, "12", 12);
		IT_TEST_SPIRITUAL_CAST(double, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::int8_t, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::uint8_t, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::uint16_t, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "12", 12);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "12", 12);

		IT_TEST_SPIRITUAL_CAST(char, "123", 123);
		IT_TEST_SPIRITUAL_CAST(short, "123", 123);
		IT_TEST_SPIRITUAL_CAST(int, "123", 123);
		IT_TEST_SPIRITUAL_CAST(long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(long long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned char, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned short, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(float, "123", 123);
		IT_TEST_SPIRITUAL_CAST(double, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::int8_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::uint8_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::uint16_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "123", 123);

		IT_TEST_SPIRITUAL_CAST(short, "123", 123);
		IT_TEST_SPIRITUAL_CAST(int, "123", 123);
		IT_TEST_SPIRITUAL_CAST(long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(long long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned short, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "123", 123);
		IT_TEST_SPIRITUAL_CAST(float, "123", 123);
		IT_TEST_SPIRITUAL_CAST(double, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::uint16_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "123", 123);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "123", 123);

		IT_TEST_SPIRITUAL_CAST(short, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(int, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(long, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(long long, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(unsigned short, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(float, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(double, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(std::uint16_t, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "1234", 1234);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "1234", 1234);

		IT_TEST_SPIRITUAL_CAST(short, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(int, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(long, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(long long, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(unsigned short, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(float, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(double, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(std::uint16_t, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "12345", 12345);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "12345", 12345);

		IT_TEST_SPIRITUAL_CAST(int, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(long, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(long long, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(float, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(double, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "123456", 123456);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "123456", 123456);

		IT_TEST_SPIRITUAL_CAST(int, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(long, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(long long, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(float, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(double, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "1234567", 1234567);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "1234567", 1234567);

		IT_TEST_SPIRITUAL_CAST(int, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(long, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(long long, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(float, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(double, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "12345678", 12345678);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "12345678", 12345678);

		IT_TEST_SPIRITUAL_CAST(int, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(long, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(long long, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(float, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(double, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "123456789", 123456789);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "123456789", 123456789);

		IT_TEST_SPIRITUAL_CAST(int, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(long, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(long long, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(float, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(double, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "1234567890", 1234567890);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "1234567890", 1234567890);

		IT_TEST_SPIRITUAL_CAST(char, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(short, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(int, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(long, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(long long, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(float, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(double, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(std::int8_t, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-1", -1);

		IT_TEST_SPIRITUAL_CAST(char, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(short, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(int, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(long, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(long long, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(float, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(double, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(std::int8_t, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-12", -12);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-12", -12);

		IT_TEST_SPIRITUAL_CAST(char, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(short, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(int, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(long, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(long long, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(float, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(double, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(std::int8_t, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-123", -123);

		IT_TEST_SPIRITUAL_CAST(short, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(int, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(long, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(long long, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(float, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(double, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-123", -123);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-123", -123);

		IT_TEST_SPIRITUAL_CAST(short, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(int, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(long, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(long long, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(float, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(double, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-1234", -1234);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-1234", -1234);

		IT_TEST_SPIRITUAL_CAST(short, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(int, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(long, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(long long, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(float, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(double, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-12345", -12345);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-12345", -12345);

		IT_TEST_SPIRITUAL_CAST(int, "-123456", -123456);
		IT_TEST_SPIRITUAL_CAST(long, "-123456", -123456);
		IT_TEST_SPIRITUAL_CAST(long long, "-123456", -123456);
		IT_TEST_SPIRITUAL_CAST(float, "-123456", -123456);
		IT_TEST_SPIRITUAL_CAST(double, "-123456", -123456);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-123456", -123456);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-123456", -123456);

		IT_TEST_SPIRITUAL_CAST(int, "-1234567", -1234567);
		IT_TEST_SPIRITUAL_CAST(long, "-1234567", -1234567);
		IT_TEST_SPIRITUAL_CAST(long long, "-1234567", -1234567);
		IT_TEST_SPIRITUAL_CAST(float, "-1234567", -1234567);
		IT_TEST_SPIRITUAL_CAST(double, "-1234567", -1234567);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-1234567", -1234567);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-1234567", -1234567);

		IT_TEST_SPIRITUAL_CAST(int, "-12345678", -12345678);
		IT_TEST_SPIRITUAL_CAST(long, "-12345678", -12345678);
		IT_TEST_SPIRITUAL_CAST(long long, "-12345678", -12345678);
		IT_TEST_SPIRITUAL_CAST(float, "-12345678", -12345678);
		IT_TEST_SPIRITUAL_CAST(double, "-12345678", -12345678);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-12345678", -12345678);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-12345678", -12345678);

		IT_TEST_SPIRITUAL_CAST(int, "-123456789", -123456789);
		IT_TEST_SPIRITUAL_CAST(long, "-123456789", -123456789);
		IT_TEST_SPIRITUAL_CAST(long long, "-123456789", -123456789);
		IT_TEST_SPIRITUAL_CAST(float, "-123456789", -123456789);
		IT_TEST_SPIRITUAL_CAST(double, "-123456789", -123456789);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-123456789", -123456789);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-123456789", -123456789);

		IT_TEST_SPIRITUAL_CAST(int, "-1234567890", -1234567890);
		IT_TEST_SPIRITUAL_CAST(long, "-1234567890", -1234567890);
		IT_TEST_SPIRITUAL_CAST(long long, "-1234567890", -1234567890);
		IT_TEST_SPIRITUAL_CAST(float, "-1234567890", -1234567890);
		IT_TEST_SPIRITUAL_CAST(double, "-1234567890", -1234567890);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "-1234567890", -1234567890);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "-1234567890", -1234567890);
	});

	describe("spiritual cast floating points", []() {
		IT_TEST_SPIRITUAL_CAST(float, "1", 1);
		IT_TEST_SPIRITUAL_CAST(double, "1", 1);

		IT_TEST_SPIRITUAL_CAST(float, "1.", 1.);
		IT_TEST_SPIRITUAL_CAST(double, "1.", 1.);

		IT_TEST_SPIRITUAL_CAST(float, ".1", .1);
		IT_TEST_SPIRITUAL_CAST(double, ".1", .1);

		IT_TEST_SPIRITUAL_CAST(float, "0.1", 0.1);
		IT_TEST_SPIRITUAL_CAST(double, "0.1", 0.1);

		IT_TEST_SPIRITUAL_CAST(float, "1.0", 1.0);
		IT_TEST_SPIRITUAL_CAST(double, "1.0", 1.0);

		IT_TEST_SPIRITUAL_CAST(float, "1.2", 1.2);
		IT_TEST_SPIRITUAL_CAST(double, "1.2", 1.2);

		IT_TEST_SPIRITUAL_CAST(float, "1.23", 1.23);
		IT_TEST_SPIRITUAL_CAST(double, "1.23", 1.23);

		IT_TEST_SPIRITUAL_CAST(float, "1.234", 1.234);
		IT_TEST_SPIRITUAL_CAST(double, "1.234", 1.234);

		IT_TEST_SPIRITUAL_CAST(float, "1.2345", 1.2345);
		IT_TEST_SPIRITUAL_CAST(double, "1.2345", 1.2345);

		IT_TEST_SPIRITUAL_CAST(float, "1.23456", 1.23456);
		IT_TEST_SPIRITUAL_CAST(double, "1.23456", 1.23456);

		IT_TEST_SPIRITUAL_CAST(float, "1.234567", 1.234567);
		IT_TEST_SPIRITUAL_CAST(double, "1.234567", 1.234567);

		IT_TEST_SPIRITUAL_CAST(float, "1.2345678", 1.2345678);
		IT_TEST_SPIRITUAL_CAST(double, "1.2345678", 1.2345678);

		IT_TEST_SPIRITUAL_CAST(float, "1.23456789", 1.23456789);
		IT_TEST_SPIRITUAL_CAST(double, "1.23456789", 1.23456789);

		IT_TEST_SPIRITUAL_CAST(float, "-1", -1);
		IT_TEST_SPIRITUAL_CAST(double, "-1", -1);

		IT_TEST_SPIRITUAL_CAST(float, "-1.", -1.);
		IT_TEST_SPIRITUAL_CAST(double, "-1.", -1.);

		IT_TEST_SPIRITUAL_CAST(float, "-.1", -.1);
		IT_TEST_SPIRITUAL_CAST(double, "-.1", -.1);

		IT_TEST_SPIRITUAL_CAST(float, "-0.1", -0.1);
		IT_TEST_SPIRITUAL_CAST(double, "-0.1", -0.1);

		IT_TEST_SPIRITUAL_CAST(float, "-1.0", -1.0);
		IT_TEST_SPIRITUAL_CAST(double, "-1.0", -1.0);

		IT_TEST_SPIRITUAL_CAST(float, "-1.2", -1.2);
		IT_TEST_SPIRITUAL_CAST(double, "-1.2", -1.2);

		IT_TEST_SPIRITUAL_CAST(float, "-1.23", -1.23);
		IT_TEST_SPIRITUAL_CAST(double, "-1.23", -1.23);

		IT_TEST_SPIRITUAL_CAST(float, "-1.234", -1.234);
		IT_TEST_SPIRITUAL_CAST(double, "-1.234", -1.234);

		IT_TEST_SPIRITUAL_CAST(float, "-1.2345", -1.2345);
		IT_TEST_SPIRITUAL_CAST(double, "-1.2345", -1.2345);

		IT_TEST_SPIRITUAL_CAST(float, "-1.23456", -1.23456);
		IT_TEST_SPIRITUAL_CAST(double, "-1.23456", -1.23456);

		IT_TEST_SPIRITUAL_CAST(float, "-1.234567", -1.234567);
		IT_TEST_SPIRITUAL_CAST(double, "-1.234567", -1.234567);

		IT_TEST_SPIRITUAL_CAST(float, "-1.2345678", -1.2345678);
		IT_TEST_SPIRITUAL_CAST(double, "-1.2345678", -1.2345678);

		IT_TEST_SPIRITUAL_CAST(float, "-1.23456789", -1.23456789);
		IT_TEST_SPIRITUAL_CAST(double, "-1.23456789", -1.23456789);

		// ~f notation is invalid for parser
		// IT_TEST_SPIRITUAL_CAST(float, "1.f", 1.f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.f", 1.f);

		// IT_TEST_SPIRITUAL_CAST(float, "-.1f", .1f);
		// IT_TEST_SPIRITUAL_CAST(double, "-.1f", .1f);

		// IT_TEST_SPIRITUAL_CAST(float, "0.1f", 0.1f);
		// IT_TEST_SPIRITUAL_CAST(double, "0.1f", 0.1f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.0f", 1.0f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.0f", 1.0f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.2f", 1.2f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.2f", 1.2f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.23f", 1.23f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.23f", 1.23f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.234f", 1.234f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.234f", 1.234f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.2345f", 1.2345f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.2345f", 1.2345f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.23456f", 1.23456f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.23456f", 1.23456f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.234567f", 1.234567f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.234567f", 1.234567f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.2345678f", 1.2345678f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.2345678f", 1.2345678f);

		// IT_TEST_SPIRITUAL_CAST(float, "1.23456789f", 1.23456789f);
		// IT_TEST_SPIRITUAL_CAST(double, "1.23456789f", 1.23456789f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.f", -1.f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.f", -1.f);

		// IT_TEST_SPIRITUAL_CAST(float, "-.1f", -.1f);
		// IT_TEST_SPIRITUAL_CAST(double, "-.1f", -.1f);

		// IT_TEST_SPIRITUAL_CAST(float, "-0.1f", -0.1f);
		// IT_TEST_SPIRITUAL_CAST(double, "-0.1f", -0.1f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.0f", -1.0f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.0f", -1.0f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.2f", -1.2f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.2f", -1.2f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.23f", -1.23f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.23f", -1.23f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.234f", -1.234f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.234f", -1.234f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.2345f", -1.2345f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.2345f", -1.2345f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.23456f", -1.23456f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.23456f", -1.23456f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.234567f", -1.234567f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.234567f", -1.234567f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.2345678f", -1.2345678f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.2345678f", -1.2345678f);

		// IT_TEST_SPIRITUAL_CAST(float, "-1.23456789f", -1.23456789f);
		// IT_TEST_SPIRITUAL_CAST(double, "-1.23456789f", -1.23456789f);

		IT_TEST_SPIRITUAL_CAST(float, "-1.5496e-006", -1.5496e-006);
		IT_TEST_SPIRITUAL_CAST(double, "-1.5496e-006", -1.5496e-006);
	});

	describe("spiritual cast exceptions", []() {
		IT_TEST_SPIRITUAL_CAST(bool, "true", false);
		IT_TEST_SPIRITUAL_CAST(bool, "false", false);
		IT_TEST_SPIRITUAL_CAST(bool, "tru", true);
		IT_TEST_SPIRITUAL_CAST(bool, "fals", true);
		IT_TEST_SPIRITUAL_CAST(bool, "tru", true);
		IT_TEST_SPIRITUAL_CAST(bool, "flase", true);
		IT_TEST_SPIRITUAL_CAST(bool, "fasle", true);
		IT_TEST_SPIRITUAL_CAST(bool, "1", false);
		IT_TEST_SPIRITUAL_CAST(bool, "0", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "1", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "12", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "123", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "1234", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "12345", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "123456", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "1234567", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "12345678", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "123456789", false);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "1234567890", false);

		// negative numbers
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-1", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-1", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-1", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-12", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-12", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-12", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-123", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-123", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-123", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-1234", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-1234", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-1234", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-12345", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-12345", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-12345", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-123456", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-123456", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-123456", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-1234567", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-1234567", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-1234567", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-12345678", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-12345678", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-12345678", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-123456789", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-123456789", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-123456789", true);

		IT_TEST_SPIRITUAL_CAST_EXCEPTION(char, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(short, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(int, "-1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long, "-1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(long long, "-1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned char, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned short, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned int, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(unsigned long long, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(float, "-1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(double, "-1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int8_t, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int16_t, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int32_t, "-1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::int64_t, "-1234567890", false);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint8_t, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint16_t, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint32_t, "-1234567890", true);
		IT_TEST_SPIRITUAL_CAST_EXCEPTION(std::uint64_t, "-1234567890", true);

	});
});
