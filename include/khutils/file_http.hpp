#ifndef KHUTILS_FILE_HTTP_HPP_INC
#define KHUTILS_FILE_HTTP_HPP_INC

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

namespace khutils
{
	namespace ip = boost::asio::ip;
	using namespace fmt::literals;

	//////////////////////////////////////////////////////////////////////////
	//!!! totally fixed on 1 server and path system for now
	//!!! TODO: make configurable

	static const std::string serverName = "10.33.82.234";

	// total hack to adjust file path to test server
	std::string patchUrl(const std::string& url)
	{
		std::regex expression(R"(3davt/files/)");

		return std::regex_replace(url, expression, "");
	}

	//! modeled after
	//! http://www.boost.org/doc/libs/1_47_0/doc/html/boost_asio/example/iostreams/http_client.cpp
	void openHttpSocket(ip::tcp::iostream& s, const std::string& url_)
	{
		std::string url = patchUrl(url_);

		s.expires_from_now(boost::posix_time::seconds(60));

		s.connect(serverName, "http");

		if (!s)
		{
			static std::string errorMsg;
			errorMsg = "Could not open URL " + url + " . Unresolved host.";
			throw FatalImportException(errorMsg);
		}

		s << "GET " << url << " HTTP/1.0\r\n";
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
			errorMsg = "Could not open URL 'http://{}{}'. Invalid response."_format(serverName, url);
			throw FatalImportException(errorMsg);
		}

		if (status_code != 200)
		{
			static std::string errorMsg;
			errorMsg = "Could not open URL 'http://{}{}'. Status code {} not 200."_format(serverName, url, status_code);
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
