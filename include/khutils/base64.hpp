#ifndef KHUTILS_BASE64_HPP_INC
#define KHUTILS_BASE64_HPP_INC

#include <string>
#include <vector>

namespace khutils
{
	std::string base64Encode(const uint8_t* const, size_t length);
	std::vector<uint8_t> base64Decode(const char* const, size_t length);

	std::string			 base64Encode(const std::vector<uint8_t>&);
	std::vector<uint8_t> base64Decode(const std::string&);

}	// namespace khutils

#if defined(KHUTILS_BASE64_IMPL)

#define KHUTILS_ASSERTION_INLINE

#include "assertion.hpp"

#include <array>
#include <regex>
#include <sstream>
#include <string>

//-------------------------------------
namespace khutils
{
	constexpr const char base64_chars[]
	  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";


	inline bool is_base64(unsigned char c)
	{
		return (isalnum(c) || (c == '+') || (c == '/'));
	}

	//-------------------------------------

	std::string base64Encode(const uint8_t* const buf, size_t length)
	{
		const uint8_t* bytes_to_encode = buf;
		std::string	ret;
		auto		   bi = std::back_inserter(ret);
		int			   i = 0, j = 0;
		unsigned char  char_array_3[3], char_array_4[4];

		while (length--)
		{
			char_array_3[i++] = *(bytes_to_encode++);
			if (i == 3)
			{
				char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
				char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
				char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
				char_array_4[3] = char_array_3[2] & 0x3f;

				for (i = 0; (i < 4); i++)
				{
					*bi++ = base64_chars[char_array_4[i]];
				}
				i = 0;
			}
		}

		if (i)
		{
			for (j = i; j < 3; j++)
			{
				char_array_3[j] = '\0';
			}

			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

			for (j = 0; (j < i + 1); j++)
				*bi++ = base64_chars[char_array_4[j]];

			while ((i++ < 3))
				*bi++ = '=';
		}

		return ret;
	}

	std::vector<uint8_t> base64Decode(const char* const encoded_string, size_t length)
	{
		int			  i = 0, j = 0;
		size_t		  in_ = 0;
		unsigned char char_array_3[3], char_array_4[4];

		std::vector<uint8_t> ret;
		auto				 bi = std::back_inserter(ret);

		while (length-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_]))
		{
			char_array_4[i++] = encoded_string[in_];
			++in_;

			if (i == 4)
			{
				for (i = 0; i < 4; i++)
				{
					char_array_4[i] = std::distance(base64_chars, std::find(base64_chars, base64_chars+sizeof(base64_chars), (char_array_4[i])));
				}

				char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
				char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
				char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

				for (i = 0; (i < 3); i++)
				{
					*bi++ = char_array_3[i];
				}
				i = 0;
			}
		}

		if (i)
		{
			for (j = 0; j < i; j++)
			{
				char_array_4[j] = std::distance(base64_chars, std::find(base64_chars, base64_chars+sizeof(base64_chars), (char_array_4[j])));
			}

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);

			for (j = 0; (j < i - 1); j++)
			{
				*bi++ = char_array_3[j];
			}
		}

		return ret;
	}

	std::string base64Encode(const std::vector<uint8_t>& data)
	{
		return base64Encode(data.data(), data.size());
	}

	std::vector<uint8_t> base64Decode(const std::string& s)
	{
		return base64Decode(s.c_str(), s.size());
	}

	//-------------------------------------

}	// namespace khutils


#endif	// defined(KHUTILS_BASE64_IMPL)

#if defined(KHUTILS_BASE64_UNITTEST)

#include "assertion.hpp"
#include "logging.hpp"

#include <bandit/bandit.h>
using namespace bandit;

go_bandit([]() {
	using namespace khutils;
	const std::vector<uint8_t> testdata = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	it("KHUTILS base64 encode", [&testdata]() {	//
		auto enc = base64Encode(testdata);
		khutils::logger::log() << enc;

		auto dec = base64Decode(enc);

		KHUTILS_ASSERT_EQUALS(testdata.size(), dec.size());
		for (size_t i = 0; i < dec.size(); ++i)
		{
			KHUTILS_ASSERT_EQUALS(testdata.at(i), dec.at(i));
		}
	});
});

#endif	// defined(KHUTILS_BASE64_UNITTEST)


#endif	// !KHUTILS_BASE64_HPP_INC
