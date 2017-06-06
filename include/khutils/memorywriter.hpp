#ifndef KHUTILS_MEMORYWRITER_HPP_INC
#define KHUTILS_MEMORYWRITER_HPP_INC

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/file.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/typeconversion.hpp"
#include "khutils/writerinterface.hpp"

#include <functional>
#include <vector>

namespace khutils
{
	struct MemoryWriterStateInterface
	{
		//! writes n bytes and updates internal position
		//! @return int: 0 or negative: out of range; positive: ok
		virtual int write_bytes(void* data, size_t size) = 0;

		//! writes n bytes and DOES NOT update internal position
		//! @return int: 0 or negative: out of range; positive: ok
		virtual int put_bytes(void* data, size_t size) = 0;

		//! updates internal position
		//! @return int: 0 or negative: out of range; positive: ok
		virtual int set_position(size_t offset) = 0;

		//! returns current position
		virtual size_t get_position() = 0;

		//! return true if at end or beyond
		virtual bool is_end() = 0;
	};

	//----------------------------

	//! note: memory must be PRE-ALLOCATED
	//! NO RESIZING OCCURS
	template <typename ByteForwardIterator>
	struct BFI_MemoryWriterStateInterface : MemoryWriterStateInterface
	{
		const ByteForwardIterator begin;
		const ByteForwardIterator end;
		ByteForwardIterator		  current;
		static_assert(sizeof(decltype(*begin)) == sizeof(uint8_t), "wrong iterator type: not pointing to bytes");

		BFI_MemoryWriterStateInterface() = delete;
		BFI_MemoryWriterStateInterface(ByteForwardIterator alpha, ByteForwardIterator omega)
			: begin(alpha)	//
			, current(alpha)
			, end(omega)
		{
		}
		BFI_MemoryWriterStateInterface(const BFI_MemoryWriterStateInterface&) = default;
		BFI_MemoryWriterStateInterface(BFI_MemoryWriterStateInterface&&)	  = default;

		BFI_MemoryWriterStateInterface& operator=(const BFI_MemoryWriterStateInterface&) = default;
		BFI_MemoryWriterStateInterface& operator=(BFI_MemoryWriterStateInterface&&) = default;

		//- MemoryWriterStateInterface
		virtual int write_bytes(void* data, size_t size)
		{
			if (size < std::distance(current, end))
			{
				std::copy((char*)data, (char*)data + size, current);
				current += size;	// UPDATE current
				return size;
			}

			return (int32_t)std::distance(current, end) - (int32_t)size;
		}

		virtual int put_bytes(void* data, size_t size)
		{
			if (size < std::distance(current, end))
			{
				std::copy((char*)data, (char*)data + size, current);
				// DO NOT UPDATE current
				return size;
			}

			return (int32_t)std::distance(current, end) - (int32_t)size;
		}

		virtual int set_position(size_t offset)
		{
			if (offset <= std::distance(begin, end))
			{
				current = begin + offset;
				return offset;
			}

			return std::distance(begin, end) - offset;
		}

		virtual size_t get_position()
		{
			return std::distance(begin, current);
		}

		virtual bool is_end()
		{
			return std::distance(begin, end) <= std::distance(begin, current);
		}
	};

	template <typename ByteForwardIterator>
	std::shared_ptr<MemoryWriterStateInterface> make_bfi_writerstate(ByteForwardIterator alpha, ByteForwardIterator omega)
	{
		return std::shared_ptr<MemoryWriterStateInterface>{new BFI_MemoryWriterStateInterface<ByteForwardIterator>(alpha, omega)};
	}

	//----------------------------

	class MemoryWriterImplementation : public virtual WriterInterface
	{
	public:
		typedef std::shared_ptr<MemoryWriterStateInterface> State;

	protected:
		State m_state;

	protected:
		MemoryWriterImplementation()								  = delete;
		MemoryWriterImplementation(const MemoryWriterImplementation&) = default;
		MemoryWriterImplementation(MemoryWriterImplementation&&)	  = default;
		MemoryWriterImplementation(const State& state);
		MemoryWriterImplementation(State&& state);

		MemoryWriterImplementation& operator=(const MemoryWriterImplementation&) = default;
		MemoryWriterImplementation& operator=(MemoryWriterImplementation&&) = default;

	public:
		virtual ~MemoryWriterImplementation() = default;

		//-- handler interface
		virtual size_t getCurrentOffset();
		virtual void jumpToOffset(size_t pos);
		virtual void skip(size_t bytes);
		virtual bool isEnd();

		//-- writer interface
		virtual void write(void* data, size_t size);
		virtual void put(void* data, size_t size);
		virtual void writeAt(size_t offset, void* data, size_t size);
		virtual void putAt(size_t offset, void* data, size_t size);
	};

