#include "khutils/assertion.hpp"
#include "khutils/logging.hpp"
#include "khutils/runtime_exceptions.hpp"
#include "khutils/spiritual_cast.hpp"
#include "khutils/spiritual_compare.hpp"

#include <bandit/bandit.h>
#include <fstream>
#include <functional>
#include <limits>
#include <sstream>
#include <string>

using namespace bandit;
using namespace khutils;


template <typename T>
static void spiritual_cast_test(const std::string& str, const T expect)
{
	T val = khutils::spiritual_cast<T>(str);
	AssertThat(val, Equals(expect));
};

template <typename T>
static void spiritual_cast_test_exception(const std::string& str, const T expect)
{
	bool hasExcepted = false;
	try
	{
		T val = khutils::spiritual_cast<T>(str);
	}
	catch (const khutils::SpiritualCastException& e)
	{
		hasExcepted = true;
	}
	AssertThat(hasExcepted, Equals(expect));
};

#define IT_TEST_SPIRITUAL_CAST(type, str, expect)                                                                      \
	it(#type " from " str, std::bind(spiritual_cast_test<type>, str, expect));

#define IT_TEST_SPIRITUAL_CAST_LIMIT(type, limit)                                                                      \
	it(#type " from " #limit, std::bind(spiritual_cast_test<type>, std::to_string(limit), limit));

#define IT_TEST_SPIRITUAL_CAST_EXCEPTION(type, str, expect)                                                            \
	it(#type " from " str, std::bind(spiritual_cast_test_exception<type>, str, expect));

static void spiritual_compare_test(const std::string& lhv, const std::string& rhv, bool expect)
{
	bool comp = khutils::spiritual_compare(lhv, rhv);
	AssertThat(comp, Equals(expect));
}

#define IT_TEST_SPIRITUAL_COMPARE(strA, strB, expect)                                                                  \
	it(strA " =?= " strB, std::bind(spiritual_compare_test, strA, strB, expect))

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

		IT_TEST_SPIRITUAL_CAST(char, "256", 256);
		IT_TEST_SPIRITUAL_CAST(short, "256", 256);
		IT_TEST_SPIRITUAL_CAST(int, "256", 256);
		IT_TEST_SPIRITUAL_CAST(long, "256", 256);
		IT_TEST_SPIRITUAL_CAST(long long, "256", 256);
		IT_TEST_SPIRITUAL_CAST(unsigned char, "256", 256);
		IT_TEST_SPIRITUAL_CAST(unsigned short, "256", 256);
		IT_TEST_SPIRITUAL_CAST(unsigned int, "256", 256);
		IT_TEST_SPIRITUAL_CAST(unsigned long, "256", 256);
		IT_TEST_SPIRITUAL_CAST(unsigned long long, "256", 256);
		IT_TEST_SPIRITUAL_CAST(float, "256", 256);
		IT_TEST_SPIRITUAL_CAST(double, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::int8_t, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::int16_t, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::int32_t, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::int64_t, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::uint8_t, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::uint16_t, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::uint32_t, "256", 256);
		IT_TEST_SPIRITUAL_CAST(std::uint64_t, "256", 256);

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

		IT_TEST_SPIRITUAL_CAST(float, "-1.5496e-006", -1.5496e-006);
		IT_TEST_SPIRITUAL_CAST(double, "-1.5496e-006", -1.5496e-006);
	});

	describe("spiritual cast at numeric limits", []() {
		// 8 bit
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<char>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<char>::max());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned char>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned char>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned char>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned char>::max());

		// 16 bit
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<short>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<short>::max());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned short>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned short>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned short>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned short>::max());

		// 32 bit
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<int>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<int>::max());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned int>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned int>::max());

		// long
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<long int>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<long int>::max());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned long int>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned long int>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned long int>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned long int>::max());

		// long long
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<long long>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<long long>::max());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned long long>::min());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned long long>::min());

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, std::numeric_limits<unsigned long long>::max());
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, std::numeric_limits<unsigned long long>::max());
	});

	describe("spiritual cast beyond numeric limits", []() {
		// 8 bit
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<char>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<char>::max()) + 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned char>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned char>::max()) + 1));

		// 16 bit
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<short>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<short>::max()) + 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned short>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned short>::max()) + 1));

		// 32 bit
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<int>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<int>::max()) + 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned int>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned int>::max()) + 1));

		// long
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<long int>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<long int>::max()) + 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned long int>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<unsigned long int>::max()) + 1));

		// long long
		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((long long)std::numeric_limits<long long>::min()) - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((long long)std::numeric_limits<long long>::min()) - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (((unsigned long long)std::numeric_limits<long long>::max()) + 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (std::numeric_limits<unsigned long long>::min() - 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (std::numeric_limits<unsigned long long>::min() - 1));

		IT_TEST_SPIRITUAL_CAST_LIMIT(char, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(short, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(int, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(long long, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned char, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned short, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned int, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(unsigned long long, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(float, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(double, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int8_t, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int16_t, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int32_t, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::int64_t, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint8_t, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint16_t, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint32_t, (std::numeric_limits<unsigned long long>::max() + 1));
		IT_TEST_SPIRITUAL_CAST_LIMIT(std::uint64_t, (std::numeric_limits<unsigned long long>::max() + 1));
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

	describe("spiritual compare", []() {
		IT_TEST_SPIRITUAL_COMPARE("abc", "abc", true);
		IT_TEST_SPIRITUAL_COMPARE("abc", "def", false);

		IT_TEST_SPIRITUAL_COMPARE("abc", "abcd", false);
		IT_TEST_SPIRITUAL_COMPARE("abcd", "abc", false);

		IT_TEST_SPIRITUAL_COMPARE("abc", "ABC", false);
		IT_TEST_SPIRITUAL_COMPARE("abc", "AbC", false);

		IT_TEST_SPIRITUAL_COMPARE("abc", R"(abc)", true);
	});
});
