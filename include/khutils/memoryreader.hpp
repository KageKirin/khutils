#ifndef KHUTILS_MEMORYREADER_HPP_INC
#define KHUTILS_MEMORYREADER_HPP_INC

#define KHUTILS_ASSERTION_INLINE

#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/readerinterface.hpp"
#include "khutils/typeconversion.hpp"

#include <functional>
#include <vector>

namespace khutils
{
	struct MemoryReaderStateInterface
	{
		//! reads n bytes and updates internal position
		//! @return int: 0 or negative: out of range; positive: ok
		virtual int read_bytes(void* data, size_t size) = 0;

		//! reads n bytes and DOES NOT update internal position
		//! @return int: 0 or negative: out of range; positive: ok
		virtual int fetch_bytes(void* data, size_t size) = 0;

		//! updates internal position
		//! @return int: 0 or negative: out of range; positive: ok
		virtual int set_position(size_t offset) = 0;

		//! returns current position
		virtual size_t get_position() = 0;

		//! return true if at end or beyond
		virtual bool is_end() = 0;
	};

	//----------------------------

	template <typename ByteForwardIterator>
	struct BFI_MemoryReaderStateInterface : MemoryReaderStateInterface
	{
		const ByteForwardIterator begin;
		const ByteForwardIterator end;
		ByteForwardIterator		  current;
		// static_assert(sizeof(decltype(*begin)) == sizeof(uint8_t), "wrong iterator type: not pointing to bytes");

		BFI_MemoryReaderStateInterface() = delete;
		BFI_MemoryReaderStateInterface(ByteForwardIterator alpha, ByteForwardIterator omega)
			: begin(alpha)	//
			, current(alpha)
			, end(omega)
		{
		}
		BFI_MemoryReaderStateInterface(const BFI_MemoryReaderStateInterface&) = default;
		BFI_MemoryReaderStateInterface(BFI_MemoryReaderStateInterface&&)	  = default;

		BFI_MemoryReaderStateInterface& operator=(const BFI_MemoryReaderStateInterface&) = default;
		BFI_MemoryReaderStateInterface& operator=(BFI_MemoryReaderStateInterface&&) = default;

		//- MemoryReaderStateInterface
		virtual int read_bytes(void* data, size_t size)
		{
			if (size < std::distance(current, end))
			{
				std::copy(current, current + size, (char*)data);
				current += size;	// UPDATE current
				return size;
			}

			return (int32_t)std::distance(current, end) - (int32_t)size;
		}

