#ifndef KHUTILS_STREAMREADER_HPP_INC
#define KHUTILS_STREAMREADER_HPP_INC

#define KHUTILS_ASSERTION_INLINE

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/readerinterface.hpp"
#include "khutils/typeconversion.hpp"

#include <functional>
#include <istream>
#include <vector>

namespace khutils
{
	class StreamReaderImplementation : public virtual ReaderInterface
	{
	protected:
		std::istream& m_is;

		StreamReaderImplementation()								  = delete;
		StreamReaderImplementation(const StreamReaderImplementation&) = default;
		StreamReaderImplementation(StreamReaderImplementation&&)	  = default;
		StreamReaderImplementation(std::istream& is);

		StreamReaderImplementation& operator=(const StreamReaderImplementation&) = default;
		StreamReaderImplementation& operator=(StreamReaderImplementation&&) = default;

	public:
		virtual ~StreamReaderImplementation() = default;

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
	class _StreamReader : public StreamReaderImplementation, public EndianReaderInterface<_order>
	{
	public:
		_StreamReader()						= delete;
		_StreamReader(const _StreamReader&) = default;
		_StreamReader(_StreamReader&&)		= default;
		_StreamReader(std::istream& is)			//
			: StreamReaderImplementation(is)	//
			, EndianReaderInterface<_order>()
		{
		}
		virtual ~_StreamReader() = default;

		_StreamReader& operator=(const _StreamReader&) = default;
		_StreamReader& operator=(_StreamReader&&) = default;

		//-- handler interface
		virtual size_t getCurrentOffset()
		{
			return StreamReaderImplementation::getCurrentOffset();
		}
		virtual void jumpToOffset(size_t pos)
		{
			StreamReaderImplementation::jumpToOffset(pos);
		}
		virtual void skip(size_t bytes)
		{
			StreamReaderImplementation::skip(bytes);
		}
		virtual bool isEnd()
		{
			return StreamReaderImplementation::isEnd();
		}

		//-- reader interface
		virtual void read(void* data, size_t size)
		{
			StreamReaderImplementation::read(data, size);
		}
	};

	//----------------------------

	using streamreader				 = _StreamReader<endian::native>;
	using little_endian_streamreader = _StreamReader<endian::order::little>;
	using big_endian_streamreader	= _StreamReader<endian::order::big>;

	struct streamreader_trait
	{
		typedef streamreader			   native_endian_reader;
		typedef little_endian_streamreader little_endian_reader;
		typedef big_endian_streamreader	big_endian_reader;
	};

}	// namespace khutils


#if defined(KHUTILS_STREAMREADER_IMPL)

khutils::StreamReaderImplementation::StreamReaderImplementation(std::istream& is)	//
	: m_is(is)
{
}

//----------------------------
//-- handler interface

size_t khutils::StreamReaderImplementation::getCurrentOffset()
{
	return m_is.tellg();
}

//----------------------------

void khutils::StreamReaderImplementation::jumpToOffset(size_t pos)
{
	m_is.seekg(pos);
}

//----------------------------

void khutils::StreamReaderImplementation::skip(size_t bytes)
{
	m_is.ignore(bytes);
}

//----------------------------

bool khutils::StreamReaderImplementation::isEnd()
{
	return m_is.eof();
}

//----------------------------
//-- reader interface

void khutils::StreamReaderImplementation::read(void* data, size_t size)
{
	m_is.read(reinterpret_cast<char*>(data), size);
}

#endif	// defined(KHUTILS_STREAMREADER_IMPL)


#endif	// KHUTILS_STREAMREADER_HPP_INC
