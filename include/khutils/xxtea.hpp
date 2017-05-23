#ifndef KHUTILS_XXTEA_HPP_INC
#define KHUTILS_XXTEA_HPP_INC

#include <cctype>
#include <string>
#include <vector>

namespace khutils
{
	std::vector<uint8_t> xxtea_encode(const std::string&);
	std::vector<uint8_t> xxtea_encode(const std::vector<uint8_t>&);

	std::string			 xxtea_decode_string(const std::vector<uint8_t>&);
	std::vector<uint8_t> xxtea_decode_data(const std::vector<uint8_t>&);

}	// namespace khutils

#if defined(KHUTILS_XXTEA_IMPL)

#include "assertion.hpp"
#include <algorithm>

namespace khutils
{
	constexpr char	 xxtea_key[]	= "57786eaf7b1c579364a8b96a4d76e5e4";
	constexpr size_t   xxtea_key_size = 256 / 8;
	constexpr uint32_t xxtea_delta	= 0x9e3779b9;

	//#define MX (((z >> 5 ^ y << 2) + (y >> 3 ^ z << 4)) ^ ((sum ^ y) + (key[(p & 3) ^ e] ^ z)))

	// actual implementation
	std::vector<uint32_t> xxtea_encode(std::vector<uint32_t> data)
	{
		uint32_t z   = data.back();
		uint32_t y   = data.front();
		uint32_t sum = 0;
		uint32_t q   = 6 + 52 / data.size();

		while (q-- > 0)
		{
			sum				 = sum + xxtea_delta;
			const uint32_t e = (sum >> 2) & 3;
			uint32_t	   p = 0;
			for (; p < data.size() - 1; p++)
			{
				y = data.at(p + 1);
				z = data.at(p) += ((((z) >> 5 ^ y << 2) + ((y) >> 3 ^ z << 4))	//
								   ^ ((sum ^ y) + (xxtea_key[(p & 3) ^ e] ^ z)));
			}

			y = data.front();
			z = data.back() += ((((z) >> 5 ^ y << 2) + ((y) >> 3 ^ z << 4))	//
								^ ((sum ^ y) + (xxtea_key[(p & 3) ^ e] ^ z)));
		}
		return data;
	}

	std::vector<uint32_t> xxtea_decode(std::vector<uint32_t> data)
	{
		uint32_t z = data.back();
		uint32_t y = data.front();
		uint32_t sum;
		uint32_t q = 6 + 52 / data.size();

		sum = q * xxtea_delta;
		while (sum != 0)
		{
			const uint32_t e = sum >> 2 & 3;
			uint32_t	   p = data.size() - 1;
			for (; p > 0; p--)
			{
				z = data.at(p - 1);
				y = data.at(p) -= (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4)	//
								  ^ (sum ^ y) + (xxtea_key[p & 3 ^ e] ^ z);
			}

			z = data.back();
			y = data.front() -= (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4)	//
								^ (sum ^ y) + (xxtea_key[p & 3 ^ e] ^ z);
			sum = sum - xxtea_delta;
		}
		return data;
	}

	//-------------------------------------------------------

	std::vector<uint8_t> xxtea_encode(const std::string& s)
	{
		std::vector<uint8_t> sdata;
		sdata.reserve(s.size());
		std::transform(s.begin(), s.end(), std::back_inserter(sdata), [](auto& c) { return (uint8_t)c; });

		return xxtea_encode(sdata);
	}

	std::vector<uint8_t> xxtea_encode(const std::vector<uint8_t>& data_)
	{
		std::vector<uint8_t> data(data_);
		data.resize(data.size() + data.size() % 4, 0);	// add padding

		auto enc = xxtea_encode(std::vector<uint32_t>(reinterpret_cast<uint32_t*>(&*data.begin()),	//
													  reinterpret_cast<uint32_t*>(&*data.end())));
		return std::vector<uint8_t>(reinterpret_cast<uint8_t*>(&*enc.begin()),	//
									reinterpret_cast<uint8_t*>(&*enc.end()));
	}

	//-------------------------------------------------------

	std::string xxtea_decode_string(const std::vector<uint8_t>& data)
	{
		auto		dec = xxtea_decode_data(data);
		std::string ret;
		ret.reserve(dec.size());
		std::transform(dec.begin(), dec.end(), std::back_inserter(ret), [](auto& b) { return (char)b; });

		return ret;
	}

	std::vector<uint8_t> xxtea_decode_data(const std::vector<uint8_t>& data)
	{
		auto dec = xxtea_decode(std::vector<uint32_t>(reinterpret_cast<const uint32_t*>(&*data.begin()),	//
													  reinterpret_cast<const uint32_t*>(&*data.end())));
		return std::vector<uint8_t>(reinterpret_cast<uint8_t*>(&*dec.begin()),	//
									reinterpret_cast<uint8_t*>(&*dec.end()));
	}

	//-------------------------------------------------------

}	// namespace khutils

#endif	// defined(KHUTILS_XXTEA_IMPL)

#if defined(KHUTILS_XXTEA_UNITTEST)

#include "assertion.hpp"
#include "logging.hpp"

#include <bandit/bandit.h>
using namespace bandit;

go_bandit([]() {
	using namespace khutils;
	const std::vector<uint8_t> testdata = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB};

	it("KHUTILS XXTEA", [&testdata]() {	//
		auto enc = xxtea_encode(testdata);

		auto dec = xxtea_decode_data(enc);

		KHUTILS_ASSERT_EQUALS(testdata.size(), dec.size());
		for (size_t i = 0; i < dec.size(); ++i)
		{
			KHUTILS_ASSERT_EQUALS(testdata.at(i), dec.at(i));
		}
	});
});

#endif	// defined(KHUTILS_XXTEA_UNITTEST)

#if defined(KHUTILS_XXTEA_ENCODER_TOOL) || defined(KHUTILS_XXTEA_DECODER_TOOL)

#include "file.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	using namespace khutils;

	std::vector<uint8_t> buf;
	if (argc < 2)
	{
		buf = openBufferFromStreamProgressive(std::cin);
	}
	else
	{
		buf = openLocalFileBuffer(argv[1]);
	}

	if (buf.empty())
	{
		return -1;
	}

	auto data
#if defined(KHUTILS_XXTEA_ENCODER_TOOL)
	  = xxtea_encode(buf);
#elif defined(KHUTILS_XXTEA_DECODER_TOOL)
	  = xxtea_decode_data(buf);
#endif	//


	if (argc == 3)
	{
		dumpBufferToLocalFile(data, argv[2]);
	}
	else
	{
		dumpBufferToStream(data, std::cout);
	}

	return 0;
}

#endif	// defined(KHUTILS_XXTEA_ENCODER_TOOL) || defined(KHUTILS_XXTEA_DECODER_TOOL)


#endif	// !KHUTILS_XXTEA_HPP_INC
