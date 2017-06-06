#ifndef KHUTILS_READERINTERFACE_HPP_INC
#define KHUTILS_READERINTERFACE_HPP_INC

#define KHUTILS_ASSERTION_INLINE


#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/typeconversion.hpp"


namespace khutils
{
	struct ReaderInterface : HandlerInterface
	{
		// reads _size bytes into data
		virtual void read(void* data, size_t size) = 0;

		// reads _size bytes into data without incrementing position
		virtual void fetch(void* data, size_t size);

		// reads _size bytes at offset into data
		virtual void readAt(size_t offset, void* data, size_t size);

		// reads _size bytes at offset into data without incrementing position
		virtual void fetchAt(size_t offset, void* data, size_t size);
	};


	template <endian::order _order>
	struct EndianReaderInterface : ReaderInterface
	{
		static constexpr endian::order m_order = _order;

		// read 1 element of given type
		template <typename OutT>
		OutT read()
		{
			OutT val;
			read(&val, sizeof(val));
			return endian_reverse<endian::native, m_order>(val);
		}

		// fetch 1 element of given type
		template <typename OutT>
		OutT fetch()
		{
			OutT val;
			fetch(&val, sizeof(val));
			return endian_reverse<endian::native, m_order>(val);
		}

		// read 1 element of given type at given offset
		template <typename OutT>
		OutT readAt(size_t offset)
		{
			OutT val;
			readAt(offset, &val, sizeof(val));
			return endian_reverse<endian::native, m_order>(val);
		}

		// fetch 1 element of given type at given offset
		template <typename OutT>
		OutT fetchAt(size_t offset)
		{
			OutT val;
			fetchAt(offset, &val, sizeof(val));
			return endian_reverse<endian::native, m_order>(val);
		}

		// read n elements of given type
		template <typename OutT>
		std::vector<OutT> read(size_t count)
		{
			std::vector<OutT> val(count);
			read(&val.front(), sizeof(val) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		// fetch n elements of given type
		template <typename OutT>
		std::vector<OutT> fetch(size_t count)
		{
			std::vector<OutT> val(count);
			fetch(&val.front(), sizeof(val) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		// read n elements of given type at given offset
		template <typename OutT>
		std::vector<OutT> readAt(size_t count, size_t offset)
		{
			std::vector<OutT> val(count);
			readAt(offset, &val.front(), sizeof(val) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		// read n elements of given type at given offset
		template <typename OutT>
		std::vector<OutT> fetchAt(size_t count, size_t offset)
		{
			std::vector<OutT> val(count);
			fetchAt(offset, &val.front(), sizeof(val) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		//---

		template <typename OutT, typename ReadT>
		using std::function<OutT(ReadT)> ConversionFunc;

		// read 1 element of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		OutT readAs(ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->read<ReadT>());
		}

		// fetch 1 element of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		OutT fetchAs(ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->fetch<ReadT>());
		}

		// read 1 element of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		OutT readAsAt(size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->readAt<ReadT>(offset));
		}

		// fetch 1 element of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		OutT fetchAsAt(size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->fetchAt<ReadT>(offset));
		}

		// read n elements of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> readAs(size_t count, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->read<ReadT>(count);
			std::vector<OutT> val;
			std::tranform(rval.begin(), rval.end(), std::back_inserter(val), conv);
			return val;
		}

		// fetch n elements of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> fetchAs(size_t count, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->fetch<ReadT>(count);
			std::vector<OutT> val;
			std::tranform(rval.begin(), rval.end(), std::back_inserter(val), conv);
			return val;
		}

		// read n elements of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> readAsAt(size_t count, size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->readAt<ReadT>(count, offset);
			std::vector<OutT> val;
			std::tranform(rval.begin(), rval.end(), std::back_inserter(val), conv);
			return val;
		}

		// read n elements of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> fetchAsAt(size_t count, size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->fetchAt<ReadT>(count, offset);
			std::vector<OutT> val;
			std::tranform(rval.begin(), rval.end(), std::back_inserter(val), conv);
			return val;
		}
	};
}	// namespace khutils

#if defined(KHUTILS_READERINTERFACE_IMPL)

void khutils::ReaderInterface::fetch(void* data, size_t size)
{
	auto curPos = getCurrentOffset();
	read(data, size);
	jumpToOffset(curPos);
}

//----------------------------

void khutils::ReaderInterface::readAt(size_t offset, void* data, size_t size)
{
	jumpToOffset(offset);
	read(data, size);
}

//----------------------------

void khutils::ReaderInterface::fetchAt(size_t offset, void* data, size_t size)
{
	auto curPos = getCurrentOffset();
	readAt(offset, data, size);
	jumpToOffset(curPos);
}

#endif	// defined(KHUTILS_READERINTERFACE_IMPL)

#endif	// KHUTILS_READERINTERFACE_HPP_INC
