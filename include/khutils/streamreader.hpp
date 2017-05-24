#ifndef KHUTILS_STREAMREADER_HPP_INC
#define KHUTILS_STREAMREADER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/typeconversion.hpp"

#include <functional>
#include <istream>
#include <vector>

namespace khutils
{
	//! stream reader
	//! wraps istream.read and ostream.write in an endian-aware
	//! and bitstream-fitting manner
	//! usage: use typedef'ed version (see below)
	template <endian::order _order>
	struct _streamreader;

	using streamreader				 = _streamreader<endian::native>;
	using little_endian_streamreader = _streamreader<endian::order::little>;
	using big_endian_streamreader	= _streamreader<endian::order::big>;

	struct streamreader_trait
	{
		typedef streamreader			   native_endian_reader;
		typedef little_endian_streamreader little_endian_reader;
		typedef big_endian_streamreader	big_endian_reader;
	};

	template <endian::order _order>
	struct _streamreader : base_handler_trait<_order>
	{
		std::istream& m_is;

		_streamreader()						= delete;
		_streamreader(const _streamreader&) = default;
		_streamreader(_streamreader&&)		= default;
		_streamreader(std::istream& is) : m_is(is)
		{
		}

		_streamreader& operator=(const _streamreader&) = default;
		_streamreader& operator=(_streamreader&&) = default;

		//! reads ReadT from istream, then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT read(SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			ReadT r;
			m_is.read(reinterpret_cast<char*>(&r), sizeof(ReadT));
			return swapConv(r);
		}

		//! fetches ReadT from istream WITHOUT incrementing position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT fetch(SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto curPos = getCurrentOffset();
			OutT t		= read<OutT, ReadT>(swapConv);
			jumpToOffset(curPos);
			return t;
		}

		//! fetches ReadT from istream at given position WITHOUT incrementing
		//! position,
		//! then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT fetchAt(size_t readPos,
					 SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto curPos = getCurrentOffset();
			jumpToOffset(readPos);
			OutT t = read<OutT, ReadT>(swapConv);
			jumpToOffset(curPos);
			return t;
		}

		//! reads count * ReadT from istream, then endian-swaps and converts them into
		//! count * OutT
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

		//! fetches count * ReadT from istream WITHOUT incrementing position,
		//! then endian-swaps and converts it into count * OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		std::vector<OutT> fetch(size_t count,
								SwapConversionFuncT<OutT, ReadT> swapConv
								= base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto			  curPos = getCurrentOffset();
			std::vector<OutT> t		 = read<OutT, ReadT>(count, swapConv);
			jumpToOffset(curPos);
			return t;
		}

		//! fetches count * ReadT from istream at given position WITHOUT incrementing
		//! position,
		//! then endian-swaps and converts it into count * OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		std::vector<OutT> fetchAt(size_t readPos,
								  size_t count,
								  SwapConversionFuncT<OutT, ReadT> swapConv
								  = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto curPos = getCurrentOffset();
			jumpToOffset(readPos);
			std::vector<OutT> t = read<OutT, ReadT>(count, swapConv);
			jumpToOffset(curPos);
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
			auto pos			= getCurrentOffset();
			auto nextAlignedPos = pos + (pos % _Alignment);
			skip<char>(nextAlignedPos - pos);
		}

		std::istream& getStream()
		{
			return m_is;
		}

		size_t getCurrentOffset()
		{
			return m_is.tellg();
		}

		void jumpToOffset(size_t pos)
		{
			m_is.seekg(pos);
		}

		bool isEnd()
		{
			return m_is.eof();
		}
	};

}	// namespace khutils

#endif	// KHUTILS_STREAMREADER_HPP_INC