	//----------------------------

	template <endian::order _order>
	class _MemoryWriter : public MemoryWriterImplementation, public EndianWriterInterface<_order>
	{
	public:
		_MemoryWriter()						= delete;
		_MemoryWriter(const _MemoryWriter&) = default;
		_MemoryWriter(_MemoryWriter&&)		= default;
		_MemoryWriter(const State& state)		   //
			: MemoryWriterImplementation(state)	//
			, EndianWriterInterface<_order>()
		{
		}
		_MemoryWriter(State&& state)			   //
			: MemoryWriterImplementation(state)	//
			, EndianWriterInterface<_order>()
		{
		}
		virtual ~_MemoryWriter() = default;

		_MemoryWriter& operator=(const _MemoryWriter&) = default;
		_MemoryWriter& operator=(_MemoryWriter&&) = default;

		//-- handler interface
		virtual size_t getCurrentOffset()
		{
			return MemoryWriterImplementation::getCurrentOffset();
		}
		virtual void jumpToOffset(size_t pos)
		{
			MemoryWriterImplementation::jumpToOffset(pos);
		}
		virtual void skip(size_t bytes)
		{
			MemoryWriterImplementation::skip(bytes);
		}
		virtual bool isEnd()
		{
			return MemoryWriterImplementation::isEnd();
		}

		//-- writer interface
		virtual void write(void* data, size_t size)
		{
			MemoryWriterImplementation::write(data, size);
		}
		virtual void put(void* data, size_t size)
		{
			MemoryWriterImplementation::put(data, size);
		}
		virtual void writeAt(size_t offset, void* data, size_t size)
		{
			MemoryWriterImplementation::writeAt(offset, data, size);
		}
		virtual void putAt(size_t offset, void* data, size_t size)
		{
			MemoryWriterImplementation::putAt(offset, data, size);
		}
	};

	//----------------------------

	using memorywriter				 = _MemoryWriter<endian::native>;
	using little_endian_memorywriter = _MemoryWriter<endian::order::little>;
	using big_endian_memorywriter	= _MemoryWriter<endian::order::big>;

	struct memorywriter_trait
	{
		typedef memorywriter			   native_endian_writer;
		typedef little_endian_memorywriter little_endian_writer;
		typedef big_endian_memorywriter	big_endian_writer;
	};

}	// namespace khutils

#if defined(KHUTILS_MEMORYWRITER_IMPL)

khutils::MemoryWriterImplementation::MemoryWriterImplementation(const State& state)	//
	: m_state(state)
{
	KHUTILS_ASSERT_PTR(state);
	KHUTILS_ASSERT_PTR(m_state);
}

//----------------------------
khutils::MemoryWriterImplementation::MemoryWriterImplementation(State&& state)	//
	: m_state(state)
{
	KHUTILS_ASSERT_PTR(state);
	KHUTILS_ASSERT_PTR(m_state);
}

//----------------------------
//-- handler interface

size_t khutils::MemoryWriterImplementation::getCurrentOffset()
{
	KHUTILS_ASSERT_PTR(m_state);
	return m_state->get_position();
}

//----------------------------

void khutils::MemoryWriterImplementation::jumpToOffset(size_t pos)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->set_position(pos);
	KHUTILS_ASSERT(r > 0);
}

//----------------------------

void khutils::MemoryWriterImplementation::skip(size_t bytes)
{
	KHUTILS_ASSERT_PTR(m_state);
	jumpToOffset(m_state->get_position() + bytes);
}

//----------------------------

bool khutils::MemoryWriterImplementation::isEnd()
{
	KHUTILS_ASSERT_PTR(m_state);
	return m_state->is_end();
}

//----------------------------
//-- writer interface

void khutils::MemoryWriterImplementation::write(void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->write_bytes(data, size);
	KHUTILS_ASSERT(r > 0);
}

//----------------------------

void khutils::MemoryWriterImplementation::put(void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->put_bytes(data, size);
	KHUTILS_ASSERT(r > 0);
}

//----------------------------

void khutils::MemoryWriterImplementation::writeAt(size_t offset, void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->set_position(offset);
	KHUTILS_ASSERT(r > 0);
	write(data, size);
}

//----------------------------

void khutils::MemoryWriterImplementation::putAt(size_t offset, void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto pos = m_state->get_position();
	auto r   = m_state->set_position(offset);
	KHUTILS_ASSERT(r > 0);
	put(data, size);
	r = m_state->set_position(pos);
	KHUTILS_ASSERT(r > 0);
}

#endif	// defined(KHUTILS_MEMORYWRITER_IMPL)

#endif	// KHUTILS_MEMORYWRITER_HPP_INC
