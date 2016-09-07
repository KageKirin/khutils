#ifndef KHUTILS_UTF8STRING_HPP_INC
#define KHUTILS_UTF8STRING_HPP_INC

#include <string>

namespace khutils
{
	// transforms given wstring to utf8/string
	std::string to_utf8string(const std::wstring&);

	// transforms given string to utf16/wstring
	std::wstring to_utf16string(const std::string&);

}	// namespace khutils

#if defined(KHUTILS_UTF8STRING_IMPL)

#include "khutils/utf8string.hpp"

#include <boost/nowide/convert.hpp>

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

}	// namespace khutils

#endif	// defined (KHUTILS_UTF8STRING_IMPL)

#endif	// !KHUTILS_UTF8STRING_HPP_INC