		virtual int fetch_bytes(void* data, size_t size)
		{
			if (size < std::distance(current, end))
			{
				std::copy(current, current + size, (char*)data);
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
	std::shared_ptr<MemoryReaderStateInterface> make_bfi_readerstate(ByteForwardIterator alpha, ByteForwardIterator omega)
	{
		return std::shared_ptr<MemoryReaderStateInterface>{new BFI_MemoryReaderStateInterface<ByteForwardIterator>(alpha, omega)};
	}

	//----------------------------

	class MemoryReaderImplementation : public virtual ReaderInterface
	{
	public:
		typedef std::shared_ptr<MemoryReaderStateInterface> State;

	protected:
		State m_state;

	protected:
		MemoryReaderImplementation()								  = delete;
		MemoryReaderImplementation(const MemoryReaderImplementation&) = default;
		MemoryReaderImplementation(MemoryReaderImplementation&&)	  = default;
		MemoryReaderImplementation(const State& state);
		MemoryReaderImplementation(State&& state);

		MemoryReaderImplementation& operator=(const MemoryReaderImplementation&) = default;
		MemoryReaderImplementation& operator=(MemoryReaderImplementation&&) = default;

	public:
		virtual ~MemoryReaderImplementation() = default;

		//-- handler interface
		virtual size_t getCurrentOffset();
		virtual void   jumpToOffset(size_t pos);
		virtual void   skip(size_t bytes);
		virtual bool   isEnd();

		//-- reader interface
		virtual void read(void* data, size_t size);
		virtual void fetch(void* data, size_t size);
		virtual void readAt(size_t offset, void* data, size_t size);
		virtual void fetchAt(size_t offset, void* data, size_t size);
	};

	//----------------------------

	template <endian::order _order>
	class _MemoryReader : public MemoryReaderImplementation, public EndianReaderInterface<_order>
	{
	public:
		_MemoryReader()						= delete;
		_MemoryReader(const _MemoryReader&) = default;
		_MemoryReader(_MemoryReader&&)		= default;
		_MemoryReader(const State& state)		   //
			: MemoryReaderImplementation(state)	//
			, EndianReaderInterface<_order>()
		{
		}
		_MemoryReader(State&& state)			   //
			: MemoryReaderImplementation(state)	//
			, EndianReaderInterface<_order>()
		{
		}
		virtual ~_MemoryReader() = default;

		_MemoryReader& operator=(const _MemoryReader&) = default;
		_MemoryReader& operator=(_MemoryReader&&) = default;

		//-- handler interface
		virtual size_t getCurrentOffset()
		{
			return MemoryReaderImplementation::getCurrentOffset();
		}
		virtual void jumpToOffset(size_t pos)
		{
			MemoryReaderImplementation::jumpToOffset(pos);
		}
		virtual void skip(size_t bytes)
		{
			MemoryReaderImplementation::skip(bytes);
		}
		virtual bool isEnd()
		{
			return MemoryReaderImplementation::isEnd();
		}

		//-- reader interface
		virtual void read(void* data, size_t size)
		{
			MemoryReaderImplementation::read(data, size);
		}
		virtual void fetch(void* data, size_t size)
		{
			MemoryReaderImplementation::fetch(data, size);
		}
		virtual void readAt(size_t offset, void* data, size_t size)
		{
			MemoryReaderImplementation::readAt(offset, data, size);
		}
		virtual void fetchAt(size_t offset, void* data, size_t size)
		{
			MemoryReaderImplementation::fetchAt(offset, data, size);
		}
	};

	//----------------------------

	using memoryreader				 = _MemoryReader<endian::native>;
	using little_endian_memoryreader = _MemoryReader<endian::order::little>;
	using big_endian_memoryreader	= _MemoryReader<endian::order::big>;

	struct memoryreader_trait
	{
		typedef memoryreader			   native_endian_reader;
		typedef little_endian_memoryreader little_endian_reader;
		typedef big_endian_memoryreader	big_endian_reader;
	};

}	// namespace khutils


#if defined(KHUTILS_MEMORYREADER_IMPL)

khutils::MemoryReaderImplementation::MemoryReaderImplementation(const State& state)	//
	: m_state(state)
{
	KHUTILS_ASSERT_PTR(state);
	KHUTILS_ASSERT_PTR(m_state);
}

//----------------------------

khutils::MemoryReaderImplementation::MemoryReaderImplementation(State&& state)	//
	: m_state(state)
{
	KHUTILS_ASSERT_PTR(state);
	KHUTILS_ASSERT_PTR(m_state);
}

//----------------------------
//-- handler interface

size_t khutils::MemoryReaderImplementation::getCurrentOffset()
{
	KHUTILS_ASSERT_PTR(m_state);
	return m_state->get_position();
}

//----------------------------

void khutils::MemoryReaderImplementation::jumpToOffset(size_t pos)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->set_position(pos);
	KHUTILS_ASSERT(r > 0);
}

//----------------------------

void khutils::MemoryReaderImplementation::skip(size_t bytes)
{
	KHUTILS_ASSERT_PTR(m_state);
	jumpToOffset(m_state->get_position() + bytes);
}

//----------------------------

bool khutils::MemoryReaderImplementation::isEnd()
{
	KHUTILS_ASSERT_PTR(m_state);
	return m_state->is_end();
}

//----------------------------
//-- reader interface

void khutils::MemoryReaderImplementation::read(void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->read_bytes(data, size);
	KHUTILS_ASSERT(r > 0);
}

//----------------------------

void khutils::MemoryReaderImplementation::fetch(void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->fetch_bytes(data, size);
	KHUTILS_ASSERT(r > 0);
}

//----------------------------

void khutils::MemoryReaderImplementation::readAt(size_t offset, void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto r = m_state->set_position(offset);
	KHUTILS_ASSERT(r > 0);
	read(data, size);
}

//----------------------------

void khutils::MemoryReaderImplementation::fetchAt(size_t offset, void* data, size_t size)
{
	KHUTILS_ASSERT_PTR(m_state);
	auto pos = m_state->get_position();
	auto r   = m_state->set_position(offset);
	KHUTILS_ASSERT(r > 0);
	fetch(data, size);
	r = m_state->set_position(pos);
	KHUTILS_ASSERT(r > 0);
}

#endif	// defined(KHUTILS_MEMORYREADER_IMPL)

#endif	// KHUTILS_MEMORYREADER_HPP_INC
