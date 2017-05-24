#ifndef KHUTILS_BASE_HANDLER_HPP_INC
#define KHUTILS_BASE_HANDLER_HPP_INC

#include "khutils/typeconversion.hpp"
#include <boost/endian/conversion.hpp>
#include <functional>

namespace khutils
{
	using boost::endian::order;

	//! signature for swap conversion functions
	template <typename OutT, typename InT>
	using SwapConversionFuncT = std::function<OutT(InT)>;

	template <typename OutT, typename InT>
	inline OutT noopSwap(InT _val)
	{
		return reinterpret_convert<OutT, InT>(_val);
	}

	template <order _order>
	struct base_handler_trait
	{
		static constexpr order m_order = _order;

		template <typename T>
		static T read_swap(T from)
		{
			return conditional_reverse<_order, order::native>(from);
		}

		template <typename T>
		static T write_swap(T from)
		{
			return conditional_reverse<order::native, _order>(from);
		}

		template <typename OutT, typename InT>
		static OutT convert(InT _val)
		{
			return reinterpret_convert<OutT, InT>(_val);
		}

		//! swap conversion function
		// swaps InT, then converts result to OutT
		// used for reading functions
		template <typename OutT, typename InT>
		static OutT convert_after_swap(InT _val)
		{
			return convert<OutT, InT>(read_swap(_val));
		}

		//! swap conversion function
		// converts InT to OutT, then swaps OutT
		// used for writing functions
		template <typename OutT, typename InT>
		static OutT swap_after_convert(InT _val)
		{
			return write_swap(convert<OutT, InT>(_val));
		}
	};

}	// namespace khutils

#endif	// ! KHUTILS_BASE_HANDLER_HPP_INC
