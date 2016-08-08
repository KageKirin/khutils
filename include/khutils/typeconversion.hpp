#ifndef KHUTILS_TYPECONVERSION_HPP_INC
#define KHUTILS_TYPECONVERSION_HPP_INC

namespace khutils
{
	// converts provided _InT into _OutT performing reinterpret_cast on memory
	template <typename _OutT, typename _InT = _OutT>
	_OutT reinterpret_convert(_InT r)
	{
		return *reinterpret_cast<_OutT*>(&r);
	}

	// converts provided _InT into _OutT using union reinterpretation
	template <typename _OutT, typename _InT = _OutT>
	_OutT fast_convert(_InT r)
	{
		union conversion {
			_OutT t;
			_InT  r;
		};
		conversion val;
		val.r = r;
		return val.t;
	}

	///

}	// namespace khutils

#endif	// KHUTILS_TYPECONVERSION_HPP_INC
