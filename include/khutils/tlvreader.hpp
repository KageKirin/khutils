#ifndef KHUTILS_TLV_READER_HPP_INC
#define KHUTILS_TLV_READER_HPP_INC

#include "khutils/tlv.hpp"

namespace khutils
{
	template <class TLVelementT, typename BaseReaderT>
	struct TLVreader : BaseReaderT
	{
		typedef TLVelementT tlv_element_type;
		using BaseReaderT::BaseReaderT;

		//! reads the next data as TLVelement and returns it
		tlv_element_type read_next()
		{
			auto cur	= this->template getCurrentOffset();
			auto tag	= this->template fetchAt<typename TLVelementT::tag_type>(cur + TLVelementT::tag_offset);
			auto length = this->template fetchAt<typename TLVelementT::length_type>(cur + TLVelementT::length_offset);

			return tlv_element_type(this->template read<uint8_t>(size_t(length)));
		}
	};

}	// namespace khutils

#endif	// KHUTILS_TLV_READER_HPP_INC
