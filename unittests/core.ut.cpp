#include "khutils/logging.hpp"
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
	// logger
	describe("spiritual cast", []() {
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
	});
});
