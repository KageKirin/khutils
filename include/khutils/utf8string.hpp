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

	namespace sjis_to_utf8
	{
		extern uint16_t sjisToUtf8(uint16_t code);
		extern uint16_t utf8ToSjis(uint16_t code);
		extern bool validSjisCode(uint16_t code);
		extern bool validUtf8Code(uint16_t code);
	}	// sjis_to_utf8

	inline std::string utf8CodeToString(uint16_t code)
	{
		std::string output("");
		if (code < 0x80)
		{
			output += char(code);
		}
		else if (code < 0x800)
		{
			output += char(0xC0 | (code >> 6));
			output += char(0x80 | (code & 0x3f));
		}
		else
		{
			output += char(0xE0 | (code >> 12));
			output += char(0x80 | ((code & 0xfff) >> 6));
			output += char(0x80 | (code & 0x3f));
		}
		return output;
	}

	std::string sjis_to_utf8string(const std::string& s)
	{
		auto	   curIt = begin(s);
		const auto endIt = end(s);

		std::string outStr;
		while (curIt != endIt)
		{
			// check single-byte
			uint16_t curCode = uint16_t(*curIt);
			curIt++;

			if (sjis_to_utf8::validSjisCode(curCode))
			{
				uint16_t utf8Code = sjis_to_utf8::sjisToUtf8(curCode);
				outStr += utf8CodeToString(utf8Code);
				continue;
			}
			else if (curIt == endIt)
			{
				break;
			}

			// check double-byte
			curCode = (curCode << 8) | uint16_t(*curIt);
			curIt++;

			if (sjis_to_utf8::validSjisCode(curCode))
			{
				uint16_t utf8Code = sjis_to_utf8::sjisToUtf8(curCode);
				outStr += utf8CodeToString(utf8Code);
				continue;
			}

			outStr += " ";

			logger::debug() << outStr;
		}

		return outStr;
	}

}	// namespace khutils

#endif	// defined (KHUTILS_UTF8STRING_IMPL)

#endif	// !KHUTILS_UTF8STRING_HPP_INC
