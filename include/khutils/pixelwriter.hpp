#ifndef KHUTILS_PIXELWRITER_HPP_INC
#define KHUTILS_PIXELWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/memoryhandler.hpp"
#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <vector>

namespace khutils
{
	using boost::endian::order;

	//! data writer
	//! writes data into PRE-ALLOCATED buffer
	//! DOES NOT RESIZE BUFFER
	//! usage: use typedef'ed version (see below)
	template <typename ByteForwardIterator, order _order>
	struct _pixelwriter;

	template <typename ByteForwardIterator>
	using pixelwriter = _pixelwriter<ByteForwardIterator, order::native>;
	template <typename ByteForwardIterator>
	using little_endian_pixelwriter = _pixelwriter<ByteForwardIterator, order::little>;
	template <typename ByteForwardIterator>
	using big_endian_pixelwriter = _pixelwriter<ByteForwardIterator, order::big>;

	template <typename ByteForwardIterator>
	struct pixelwriter_trait
	{
		typedef pixelwriter<ByteForwardIterator>			   native_endian_writer;
		typedef little_endian_pixelwriter<ByteForwardIterator> little_endian_writer;
		typedef big_endian_pixelwriter<ByteForwardIterator>	big_endian_writer;
	};

	template <typename ByteForwardIterator, order _order>
	struct _pixelwriter : protected _memorywriter<ByteForwardIterator, _order>
	{
		size_t m_width;
		size_t m_height;

		_pixelwriter()					  = delete;
		_pixelwriter(const _pixelwriter&) = default;
		_pixelwriter(_pixelwriter&&)	  = default;
		_pixelwriter(size_t				 width,
					 size_t				 height,
					 ByteForwardIterator begin,
					 ByteForwardIterator end)	//
		  : _memorywriter(begin, end),
			m_width(width),
			m_height(height)
		{
		}

		_pixelwriter& operator=(const _pixelwriter&) = default;
		_pixelwriter& operator=(_pixelwriter&&) = default;

		void poke(PixelType val, size_t offset)
		{
			KHUTILS_ASSERT_EXPR(offset, Is().LessThan(m_width * m_height));
			return putAt<PixelType>(val, offset);
		}

		void pokeAt(PixelType val, size_t x, size_t y)
		{
			KHUTILS_ASSERT_EXPR(x, Is().LessThan(m_width));
			KHUTILS_ASSERT_EXPR(y, Is().LessThan(m_height));
			return poke(val, y * m_width + x);
		}
	};

}	// namespace khutils

#endif	// KHUTILS_PIXELWRITER_HPP_INC
