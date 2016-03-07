#ifndef KUTILS_CORE_STREAMREADER_HPP_INC
#define KUTILS_CORE_STREAMREADER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include <boost/endian/conversion.hpp>
#include <istream>

namespace khutils
{
	using boost::endian::order;

	//! stream handler
	//! wraps istream.read and ostream.write in an endian-aware
	//! and bitstream-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _streamhandler;

	typedef _streamhandler<order::native> streamhandler;
	typedef _streamhandler<order::little> little_endian_streamhandler;
	typedef _streamhandler<order::big>	big_endian_streamhandler;

	template <order _order>
	struct _streamhandler
	{
		// converts provided _InT into _OutT performing reinterpret_cast on memory
		template <typename _OutT, typename _InT = _OutT>
		_OutT reinterpret_convert(_InT& r)
		{
			return *reinterpret_cast<_OutT*>(&r);
		}

		// converts provided _InT into _OutT using union reinterpretation
		template <typename _OutT, typename _InT = _OutT>
		_OutT fast_convert(_InT& r)
		{
			union conversion {
				_OutT t;
				_InT  r;
			};
			conversion val;
			val.r = r;
			return val.t;
		}

		//! reads _ReadT from istream, then endian-swaps and converts it into _OutT
		//! optional convert function can be used to upsample _ReadT into bytewise
		//! bigger _OutT
		//! e.g. to convert read U16 as F32
		template <typename _OutT, typename _ReadT = _OutT>
		static _OutT read(std::istream& is, std::function<_OutT(_ReadT&)> convert = reinterpret_convert<_OutT, _ReadT>)
		{
			using boost::endian::conditional_reverse;

			_ReadT r;
			is.read(reinterpret_cast<char*>(&r), sizeof(_ReadT));
			return convert(conditional_reverse(r));
		}

		//! writes _WriteT into ostream after converting and end0an-swapping provided
		//! _InT
		//! optional convert function can be used to downsample _InT into bytewise
		//! smaller _WriteT
		//! e.g. to write F32 as U16
		template <typename _WriteT, typename _InT = _WriteT>
		static void write(std::ostream& os, _InT t, std::function<_WriteT(_InT&)> convert = reinterpret_convert<_WriteT, _InT>)
		{
			using boost::endian::conditional_reverse;

			_WriteT r = conditional_reverse(convert(t));
			os.write(reinterpret_cast<char*>(&r), sizeof(_WriteT));
		}
	};

}	// namespace khutils

#endif	// KUTILS_CORE_STREAMREADER_HPP_INC
