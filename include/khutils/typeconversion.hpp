#ifndef KHUTILS_TYPECONVERSION_HPP_INC
#define KHUTILS_TYPECONVERSION_HPP_INC

#include <boost/config.hpp>
#include <boost/cstdint.hpp>

// overload function endian_reverse BEFORE including header
namespace boost
{
	namespace endian
	{
		double endian_reverse(double x) BOOST_NOEXCEPT;
		float endian_reverse(float x) BOOST_NOEXCEPT;

	}	// namespace endian
}	// namespace boost

#include <boost/endian/conversion.hpp>

namespace boost
{
	namespace endian
	{

		inline double endian_reverse(double x) BOOST_NOEXCEPT
		{
			auto rx = endian_reverse(*reinterpret_cast<uint64_t*>(&x));
			return *reinterpret_cast<double*>(&rx);
		}

		inline float endian_reverse(float x) BOOST_NOEXCEPT
		{
			auto rx = endian_reverse(*reinterpret_cast<uint32_t*>(&x));
			return *reinterpret_cast<float*>(&rx);
		}

	}	// namespace endian
}	// namespace boost

namespace khutils
{
	// converts provided InT into OutT performing reinterpret_cast on memory
	template <typename OutT, typename InT = OutT>
	OutT reinterpret_convert(InT r)
	{
		return *reinterpret_cast<OutT*>(&r);
	}

	// converts provided InT into OutT using union reinterpretation
	template <typename OutT, typename InT = OutT>
	OutT fast_convert(InT r)
	{
		union conversion {
			OutT t;
			InT  r;
		};
		conversion val;
		val.r = r;
		return val.t;
	}

	// importing boost::endian_reverse symbol into our namespace
	using boost::endian::endian_reverse;
	using boost::endian::conditional_reverse;

	// TODO: overload endian_reverse for more types

}	// namespace khutils

#endif	// KHUTILS_TYPECONVERSION_HPP_INC
