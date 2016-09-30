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

	// transforms given shit-jis string to utf8/string
	std::string sjis_to_utf8string(const std::string&);

}	// namespace khutils

#if defined(KHUTILS_UTF8STRING_IMPL)

#include "khutils/logging.hpp"
#include "khutils/utf8/utf8string.hpp"

#include <boost/nowide/convert.hpp>
#include <iconv.h>

#include <codecvt>
#include <locale>
#include <vector>

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

	std::string sjis_to_utf8string(const std::string& s)
	{
		std::vector<char> buffer(s.size() * 4);	// just to be on the safe side

		const char* src	= s.c_str();
		char*		dst	= &buffer[0];
		size_t		srclen = s.size();
		size_t		dstlen = buffer.size();

		iconv_t conv = iconv_open("UTF-8", "SHIFT_JIS");
		iconv(conv, const_cast<char**>(&src), &srclen, &dst, &dstlen);
		iconv_close(conv);

		return std::string(buffer.data(), buffer.size());
	}

}	// namespace khutils

#endif	// defined (KHUTILS_UTF8STRING_IMPL)

#endif	// !KHUTILS_UTF8STRING_HPP_INC
