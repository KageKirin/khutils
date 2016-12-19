#ifndef KHUTILS_READER_WRAPPER_HPP_INC
#define KHUTILS_READER_WRAPPER_HPP_INC

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <vector>

namespace khutils
{

	template <typename ReaderT>
	class readerwrapper
	{
		ReaderT& m_reader;

	public:
		readerwrapper() = delete;
		readerwrapper(ReaderT& reader) : m_reader(reader)
		{
		}
		readerwrapper(ReaderT&&)	   = delete;
		readerwrapper(readerwrapper&)  = default;
		readerwrapper(readerwrapper&&) = default;
		~readerwrapper()			   = default;

		readerwrapper& operator=(const readerwrapper&) = default;
		readerwrapper& operator=(readerwrapper&&) = default;


		//! reads ReadT from data, then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		inline OutT read(SwapConversionFuncT<OutT, ReadT> swapConv
						 = base_handler_trait<ReaderT::m_order>::template convert_after_swap<OutT, ReadT>)
		{
			return m_reader.template read<OutT, ReadT>(swapConv);
		}

		//! fetches ReadT from data WITHOUT incrementing position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		inline OutT fetch(SwapConversionFuncT<OutT, ReadT> swapConv
						  = base_handler_trait<ReaderT::m_order>::template convert_after_swap<OutT, ReadT>)
		{
			return m_reader.template fetch<OutT, ReadT>(swapConv);
		}

		//! fetches ReadT from data at given position WITHOUT incrementing position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		inline OutT fetchAt(size_t readPos,
							SwapConversionFuncT<OutT, ReadT> swapConv
							= base_handler_trait<ReaderT::m_order>::template convert_after_swap<OutT, ReadT>)
		{
			return m_reader.template read<OutT, ReadT>(readPos, swapConv);
		}

		//! reads count * ReadT from data, then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		inline std::vector<OutT> read(size_t count,
									  SwapConversionFuncT<OutT, ReadT> swapConv
									  = base_handler_trait<ReaderT::m_order>::template convert_after_swap<OutT, ReadT>)
		{
			return m_reader.template read<OutT, ReadT>(count, swapConv);
		}

		//! fetches count * ReadT from data WITHOUT incrementing position, then
		//! endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		inline std::vector<OutT> fetch(size_t count,
									   SwapConversionFuncT<OutT, ReadT> swapConv
									   = base_handler_trait<ReaderT::m_order>::template convert_after_swap<OutT, ReadT>)
		{
			return m_reader.template fetch<OutT, ReadT>(count, swapConv);
		}

		//! fetches count * ReadT from data at given position WITHOUT incrementing
		//! position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		inline std::vector<OutT> fetchAt(size_t readPos,
										 size_t count,
										 SwapConversionFuncT<OutT, ReadT> swapConv
										 = base_handler_trait<ReaderT::m_order>::template convert_after_swap<OutT, ReadT>)
		{
			return m_reader.template read<OutT, ReadT>(readPos, count, swapConv);
		}

		template <typename _SkipT>
		inline void skip(size_t count = 1)
		{
			m_reader.template read<_SkipT>(count);
		}

		template <size_t _Alignment>
		inline void		 alignToNext()
		{
			m_reader.template alignToNext<_Alignment>();
		}

		inline size_t getCurrentOffset()
		{
			return m_reader.template getCurrentOffset();
		}

		inline void jumpToOffset(size_t pos)
		{
			m_reader.template jumpToOffset(pos);
		}

		inline bool isEnd()
		{
			return m_reader.template isEnd();
		}
	};
}	// namespace khutils


#endif	// !KHUTILS_READER_WRAPPER_HPP_INC
