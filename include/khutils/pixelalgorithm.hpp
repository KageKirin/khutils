#ifndef KHUTILS_PIXEL_ALGORITHM_HPP_INC
#define KHUTILS_PIXEL_ALGORITHM_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/assertion.hpp"
#include "khutils/pixelhandler.hpp"

#include <boost/range/irange.hpp>
#include <functional>
#include <vector>

namespace khutils
{
	//! Kernel: ternary function(value, x, y)
	template <typename Kernel, typename PixelType>
	void apply_kernel(const pixelreader<PixelType>& reader, pixelwriter<PixelType>& writer, Kernel kernel)
	{
		KHUTILS_ASSERT_EQUALS(reader.m_width * reader.m_height, writer.m_width * writer.m_height);
		KHUTILS_ASSERT_EQUALS(std::distance(reader.begin(), reader.end()), std::distance(writer.begin(), writer.end()));

		for (auto yy : boost::irange((size_t)0, reader.m_height, (size_t)1))
		{
			for (auto xx : boost::irange((size_t)0, reader.m_width, (size_t)1))
			{
				writer.pokeAt(kernel(reader.peekAt(xx, yy), xx, yy), xx, yy);
			}
		}
	}

}	// namespace khutils

#endif	// KHUTILS_PIXEL_ALGORITHM_HPP_INC
