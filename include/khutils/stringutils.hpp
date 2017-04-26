#ifndef KHUTILS_STRINGUTILS_HPP_INC
#define KHUTILS_STRINGUTILS_HPP_INC

//!! implementation uses boost.algorithm.string

#include <string>
#include <vector>

namespace khutils
{
	template <typename DelimiterPredicate>
	std::vector<std::string> split_string(const std::string&, DelimiterPredicate);

	std::vector<std::string> split_string(const std::string&, const std::string& delim);
	std::string join_strings(const std::vector<std::string>&, const std::string& delim);

}	// namespace khutils


#if defined(KHUTILS_STRINGUTILS_INLINE)

#include <boost/algorithm/string/split.hpp>

template <typename DelimiterPredicate>
std::vector<std::string> khutils::split_string(const std::string& str, DelimiterPredicate pred)
{
	std::vector<std::string> strings;
	boost::split(strings, str, pred, boost::token_compress_on);
	return strings;
}

#endif	// defined (KHUTILS_STRINGUTILS_INLINE)


#if defined(KHUTILS_STRINGUTILS_IMPL)

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

std::vector<std::string> khutils::split_string(const std::string& str, const std::string& delim)
{
	return khutils::split_string(str, boost::is_any_of(delim));
}

std::string khutils::join_strings(const std::vector<std::string>& strings, const std::string& delim)
{
	std::string str;
	for (auto& s : strings)
	{
		str += s + delim;
	}
	return str;
}


#endif	// defined (KHUTILS_STRINGUTILS_IMPL)

#endif	// !KHUTILS_STRINGUTILS_HPP_INC
