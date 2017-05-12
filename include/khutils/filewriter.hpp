#ifndef KHUTILS_FILEWRITER_HPP_INC
#define KHUTILS_FILEWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/base_handler.hpp"
#include "khutils/file.hpp"
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

	struct filewriter_trait
	{
		typedef filewriter				 native_endian_writer;
		typedef little_endian_filewriter little_endian_writer;
		typedef big_endian_filewriter	big_endian_writer;
	};

	template <order _order>
	struct _filewriter : base_handler_trait<_order>
	{
		std::reference_wrapper<const FilePtr> m_file;

		_filewriter()					= delete;
		_filewriter(const _filewriter&) = default;
		_filewriter(_filewriter&&)		= default;
		_filewriter(const FilePtr& file) : m_file(file)
		{
		}
		_filewriter(std::reference_wrapper<const FilePtr>&& file) : m_file(file)
		{
		}
		_filewriter(const std::reference_wrapper<const FilePtr>& file) : m_file(file)
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
			fwrite(&r, sizeof(char), sizeof(WriteT), m_file.get().get());
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
			std::for_each(t, t + count, [&swapConv, this](const auto& elem) { this->write<WriteT, InT>(elem, swapConv); });
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
				fwrite(&c, sizeof(char), 1, m_file.get().get());
			}
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= getCurrentOffset();
			auto nextAlignedPos = pos + (pos % _Alignment);
			skip<char>(nextAlignedPos - pos);
		}

		const FilePtr& getFile()
		{
			return m_file;
		}

		size_t getCurrentOffset()
		{
			return ftell(m_file.get().get());
		}

		bool isEnd()
		{
			return feof(m_file.get().get());
		}
	};

}	// namespace khutils

#endif	// KHUTILS_FILEWRITER_HPP_INC
