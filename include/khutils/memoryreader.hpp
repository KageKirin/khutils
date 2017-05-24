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

	template <typename ByteForwardIterator>
	struct _memoryreader_state
	{
		const ByteForwardIterator begin;
		const ByteForwardIterator end;
		ByteForwardIterator		  current;

		_memoryreader_state() = delete;
		_memoryreader_state(ByteForwardIterator alpha, ByteForwardIterator omega)
			: begin(alpha), current(alpha), end(omega)
		{
		}
		_memoryreader_state(const _memoryreader_state&) = default;
		_memoryreader_state(_memoryreader_state&&)		= default;

		_memoryreader_state& operator=(const _memoryreader_state&) = default;
		_memoryreader_state& operator=(_memoryreader_state&&) = default;
	};

	template <typename ByteForwardIterator, order _order>
	struct _memoryreader : base_handler_trait<_order>
	{
		typedef _memoryreader_state<ByteForwardIterator>				 state;
		std::reference_wrapper<_memoryreader_state<ByteForwardIterator>> m_ih;
		//static_assert(sizeof(decltype(*(m_ih.get().begin))) == 1, "not a 1 byte sized datatype");

		_memoryreader()						= delete;
		_memoryreader(const _memoryreader&) = default;
		_memoryreader(_memoryreader&&)		= default;
		_memoryreader(_memoryreader_state<ByteForwardIterator>& ih) : m_ih(ih)	//
		{
			KHUTILS_ASSERT_NOT(ih.begin, ih.end);
		}
		_memoryreader(std::reference_wrapper<_memoryreader_state<ByteForwardIterator>>& ih) : m_ih(ih)
		{
			KHUTILS_ASSERT_NOT(ih.begin, ih.end);
		}
		_memoryreader(std::reference_wrapper<_memoryreader_state<ByteForwardIterator>>&& ih) : m_ih(ih)
		{
			KHUTILS_ASSERT_NOT(ih.begin, ih.end);
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
				if (m_ih.get().current != m_ih.get().end)
				{
					rawdata[i] = *(m_ih.get().current);
				}
				++m_ih.get().current;
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
			auto curPos		   = m_ih.get().current;
			OutT t			   = read<OutT, ReadT>(swapConv);
			m_ih.get().current = curPos;
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
			auto curPos		   = m_ih.get().current;
			m_ih.current	   = m_ih.get().begin + readPos;
			OutT t			   = read<OutT, ReadT>(swapConv);
			m_ih.get().current = curPos;
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
			auto			  curPos = m_ih.get().current;
			std::vector<OutT> t		 = read<OutT, ReadT>(count, swapConv);
			m_ih.get().current		 = curPos;
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
			auto curPos			= m_ih.get().current;
			m_ih.get().current  = m_ih.get().begin + readPos;
			std::vector<OutT> t = read<OutT, ReadT>(count, swapConv);
			m_ih.get().current  = curPos;
			return t;
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			for (size_t i = 0; i < (sizeof(_SkipT) * count); ++i)
			{
				++m_ih.get().current;
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
			return m_ih.get().current;
		}

		size_t getCurrentOffset()
		{
			return std::distance(m_ih.get().begin, getCurrent());
		}

		void jumpToOffset(size_t pos)
		{
			m_ih.get().current = m_ih.get().begin + pos;
		}

		bool isEnd()
		{
			return m_ih.get().current == m_ih.get().end;
		}
	};

}	// namespace khutils

#endif	// KHUTILS_MEMORYREADER_HPP_INC
