#ifndef KHUTILS_FILEREADER_HPP_INC
#define KHUTILS_FILEREADER_HPP_INC

#define KHUTILS_ASSERTION_INLINE

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/file.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/readerinterface.hpp"
#include "khutils/typeconversion.hpp"

#include <cstdio>
#include <functional>
#include <memory>
#include <vector>

namespace khutils
{
	class FileReaderImplementation : public virtual ReaderInterface
	{
	protected:
		std::reference_wrapper<const FilePtr> m_file;

		FileReaderImplementation()								  = delete;
		FileReaderImplementation(const FileReaderImplementation&) = default;
		FileReaderImplementation(FileReaderImplementation&&)	  = default;
		FileReaderImplementation(const FilePtr& file);
		FileReaderImplementation(std::reference_wrapper<const FilePtr>&& file);
		FileReaderImplementation(const std::reference_wrapper<const FilePtr>& file);

		FileReaderImplementation& operator=(const FileReaderImplementation&) = default;
		FileReaderImplementation& operator=(FileReaderImplementation&&) = default;

	public:
		virtual ~FileReaderImplementation() = default;

		//-- handler interface
		virtual size_t getCurrentOffset();
		virtual void jumpToOffset(size_t pos);
		virtual void skip(size_t bytes);
		virtual bool isEnd();

		//-- reader interface
		virtual void read(void* data, size_t size);
	};

	//----------------------------

	template <endian::order _order>
	class _FileReader : public FileReaderImplementation, public EndianReaderInterface<_order>
	{
	public:
		_FileReader()					= delete;
		_FileReader(const _FileReader&) = default;
		_FileReader(_FileReader&&)		= default;
		_FileReader(const FilePtr& file)		//
			: FileReaderImplementation(file)	//
			, EndianReaderInterface<_order>()
		{
		}
		_FileReader(std::reference_wrapper<const FilePtr>&& file)	//
			: FileReaderImplementation(file)						 //
			, EndianReaderInterface<_order>()
		{
		}
		_FileReader(const std::reference_wrapper<const FilePtr>& file)	//
			: FileReaderImplementation(file)							  //
			, EndianReaderInterface<_order>()
		{
		}
		virtual ~_FileReader() = default;

		_FileReader& operator=(const _FileReader&) = default;
		_FileReader& operator=(_FileReader&&) = default;

		//-- handler interface
		virtual size_t getCurrentOffset()
		{
			return FileReaderImplementation::getCurrentOffset();
		}
		virtual void jumpToOffset(size_t pos)
		{
			FileReaderImplementation::jumpToOffset(pos);
		}
		virtual void skip(size_t bytes)
		{
			FileReaderImplementation::skip(bytes);
		}
		virtual bool isEnd()
		{
			return FileReaderImplementation::isEnd();
		}

		//-- reader interface
		virtual void read(void* data, size_t size)
		{
			FileReaderImplementation::read(data, size);
		}
	};

	//----------------------------

	using filereader			   = _FileReader<endian::native>;
	using little_endian_filereader = _FileReader<endian::order::little>;
	using big_endian_filereader	= _FileReader<endian::order::big>;

	struct filereader_trait
	{
		typedef filereader				 native_endian_reader;
		typedef little_endian_filereader little_endian_reader;
		typedef big_endian_filereader	big_endian_reader;
	};

}	// namespace khutils


#if defined(KHUTILS_FILEREADER_IMPL)

khutils::FileReaderImplementation::FileReaderImplementation(const FilePtr& file)	//
	: m_file(file)
{
}

//----------------------------

khutils::FileReaderImplementation::FileReaderImplementation(std::reference_wrapper<const FilePtr>&& file)	//
	: m_file(file)
{
}

//----------------------------

khutils::FileReaderImplementation::FileReaderImplementation(const std::reference_wrapper<const FilePtr>& file)	//
	: m_file(file)
{
}

//----------------------------
//-- handler interface

size_t khutils::FileReaderImplementation::getCurrentOffset()
{
	return ftell(m_file.get().get());
}

//----------------------------

void khutils::FileReaderImplementation::jumpToOffset(size_t pos)
{
	fseek(m_file.get().get(), pos, SEEK_SET);
}

//----------------------------

void khutils::FileReaderImplementation::skip(size_t bytes)
{
	auto curPos = getCurrentOffset();
	jumpToOffset(curPos + bytes);
}

//----------------------------

bool khutils::FileReaderImplementation::isEnd()
{
	return feof(m_file.get().get());
}

//----------------------------
//-- reader interface

void khutils::FileReaderImplementation::read(void* data, size_t size)
{
	fread(data, sizeof(char), size, m_file.get().get());
}

#endif	// defined(KHUTILS_FILEREADER_IMPL)


#endif	// KHUTILS_FILEREADER_HPP_INC
