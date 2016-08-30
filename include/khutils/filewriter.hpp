#ifndef KHUTILS_FILEWRITER_HPP_INC
#define KHUTILS_FILEWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <cstdio>
#include <functional>
#include <memory>

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
	struct _filewriter
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

		//! writes _WriteT into ofile after converting and end0an-swapping provided
		//! _InT
		//! optional convert function can be used to downsample _InT into bytewise
		//! smaller _WriteT
		//! e.g. to write F32 as U16
		template <typename _WriteT, typename _InT = _WriteT>
		void write(_InT t, std::function<_WriteT(_InT)> convert = std::bind(reinterpret_convert<_WriteT, _InT>, std::placeholders::_1))
		{
			_WriteT r = conditional_reverse<_order, order::native>(convert(t));
			fwrite(&r, sizeof(char), sizeof(_WriteT), m_file.get());
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
