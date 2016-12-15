#ifndef KHUTILS_FILE_HTTP_HPP_INC
#define KHUTILS_FILE_HTTP_HPP_INC

#include <string>

namespace khutils
{
	std::string getServerName(const std::string& url);
	std::string getServerPath(const std::string& url);
	std::string getServerPathHash(const std::string& url);
	std::string getServerPathWithHash(const std::string& url);
} // namespace khutils

#if defined(KHUTILS_FILE_HTTP_IMPL)

#include <fmt/format.h>

#include "khutils/file.hpp"
#include "khutils/logging.hpp"
#include "khutils/runtime_exceptions.hpp"

#include <boost/asio/ip/tcp.hpp>
#include <boost/filesystem/path.hpp>

#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

namespace khutils
{
	namespace ip = boost::asio::ip;
	using namespace fmt::literals;

	//////////////////////////////////////////////////////////////////////////
	//! URI regex as specified in original RFC
	//! @see: https://tools.ietf.org/html/rfc3986#appendix-B
	static constexpr char URI_pattern[] = R"(^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)";
	static const std::regex reURI(URI_pattern);

	std::string getServerName(const std::string& url)
	{
		std::smatch match;
		bool matchOK = std::regex_match(url, match, reURI);
		assert(matchOK);
		assert(match.size() > 4);

		return match[4];
	}

	std::string getServerPath(const std::string& url)
	{
		std::smatch match;
		bool matchOK = std::regex_match(url, match, reURI);
		assert(matchOK);
		assert(match.size() > 5);

		return match[5];
	}

	std::string getServerPathHash(const std::string& url)
	{
		std::smatch match;
		bool matchOK = std::regex_match(url, match, reURI);
		assert(matchOK);
		assert(match.size() > 9);

		return match[9];
	}

	std::string getServerPathWithHash(const std::string& url)
	{
		std::smatch match;
		bool matchOK = std::regex_match(url, match, reURI);
		assert(matchOK);
		assert(match.size() > 9);

		return match[5].str() + match[8].str();
	}

	//! modeled after
	//! http://www.boost.org/doc/libs/1_47_0/doc/html/boost_asio/example/iostreams/http_client.cpp
	//! only work on http, NOT https
	void openHttpSocket(ip::tcp::iostream& s, const std::string& url)
	{
		auto serverName = getServerName(url);
		auto resourcePath = getServerPathWithHash(url);

		s.expires_from_now(boost::posix_time::seconds(60));

		s.connect(serverName, "http");

		if (!s)
		{
			static std::string errorMsg;
			errorMsg = "Could not open URL " + url + " . Unresolved host. " + serverName;
			throw FatalImportException(errorMsg);
		}

		s << "GET " << resourcePath << " HTTP/1.0\r\n";
		s << "Host: " << serverName << "\r\n";
		s << "Accept: */*\r\n";
		s << "Connection: close\r\n\r\n";

		// Check that response is OK.
		std::string http_version;
		s >> http_version;
		unsigned int status_code;
		s >> status_code;
		std::string status_message;
		std::getline(s, status_message);

		if (!s || http_version.substr(0, 5) != "HTTP/")
		{
			static std::string errorMsg;
			errorMsg = "Could not open URL '{}'. Invalid response. {}"_format(url, status_message);
			throw FatalImportException(errorMsg);
		}

		if (status_code != 200)
		{
			static std::string errorMsg;
			errorMsg = "Could not open URL '{}'. Status code {} not 200. {}"_format(url, status_code, status_message);
			throw FatalImportException(errorMsg);
		}

		// Process the response headers, which are terminated by a blank line.
		std::string header;
		while (std::getline(s, header) && header != "\r")
		{
			// ideally use null() instead
			logger::debug() << header;
		}
	}

	//////////////////////////////////////////////////////////////////////////

	std::stringstream openHttpFile(const std::string& url)
	{
		ip::tcp::iostream s;
		openHttpSocket(s, url);

		// return response body
		std::stringstream ret;
		ret << s.rdbuf();
		return ret;
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FILE_HTTP_IMPL)

#endif	// !KHUTILS_FILE_HTTP_HPP_INC
