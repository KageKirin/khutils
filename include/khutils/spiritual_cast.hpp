#ifndef KHUTILS_SPIRITUAL_CAST_HPP_INC
#define KHUTILS_SPIRITUAL_CAST_HPP_INC

#include <cctype>
#include <glm/fwd.hpp>
#include <string>

namespace khutils
{
	using std::int8_t;
	using std::int16_t;
	using std::int32_t;
	using std::int64_t;
	using std::uint8_t;
	using std::uint16_t;
	using std::uint32_t;
	using std::uint64_t;
	//! spiritual_cast<type>(string) performs a lexical cast from a string into the
	//! given type
	//! it works like boost::lexical_cast<type>(string), but uses boost.spirit.x3
	//! for performant parsing
	//! TODO: extend as needed

	template <typename _Type>
	_Type spiritual_cast(const std::string& str);

	//////////////////////////////////////////////////////////////////////////
	//- basic type declaration/template instantiation

	template <>
	bool spiritual_cast<bool>(const std::string& str);
	template <>
	char spiritual_cast<char>(const std::string& str);
	// template <>
	// short spiritual_cast<short>(const std::string& str);
	// template <>
	// int spiritual_cast<int>(const std::string& str);
	template <>
	long spiritual_cast<long>(const std::string& str);
	// template <>
	// long long spiritual_cast<long long>(const std::string& str);
	// template <>
	// unsigned char spiritual_cast<unsigned char>(const std::string& str);
	// template <>
	// unsigned short spiritual_cast<unsigned short>(const std::string& str);
	// template <>
	// unsigned int spiritual_cast<unsigned int>(const std::string& str);
	template <>
	unsigned long spiritual_cast<unsigned long>(const std::string& str);
	// template <>
	// unsigned long long spiritual_cast<unsigned long long>(const std::string&
	// str);

	template <>
	int8_t spiritual_cast<int8_t>(const std::string& str);
	template <>
	int16_t spiritual_cast<int16_t>(const std::string& str);
	template <>
	int32_t spiritual_cast<int32_t>(const std::string& str);
	template <>
	int64_t spiritual_cast<int64_t>(const std::string& str);
	template <>
	uint8_t spiritual_cast<uint8_t>(const std::string& str);
	template <>
	uint16_t spiritual_cast<uint16_t>(const std::string& str);
	template <>
	uint32_t spiritual_cast<uint32_t>(const std::string& str);
	template <>
	uint64_t spiritual_cast<uint64_t>(const std::string& str);

	template <>
	float spiritual_cast<float>(const std::string& str);
	template <>
	double spiritual_cast<double>(const std::string& str);

	//////////////////////////////////////////////////////////////////////////
	//- composite types

	//////////////////////////////////////////////////////////////////////////
	//- char to string

	template <typename _Type>
	inline _Type spiritual_cast(const char* sz)
	{
		return spiritual_cast<_Type>(std::string(sz));
	}

}	// namespace khutils

#if defined(KHUTILS_SPIRITUAL_CAST_IMPL)

#include "runtime_exceptions.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/spirit/home/x3.hpp>

#include <fmt/format.h>
#include <glm/glm.hpp>

//////////////////////////////////////////////////////////////////////////
//- structure adapters for composite types

//////////////////////////////////////////////////////////////////////////

namespace khutils
{
	using namespace fmt::literals;
	namespace x3	= boost::spirit::x3;
	namespace ascii = boost::spirit::x3::ascii;

	using x3::short_;
	using x3::int_;
	using x3::long_;
	using x3::long_long;

	using x3::ushort_;
	using x3::uint_;
	using x3::ulong_;
	using x3::ulong_long;

	using x3::float_;
	using x3::double_;
	using x3::char_;
	using x3::bool_;
	// using x3::uchar_;

	using x3::int8;
	using x3::int16;
	using x3::int32;
	using x3::int64;

	using x3::uint8;
	using x3::uint16;
	using x3::uint32;
	using x3::uint64;

	using ascii::space;

	using x3::parse;
	using x3::parse;

	//////////////////////////////////////////////////////////////////////////
	//- basic types

	template <>
	bool spiritual_cast<bool>(const std::string& str)
	{
		bool value;
		auto first = begin(str);
		auto last  = end(str);

		bool r = parse(first, last, (bool_), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<bool>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	char spiritual_cast<char>(const std::string& str)
	{
		char value;
		auto first = begin(str);
		auto last  = end(str);

		bool r = parse(first, last, (int8), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<char>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	long spiritual_cast<long>(const std::string& str)
	{
		long value;
		auto first = begin(str);
		auto last  = end(str);

		bool r = parse(first, last, (long_), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<long>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	unsigned long spiritual_cast<unsigned long>(const std::string& str)
	{
		unsigned long value;
		auto		  first = begin(str);
		auto		  last  = end(str);

		bool r = parse(first, last, (ulong_), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<unsigned long>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	float spiritual_cast<float>(const std::string& str)
	{
		float value;
		auto  first = begin(str);
		auto  last  = end(str);

		bool r = parse(first, last, (float_), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<float>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	double spiritual_cast<double>(const std::string& str)
	{
		double value;
		auto   first = begin(str);
		auto   last  = end(str);

		bool r = parse(first, last, (double_), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<double>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	int8_t spiritual_cast<int8_t>(const std::string& str)
	{
		int8_t value;
		auto   first = begin(str);
		auto   last  = end(str);

		bool r = parse(first, last, (int8), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<int8_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	int16_t spiritual_cast<int16_t>(const std::string& str)
	{
		int16_t value;
		auto	first = begin(str);
		auto	last  = end(str);

		bool r = parse(first, last, (int16), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<int16_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	int32_t spiritual_cast<int32_t>(const std::string& str)
	{
		int32_t value;
		auto	first = begin(str);
		auto	last  = end(str);

		bool r = parse(first, last, (int32), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<int32_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	int64_t spiritual_cast<int64_t>(const std::string& str)
	{
		int64_t value;
		auto	first = begin(str);
		auto	last  = end(str);

		bool r = parse(first, last, (int64), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<int64_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	uint8_t spiritual_cast<uint8_t>(const std::string& str)
	{
		uint8_t value;
		auto	first = begin(str);
		auto	last  = end(str);

		bool r = parse(first, last, (uint8), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<uint8_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	uint16_t spiritual_cast<uint16_t>(const std::string& str)
	{
		uint16_t value;
		auto	 first = begin(str);
		auto	 last  = end(str);

		bool r = parse(first, last, (uint16), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<uint16_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	uint32_t spiritual_cast<uint32_t>(const std::string& str)
	{
		uint32_t value;
		auto	 first = begin(str);
		auto	 last  = end(str);

		bool r = parse(first, last, (uint32), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<uint32_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	template <>
	uint64_t spiritual_cast<uint64_t>(const std::string& str)
	{
		uint64_t value;
		auto	 first = begin(str);
		auto	 last  = end(str);

		bool r = parse(first, last, (uint64), value);
		if (!r || first != last)	// fail if we did not get a full match
		{
			static std::string errMsg;
			errMsg = "spiritual_cast<uint64_t>({})"_format(str);
			throw SpiritualCastException(errMsg);
		}

		return value;
	}

	//////////////////////////////////////////////////////////////////////////
	//- other types

}	// namespace khutils

#endif	// defined (KHUTILS_SPIRITUAL_CAST_IMPL)

#endif	// !KHUTILS_SPIRITUAL_CAST_HPP_INC
