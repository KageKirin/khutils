#ifndef KHUTILS_PIXEL_ALGORITHM_HPP_INC
#define KHUTILS_PIXEL_ALGORITHM_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/assertion.hpp"
#include "khutils/pixelhandler.hpp"

#include <boost/range/irange.hpp>
#include <functional>
#include <algorithm>
#include <vector>
#if __cplusplus == 201703L
#include <execution>
#endif //__cplusplus == 201703L

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
		auto xxyy = std::vector<std::tuple<size_t, size_t>>(xx.size() * yy.size());
		std::for_each(yy.begin(), yy.end(), [&xx, &xxyy](auto _yy) {
			std::for_each(xx.begin(), xx.end(), [&xx, &_yy, &xxyy](auto _xx){
				xxyy[_yy * xx.size() + _xx] = {_xx, _yy};
			});
		});

		std::for_each(
#if __cplusplus == 201703L
			std::execution::par,
#endif //__cplusplus == 201703L
			xxyy.begin(), xxyy.end(), [&writer, &reader, &kernel](auto _xy) {

			writer.pokeAt(kernel(reader.peekAt(std::get<0>(_xy), std::get<1>(_xy)), std::get<0>(_xy), std::get<1>(_xy)), std::get<0>(_xy), std::get<1>(_xy));
		});
	}

}	// namespace khutils

#endif	// KHUTILS_PIXEL_ALGORITHM_HPP_INC
