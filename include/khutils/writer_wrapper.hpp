#ifndef KHUTILS_WRITER_WRAPPER_HPP_INC
#define KHUTILS_WRITER_WRAPPER_HPP_INC

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <vector>

namespace khutils
{

	template <typename WriterT>
	class writerwrapper
	{
		WriterT& m_writer;

	public:
		writerwrapper() = delete;
		writerwrapper(WriterT& writer) : m_writer(writer)
		{
		}
		writerwrapper(WriterT&&)	   = delete;
		writerwrapper(writerwrapper&)  = default;
		writerwrapper(writerwrapper&&) = default;

		writerwrapper& operator=(const writerwrapper&) = default;
		writerwrapper& operator=(writerwrapper&&) = default;


		//! writes WriteT into buffer after converting and endian-swapping provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT = WriteT>
		inline void write(InT t,
						  SwapConversionFuncT<WriteT, InT> swapConv
						  = base_handler_trait<WriterT::m_order>::template swap_after_convert<WriteT, InT>)
		{
			m_writer.template write<WriteT, InT>(t, swapConv);
		}

		//! writes count * WriteT into buffer after converting and endian-swapping
		//! provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT = WriteT>
		inline void write(const InT* t,
						  size_t	 count,
						  SwapConversionFuncT<WriteT, InT> swapConv
						  = base_handler_trait<WriterT::m_order>::template swap_after_convert<WriteT, InT>)
		{
			m_writer.template write<WriteT, InT>(t, count, swapConv);
		}

		//! writes vector<WriteT> into buffer after converting and endian-swapping
		//! provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT = WriteT>
		inline void write(const std::vector<InT>& t,
						  SwapConversionFuncT<WriteT, InT> swapConv
						  = base_handler_trait<WriterT::m_order>::template swap_after_convert<WriteT, InT>)
		{
			m_writer.template write<WriteT, InT>(t, swapConv);
		}

		//! puts WriteT from data WITHOUT incrementing position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger InT
		//! e.g. to convert read U16 as F32
		template <typename WriteT, typename InT = WriteT>
		inline void put(InT t,
						SwapConversionFuncT<WriteT, InT> swapConv
						= base_handler_trait<WriterT::m_order>::template swap_after_convert<WriteT, InT>)
		{
			m_writer.template put<WriteT, InT>(t, swapConv);
		}

		//! puts WriteT from data at given position WITHOUT incrementing position,
		//! then endian-swaps and converts it into InT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger InT
		//! e.g. to convert read U16 as F32
		template <typename WriteT, typename InT = WriteT>
		inline void putAt(InT	t,
						  size_t writePos,
						  SwapConversionFuncT<WriteT, InT> swapConv
						  = base_handler_trait<WriterT::m_order>::template swap_after_convert<WriteT, InT>)
		{
			m_writer.template putAt<WriteT, InT>(t, writePos, swapConv);
		}

		template <typename _SkipT>
		inline void skip(size_t count = 1)
		{
			m_writer.template skip<_SkipT>(count);
		}

		template <size_t _Alignment>
		inline void		 alignToNext()
		{
			m_writer.template alignToNext<_Alignment>();
		}

		inline size_t getCurrentOffset()
		{
			return m_writer.template getCurrentOffset();
		}

		bool isEnd()
		{
			return m_writer.template isEnd();
		}
	};
}	// namespace khutils


#endif	// !KHUTILS_WRITER_WRAPPER_HPP_INC
