#ifndef KHUTILS_WRITER_OVERLOAD_HPP_INC
#define KHUTILS_WRITER_OVERLOAD_HPP_INC

//! usage:
//! 1. include this file in a cpp AFTER including the writer to overload
//! 2. use the KUTILS_OVERLOAD_WRITER macro to overload writer::write<> for
//! single element
//! 3. func must be passed enclosed in parenthesis ({ /*...*/})


#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

#define KUTILS_OVERLOAD_WRITER_DECL(writerT, writeT, inT)                                                              \
	template <>                                                                                                        \
	void writerT::template write<writeT, inT>(inT t, SwapConversionFuncT<writeT, inT> swapConv);

#define KUTILS_OVERLOAD_WRITER_IMPL(writerT, writeT, inT, func)                                                        \
	template <>                                                                                                        \
	void writerT::template write<writeT, inT>(inT t, SwapConversionFuncT<writeT, inT> swapConv) BOOST_PP_REMOVE_PARENS(func)

#define KUTILS_OVERLOAD_WRITER_DECL_R(r, data, elem)                                                                   \
	template <>                                                                                                        \
	KUTILS_OVERLOAD_WRITER_DECL(elem, BOOST_PP_ARRAY_ELEM(0, data), BOOST_PP_ARRAY_ELEM(1, data))

#define KUTILS_OVERLOAD_WRITER_IMPL_R(r, data, elem)                                                                   \
	template <>                                                                                                        \
	KUTILS_OVERLOAD_WRITER_IMPL(elem, BOOST_PP_ARRAY_ELEM(0, data), BOOST_PP_ARRAY_ELEM(1, data), BOOST_PP_ARRAY_ELEM(2, data))

// use this to overload several readers at once for same data types
// readerseq: sequence type, #define ((a)(b))
#define KUTILS_OVERLOAD_WRITERSEQ_DECL(readerseq, writeT, inT)                                                         \
	BOOST_PP_SEQ_FOR_EACH(KUTILS_OVERLOAD_WRITER_DECL_R, (2, (writeT, inT)), readerseq)

#define KUTILS_OVERLOAD_WRITERSEQ_IMPL(readerseq, writeT, inT, func)                                                   \
	BOOST_PP_SEQ_FOR_EACH(KUTILS_OVERLOAD_WRITER_IMPL_R, (3, (writeT, inT, func)), readerseq)

namespace khutils
{
}	// namespace khutils

#endif	// ! KHUTILS_WRITER_OVERLOAD_HPP_INC
