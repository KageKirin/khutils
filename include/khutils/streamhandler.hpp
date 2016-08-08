#ifndef KHUTILS_STREAMREADER_HPP_INC
#define KHUTILS_STREAMREADER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include <boost/endian/conversion.hpp>
#include <functional>
#include <istream>

namespace khutils
{
	using boost::endian::order;

	//! stream reader
	//! wraps istream.read and ostream.write in an endian-aware
	//! and bitstream-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _streamreader;

	typedef _streamreader<order::native> streamreader;
	typedef _streamreader<order::little> little_endian_streamreader;
	typedef _streamreader<order::big>	big_endian_streamreader;

	//! stream writer
	//! wraps ostream.write in an endian-aware
	//! and bitstream-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _streamwriter;

	typedef _streamwriter<order::native> streamwriter;
	typedef _streamwriter<order::little> little_endian_streamwriter;
	typedef _streamwriter<order::big>	big_endian_streamwriter;

	///

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

	template <order _order>
	struct _streamreader
	{
		std::istream& m_is;

		_streamreader()							= delete;
		_streamreader(const _streamreader& ref) = delete;
		_streamreader(std::istream& is) : m_is(is)
		{
		}

		//! reads _ReadT from istream, then endian-swaps and converts it into _OutT
		//! optional convert function can be used to upsample _ReadT into bytewise
		//! bigger _OutT
		//! e.g. to convert read U16 as F32
		template <typename _OutT, typename _ReadT = _OutT>
		_OutT read(std::function<_OutT(_ReadT)> convert = std::bind(reinterpret_convert<_OutT, _ReadT>, std::placeholders::_1))
		{
			using boost::endian::conditional_reverse;

			_ReadT r;
			m_is.read(reinterpret_cast<char*>(&r), sizeof(_ReadT));
			return convert(conditional_reverse<order::native, _order>(r));
		}

		//! fetches _ReadT from istream WITHOUT incrementing position, then
		//! endian-swaps and converts it into _OutT
		//! optional convert function can be used to upsample _ReadT into bytewise
		//! bigger _OutT
		//! e.g. to convert read U16 as F32
		template <typename _OutT, typename _ReadT = _OutT>
		_OutT fetch(std::function<_OutT(_ReadT)> convert = std::bind(reinterpret_convert<_OutT, _ReadT>, std::placeholders::_1))
		{
			auto  pos = m_is.tellg();
			_OutT t   = read<_OutT, _ReadT>(convert);
			m_is.seekg(pos);
			return t;
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			m_is.ignore(sizeof(_SkipT) * count);
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= m_is.tellg();
			auto nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;
			m_is.ignore(nextAlignedPos - pos);
		}
	};

	template <order _order>
	struct _streamwriter
	{
		std::ostream& m_os;

		_streamwriter()							= delete;
		_streamwriter(const _streamwriter& ref) = delete;
		_streamwriter(std::ostream& os) : m_os(os)
		{
		}

		//! writes _WriteT into ostream after converting and end0an-swapping provided
		//! _InT
		//! optional convert function can be used to downsample _InT into bytewise
		//! smaller _WriteT
		//! e.g. to write F32 as U16
		template <typename _WriteT, typename _InT = _WriteT>
		void write(_InT t, std::function<_WriteT(_InT)> convert = std::bind(reinterpret_convert<_WriteT, _InT>, std::placeholders::_1))
		{
			using boost::endian::conditional_reverse;

			_WriteT r = conditional_reverse<_order, order::native>(convert(t));
			m_os.write(reinterpret_cast<char*>(&r), sizeof(_WriteT));
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			const char c = 0;
			for (size_t i = 0; i < sizeof(_SkipT) * count; ++i)
			{
				m_os.write(&c, 1);
			}
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto	   pos			  = m_os.tellp();
			auto	   nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;
			auto	   fillup		  = nextAlignedPos - pos;
			const char c			  = 0;
			for (size_t i = 0; i < fillup; ++i)
			{
				m_os.write(&c, 1);
			}
		}
	};

}	// namespace khutils

#endif	// KHUTILS_STREAMREADER_HPP_INC
