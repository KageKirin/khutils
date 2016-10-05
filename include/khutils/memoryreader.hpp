#ifndef KHUTILS_MEMORYREADER_HPP_INC
#define KHUTILS_MEMORYREADER_HPP_INC

#define KHUTILS_ASSERTION_INLINE

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <vector>

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

	template <typename ByteForwardIterator>
	struct memoryreader_trait
	{
		typedef memoryreader<ByteForwardIterator>				native_endian_reader;
		typedef little_endian_memoryreader<ByteForwardIterator> little_endian_reader;
		typedef big_endian_memoryreader<ByteForwardIterator>	big_endian_reader;
	};

	template <typename ByteForwardIterator, order _order>
	struct _memoryreader : base_handler_trait<_order>
	{
		ByteForwardIterator m_begin;
		ByteForwardIterator m_end;
		ByteForwardIterator m_current;
		static_assert(sizeof(decltype(*m_begin)) == 1);

		_memoryreader()						= delete;
		_memoryreader(const _memoryreader&) = default;
		_memoryreader(_memoryreader&&)		= default;
		_memoryreader(ByteForwardIterator begin, ByteForwardIterator end)
			: m_begin(begin)	//
			, m_end(end)
			, m_current(m_begin)
		{
			KHUTILS_ASSERT_NOT(begin, end);
		}

		_memoryreader& operator=(const _memoryreader&) = default;
		_memoryreader& operator=(_memoryreader&&) = default;

		//! reads ReadT from data, then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT read(SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			ReadT r		  = (ReadT)0;
			char* rawdata = reinterpret_cast<char*>(&r);
			for (size_t i = 0; i < sizeof(ReadT); ++i)
			{
				if (m_current != m_end)
				{
					rawdata[i] = *(m_current);
				}
				++m_current;
			}

			return swapConv(r);
		}

		//! fetches ReadT from data WITHOUT incrementing position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT fetch(SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto curPos = m_current;
			OutT t		= read<OutT, ReadT>(swapConv);
			m_current   = curPos;
			return t;
		}

		//! fetches ReadT from data at given position WITHOUT incrementing position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT fetchAt(size_t readPos,
					 SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto curPos = m_current;
			m_current   = m_begin + readPos;
			OutT t		= read<OutT, ReadT>(swapConv);
			m_current   = curPos;
			return t;
		}

		//! reads count * ReadT from data, then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		std::vector<OutT> read(size_t count,
							   SwapConversionFuncT<OutT, ReadT> swapConv
							   = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			std::vector<OutT> t(count);
			std::generate_n(t.begin(), count, [&swapConv, this]() { return this->read<OutT, ReadT>(swapConv); });
			return t;
		}

		//! fetches count * ReadT from data WITHOUT incrementing position, then
		//! endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		std::vector<OutT> fetch(size_t count,
								SwapConversionFuncT<OutT, ReadT> swapConv
								= base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto			  curPos = m_current;
			std::vector<OutT> t		 = read<OutT, ReadT>(count, swapConv);
			m_current				 = curPos;
			return t;
		}

		//! fetches count * ReadT from data at given position WITHOUT incrementing
		//! position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		std::vector<OutT> fetchAt(size_t readPos,
								  size_t count,
								  SwapConversionFuncT<OutT, ReadT> swapConv
								  = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto curPos			= m_current;
			m_current			= m_begin + readPos;
			std::vector<OutT> t = read<OutT, ReadT>(count, swapConv);
			m_current			= curPos;
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
			auto pos			= getCurrentOffset();
			auto nextAlignedPos = pos + (pos % _Alignment);
			skip<char>(nextAlignedPos - pos);
		}

		ByteForwardIterator getCurrent()
		{
			return m_current;
		}

		size_t getCurrentOffset()
		{
			return std::distance(m_begin, getCurrent());
		}

		void jumpToOffset(size_t pos)
		{
			m_current = m_begin + pos;
		}

		bool isEnd()
		{
			return m_current == m_end;
		}
	};

}	// namespace khutils

#endif	// KHUTILS_MEMORYREADER_HPP_INC
