#ifndef KHUTILS_FILE_HTTP_HPP_INC
#define KHUTILS_FILE_HTTP_HPP_INC

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include <boost/asio/ip/tcp.hpp>

namespace khutils
{
	std::string getServerName(const std::string& url);
	std::string getServerPath(const std::string& url);
	std::string getServerPathHash(const std::string& url);
	std::string getServerPathWithHash(const std::string& url);
	std::string urlToHttpRequestHeader(const std::string& url);

	void openHttpSocket(boost::asio::ip::tcp::iostream& s, const std::string& url);


	std::stringstream openHttpFile(const std::string& url);
	std::vector<uint8_t> openHttpFileBuffer(const std::string& url);

	std::stringstream openHttpFile_boost(const std::string& url);
	std::vector<uint8_t> openHttpFileBuffer_boost(const std::string& url);

}	// namespace khutils

#if defined(KHUTILS_FILE_HTTP_IMPL)

#include <fmt/format.h>

#include "khutils/file.hpp"
#include "khutils/logging.hpp"
#include "khutils/runtime_exceptions.hpp"

#include <boost/asio/ip/tcp.hpp>
#include <boost/filesystem/path.hpp>

#include "bnet/bnet.h"
#include "bx/string.h"
#include "common/url.h"


#include <cassert>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace khutils
{
	namespace ip = boost::asio::ip;
	using namespace fmt::literals;

	//////////////////////////////////////////////////////////////////////////
	//! URI regex as specified in original RFC
	//! @see: https://tools.ietf.org/html/rfc3986#appendix-B
	static constexpr char   URI_pattern[] = R"(^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)";
	static const std::regex reURI(URI_pattern);

	std::string getServerName(const std::string& url)
	{
		char* tokens[UrlToken::Count];
		char  temp[1024];
		tokenizeUrl(url.c_str(), temp, sizeof(temp), tokens);

		return tokens[UrlToken::Host];
	}

	//------------------------------------------

	std::string getServerPath(const std::string& url)
	{
		char* tokens[UrlToken::Count];
		char  temp[1024];
		tokenizeUrl(url.c_str(), temp, sizeof(temp), tokens);

		return tokens[UrlToken::Path];
	}

	//------------------------------------------

	std::string getServerPathHash(const std::string& url)
	{
		char* tokens[UrlToken::Count];
		char  temp[1024];
		tokenizeUrl(url.c_str(), temp, sizeof(temp), tokens);

		return tokens[UrlToken::Query];
	}

	//------------------------------------------

	std::string getServerPathWithHash(const std::string& url)
	{
		char* tokens[UrlToken::Count];
		char  temp[1024];
		tokenizeUrl(url.c_str(), temp, sizeof(temp), tokens);

		return std::string(tokens[UrlToken::Path]) + tokens[UrlToken::Query];
	}

	//------------------------------------------

	std::string urlToHttpRequestHeader(const std::string& url)
	{
		using namespace fmt::literals;

		char* tokens[UrlToken::Count];
		char  temp[1024];
		tokenizeUrl(url.c_str(), temp, sizeof(temp), tokens);

		return "GET /{} HTTP/1.0\r\nHost: {}\r\n\r\n"_format(tokens[UrlToken::Path], tokens[UrlToken::Host]);
	}

	//------------------------------------------

	std::tuple<uint32_t, uint16_t, bool> getServerIPPort(const std::string& url)
	{
		char* tokens[UrlToken::Count];
		char  temp[1024];
		tokenizeUrl(url.c_str(), temp, sizeof(temp), tokens);

		bool	 secure = false;
		uint16_t port   = 80;

		if (0 == bx::strCmpI(tokens[UrlToken::Scheme], "https"))
		{
			port   = 443;
			secure = true;
		}

		if (tokens[UrlToken::Port][0] != '\0')
		{
			port = std::atoi(tokens[UrlToken::Port]);
		}

		return {bnet::toIpv4(tokens[UrlToken::Host]), port, secure};
	}


	//////////////////////////////////////////////////////////////////////////
	//! modeled after
	//! http://www.boost.org/doc/libs/1_47_0/doc/html/boost_asio/example/iostreams/http_client.cpp
	//! only work on http, NOT https
	void openHttpSocket(ip::tcp::iostream& s, const std::string& url)
	{
		logger::debug() << "openHttpSocket() to " << url;

		auto serverName   = getServerName(url);
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

	//------------------------------------------

	//////////////////////////////////////////////////////////////////////////

	bnet::Handle httpSendRequest(uint32_t _ip, uint16_t _port, const char* _request, bool secure)
	{
		bnet::Handle handle = bnet::connect(_ip, _port, true, secure);

		bnet::Message* out = bnet::alloc(handle, (uint16_t)strlen(_request));
		bx::memCopy(out->data, _request, out->size);
		bnet::send(out);
		bnet::notify(handle, UINT64_C(0x123456789ABCDEF));

		return handle;
	}

	//------------------------------------------

	bnet::Handle httpSendFileRequest(const std::string& url)
	{
		uint32_t ip;
		uint16_t port;
		bool	 secure;
		std::tie(ip, port, secure) = getServerIPPort(url);

		return httpSendRequest(ip, port, urlToHttpRequestHeader(url).c_str(), secure);
	}

	//------------------------------------------

	std::vector<uint8_t> openHttpFileBuffer(const std::string& url)
	{
		static bool once = true;
		if (once)
		{
			bnet::init(1, 0, nullptr);
			once = false;
		}

		auto handle = httpSendFileRequest(url);
		KHUTILS_ASSERT(bnet::isValid(handle));

		std::vector<uint8_t> buffer;

		bool cont = bnet::isValid(handle);
		while (cont)
		{
			bnet::Message* msg = bnet::recv();
			if (NULL != msg)
			{
				if (bnet::MessageId::UserDefined > msg->data[0])
				{
					switch (msg->data[0])
					{
						case bnet::MessageId::Notify:
						{
							khutils::logger::error() << "notify";
						}
						break;

						case bnet::MessageId::LostConnection:
						{
							cont = false;
							khutils::logger::error() << "lost connection";
						}
						break;

						case bnet::MessageId::ConnectFailed:
						{
							cont = false;
							khutils::logger::error() << "connection failed";
						}
						break;

						case bnet::MessageId::RawData:
						{
							uint8_t* start = &msg->data[1];
							uint8_t* end   = start + (msg->size - 1);
							std::copy(start, end, std::back_inserter(buffer));
						}
						break;
					}
				}
				bnet::release(msg);
			}
		}
		return buffer;
	}

	//////////////////////////////////////////////////////////////////////////

	std::stringstream openHttpFile_boost(const std::string& url)
	{
		ip::tcp::iostream s;
		openHttpSocket(s, url);

		// return response body
		std::stringstream ret;
		ret << s.rdbuf();
		return ret;
	}

	//------------------------------------------

	std::vector<uint8_t> openHttpFileBuffer_boost(const std::string& url)
	{
		ip::tcp::iostream s;
		openHttpSocket(s, url);

		// return response body
		std::vector<uint8_t> ret;
		while (s.good())
		{
			uint8_t c;
			s.read((char*)&c, 1);
			// logger::debug() << c;
			ret.push_back(c);
		}
		return ret;
	}

	//------------------------------------------


	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FILE_HTTP_IMPL)

#endif	// !KHUTILS_FILE_HTTP_HPP_INC
