#ifndef KHUTILS_UTF8STRING_HPP_INC
#define KHUTILS_UTF8STRING_HPP_INC

#include <string>

namespace khutils
{
	// transforms given wstring to utf8/string
	std::string to_utf8string(const std::wstring&);

	// transforms given wstring to utf16string
	std::string to_utf8string(const std::u16string&);

	// transforms given string to wstring
	std::wstring to_wstring(const std::string&);

}	// namespace khutils

#if defined(KHUTILS_UTF8STRING_IMPL)

#include "khutils/utf8string.hpp"

#include <boost/nowide/convert.hpp>

#include <codecvt>
#include <locale>

namespace khutils
{
	// just wrapping to boost.nowide in here
	// this is done to avoid large refactoring costs
	// in case we need to switch unicode conversion lib

	std::string to_utf8string(const std::wstring& s)
	{
		return boost::nowide::narrow(s);
	}

	std::wstring to_utf16string(const std::string& s)
	{
		return boost::nowide::widen(s);
	}

	std::string to_utf8string(const std::u16string& s)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conversion;
		return conversion.to_bytes(s);
	}

}	// namespace khutils

#endif	// defined (KHUTILS_UTF8STRING_IMPL)

#endif	// !KHUTILS_UTF8STRING_HPP_INC
