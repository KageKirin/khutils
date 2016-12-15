#ifndef KHUTILS_ALGORITHM_INDEXED_HPP_INC
#define KHUTILS_ALGORITHM_INDEXED_HPP_INC

#include <algorithm>
#include <functional>
#include <pythonic/enumerate.h>

namespace khutils
{
	// naive C++ implementation
	template <class InputIt, class BinaryOperation>
	void for_each_indexed0(InputIt first, InputIt last, BinaryOperation binary_op)
	{
		for (auto it = first; it != last; ++it)
		{
			binary_op(*it, std::distance(it, first));
		}
	}

	// naive C++11 implementation
	template <class InputIt, class BinaryOperation>
	void for_each_indexed(InputIt first, InputIt last, BinaryOperation binary_op)
	{
		size_t index = 0;
		std::for_each(first, last, [&index, &binary_op](const typename InputIt::value_type& value) {
			binary_op(value, index);
			++index;
			// maybe return binary_op(value, index++); works as well
		});
	}

	// using pythonic.enumerate
	template <class _Collection, class BinaryOperation>
	void for_each_indexed_pythonic(_Collection collection, BinaryOperation binary_op)
	{
		for (auto vp : pythonic::enumerate(collection))
		{
			binary_op(vp.second, vp.first);
		}
	}

	// naive C++ implementation
	template <class InputIt, class OutputIt, class BinaryOperation>
	OutputIt transform_indexed0(InputIt first, InputIt last, OutputIt d_first, BinaryOperation binary_op)
	{
		auto d_it = d_first;
		for (auto it = first; it != last; ++it)
		{
			size_t index = std::distance(it, first);
			d_it		 = d_first + index;
			*d_it		 = binary_op(*it, index);
		}
		return d_it;
	}

	// naive C++11 implementation
	template <class InputIt, class OutputIt, class BinaryOperation>
	OutputIt transform_indexed(InputIt first, InputIt last, OutputIt d_first, BinaryOperation binary_op)
	{
		size_t index = 0;
		return std::transform(first, last, d_first, [&index, &binary_op](const typename InputIt::value_type& value) -> typename OutputIt::value_type {
			auto v = binary_op(value, index);
			++index;
			return v;

			// maybe return binary_op(value, index++); works as well
		});
	}

	// using pythonic.enumerate
	template <class _Collection, class OutputIt, class BinaryOperation>
	void transform_indexed_pythonic(_Collection collection, OutputIt d_first, BinaryOperation binary_op)
	{
		for (auto vp : pythonic::enumerate(collection))
		{
			*(d_first + vp.first) = binary_op(vp.second, vp.first);
		}
	}

}	// namespace khutils

#endif	//! KHUTILS_ALGORITHM_INDEXED_HPP_INC
