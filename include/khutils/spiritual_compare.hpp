#ifndef KHUTILS_SPIRITUAL_COMPARE_HPP_INC
#define KHUTILS_SPIRITUAL_COMPARE_HPP_INC

#include <cctype>
#include <string>

namespace khutils
{
	// compares through a spirit parser
	bool spiritual_compare(const std::string& lhv, const std::string& rhv);
	bool spiritual_compare(const char* lhv, const char* rhv);

}	// namespace khutils

#if defined(KHUTILS_SPIRITUAL_COMPARE_IMPL)

#include "runtime_exceptions.hpp"
#include "spiritual_compare.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/spirit/home/x3.hpp>

#include <cppformat/format.h>
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
	using x3::lit;

	using ascii::space;

	using x3::parse;
	using x3::phrase_parse;

	//////////////////////////////////////////////////////////////////////////
	//-

	bool spiritual_compare(const std::string& lhv, const std::string& rhv)
	{
		auto first = begin(rhv);
		auto last  = end(rhv);

		bool r = parse(first, last, (lit(lhv)));

		return r && first == last;
	}

	bool spiritual_compare(const char* lhv, const char* rhv)
	{
		auto first = rhv;
		auto last  = rhv + strlen(rhv);

		bool r = parse(first, last, (lit(lhv)));

		return r && first == last;
	}

	//////////////////////////////////////////////////////////////////////////
	//- other types

}	// namespace khutils

#endif	// defined (KHUTILS_SPIRITUAL_COMPARE_IMPL)

#endif	// !KHUTILS_SPIRITUAL_COMPARE_HPP_INC
