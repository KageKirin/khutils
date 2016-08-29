#ifndef KHUTILS_STREAMREADER_HPP_INC
#define KHUTILS_STREAMREADER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <istream>

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
		std::istream& m_is;

		_streamreader()						= delete;
		_streamreader(const _streamreader&) = default;
		_streamreader(_streamreader&&)		= default;
		_streamreader(std::istream& is) : m_is(is)
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
			m_is.read(reinterpret_cast<char*>(&r), sizeof(_ReadT));
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
			auto  pos = m_is.tellg();
			_OutT t   = read<_OutT, _ReadT>(convert);
			m_is.seekg(pos);
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
			auto pos			= m_is.tellg();
			auto nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;

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
	};

}	// namespace khutils

#endif	// KHUTILS_STREAMREADER_HPP_INC
