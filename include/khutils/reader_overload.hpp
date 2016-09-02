#ifndef KHUTILS_READER_OVERLOAD_HPP_INC
#define KHUTILS_READER_OVERLOAD_HPP_INC

//! usage:
//! 1. include this file in a cpp AFTER including the reader to overload
//! 2. use the KUTILS_OVERLOAD_READER macro to overload reader::read<> for
//! single element
//! 3. func must be passed enclosed in parenthesis ({ /*...*/})


#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

#define KUTILS_OVERLOAD_READER_DECL(readerT, outT, readT)                                                              \
	template <>                                                                                                        \
	outT readerT::template read<outT, readT>(SwapConversionFuncT<outT, readT> swapConv);

#define KUTILS_OVERLOAD_READER_IMPL(readerT, outT, readT, func)                                                        \
	template <>                                                                                                        \
	outT readerT::template read<outT, readT>(SwapConversionFuncT<outT, readT> swapConv) BOOST_PP_REMOVE_PARENS(func)

namespace khutils
{
}	// namespace khutils

#endif	// ! KHUTILS_READER_OVERLOAD_HPP_INC
