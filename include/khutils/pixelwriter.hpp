#ifndef KHUTILS_PIXELWRITER_HPP_INC
#define KHUTILS_PIXELWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal
#include "khutils/assertion.hpp"

#include <functional>
#include <vector>

namespace khutils
{
	//! data writer
	//! writes data into PRE-ALLOCATED buffer
	//! DOES NOT RESIZE BUFFER
	//! usage: use typedef'ed version (see below)
	template <typename PixelType>
	struct _pixelwriter;

	template <typename PixelType>
	using pixelwriter = _pixelwriter<PixelType>;

	template <typename PixelType>
	struct pixelwriter_trait
	{
		typedef pixelwriter<PixelType> native_endian_writer;
	};

	template <typename PixelType>
	struct _pixelwriter
	{
		PixelType* m_begin;
		PixelType* m_end;
		size_t	 m_width;
		size_t	 m_height;

		_pixelwriter()					  = delete;
		_pixelwriter(const _pixelwriter&) = default;
		_pixelwriter(_pixelwriter&&)	  = default;
		_pixelwriter(size_t width, size_t height, PixelType* begin, PixelType* end)	//
		  : m_begin(begin),
			m_end(end),
			m_width(width),
			m_height(height)
		{
			KHUTILS_ASSERT_EQUALS(m_width * m_height, (size_t)std::distance(m_begin, m_end));
		}

		_pixelwriter& operator=(const _pixelwriter&) = default;
		_pixelwriter& operator=(_pixelwriter&&) = default;

		void poke(PixelType val, size_t offset)
		{
			KHUTILS_ASSERT_EXPR(offset, Is().LessThan(m_width * m_height));
			KHUTILS_ASSERT_EXPR(offset, Is().LessThan(std::distance(begin(), end())));
			begin()[offset] = val;
		}

		void pokeAt(PixelType val, size_t x, size_t y)
		{
			KHUTILS_ASSERT_EXPR(x, Is().LessThan(m_width));
			KHUTILS_ASSERT_EXPR(y, Is().LessThan(m_height));
			poke(val, y * m_width + x);
		}

		size_t pixelCount() const
		{
			return m_width * m_height;
		}

		PixelType* begin()
		{
			return m_begin;
		}

		PixelType* end()
		{
			return m_end;
		}
	};

}	// namespace khutils

#endif	// KHUTILS_PIXELWRITER_HPP_INC
