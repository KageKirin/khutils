#ifndef KHUTILS_FILE_HPP_INC﻿
#define KHUTILS_FILE_HPP_INC﻿

#include <cctype>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include <string>
#include <vector>

namespace khutils
{
	std::ifstream openLocalFile(const std::string& filename);
	std::vector<uint8_t> openLocalFileBuffer(const std::string& filename);

	std::stringstream openHttpFile(const std::string& url);
	std::vector<uint8_t> openHttpFileBuffer(const std::string& url);

	std::ofstream openOutputFile(const std::string& filename);

}	// namespace khutils

#if defined(KHUTILS_FILE_IMPL)

#include "khutils/logging.hpp"
#include "khutils/runtime_exceptions.hpp"

#include <boost/filesystem/path.hpp>

#include <fstream>

namespace khutils
{
	std::ifstream openLocalFile(const std::string& filename)
	{
		using boost::filesystem::path;

		std::ifstream ifs(filename);
		if (!ifs)
		{
			khutils::logger::error() << "Failed to open " << filename << std::endl;
			static std::string errorMsg;
			errorMsg = "Could not open " + filename;
			throw FatalImportException(errorMsg);
		}

		return ifs;
	}

	std::vector<uint8_t> openLocalFileBuffer(const std::string& filename)
	{
		using boost::filesystem::path;

		std::ifstream ifs(filename);
		if (!ifs)
		{
			khutils::logger::error() << "Failed to open " << filename << std::endl;
			static std::string errorMsg;
			errorMsg = "Could not open " + filename;
			throw FatalImportException(errorMsg);
		}

		std::vector<uint8_t> ret;
		while (ifs.good())
		{
			uint8_t c;
			ifs.read((char*)&c, 1);
			ret.push_back(c);
		}
		return ret;
	}

	std::ofstream openOutputFile(const std::string& filename)
	{
		std::ofstream ofs(filename);
		if (!ofs)
		{
			khutils::logger::error() << "Failed to open " << filename << std::endl;
			static std::string errorMsg;
			errorMsg = "Could not open " + filename;
			throw FatalExportException(errorMsg);
		}

		return ofs;
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FILE_IMPL)

#endif	// !KHUTILS_FILE_HPP_INC
