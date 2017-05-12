#ifndef KHUTILS_UNITTEST_HELPER_HPP_INC
#define KHUTILS_UNITTEST_HELPER_HPP_INC

#include "khutils/file.hpp"
#include <cctype>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>


namespace khutils
{
	std::string				  as_string(const std::vector<uint8_t>&);
	inline const std::string& as_string(const std::string& s)
	{
		return s;
	}

	std::vector<uint8_t>			   as_buffer(const std::string&);
	inline const std::vector<uint8_t>& as_buffer(const std::vector<uint8_t>& b)
	{
		return b;
	}

	std::istringstream as_stream(const std::string&);
	std::istringstream as_stream(const std::vector<uint8_t>&);

	khutils::FilePtr as_file(const std::string&);
	khutils::FilePtr as_file(const std::vector<uint8_t>&);

}	// namespace khutils


#if defined(KHUTILS_UNITTEST_HELPER_IMPL)

#include <algorithm>

std::string khutils::as_string(const std::vector<uint8_t>& b)
{
	return std::string(reinterpret_cast<const char*>(b.data()), b.size());
}

//---

std::vector<uint8_t> khutils::as_buffer(const std::string& s)
{
	std::vector<uint8_t> b;
	b.reserve(s.size());
	std::transform(s.begin(), s.end(), std::back_inserter(b), [](auto& c) { return uint8_t(c); });
	return b;
}

//---

std::istringstream khutils::as_stream(const std::string& s)
{
	return std::istringstream(s);
}

//---

std::istringstream khutils::as_stream(const std::vector<uint8_t>& b)
{
	return as_stream(as_string(b));
}

//---

khutils::FilePtr khutils::as_file(const std::string& s)
{
	auto file = openTempFilePtr();
	fwrite(s.c_str(), s.size(), 1, file.get());
	rewind(file.get());
	return file;
}

//---

khutils::FilePtr khutils::as_file(const std::vector<uint8_t>& b)
{
	auto file = openTempFilePtr();
	fwrite(reinterpret_cast<const char*>(b.data()), b.size(), 1, file.get());
	rewind(file.get());
	return file;
}

//---


#endif	// defined(KHUTILS_UNITTEST_HELPER_IMPL)

#endif	// !KHUTILS_Z_UNITTEST_HELPER_HPP_INC
