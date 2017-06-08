#ifndef KHUTILS_READERINTERFACE_HPP_INC
#define KHUTILS_READERINTERFACE_HPP_INC

#define KHUTILS_ASSERTION_INLINE


#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/typeconversion.hpp"

#include <algorithm>
#include <functional>

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
	struct EndianReaderInterface : virtual ReaderInterface
	{
		static constexpr endian::order m_order = _order;

		// read 1 element of given type
		template <typename OutT>
		OutT readType()
		{
			OutT val;
			read(&val, sizeof(OutT));
			return endian_reverse<endian::native, m_order>(val);
		}

		// fetch 1 element of given type
		template <typename OutT>
		OutT fetchType()
		{
			OutT val;
			fetch(&val, sizeof(OutT));
			return endian_reverse<endian::native, m_order>(val);
		}

		// read 1 element of given type at given offset
		template <typename OutT>
		OutT readTypeAt(size_t offset)
		{
			OutT val;
			readAt(offset, &val, sizeof(OutT));
			return endian_reverse<endian::native, m_order>(val);
		}

		// fetch 1 element of given type at given offset
		template <typename OutT>
		OutT fetchTypeAt(size_t offset)
		{
			OutT val;
			fetchAt(offset, &val, sizeof(OutT));
			return endian_reverse<endian::native, m_order>(val);
		}

		// read n elements of given type
		template <typename OutT>
		std::vector<OutT> readType(size_t count)
		{
			std::vector<OutT> val(count);
			read(&val.front(), sizeof(OutT) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		// fetch n elements of given type
		template <typename OutT>
		std::vector<OutT> fetchType(size_t count)
		{
			std::vector<OutT> val(count);
			fetch(&val.front(), sizeof(OutT) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		// read n elements of given type at given offset
		template <typename OutT>
		std::vector<OutT> readTypeAt(size_t count, size_t offset)
		{
			std::vector<OutT> val(count);
			readAt(offset, &val.front(), sizeof(OutT) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		// read n elements of given type at given offset
		template <typename OutT>
		std::vector<OutT> fetchTypeAt(size_t count, size_t offset)
		{
			std::vector<OutT> val(count);
			fetchAt(offset, &val.front(), sizeof(OutT) * count);
			std::transform(val.begin(), val.end(), val.begin(), [](auto& _v) {
				return endian_reverse<endian::native, m_order>(_v);
			});
			return val;
		}

		//---

		template <typename OutT, typename ReadT>
		using ConversionFunc = std::function<OutT(ReadT)>;

		// read 1 element of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		OutT readTypeAs(ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->readType<ReadT>());
		}

		// fetch 1 element of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		OutT fetchTypeAs(ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->fetchType<ReadT>());
		}

		// read 1 element of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		OutT readTypeAsAt(size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->readTypeAt<ReadT>(offset));
		}

		// fetch 1 element of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		OutT fetchTypeAsAt(size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			return conv(this->fetchTypeAt<ReadT>(offset));
		}

		// read n elements of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> readTypeAs(size_t count, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->readType<ReadT>(count);
			std::vector<OutT> val;
			std::transform(rval.begin(), rval.end(), std::back_inserter(val), conv);
			return val;
		}

		// fetch n elements of ReadT, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> fetchTypeAs(size_t count, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->fetchType<ReadT>(count);
			std::vector<OutT> val;
			std::transform(rval.begin(), rval.end(), std::back_inserter(val), conv);
			return val;
		}

		// read n elements of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> readTypeAsAt(size_t count, size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->readTypeAt<ReadT>(count, offset);
			std::vector<OutT> val;
			std::transform(rval.begin(), rval.end(), std::back_inserter(val), conv);
			return val;
		}

		// read n elements of ReadT at given offset, return as OutT
		template <typename OutT, typename ReadT>
		std::vector<OutT> fetchTypeAsAt(size_t count, size_t offset, ConversionFunc<OutT, ReadT> conv)
		{
			auto			  rval = this->fetchTypeAt<ReadT>(count, offset);
			std::vector<OutT> val;
			std::transform(rval.begin(), rval.end(), std::back_inserter(val), conv);
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
