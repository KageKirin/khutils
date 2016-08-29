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

	//! stream reader
	//! wraps istream.read and ostream.write in an endian-aware
	//! and bitstream-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _streamreader;

	using streamreader				 = _streamreader<order::native>;
	using little_endian_streamreader = _streamreader<order::little>;
	using big_endian_streamreader	= _streamreader<order::big>;

	template <order _order>
	struct _streamreader
	{
		const std::shared_ptr<FILE> m_file;

		_streamreader()						= delete;
		_streamreader(const _streamreader&) = default;
		_streamreader(_streamreader&&)		= default;
		_streamreader(const std::shared_ptr<FILE>& file) : m_file(file)
		{
		}

		_streamreader& operator=(const _streamreader&) = default;
		_streamreader& operator=(_streamreader&&) = default;

		//! reads _ReadT from istream, then endian-swaps and converts it into _OutT
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

		//! fetches _ReadT from istream WITHOUT incrementing position, then
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
