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

		auto yy = boost::irange((size_t)0, reader.m_height, (size_t)1);
		auto xx = boost::irange((size_t)0, reader.m_width, (size_t)1);

		std::for_each(
#if __cplusplus == 201703L
			std::execution::par,
#endif //__cplusplus == 201703L
			yy.begin(), yy.end(), [&xx, &writer, &reader, &kernel](auto _yy) {

			std::for_each(
#if __cplusplus == 201703L
				std::execution::par,
#endif //__cplusplus == 201703L
				xx.begin(), xx.end(), [&writer, &reader, &kernel, &_yy](auto _xx) {

				writer.pokeAt(kernel(reader.peekAt(_xx, _yy), _xx, _yy), _xx, _yy);
			});
		});
	}

}	// namespace khutils

#endif	// KHUTILS_PIXEL_ALGORITHM_HPP_INC
