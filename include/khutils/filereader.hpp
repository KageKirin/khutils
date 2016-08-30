#ifndef KHUTILS_FILEREADER_HPP_INC
#define KHUTILS_FILEREADER_HPP_INC

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
	struct _filereader
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

		//! reads _ReadT from ifile, then endian-swaps and converts it into _OutT
		//! optional convert function can be used to upsample _ReadT into bytewise
		//! bigger _OutT
		//! e.g. to convert read U16 as F32
		template <typename _OutT, typename _ReadT = _OutT>
		_OutT read(std::function<_OutT(_ReadT)> convert = std::bind(reinterpret_convert<_OutT, _ReadT>, std::placeholders::_1))
		{
			_ReadT r;
			fread(&r, sizeof(char), sizeof(_ReadT), m_file.get());
			return convert(conditional_reverse<order::native, _order>(r));
		}

		//! fetches _ReadT from ifile WITHOUT incrementing position, then
		//! endian-swaps and converts it into _OutT
		//! optional convert function can be used to upsample _ReadT into bytewise
		//! bigger _OutT
		//! e.g. to convert read U16 as F32
		template <typename _OutT, typename _ReadT = _OutT>
		_OutT fetch(std::function<_OutT(_ReadT)> convert = std::bind(reinterpret_convert<_OutT, _ReadT>, std::placeholders::_1))
		{
			auto  pos = ftell(m_file.get());
			_OutT t   = read<_OutT, _ReadT>(convert);
			fseek(pos, m_file.get());
			return t;
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			auto pos = ftell(m_file.get());
			fseek(pos + sizeof(_SkipT) * count, m_file.get());
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
