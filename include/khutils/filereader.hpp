#ifndef KHUTILS_FILEREADER_HPP_INC
#define KHUTILS_FILEREADER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/base_handler.hpp"
#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <cstdio>
#include <functional>
#include <memory>
#include <vector>

namespace khutils
{
	using boost::endian::order;

	//! file reader
	//! wraps FILE* read in an endian-aware
	//! and bit-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _filereader;

	using filereader			   = _filereader<order::native>;
	using little_endian_filereader = _filereader<order::little>;
	using big_endian_filereader	= _filereader<order::big>;

	struct filereader_trait
	{
		typedef filereader				 native_endian_reader;
		typedef little_endian_filereader little_endian_reader;
		typedef big_endian_filereader	big_endian_reader;
	};

	template <order _order>
	struct _filereader : base_handler_trait<_order>
	{
		const std::shared_ptr<FILE> m_file;

		_filereader()					= delete;
		_filereader(const _filereader&) = default;
		_filereader(_filereader&&)		= default;
		_filereader(const std::shared_ptr<FILE>& file) : m_file(file)
		{
		}

		_filereader& operator=(const _filereader&) = default;
		_filereader& operator=(_filereader&&) = default;

		//! reads ReadT from file, then endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT read(SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			ReadT r;
			fread(&r, sizeof(char), sizeof(ReadT), m_file.get());
			return swapConv(r);
		}

		//! fetches ReadT from file WITHOUT incrementing position,
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

		//! fetches ReadT from file at given position WITHOUT incrementing position,
		//! then
		//! endian-swaps and converts it into OutT
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

		//! reads count * ReadT from file, then endian-swaps and converts it into OutT
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

		//! fetches count * ReadT from file WITHOUT incrementing position,
		//! then endian-swaps and converts it into OutT
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

		//! fetches count * ReadT from file at given position WITHOUT incrementing
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
			auto curPos = getCurrentOffset();
			jumpToOffset(readPos);
			std::vector<OutT> t = read<OutT, ReadT>(count, swapConv);
			jumpToOffset(curPos);
			return t;
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			auto curPos = getCurrentOffset();
			jumpToOffset(curPos + sizeof(_SkipT) * count);
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= getCurrentOffset();
			auto nextAlignedPos = pos + (pos % _Alignment);
			skip<char>(nextAlignedPos - pos);
		}

		const std::shared_ptr<FILE>& getFile()
		{
			return m_file;
		}

		size_t getCurrentOffset()
		{
			return ftell(m_file.get());
		}

		void jumpToOffset(size_t pos)
		{
			fseek(m_file.get(), pos, SEEK_SET);
		}
	};

}	// namespace khutils

#endif	// KHUTILS_FILEREADER_HPP_INC
