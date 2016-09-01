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
			return (r);
		}

		//! fetches ReadT from file WITHOUT incrementing position, then
		//! endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		OutT fetch(SwapConversionFuncT<OutT, ReadT> swapConv = base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto pos = ftell(m_file.get());
			OutT t   = read<OutT, ReadT>(swapConv);
			fseek(m_file.get(), pos, SEEK_SET);
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
			std::generate_n(t.begin(), count, [&swapConv]() { return read<OutT, InT>(swapConv); });
			return t;
		}

		//! fetches count * ReadT from file WITHOUT incrementing position, then
		//! endian-swaps and converts it into OutT
		//! optional convert function can be used to upsample ReadT into bytewise
		//! bigger OutT
		//! e.g. to convert read U16 as F32
		template <typename OutT, typename ReadT = OutT>
		std::vector<OutT> fetch(size_t count,
								SwapConversionFuncT<OutT, ReadT> swapConv
								= base_handler_trait<_order>::template convert_after_swap<OutT, ReadT>)
		{
			auto			  pos = ftell(m_file.get());
			std::vector<OutT> t   = read<OutT, ReadT>(count, swapConv);
			fseek(m_file.get(), pos, SEEK_SET);
			return t;
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			auto pos = ftell(m_file.get());
			fseek(m_file.get(), pos + sizeof(_SkipT) * count, SEEK_SET);
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= ftell(m_file.get());
			auto nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;
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
	};

}	// namespace khutils

#endif	// KHUTILS_FILEREADER_HPP_INC
