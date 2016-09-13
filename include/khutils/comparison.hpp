#ifndef KHUTILS_COMPARISON_HPP_INC
#define KHUTILS_COMPARISON_HPP_INC

#include <cstdint>
#include <limits>

namespace khutils
{
	template <typename T>
	bool compareEpsilon(const T& lhv, const T& rhv, const T epsilon = std::numeric_limits<T>::epsilon())
	{
		T diff = lhv - rhv;
		return -epsilon <= diff && diff <= epsilon;
	}

	//- hack for float comparison
	bool compareLiterally(const float& lhv, const float& rhv);
	bool compare(const float& lhv, const float& rhv);

	//- hack for double comparison
	bool compareLiterally(const double& lhv, const double& rhv);
	bool compare(const double& lhv, const double& rhv);

	bool compareLiterally(const int32_t& lhv, const int32_t& rhv);
	bool compareLiterally(const uint32_t& lhv, const uint32_t& rhv);
	bool compareLiterally(const int16_t& lhv, const int16_t& rhv);
	bool compareLiterally(const uint16_t& lhv, const uint16_t& rhv);
	bool compareLiterally(const int8_t& lhv, const int8_t& rhv);
	bool compareLiterally(const uint8_t& lhv, const uint8_t& rhv);

}	// namespace khutils

#if defined(KHUTILS_COMPARISON_IMPL)

#include "khutils/comparison.hpp"
#include "khutils/spiritual_compare.hpp"

namespace khutils
{
	bool compareLiterally(const float& lhv, const float& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

	bool compare(const float& lhv, const float& rhv)
	{
		return compareLiterally(lhv, rhv) || compareEpsilon<float>(lhv, rhv, 0.0001);
	}

	//- hack for double comparison
	//- because fuck IEEE 754
	bool compareLiterally(const double& lhv, const double& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

	bool compare(const double& lhv, const double& rhv)
	{
		return compareLiterally(lhv, rhv) || compareEpsilon<double>(lhv, rhv, 0.0001);
	}

	bool compareLiterally(const int32_t& lhv, const int32_t& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

	bool compareLiterally(const uint32_t& lhv, const uint32_t& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

	bool compareLiterally(const int16_t& lhv, const int16_t& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

	bool compareLiterally(const uint16_t& lhv, const uint16_t& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

	bool compareLiterally(const int8_t& lhv, const int8_t& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

	bool compareLiterally(const uint8_t& lhv, const uint8_t& rhv)
	{
		return spiritual_compare(std::to_string(lhv), std::to_string(rhv));
	}

}	// namespace khutils

#endif	// defined (KHUTILS_COMPARISON_IMPL)

#endif	// !KHUTILS_COMPARISON_HPP_INC
