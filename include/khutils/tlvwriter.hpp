#ifndef KHUTILS_TLV_WRITER_HPP_INC
#define KHUTILS_TLV_WRITER_HPP_INC

#include "khutils/tlv.hpp"

namespace khutils
{
	template <class TLVelementT, typename BaseWriterT>
	struct TLVwriter : BaseWriterT
	{
		using BaseWriterT::BaseWriterT;
	};

}	// namespace khutils

#endif	// KHUTILS_TLV_WRITER_HPP_INC
