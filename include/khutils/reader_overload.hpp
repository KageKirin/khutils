#ifndef KHUTILS_READER_OVERLOAD_HPP_INC
#define KHUTILS_READER_OVERLOAD_HPP_INC

//! usage:
//! 1. include this file in a cpp AFTER including the reader to overload
//! 2. use the KUTILS_OVERLOAD_READER macro to overload reader::read<> for
//! single element
//! 3. func must be passed enclosed in parenthesis ({ /*...*/})


#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

#define KUTILS_OVERLOAD_READER_DECL(readerT, outT, readT)                                                              \
	template <>                                                                                                        \
	outT readerT::template read<outT, readT>(SwapConversionFuncT<outT, readT> swapConv);

#define KUTILS_OVERLOAD_READER_IMPL(readerT, outT, readT, func)                                                        \
	template <>                                                                                                        \
	outT readerT::template read<outT, readT>(SwapConversionFuncT<outT, readT> swapConv) BOOST_PP_REMOVE_PARENS(func)

#define KUTILS_OVERLOAD_READER_DECL_R(r, data, elem)                                                                   \
	template <>                                                                                                        \
	KUTILS_OVERLOAD_READER_DECL(elem, BOOST_PP_ARRAY_ELEM(0, data), BOOST_PP_ARRAY_ELEM(1, data))

#define KUTILS_OVERLOAD_READER_IMPL_R(r, data, elem)                                                                   \
	template <>                                                                                                        \
	KUTILS_OVERLOAD_READER_IMPL(elem, BOOST_PP_ARRAY_ELEM(0, data), BOOST_PP_ARRAY_ELEM(1, data), BOOST_PP_ARRAY_ELEM(2, data))

// use this to overload several readers at once for same data types
// readerseq: sequence type, #define ((a)(b))
#define KUTILS_OVERLOAD_READERSEQ_DECL(readerseq, outT, readT)                                                         \
	BOOST_PP_SEQ_FOR_EACH(KUTILS_OVERLOAD_READER_DECL_R, (2, (outT, readT)), readerseq)

#define KUTILS_OVERLOAD_READERSEQ_IMPL(readerseq, outT, readT, func)                                                   \
	BOOST_PP_SEQ_FOR_EACH(KUTILS_OVERLOAD_READER_IMPL_R, (3, (outT, readT, func)), readerseq)

namespace khutils
{
}	// namespace khutils

#endif	// ! KHUTILS_READER_OVERLOAD_HPP_INC
