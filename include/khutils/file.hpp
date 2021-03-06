#ifndef KHUTILS_FILE_HPP_INC
#define KHUTILS_FILE_HPP_INC

#include <cctype>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace khutils
{
	typedef std::unique_ptr<FILE, decltype(&std::fclose)> FilePtr;
	FilePtr openLocalFilePtr(const std::string& filename, const char* mode);
	FilePtr openTempFilePtr();

	std::ifstream openLocalFile(const std::string& filename);
	std::vector<uint8_t> openLocalFileBuffer(const std::string& filename);

	std::stringstream openHttpFile(const std::string& url);
	std::vector<uint8_t> openHttpFileBuffer(const std::string& url);

	std::ofstream openOutputFile(const std::string& filename);
	void dumpBufferToLocalFile(const std::vector<uint8_t>& databuffer, const std::string& filename);
	void dumpBufferToLocalFile(const uint8_t* data, size_t length, const std::string& filename);

	std::vector<uint8_t> openBufferFromStream(std::istream& ins);
	std::vector<uint8_t> openBufferFromStreamProgressive(std::istream& ins);
	void dumpBufferToStream(const std::vector<uint8_t>& databuffer, std::ostream& outs);
	void dumpBufferToStream(const uint8_t* data, size_t length, std::ostream& outs);

	std::vector<uint8_t> openBufferFromFile(const FilePtr& file);
	std::vector<uint8_t> openBufferFromFile(FILE* file);
	std::vector<uint8_t> openBufferFromFileProgressive(const FilePtr& file);
	std::vector<uint8_t> openBufferFromFileProgressive(FILE* file);
	void dumpBufferToFile(const std::vector<uint8_t>& databuffer, const FilePtr& file);
	void dumpBufferToFile(const uint8_t* data, size_t length, const FilePtr& file);

}	// namespace khutils

#if defined(KHUTILS_FILE_IMPL)

#include "khutils/logging.hpp"
#include "khutils/runtime_exceptions.hpp"

#include <boost/filesystem/path.hpp>

#include <fstream>

namespace khutils
{
	//--------------------------------

	FilePtr openTempFilePtr()
	{
		return FilePtr{std::tmpfile(), std::fclose};
	}

	//--------------------------------

	FilePtr openLocalFilePtr(const std::string& filename, const char* mode)
	{
		return FilePtr{std::fopen(filename.c_str(), mode), std::fclose};
	}

	//--------------------------------

	std::ifstream openLocalFile(const std::string& filename)
	{
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

	//--------------------------------

	std::vector<uint8_t> openLocalFileBuffer(const std::string& filename)
	{
		auto ifs = openLocalFile(filename);
		return openBufferFromStream(ifs);
	}

	//--------------------------------

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

	//--------------------------------

	std::vector<uint8_t> openBufferFromStream(std::istream& ins)
	{
		KHUTILS_ASSERT((bool)ins);
		ins.seekg(0, ins.end);
		size_t length = ins.tellg();
		ins.seekg(0, ins.beg);

		std::vector<uint8_t> databuffer(length);
		ins.read(reinterpret_cast<char*>(&databuffer[0]), length);
		return databuffer;
	}

	//--------------------------------

	std::vector<uint8_t> openBufferFromFile(const FilePtr& file)
	{
		KHUTILS_ASSERT_PTR(file);
		return openBufferFromFile(file.get());
	}

	std::vector<uint8_t> openBufferFromFile(FILE* file)
	{
		KHUTILS_ASSERT_PTR(file);
		fseek(file, 0, SEEK_END);
		size_t length = ftell(file);
		rewind(file);

		std::vector<uint8_t> databuffer(length);
		fread(reinterpret_cast<char*>(&databuffer[0]), length, 1, file);
		return databuffer;
	}

	//--------------------------------

	std::vector<uint8_t> openBufferFromStreamProgressive(std::istream& ins)
	{
		std::vector<uint8_t> databuffer;
		auto				 bi = std::back_inserter(databuffer);
		while (ins)
		{
			ins.read(reinterpret_cast<char*>(&*bi), 1);
			++bi;
		}
		return databuffer;
	}

	//--------------------------------

	std::vector<uint8_t> openBufferFromFileProgressive(const FilePtr& file)
	{
		KHUTILS_ASSERT_PTR(file);
		return openBufferFromFileProgressive(file.get());
	}

	std::vector<uint8_t> openBufferFromFileProgressive(FILE* file)
	{
		std::vector<uint8_t> databuffer;
		auto				 bi = std::back_inserter(databuffer);
		while (!feof(file))
		{
			fread(reinterpret_cast<char*>(&*bi), 1, 1, file);
			++bi;
		}
		return databuffer;
	}

	//--------------------------------

	void dumpBufferToLocalFile(const std::vector<uint8_t>& databuffer, const std::string& filename)
	{
		dumpBufferToLocalFile(databuffer.data(), databuffer.size(), filename);
	}

	void dumpBufferToLocalFile(const uint8_t* data, size_t length, const std::string& filename)
	{
		auto ofs = openOutputFile(filename);
		dumpBufferToStream(data, length, ofs);
	}

	//--------------------------------

	void dumpBufferToStream(const std::vector<uint8_t>& databuffer, std::ostream& outs)
	{
		dumpBufferToStream(databuffer.data(), databuffer.size(), outs);
	}

	void dumpBufferToStream(const uint8_t* data, size_t length, std::ostream& outs)
	{
		KHUTILS_ASSERT((bool)outs);
		outs.write((char*)data, length);
	}

	//--------------------------------

	void dumpBufferToFile(const std::vector<uint8_t>& databuffer, const FilePtr& file)
	{
		dumpBufferToFile(databuffer.data(), databuffer.size(), file);
	}

	void dumpBufferToFile(const uint8_t* data, size_t length, const FilePtr& file)
	{
		KHUTILS_ASSERT_PTR(file);
		std::fwrite((char*)data, length, 1, file.get());
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FILE_IMPL)

#endif	// !KHUTILS_FILE_HPP_INC
