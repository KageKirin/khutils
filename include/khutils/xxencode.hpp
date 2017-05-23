#ifndef KHUTILS_XXENCODE_HPP_INC
#define KHUTILS_XXENCODE_HPP_INC

#include <vector>

namespace khutils
{
	std::string			 uu_encode(const std::vector<uint8_t>&);
	std::vector<uint8_t> uu_decode(const std::string&);

	std::string			 xx_encode(const std::vector<uint8_t>&);
	std::vector<uint8_t> xx_decode(const std::string&);

	std::string			 zz_encode(const std::vector<uint8_t>&);
	std::vector<uint8_t> zz_decode(const std::string&);

	std::string			 base64_encode(const std::vector<uint8_t>&);
	std::vector<uint8_t> base64_decode(const std::string&);
}	// namespace khutils

#if defined(KHUTILS_XXENCODE_IMPL)

#define KHUTILS_ASSERTION_INLINE

#include "assertion.hpp"

#include <array>
#include <regex>
#include <sstream>
#include <string>

//-------------------------------------
namespace khutils
{
	// backticks
	constexpr char uu_set[] = "`!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_";
	// spaces instead of backticks
	constexpr char uu_old_set[] = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_";

	constexpr char xx_set[] = "+-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	constexpr char zz_set[] = "`abcdefghijklmnopqrstuvwxyz;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_";

	constexpr char mm_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	constexpr char Mm_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	//-------------------------------------

	// basic 1 character encoding function to make a char printing
	inline char encode_byte(uint32_t c, const char* set)
	{
		return set[c & 077];
	}

	// single character decode
	typedef std::array<uint8_t, 256> table_t;
	inline uint8_t decode_byte(char c, const table_t& table)
	{
		return table.at(c & 0xFF);
	}


	constexpr table_t create_table(const char* set)
	{
		table_t table = {0};
		for (uint8_t n = 0; set[n]; n++)
		{
			table[set[n] & 0xFF] = (n & 077);
		}
		return table;
	}

	//-------------------------------------


	std::string encode_with_set(const std::vector<uint8_t>& data,
								const char*					set,
								bool						withLineLength = true,
								void (*special)(char*, int32_t n) = nullptr)
	{
		std::ostringstream ss;

		const size_t lineSize = 45;
		auto		 it		  = data.begin();
		for (int remainder = std::min(lineSize, data.size());	//
			 remainder >= 0;
			 it += lineSize, remainder = std::min((int)lineSize, (int)data.size() - (int)std::distance(data.begin(), it)))
		{
			char  buffer[80] = {0};
			char* wptr		 = buffer;

			if (withLineLength)
			{
				*wptr++ = encode_byte((uint32_t)remainder, set);
			}

			uint32_t csum = 0;
			for (int i = 0; i < remainder; i += 3)
			{
				auto	 p = it + i;
				uint32_t v;

				*wptr++ = encode_byte(v = (*p >> 2), set);
				csum += v;
				*wptr++ = encode_byte(v = (((*p << 4) & 060) | ((p[1] >> 4) & 017)), set);
				csum += v;
				*wptr++ = encode_byte(v = (((p[1] << 2) & 074) | ((p[2] >> 6) & 03)), set);
				csum += v;
				*wptr++ = encode_byte(v = (p[2] & 077), set);
				csum += v;
			}

			if (special)
			{
				special(wptr, remainder);
			}

			*wptr++ = encode_byte(csum, set);

			ss << buffer << std::endl;
		}

		return ss.str();
	}

	std::vector<uint8_t> decode_with_set(const std::string& data, const char* set, std::regex reEnd)
	{
		std::vector<uint8_t> ret;

		auto table = create_table(set);


		std::istringstream ss(data);
		while (ss)
		{
			std::string line;
			ss >> line;
			if (std::regex_match(line, reEnd))
			{
				break;
			}

			// uu,xx,zz decode
			{
				const char* buf		   = line.c_str();
				const char* bp		   = buf;
				int32_t		lineLength = decode_byte(*bp++, table);

				if (lineLength <= 0)
					break;

				auto wptr = std::back_inserter(ret);
				while (lineLength > 0)
				{
					*wptr++ = decode_byte(*bp, table) << 2 | decode_byte(bp[1], table) >> 4;
					*wptr++ = decode_byte(bp[1], table) << 4 | decode_byte(bp[2], table) >> 2;
					*wptr++ = decode_byte(bp[2], table) << 6 | decode_byte(bp[3], table);
					bp += 4;
					lineLength -= 3;
				}
			}
		}

		return ret;
	}

	//-------------------------------------
	//-------------------------------------

	std::string uu_encode(const std::vector<uint8_t>& data)
	{
		return std::string("begin 666 <data>\n")	//
			   + encode_with_set(data, uu_set)		//
			   + "end\n";
	}

	std::vector<uint8_t> uu_decode(const std::string& data)
	{
		//KHUTILS_ASSERT(std::regex_match(data, std::regex("R(^begin )")));
		return decode_with_set(data.substr(data.find_first_of("\n") + 1), uu_set, std::regex("R(^end)"));
	}

	//-------------------------------------

	std::string xx_encode(const std::vector<uint8_t>& data)
	{
		return std::string("begin 666 <data>\n")	//
			   + encode_with_set(data, xx_set)		//
			   + "end\n";
	}

	std::vector<uint8_t> xx_decode(const std::string& data)
	{
		KHUTILS_ASSERT(std::regex_match(data, std::regex("R(^begin )")));
		return decode_with_set(data.substr(data.find_first_of("\n") + 1), xx_set, std::regex("R(^end)"));
	}

	//-------------------------------------

	std::string zz_encode(const std::vector<uint8_t>& data)
	{
		return std::string("begin 666 <data>\n")	//
			   + encode_with_set(data, zz_set)		//
			   + "end\n";
	}

	std::vector<uint8_t> zz_decode(const std::string& data)
	{
		KHUTILS_ASSERT(std::regex_match(data, std::regex("R(^begin )")));
		return decode_with_set(data.substr(data.find_first_of("\n") + 1), zz_set, std::regex("R(^end)"));
	}

	//-------------------------------------

	std::string base64_encode(const std::vector<uint8_t>& data)
	{
		return std::string("begin-base64 666 <data>\n")	//
			   + encode_with_set(data,
								 mm_set,
								 false,
								 [](char* wptr, int n) {
									 switch (n % 3)
									 {
										 case 1:
											 wptr[-2] = '=';
										 case 2:
											 wptr[-1] = '=';
									 }
								 })
			   + "====\n";
	}

	std::vector<uint8_t> base64_decode(const std::string& data)
	{
		KHUTILS_ASSERT(std::regex_match(data, std::regex("R(^begin-base64 )")));
		return decode_with_set(data.substr(data.find_first_of("\n") + 1), mm_set, std::regex("R(^====)"));
	}
	//-------------------------------------

}	// namespace khutils


#endif	// defined(KHUTILS_XXENCODE_IMPL)

#if defined(KHUTILS_XXENCODE_UNITTEST)

#include "assertion.hpp"
#include "logging.hpp"

#include <bandit/bandit.h>
using namespace bandit;

go_bandit([]() {
	using namespace khutils;
	const std::vector<uint8_t> testdata = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	it("KHUTILS XXENCODE uuencode", [&testdata]() {	//
		auto enc = uu_encode(testdata);
		khutils::logger::log() << enc;

		auto dec = uu_decode(enc);

		KHUTILS_ASSERT_EQUALS(testdata.size(), dec.size());
		for (size_t i = 0; i < dec.size(); ++i)
		{
			KHUTILS_ASSERT_EQUALS(testdata.at(i), dec.at(i));
		}
	});

	it("KHUTILS XXENCODE xxencode", [&testdata]() {	//
		auto enc = xx_encode(testdata);
		khutils::logger::log() << enc;

		auto dec = xx_decode(enc);

		KHUTILS_ASSERT_EQUALS(testdata.size(), dec.size());
		for (size_t i = 0; i < dec.size(); ++i)
		{
			KHUTILS_ASSERT_EQUALS(testdata.at(i), dec.at(i));
		}
	});

	it("KHUTILS XXENCODE zzencode", [&testdata]() {	//
		auto enc = zz_encode(testdata);
		khutils::logger::log() << enc;

		auto dec = zz_decode(enc);

		KHUTILS_ASSERT_EQUALS(testdata.size(), dec.size());
		for (size_t i = 0; i < dec.size(); ++i)
		{
			KHUTILS_ASSERT_EQUALS(testdata.at(i), dec.at(i));
		}
	});

	it("KHUTILS XXENCODE base64", [&testdata]() {	//
		auto enc = base64_encode(testdata);
		khutils::logger::log() << enc;

		auto dec = base64_decode(enc);

		KHUTILS_ASSERT_EQUALS(testdata.size(), dec.size());
		for (size_t i = 0; i < dec.size(); ++i)
		{
			KHUTILS_ASSERT_EQUALS(testdata.at(i), dec.at(i));
		}
	});
});

#endif	// defined(KHUTILS_XXENCODE_UNITTEST)


#endif	// !KHUTILS_XXENCODE_HPP_INC
