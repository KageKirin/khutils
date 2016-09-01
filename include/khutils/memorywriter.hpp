﻿#ifndef KHUTILS_MEMORYWRITER_HPP_INC
#define KHUTILS_MEMORYWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/base_handler.hpp"
#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <vector>

namespace khutils
{
	using boost::endian::order;

	//! data writer
	//! writes data into PRE-ALLOCATED buffer
	//! DOES NOT RESIZE BUFFER
	//! usage: use typedef'ed version (see below)
	template <typename ByteForwardIterator, order _order>
	struct _memorywriter;

	template <typename ByteForwardIterator>
	using memorywriter = _memorywriter<ByteForwardIterator, order::native>;
	template <typename ByteForwardIterator>
	using little_endian_memorywriter = _memorywriter<ByteForwardIterator, order::little>;
	template <typename ByteForwardIterator>
	using big_endian_memorywriter = _memorywriter<ByteForwardIterator, order::big>;

	template <typename ByteForwardIterator, order _order>
	struct _memorywriter : base_handler_trait<_order>
	{
		ByteForwardIterator m_begin;
		ByteForwardIterator m_end;
		ByteForwardIterator m_current;

		_memorywriter()						= delete;
		_memorywriter(const _memorywriter&) = default;
		_memorywriter(_memorywriter&&)		= default;
		_memorywriter(ByteForwardIterator begin, ByteForwardIterator end)
			: m_begin(begin)	//
			, m_end(end)
			, m_current(m_begin)
		{
		}

		_memorywriter& operator=(const _memorywriter&) = default;
		_memorywriter& operator=(_memorywriter&&) = default;

		// function must stay this way to be compatible with list iterators
		void _write_raw(char* rawdata, size_t count)
		{
			for (size_t i = 0; i < count; ++i)
			{
				if (m_current != m_end)
				{
					*(m_current) = rawdata[i];
				}
				++m_current;
			}
		}

		//! writes WriteT into buffer after converting and endian-swapping provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT = WriteT>
		void write(InT t, SwapConversionFuncT<WriteT, InT> swapConv = base_handler_trait<_order>::template swap_after_convert<WriteT, InT>)
		{
			WriteT r = swapConv(t);
			_write_raw(reinterpret_cast<char*>(&r), sizeof(WriteT));
		}

		//! writes count * WriteT into buffer after converting and endian-swapping
		//! provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT = WriteT>
		void write(const InT* t,
				   size_t	 count,
				   SwapConversionFuncT<WriteT, InT> swapConv = base_handler_trait<_order>::template swap_after_convert<WriteT, InT>)
		{
			std::for_each(t, t + count, [&swapConv, this](const auto& elem) { this->write<WriteT, InT>(elem, swapConv); });
		}

		//! writes vector<WriteT> into buffer after converting and endian-swapping
		//! provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT = WriteT>
		void write(const std::vector<InT>& t,
				   SwapConversionFuncT<WriteT, InT> swapConv = base_handler_trait<_order>::template swap_after_convert<WriteT, InT>)
		{
			write(t.data(), t.size(), swapConv);
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

		ByteForwardIterator getCurrent()
		{
			return m_current;
		}

		size_t getCurrentOffset()
		{
			return std::distance(m_begin, getCurrent());
		}
	};

}	// namespace khutils

#endif	// KHUTILS_MEMORYWRITER_HPP_INC