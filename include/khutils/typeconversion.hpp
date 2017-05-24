#ifndef KHUTILS_TYPECONVERSION_HPP_INC
#define KHUTILS_TYPECONVERSION_HPP_INC

#include "khutils/endian.hpp"

#include <algorithm>
#include <array>
#include <vector>


namespace khutils
{
	// converts provided InT into OutT performing reinterpret_cast on memory
	template <typename OutT, typename InT = OutT>
	OutT reinterpret_convert(InT r)
	{
		static_assert(sizeof(OutT) == sizeof(InT), "incompatible type sizes");
		return *reinterpret_cast<OutT*>(&r);
	}

	// converts provided InT into OutT using union reinterpretation
	template <typename OutT, typename InT = OutT>
	OutT fast_convert(InT r)
	{
		static_assert(sizeof(OutT) == sizeof(InT), "incompatible type sizes");
		union conversion {
			OutT t;
			InT  r;
		};
		conversion val;
		val.r = r;
		return val.t;
	}

	// converts provided InT into OutT using OutT::ctor
	// obviously pre-requirement: OutT can be constructed from InT
	template <typename OutT, typename InT = OutT>
	inline OutT construct_convert(InT r)
	{
		return OutT(r);
	}

}	// namespace khutils

#endif	// KHUTILS_TYPECONVERSION_HPP_INC
