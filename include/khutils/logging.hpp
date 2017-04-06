#ifndef KHUTILS_LOGGING_HPP_INC
#define KHUTILS_LOGGING_HPP_INC

#include <ostream>

namespace khutils
{
	struct logger
	{
		static std::ostream& null();
		static std::ostream& info();
		static std::ostream& log();
		static std::ostream& warn();
		static std::ostream& file();
		static std::ostream& file2();
		static std::ostream& csv();
		static std::ostream& csv2();
		static std::ostream& error();
		static std::ostream& debug();
		static std::ostream& big_fat_warning();
		static std::ostream& big_fat_error();
		static std::ostream& highlight();

		// overload template for specific classes
		template <typename _T>
		static std::ostream& debug_t()
		{
			return null();
		}

		// overload template for specific values
		template <int		 _I>
		static std::ostream& debug_i()
		{
			return null();
		}
	};

}	// namespace khutils

#if defined(KHUTILS_LOGGING_IMPL)

#include <fstream>
#include <iostream>
#include <string>

#if defined(KHUTILS_COLOR_LOG)
#include <rang.hpp>
#define LOG_COLOR_OK << rang::fg::green
#define LOG_COLOR_WARNING << rang::fg::yellow
#define LOG_COLOR_ERROR << rang::fg::red
#define LOG_COLOR_FAT_WARNING << rang::bg::yellow << rang::fg::gray << rang::style::bold
#define LOG_COLOR_FAT_ERROR << rang::bg::red << rang::fg::gray << rang::style::bold << rang::style::blink
#define LOG_COLOR_HIGHLIGHT << rang::fg::yellow << rang::style::italic
#define LOG_COLOR_RESET << rang::style::reset
#else
#define LOG_COLOR_OK
#define LOG_COLOR_WARNING
#define LOG_COLOR_ERROR
#define LOG_COLOR_FAT_WARNING
#define LOG_COLOR_FAT_ERROR
#define LOG_COLOR_HIGHLIGHT
#define LOG_COLOR_RESET
#endif	// defined(KHUTILS_COLOR_LOG)

// clang-format off
std::ostream&  khutils::logger::null()
{
	static std::ofstream ofs;
	return ofs;
}

std::ostream& khutils::logger::log()
{
	std::clog << std::endl
			  << u8"\U0001F604 "
			  LOG_COLOR_OK
			  << "Log: "
			  LOG_COLOR_RESET
			  ;
	return std::clog;
}

std::ostream& khutils::logger::info()
{
	std::cout << std::endl;
	return std::cout;
}

std::ostream& khutils::logger::file()
{
	static std::ofstream ofs("log.txt", std::ios_base::trunc);
	ofs << std::endl;
	return ofs;
}

std::ostream& khutils::logger::file2()
{
	static std::ofstream ofs("log2.txt", std::ios_base::trunc);
	ofs << std::endl;
	return ofs;
}

std::ostream& khutils::logger::csv()
{
	static std::ofstream ofs("data.csv", std::ios_base::trunc);
	ofs << std::endl;
	return ofs;
}

std::ostream& khutils::logger::csv2()
{
	static std::ofstream ofs("data2.csv", std::ios_base::trunc);
	ofs << std::endl;
	return ofs;
}

std::ostream& khutils::logger::warn()
{
	std::clog << std::endl
			  << u8"\U000026A0 "
			  << u8"\U0001F914 "
			  LOG_COLOR_WARNING
			  << "Warning: "
			  LOG_COLOR_RESET
			  ;
	return std::clog;
}

std::ostream& khutils::logger::error()
{
	std::clog << std::endl
			  << u8"\U00002622 "
			  << u8"\U0001F631 "
			  LOG_COLOR_ERROR
			  << "Error: "
  			  LOG_COLOR_RESET
				;
	return std::clog;
}

std::ostream& khutils::logger::debug()
{
	std::clog << std::endl
			  << u8"\U0001F37A "
			  << "Debug: ";
	return std::clog;
}


struct floodfill
{
	std::string s;
	size_t amount;
};

std::ostream& operator<<(std::ostream& os, const floodfill& f)
{
	for(size_t i = 0; i < f.amount; ++i)
	{
		os << f.s;
	}
	return os;
}


std::ostream& khutils::logger::big_fat_warning()
{
	std::clog << std::endl
		LOG_COLOR_FAT_WARNING
		<< floodfill{"*", 80} << std::endl	//std::string(80, '*')
		<< floodfill{"*", 80} << std::endl
		<< "** THIS IS A WARNING **" << std::endl << std::endl
		<< "** an unexpected situation has occurred **" << std::endl
		<< "** this is bad **" << std::endl
		LOG_COLOR_RESET
		<< std::endl;

	return std::clog;
}

std::ostream& khutils::logger::big_fat_error()
{
	std::clog << std::endl
		LOG_COLOR_FAT_ERROR
		<< floodfill{u8"\U0001F4A9", 40} << std::endl
		<< floodfill{u8"\U0001F4A9", 40} << std::endl
		<< "xx THIS IS AN ERROR xx" << std::endl << std::endl
		<< "xx an unexpected error has occurred xx" << std::endl
		<< "xx this is beyond bad xx" << std::endl
		LOG_COLOR_RESET
		<< std::endl;

	return std::clog;
}

std::ostream& khutils::logger::highlight()
{
	std::clog << std::endl LOG_COLOR_RESET LOG_COLOR_HIGHLIGHT;
	return std::clog;
}

// '\u1F4A9' to be used as well

// clang-format on

#endif	// defined (KHUTILS_LOGGING_IMPL)

#endif	// !KHUTILS_LOGGING_HPP_INC
