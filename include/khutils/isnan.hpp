#ifndef KHUTILS_ISNAN_HPP_INC
#define KHUTILS_ISNAN_HPP_INC

namespace khutils
{
	void check_NaN(const double& d);
	void check_NaN(const float& d);
	void check_NaN(const int& d);

}	// namespace khutils

#if defined(KHUTILS_ISNAN_IMPL)

#include "khutils/assertion.hpp"
#include "khutils/logging.hpp"

namespace khutils
{
	void check_NaN(const float& d)
	{
		KHUTILS_ASSERT(!isnan(d));
	}

	void check_NaN(const double& d)
	{
		KHUTILS_ASSERT(!isnan(d));
	}

	void check_NaN(const int& d)
	{
		KHUTILS_ASSERT(!isnan(d));
	}

}	// namespace khutils

#endif	// defined (KHUTILS_ISNAN_IMPL)

#endif	// !KHUTILS_ISNAN_HPP_INC
