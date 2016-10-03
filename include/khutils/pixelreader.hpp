#ifndef KHUTILS_PIXELREADER_HPP_INC
#define KHUTILS_PIXELREADER_HPP_INC

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

	//! data reader
	//! read data from buffer
	//! usage: use typedef'ed version (see below)
	template <typename PixelType, typename ByteForwardIterator, order _order>
	struct _pixelreader;

	template <typename PixelType, typename ByteForwardIterator>
	using pixelreader = _pixelreader<PixelType, ByteForwardIterator, order::native>;
	template <typename PixelType, typename ByteForwardIterator>
	using little_endian_pixelreader = _pixelreader<PixelType, ByteForwardIterator, order::little>;
	template <typename PixelType, typename ByteForwardIterator>
	using big_endian_pixelreader = _pixelreader<PixelType, ByteForwardIterator, order::big>;

	template <typename PixelType, typename ByteForwardIterator>
	struct pixelreader_trait
	{
		typedef pixelreader<PixelType, ByteForwardIterator>				  native_endian_reader;
		typedef little_endian_pixelreader<PixelType, ByteForwardIterator> little_endian_reader;
		typedef big_endian_pixelreader<PixelType, ByteForwardIterator>	big_endian_reader;
	};

	template <typename PixelType, typename ByteForwardIterator, order _order>
	struct _pixelreader : protected _memoryreader<ByteForwardIterator _order>
	{
		size_t m_width;
		size_t m_height;

		_pixelreader()					  = delete;
		_pixelreader(const _pixelreader&) = default;
		_pixelreader(_pixelreader&&)	  = default;
		_pixelreader(size_t				 width,
					 size_t				 height,
					 ByteForwardIterator begin,
					 ByteForwardIterator end)	//
		  : _memoryreader(begin, end),
			m_width(width),
			m_height(height)
		{
		}

		_pixelreader& operator=(const _pixelreader&) = default;
		_pixelreader& operator=(_pixelreader&&) = default;

		PixelType peek(size_t offset)
		{
			KHUTILS_ASSERT_EXPR(offset, Is().LessThan(m_width * m_height));
			return fetchAt<PixelType>(offset);
		}

		PixelType peekAt(size_t x, size_t y)
		{
			KHUTILS_ASSERT_EXPR(x, Is().LessThan(m_width));
			KHUTILS_ASSERT_EXPR(y, Is().LessThan(m_height));
			return peek(y * m_width + x);
		}
	};

}	// namespace khutils

#endif	// KHUTILS_PIXELREADER_HPP_INC
