#ifndef KHUTILS_TLV_HPP_INC
#define KHUTILS_TLV_HPP_INC

//! must come first and in this order
#include "khutils/typeconversion.hpp"
#include <boost/endian/conversion.hpp>

#include <array>
#include <cstdint>
#include <vector>

namespace khutils
{
	//! Type-length-value container
	template <typename TagT, typename LengthT, size_t TagOffset, size_t LengthOffset, size_t Alignment, boost::endian::order _order>
	class TLVelement
	{
	public:
		typedef TagT						  tag_type;
		typedef LengthT						  length_type;
		typedef std::vector<uint8_t>		  value_type;
		static constexpr size_t				  tag_offset	= TagOffset;
		static constexpr size_t				  length_offset = LengthOffset;
		static constexpr size_t				  alignment		= Alignment;
		static constexpr boost::endian::order endianity		= _order;

	protected:
		value_type				 m_header;
		value_type				 m_data;
		const tag_type* const	m_tagp;
		const length_type* const m_sizep;

	public:
		TLVelement(const value_type& header, const value_type& data)
			: m_header(header)
			, m_data(data)
			, m_tagp(reinterpret_cast<tag_type*>(&m_header.at(tag_offset)))
			, m_sizep(reinterpret_cast<length_type*>(&m_header.at(length_offset)))
		{
		}

		TLVelement(tag_type tag, length_type size)
			: m_header(sizeof(tag_type) + tag_offset + sizeof(length_type) + length_offset
					   + ((sizeof(tag_type) + tag_offset + sizeof(length_type) + length_offset) % alignment))
			, m_data()
			, m_tagp(reinterpret_cast<tag_type*>(&m_header.at(tag_offset)))
			, m_sizep(reinterpret_cast<length_type*>(&m_header.at(length_offset)))
		{
		}

		TLVelement(TLVelement&&)	  = default;
		TLVelement(const TLVelement&) = default;

		TLVelement& operator=(TLVelement&&) = default;
		TLVelement& operator=(const TLVelement&) = default;

		tag_type tag(boost::endian::order target = order::native) const
		{
			return conditional_reverse(*m_tagp, endianity, target);
		}

		length_type size(boost::endian::order target = order::native) const
		{
			return conditional_reverse(*m_sizep, endianity, target);
		}

		const value_type& raw_value() const
		{
			return m_data;
		}

		const uint8_t* value() const
		{
			return &m_data.at(alignment);
		}

		value_type::const_iterator value_begin() const
		{
			return m_data.begin();
		}

		value_type::const_iterator value_end() const
		{
			return m_data.end();
		}

		template <typename ValueType>
		void add_value(const ValueType& val)
		{
			const uint8_t* rawVal	= reinterpret_cast<const uint8_t*>(&val);
			size_t		   amountRaw = sizeof(ValueType);
			m_data.insert(m_data.end(), rawVal, rawVal + amountRaw);
		}

		template <typename ValueType>
		void add_values(const std::vector<ValueType>& val)
		{
			std::for_each(val.begin(), val.end(), [this](const auto& _val) { add_value(_val); });
		}

		void add_subelement(const TLVelement& element)
		{
			m_data.insert(m_data.end(), element.raw_value.begin(), element.raw_value.end());
		}

		void add_subelements(const std::vector<TLVelement>& elements)
		{
			std::for_each(elements.begin(), elements.end(), [this](const auto& _elem) { add_subelement(_elem); });
		}
	};

}	// namespace khutils

#endif	// KHUTILS_TLV_HPP_INC
