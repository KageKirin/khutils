#ifndef KHUTILS_FILEWRITER_HPP_INC
#define KHUTILS_FILEWRITER_HPP_INC

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

	//! file writer
	//! wraps FILE* write in an endian-aware
	//! and bit-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _filewriter;

	using filewriter			   = _filewriter<order::native>;
	using little_endian_filewriter = _filewriter<order::little>;
	using big_endian_filewriter	= _filewriter<order::big>;

	template <order _order>
	struct _filewriter : base_handler_trait<_order>
	{
		const std::shared_ptr<FILE> m_file;

		_filewriter()					= delete;
		_filewriter(const _filewriter&) = default;
		_filewriter(_filewriter&&)		= default;
		_filewriter(const std::shared_ptr<FILE>& file) : m_file(file)
		{
		}

		_filewriter& operator=(const _filewriter&) = default;
		_filewriter& operator=(_filewriter&&) = default;

		//! writes WriteT into ofile after converting and end0an-swapping provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT = WriteT>
		void write(InT t, SwapConversionFuncT<WriteT, InT> swapConv = base_handler_trait<_order>::template swap_after_convert<WriteT, InT>)
		{
			WriteT r = swapConv(t);
			fwrite(&r, sizeof(char), sizeof(WriteT), m_file.get());
		}

		//! writes coubnt * WriteT into ofile after converting and end0an-swapping
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
			std::vector<WriteT> r(count);
			std::transform(t, t + count, r.begin(), swapConv);

			fwrite(&r[0], sizeof(char), sizeof(WriteT) * r.size(), m_file.get());
			// or fwrite(&r[0], sizeof(WriteT), r.size(), m_file.get()); to fit FILE api
			// nicely
		}

		//! writes vector<WriteT> into ofile after converting and end0an-swapping
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
			const char c = 0;
			for (size_t i = 0; i < sizeof(_SkipT) * count; ++i)
			{
				fwrite(&c, sizeof(char), 1, m_file.get());
			}
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

#endif	// KHUTILS_FILEWRITER_HPP_INC
