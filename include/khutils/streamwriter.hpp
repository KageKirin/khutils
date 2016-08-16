#ifndef KHUTILS_STREAMWRITER_HPP_INC
#define KHUTILS_STREAMWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <ostream>

namespace khutils
{
	using boost::endian::order;

	//! stream writer
	//! wraps ostream.write in an endian-aware
	//! and bitstream-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _streamwriter;

	using streamwriter				 = _streamwriter<order::native>;
	using little_endian_streamwriter = _streamwriter<order::little>;
	using big_endian_streamwriter	= _streamwriter<order::big>;

	template <order _order>
	struct _streamwriter
	{
		std::ostream& m_os;

		_streamwriter()						= delete;
		_streamwriter(const _streamwriter&) = default;
		_streamwriter(_streamwriter&&)		= default;
		_streamwriter(std::ostream& os) : m_os(os)
		{
		}

		_streamwriter& operator=(const _streamwriter&) = default;
		_streamwriter& operator=(_streamwriter&&) = default;

		//! writes _WriteT into ostream after converting and end0an-swapping provided
		//! _InT
		//! optional convert function can be used to downsample _InT into bytewise
		//! smaller _WriteT
		//! e.g. to write F32 as U16
		template <typename _WriteT, typename _InT = _WriteT>
		void write(_InT t, std::function<_WriteT(_InT)> convert = std::bind(reinterpret_convert<_WriteT, _InT>, std::placeholders::_1))
		{
			_WriteT r = conditional_reverse<_order, order::native>(convert(t));
			m_os.write(reinterpret_cast<char*>(&r), sizeof(_WriteT));
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			const char c = 0;
			for (size_t i = 0; i < sizeof(_SkipT) * count; ++i)
			{
				m_os.write(&c, 1);
			}
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto	   pos			  = m_os.tellp();
			auto	   nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;
			auto	   fillup		  = nextAlignedPos - pos;
			const char c			  = 0;
			for (size_t i = 0; i < fillup; ++i)
			{
				m_os.write(&c, 1);
			}
		}

		std::ostream& getStream()
		{
			return m_os;
		}

		size_t getCurrentOffset()
		{
			return m_os.tellp();
		}
	};

}	// namespace khutils

#endif	// KHUTILS_STREAMWRITER_HPP_INC
