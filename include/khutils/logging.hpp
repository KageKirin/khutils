#ifndef KHUTILS_LOGGING_HPP_INC
#define KHUTILS_LOGGING_HPP_INC

#include <ostream>

namespace khutils
{
	struct logger
	{
		static std::ostream& log();
		static std::ostream& warn();
		static std::ostream& error();
		static std::ostream& debug();
	};

}	// namespace khutils

#if defined(KHUTILS_LOGGING_IMPL)


#include <iostream>

// clang-format off

std::ostream& khutils::logger::log()
{
	std::clog << u8"\U0001F604 "
			  << "Log: ";
	return std::clog;
}

std::ostream& khutils::logger::warn()
{
	std::clog << u8"\U000026A0 "
			  << u8"\U0001F914 "
			  << "Warning: ";
	return std::clog;
}

std::ostream& khutils::logger::error()
{
	std::clog << u8"\U00002622 "
			  << u8"\U0001F631 "
			  << "Error: ";
	return std::clog;
}

std::ostream& khutils::logger::debug()
{
	std::clog << u8"\U0001F37A "
			  << "Debug: ";
	return std::clog;
}

// '\u1F4A9' to be used as well

// clang-format on

#endif	// defined (KHUTILS_LOGGING_IMPL)

#endif	// !KHUTILS_LOGGING_HPP_INC
