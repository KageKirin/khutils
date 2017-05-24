#ifndef KHUTILS_ISNAN_HPP_INC
#define KHUTILS_ISNAN_HPP_INC

#include <cctype>
#include <cstdint>

namespace khutils
{
	// wrapper functions
	bool isNaN(const long double&);
	bool isNaN(const double&);
	bool isNaN(const float&);
	bool isNaN(const uint8_t&);
	bool isNaN(const uint16_t&);
	bool isNaN(const uint32_t&);
	bool isNaN(const uint64_t&);
	bool isNaN(const int8_t&);
	bool isNaN(const int16_t&);
	bool isNaN(const int32_t&);
	bool isNaN(const int64_t&);

	// asserting functions
	inline void check_NaN(const long double& d);
	inline void check_NaN(const double& d);
	inline void check_NaN(const float& d);
	inline void check_NaN(const uint8_t&);
	inline void check_NaN(const uint16_t&);
	inline void check_NaN(const uint32_t&);
	inline void check_NaN(const uint64_t&);
	inline void check_NaN(const int8_t&);
	inline void check_NaN(const int16_t&);
	inline void check_NaN(const int32_t&);
	inline void check_NaN(const int64_t&);


}	// namespace khutils

#if defined(KHUTILS_ISNAN_INLINE)

#include "khutils/assertion.hpp"

void khutils::check_NaN(const long double& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const double& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const float& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const uint8_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const uint16_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const uint32_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const uint64_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const int8_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const int16_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const int32_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

void khutils::check_NaN(const int64_t& d)
{
	KHUTILS_ASSERT(!khutils::isNaN(d));
}

#endif	// defined (KHUTILS_ISNAN_INLINE)

#if defined(KHUTILS_ISNAN_IMPL)

#include <cmath>

#ifdef WIN32
#define SAFE_ISNAN_TYPE(x) ((double)x)
#else
#define SAFE_ISNAN_TYPE(x) (x)
#endif	// WIN32

bool khutils::isNaN(const long double& d)
{
	return std::fpclassify(d) == FP_NAN;
}

bool khutils::isNaN(const double& d)
{
	return std::fpclassify(d) == FP_NAN;
}

bool khutils::isNaN(const float& d)
{
	return std::fpclassify(d) == FP_NAN;
}

bool khutils::isNaN(const uint8_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

bool khutils::isNaN(const uint16_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

bool khutils::isNaN(const uint32_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

bool khutils::isNaN(const uint64_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

bool khutils::isNaN(const int8_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

bool khutils::isNaN(const int16_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

bool khutils::isNaN(const int32_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

bool khutils::isNaN(const int64_t& d)
{
	return std::fpclassify(SAFE_ISNAN_TYPE(d)) == FP_NAN;
}

#endif	// defined (KHUTILS_ISNAN_IMPL)

#endif	// !KHUTILS_ISNAN_HPP_INC
