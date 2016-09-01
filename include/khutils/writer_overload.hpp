#ifndef KHUTILS_WRITER_OVERLOAD_HPP_INC
#define KHUTILS_WRITER_OVERLOAD_HPP_INC

//! usage:
//! 1. include this file in a cpp AFTER including the writer to overload
//! 2. use the KUTILS_OVERLOAD_WRITER macro to overload writer::write<> for
//! single element
//! 3. func must be passed enclosed in parenthesis ({ /*...*/})


#include <boost/preprocessor/punctuation/remove_parens.hpp>

#define KUTILS_OVERLOAD_WRITER_DECL(writerT, writeT, inT)                                                              \
	template <>                                                                                                        \
	void writerT::template write<writeT, inT>(inT t, SwapConversionFuncT<writeT, inT> swapConv);

#define KUTILS_OVERLOAD_WRITER_IMPL(writerT, writeT, inT, func)                                                        \
	template <>                                                                                                        \
	void writerT::template write<writeT, inT>(inT t, SwapConversionFuncT<writeT, inT> swapConv) BOOST_PP_REMOVE_PARENS(func)

namespace khutils
{
}	// namespace khutils

#endif	// ! KHUTILS_WRITER_OVERLOAD_HPP_INC
