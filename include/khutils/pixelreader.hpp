#ifndef KHUTILS_PIXELREADER_HPP_INC
#define KHUTILS_PIXELREADER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/assertion.hpp"

#include <algorithm>
#include <functional>
#include <vector>

namespace khutils
{
	//! data reader
	//! read data from buffer
	//! usage: use typedef'ed version (see below)
	template <typename PixelType>
	struct _pixelreader;

	template <typename PixelType>
	using pixelreader = _pixelreader<PixelType>;

	template <typename PixelType>
	struct pixelreader_trait
	{
		typedef pixelreader<PixelType> native_endian_reader;
	};

	template <typename PixelType>
	struct _pixelreader
	{
		const PixelType* m_begin;
		const PixelType* m_end;
		size_t			 m_width;
		size_t			 m_height;

		_pixelreader()					  = delete;
		_pixelreader(const _pixelreader&) = default;
		_pixelreader(_pixelreader&&)	  = default;
		_pixelreader(size_t			  width,
					 size_t			  height,
					 const PixelType* begin,
					 const PixelType* end)	//
		  : m_begin(begin),
			m_end(end),
			m_width(width),
			m_height(height)
		{
			KHUTILS_ASSERT_EQUALS((m_width * m_height), (size_t)std::distance(m_begin, m_end));
		}

		_pixelreader& operator=(const _pixelreader&) = default;
		_pixelreader& operator=(_pixelreader&&) = default;

		PixelType peek(size_t offset) const
		{
			auto temp = (size_t)std::distance(begin(), end());
			KHUTILS_ASSERT_EXPR(offset, Is().LessThan(m_width * m_height));
			KHUTILS_ASSERT_EXPR(offset, Is().LessThan(std::distance(begin(), end())));
			return begin()[offset];
		}

		PixelType peekAt(size_t x, size_t y) const
		{
			KHUTILS_ASSERT_EXPR(x, Is().LessThan(m_width));
			KHUTILS_ASSERT_EXPR(y, Is().LessThan(m_height));
			return peek(y * m_width + x);
		}

		size_t pixelCount() const
		{
			return m_width * m_height;
		}

		const PixelType* begin() const
		{
			return m_begin;
		}

		const PixelType* end() const
		{
			return m_end;
		}
	};

}	// namespace khutils

#endif	// KHUTILS_PIXELREADER_HPP_INC
