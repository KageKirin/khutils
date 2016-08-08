#ifndef KHUTILS_DATAREADER_HPP_INC
#define KHUTILS_DATAREADER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>

namespace khutils
{
	using boost::endian::order;

	//! data reader
	//! read data from buffer
	//! usage: use typedef'ed version (see below)
	template <typename ByteForwardIterator, order _order>
	struct _datareader;

	template <typename ByteForwardIterator>
	using datareader = _datareader<ByteForwardIterator, order::native>;
	template <typename ByteForwardIterator>
	using little_endian_datareader = _datareader<ByteForwardIterator, order::little>;
	template <typename ByteForwardIterator>
	using big_endian_datareader = _datareader<ByteForwardIterator, order::big>;

	template <typename ByteForwardIterator, order _order>
	struct _datareader
	{
		ByteForwardIterator m_begin;
		ByteForwardIterator m_end;
		ByteForwardIterator m_current;

		_datareader()					= delete;
		_datareader(const _datareader&) = default;
		_datareader(_datareader&&)		= default;
		_datareader(ByteForwardIterator begin, ByteForwardIterator end)
			: m_begin(begin)	//
			, m_end(end)
			, m_current(m_begin)
		{
		}

		_datareader& operator=(const _datareader&) = default;
		_datareader& operator=(_datareader&&) = default;

		//! reads _ReadT from data, then endian-swaps and converts it into _OutT
		//! optional convert function can be used to upsample _ReadT into bytewise
		//! bigger _OutT
		//! e.g. to convert read U16 as F32
		template <typename _OutT, typename _ReadT = _OutT>
		_OutT read(std::function<_OutT(_ReadT)> convert = std::bind(reinterpret_convert<_OutT, _ReadT>, std::placeholders::_1))
		{
			using boost::endian::conditional_reverse;

			_ReadT r	   = (_ReadT)0;
			char*  rawdata = reinterpret_cast<char*>(&r);
			for (size_t i = 0; i < sizeof(_ReadT); ++i)
			{
				if (m_current != m_end)
				{
					rawdata[i] = *(m_current);
				}
				++m_current;
			}

			return convert(conditional_reverse<order::native, _order>(r));
		}

		//! fetches _ReadT from data WITHOUT incrementing position, then
		//! endian-swaps and converts it into _OutT
		//! optional convert function can be used to upsample _ReadT into bytewise
		//! bigger _OutT
		//! e.g. to convert read U16 as F32
		template <typename _OutT, typename _ReadT = _OutT>
		_OutT fetch(std::function<_OutT(_ReadT)> convert = std::bind(reinterpret_convert<_OutT, _ReadT>, std::placeholders::_1))
		{
			auto  pos = m_current;
			_OutT t   = read<_OutT, _ReadT>(convert);
			m_current = pos;
			return t;
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			m_current += (sizeof(_SkipT) * count);
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= std::distance(m_begin, m_current);
			auto nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;
			m_current			= m_begin + (nextAlignedPos - pos);
		}
	};

}	// namespace khutils

#endif	// KHUTILS_DATAREADER_HPP_INC
