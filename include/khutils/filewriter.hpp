#ifndef KHUTILS_FILEWRITER_HPP_INC
#define KHUTILS_FILEWRITER_HPP_INC

#define KHUTILS_ASSERTION_INLINE

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/file.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/typeconversion.hpp"
#include "khutils/writerinterface.hpp"

#include <cstdio>
#include <functional>
#include <memory>
#include <vector>

namespace khutils
{
	class FileWriterImplementation : public virtual WriterInterface
	{
	protected:
		std::reference_wrapper<const FilePtr> m_file;

		FileWriterImplementation()								  = delete;
		FileWriterImplementation(const FileWriterImplementation&) = default;
		FileWriterImplementation(FileWriterImplementation&&)	  = default;
		FileWriterImplementation(const FilePtr& file);
		FileWriterImplementation(std::reference_wrapper<const FilePtr>&& file);
		FileWriterImplementation(const std::reference_wrapper<const FilePtr>& file);

		FileWriterImplementation& operator=(const FileWriterImplementation&) = default;
		FileWriterImplementation& operator=(FileWriterImplementation&&) = default;

	public:
		virtual ~FileWriterImplementation() = default;

		//-- handler interface
		virtual size_t getCurrentOffset();
		virtual void jumpToOffset(size_t pos);
		virtual void skip(size_t bytes);
		virtual bool isEnd();

		//-- writer interface
		virtual void write(void* data, size_t size);
	};

	//----------------------------

	template <endian::order _order>
	class _FileWriter : public FileWriterImplementation, public EndianWriterInterface<_order>
	{
	public:
		_FileWriter()					= delete;
		_FileWriter(const _FileWriter&) = default;
		_FileWriter(_FileWriter&&)		= default;
		_FileWriter(const FilePtr& file)		//
			: FileWriterImplementation(file)	//
			, EndianWriterInterface<_order>()
		{
		}
		_FileWriter(std::reference_wrapper<const FilePtr>&& file)	//
			: FileWriterImplementation(file)						 //
			, EndianWriterInterface<_order>()
		{
		}
		_FileWriter(const std::reference_wrapper<const FilePtr>& file)	//
			: FileWriterImplementation(file)							  //
			, EndianWriterInterface<_order>()
		{
		}
		virtual ~_FileWriter() = default;

		_FileWriter& operator=(const _FileWriter&) = default;
		_FileWriter& operator=(_FileWriter&&) = default;

		//-- handler interface
		virtual size_t getCurrentOffset()
		{
			return FileWriterImplementation::getCurrentOffset();
		}
		virtual void jumpToOffset(size_t pos)
		{
			FileWriterImplementation::jumpToOffset(pos);
		}
		virtual void skip(size_t bytes)
		{
			FileWriterImplementation::skip(bytes);
		}
		virtual bool isEnd()
		{
			return FileWriterImplementation::isEnd();
		}

		//-- writer interface
		virtual void write(void* data, size_t size)
		{
			FileWriterImplementation::write(data, size);
		}
	};

	//----------------------------

	using filewriter			   = _FileWriter<endian::native>;
	using little_endian_filewriter = _FileWriter<endian::order::little>;
	using big_endian_filewriter	= _FileWriter<endian::order::big>;

	struct filewriter_trait
	{
		typedef filewriter				 native_endian_writer;
		typedef little_endian_filewriter little_endian_writer;
		typedef big_endian_filewriter	big_endian_writer;
	};

}	// namespace khutils

#if defined(KHUTILS_FILEWRITER_IMPL)

khutils::FileWriterImplementation::FileWriterImplementation(const FilePtr& file)	//
	: m_file(file)
{
}

//----------------------------

khutils::FileWriterImplementation::FileWriterImplementation(std::reference_wrapper<const FilePtr>&& file)	//
	: m_file(file)
{
}

//----------------------------

khutils::FileWriterImplementation::FileWriterImplementation(const std::reference_wrapper<const FilePtr>& file)	//
	: m_file(file)
{
}

//----------------------------
//-- handler interface

size_t khutils::FileWriterImplementation::getCurrentOffset()
{
	return ftell(m_file.get().get());
}

//----------------------------

void khutils::FileWriterImplementation::jumpToOffset(size_t pos)
{
	fseek(m_file.get().get(), pos, SEEK_SET);
}

//----------------------------

void khutils::FileWriterImplementation::skip(size_t bytes)
{
	auto curPos = getCurrentOffset();
	jumpToOffset(curPos + bytes);
}

//----------------------------

bool khutils::FileWriterImplementation::isEnd()
{
	return feof(m_file.get().get());
}

//----------------------------
//-- writer interface

void khutils::FileWriterImplementation::write(void* data, size_t size)
{
	fwrite(data, sizeof(char), size, m_file.get().get());
}

#endif	// defined(KHUTILS_FILEWRITER_IMPL)


#endif	// KHUTILS_FILEWRITER_HPP_INC
