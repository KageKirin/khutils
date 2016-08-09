#ifndef KHUTILS_MEMORYREADER_HPP_INC
#define KHUTILS_MEMORYREADER_HPP_INC

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
	struct _memoryreader;

	template <typename ByteForwardIterator>
	using memoryreader = _memoryreader<ByteForwardIterator, order::native>;
	template <typename ByteForwardIterator>
	using little_endian_memoryreader = _memoryreader<ByteForwardIterator, order::little>;
	template <typename ByteForwardIterator>
	using big_endian_memoryreader = _memoryreader<ByteForwardIterator, order::big>;

	template <typename ByteForwardIterator, order _order>
	struct _memoryreader
	{
		ByteForwardIterator m_begin;
		ByteForwardIterator m_end;
		ByteForwardIterator m_current;

		_memoryreader()						= delete;
		_memoryreader(const _memoryreader&) = default;
		_memoryreader(_memoryreader&&)		= default;
		_memoryreader(ByteForwardIterator begin, ByteForwardIterator end)
			: m_begin(begin)	//
			, m_end(end)
			, m_current(m_begin)
		{
		}

		_memoryreader& operator=(const _memoryreader&) = default;
		_memoryreader& operator=(_memoryreader&&) = default;

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
			for (size_t i = 0; i < (sizeof(_SkipT) * count); ++i)
			{
				++m_current;
			}
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= std::distance(m_begin, m_current);
			auto nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;

			skip<char>(nextAlignedPos - pos);
		}
	};

}	// namespace khutils

#endif	// KHUTILS_MEMORYREADER_HPP_INC
