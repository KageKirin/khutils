#ifndef KHUTILS_STREAMWRITER_HPP_INC
#define KHUTILS_STREAMWRITER_HPP_INC

#define KHUTILS_ASSERTION_INLINE

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/typeconversion.hpp"
#include "khutils/writerinterface.hpp"

#include <functional>
#include <ostream>
#include <vector>

namespace khutils
{
	class StreamWriterImplementation : public virtual WriterInterface
	{
	protected:
		std::ostream& m_os;

		StreamWriterImplementation()								  = delete;
		StreamWriterImplementation(const StreamWriterImplementation&) = default;
		StreamWriterImplementation(StreamWriterImplementation&&)	  = default;
		StreamWriterImplementation(std::ostream& os);

		StreamWriterImplementation& operator=(const StreamWriterImplementation&) = default;
		StreamWriterImplementation& operator=(StreamWriterImplementation&&) = default;

	public:
		virtual ~StreamWriterImplementation() = default;

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
	class _StreamWriter : public StreamWriterImplementation, public EndianWriterInterface<_order>
	{
	public:
		_StreamWriter()						= delete;
		_StreamWriter(const _StreamWriter&) = default;
		_StreamWriter(_StreamWriter&&)		= default;
		_StreamWriter(std::ostream& os)			//
			: StreamWriterImplementation(os)	//
			, EndianWriterInterface<_order>()
		{
		}
		~_StreamWriter() = default;

		_StreamWriter& operator=(const _StreamWriter&) = default;
		_StreamWriter& operator=(_StreamWriter&&) = default;

		//-- handler interface
		virtual size_t getCurrentOffset()
		{
			return StreamWriterImplementation::getCurrentOffset();
		}
		virtual void jumpToOffset(size_t pos)
		{
			StreamWriterImplementation::jumpToOffset(pos);
		}
		virtual void skip(size_t bytes)
		{
			StreamWriterImplementation::skip(bytes);
		}
		virtual bool isEnd()
		{
			return StreamWriterImplementation::isEnd();
		}

		//-- writer interface
		virtual void write(void* data, size_t size)
		{
			StreamWriterImplementation::write(data, size);
		}
	};

	//----------------------------

	using streamwriter				 = _StreamWriter<endian::native>;
	using little_endian_streamwriter = _StreamWriter<endian::order::little>;
	using big_endian_streamwriter	= _StreamWriter<endian::order::big>;

	struct streamwriter_trait
	{
		typedef streamwriter			   native_endian_writer;
		typedef little_endian_streamwriter little_endian_writer;
		typedef big_endian_streamwriter	big_endian_writer;
	};

}	// namespace khutils


#if defined(KHUTILS_STREAMWRITER_IMPL)

khutils::StreamWriterImplementation::StreamWriterImplementation(std::ostream& os)	//
	: m_os(os)
{
}

//----------------------------
//-- handler interface

size_t khutils::StreamWriterImplementation::getCurrentOffset()
{
	return m_os.tellp();
}

//----------------------------

void khutils::StreamWriterImplementation::jumpToOffset(size_t pos)
{
	m_os.seekp(pos);
}

//----------------------------

void khutils::StreamWriterImplementation::skip(size_t bytes)
{
	const char c = 0;
	for (size_t i = 0; i < bytes; ++i)
	{
		write((void*)&c, 1);
	}
}

//----------------------------

bool khutils::StreamWriterImplementation::isEnd()
{
	return m_os.eof();
}

//----------------------------
//-- writer interface

void khutils::StreamWriterImplementation::write(void* data, size_t size)
{
	m_os.write(reinterpret_cast<char*>(data), size);
}

#endif	// defined(KHUTILS_STREAMWRITER_IMPL)

#endif	// KHUTILS_STREAMWRITER_HPP_INC
