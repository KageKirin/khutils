#ifndef KHUTILS_WRITERINTERFACE_HPP_INC
#define KHUTILS_WRITERINTERFACE_HPP_INC

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
	struct WriterInterface : HandlerInterface
	{
		// writes _size bytes into data
		virtual void write(void* data, size_t size) = 0;

		// writes _size bytes into data without incrementing position
		virtual void put(void* data, size_t size);

		// writes _size bytes at offset into data
		virtual void writeAt(size_t offset, void* data, size_t size);

		// writes _size bytes at offset into data without incrementing position
		virtual void putAt(size_t offset, void* data, size_t size);
	};


	template <endian::order _order>
	struct EndianWriterInterface : WriterInterface
	{
		static constexpr endian::order m_order = _order;

		// write 1 element of given type
		template <typename InT>
		void writeType(const InT& _val)
		{
			const InT val = endian_reverse<m_order, endian::native>(_val);
			write((void*)&val, sizeof(InT));
		}

		// put 1 element of given type
		template <typename InT>
		void putType(const InT& _val)
		{
			const InT val = endian_reverse<m_order, endian::native>(_val);
			put((void*)&val, sizeof(InT));
		}

		// write 1 element of given type at given offset
		template <typename InT>
		void writeTypeAt(const InT& _val, size_t offset)
		{
			const InT val = endian_reverse<m_order, endian::native>(_val);
			writeAt(offset, (void*)&val, sizeof(InT));
		}

		// put 1 element of given type at given offset
		template <typename InT>
		void putTypeAt(const InT& _val, size_t offset)
		{
			const InT val = endian_reverse<m_order, endian::native>(_val);
			putAt(offset, (void*)&val, sizeof(InT));
		}

		// write n elements of given type
		template <typename InT>
		void writeType(const std::vector<InT>& _val)
		{
			std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			write(&val.front(), sizeof(InT) * val.size());
		}

		// put n elements of given type
		template <typename InT>
		void putType(const std::vector<InT>& _val)
		{
			std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			put(&val.front(), sizeof(InT) * val.size());
		}

		// write n elements of given type at given offset
		template <typename InT>
		void writeTypeAt(const std::vector<InT>& _val, size_t offset)
		{
			std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			writeAt(offset, &val.front(), sizeof(InT) * val.size());
		}

		// write n elements of given type at given offset
		template <typename InT>
		void putTypeAt(const std::vector<InT>& _val, size_t offset)
		{
			std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			putAt(offset, &val.front(), sizeof(InT) * val.size());
		}

		//---

		// write n elements of given type
		template <typename InT>
		void writeType(const InT* _val, size_t count)
		{
			std::vector<InT> val;
			val.reserve(count);
			std::transform(_val, _val + count, std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			write(&val.front(), sizeof(InT) * val.size());
		}

		// put n elements of given type
		template <typename InT>
		void putType(const InT* _val, size_t count)
		{
			std::vector<InT> val;
			val.reserve(count);
			std::transform(_val, _val + count, std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			put(&val.front(), sizeof(InT) * val.size());
		}

		// write n elements of given type at given offset
		template <typename InT>
		void writeTypeAt(const InT* _val, size_t count, size_t offset)
		{
			std::vector<InT> val;
			val.reserve(count);
			std::transform(_val, _val + count, std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			writeAt(offset, &val.front(), sizeof(InT) * val.size());
		}

		// write n elements of given type at given offset
		template <typename InT>
		void putTypeAt(const InT* _val, size_t count, size_t offset)
		{
			std::vector<InT> val;
			val.reserve(count);
			std::transform(_val, _val + count, std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			putAt(offset, &val.front(), sizeof(InT) * val.size());
		}

		//---

		template <typename InT, typename WriteT>
		using ConversionFunc = std::function<WriteT(InT)>;

		// write 1 element of WriteT, return as InT
		template <typename InT, typename WriteT>
		void writeTypeAs(const InT& val, ConversionFunc<InT, WriteT> conv)
		{
			this->writeType<WriteT>(conv(val));
		}

		// put 1 element of WriteT, return as InT
		template <typename InT, typename WriteT>
		void putTypeAs(const InT& val, ConversionFunc<InT, WriteT> conv)
		{
			this->putType<WriteT>(conv(val));
		}

		// write 1 element of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void writeTypeAsAt(const InT& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			this->writeTypeAt<WriteT>(conv(val), offset);
		}

		// put 1 element of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void putTypeAsAt(const InT& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			this->putTypeAt<WriteT>(conv(val), offset);
		}

		//---

		// write n elements of WriteT, return as InT
		template <typename InT, typename WriteT>
		void writeTypeAs(const std::vector<InT>& val, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::transform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->writeType<WriteT>(wval);
		}

		// put n elements of WriteT, return as InT
		template <typename InT, typename WriteT>
		void putTypeAs(const std::vector<InT>& val, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::transform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->putType<WriteT>(wval);
		}

		// write n elements of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void writeTypeAsAt(const std::vector<InT>& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::transform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->writeTypeAt<WriteT>(wval, offset);
		}

		// write n elements of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void putTypeAsAt(const std::vector<InT>& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::transform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->putTypeAt<WriteT>(wval, offset);
		}

		//---

		// write n elements of WriteT, return as InT
		template <typename InT, typename WriteT>
		void writeTypeAs(const InT* val, size_t count, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(count);
			std::transform(val, val + count, std::back_inserter(wval), conv);

			this->writeType<WriteT>(wval);
		}

		// put n elements of WriteT, return as InT
		template <typename InT, typename WriteT>
		void putTypeAs(const InT* val, size_t count, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(count);
			std::transform(val, val + count, std::back_inserter(wval), conv);

			this->putType<WriteT>(wval);
		}

		// write n elements of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void writeTypeAsAt(const InT* val, size_t count, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(count);
			std::transform(val, val + count, std::back_inserter(wval), conv);

			this->writeTypeAt<WriteT>(wval, offset);
		}

		// write n elements of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void putTypeAsAt(const InT* val, size_t count, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			std::vector<WriteT> wval;
			wval.reserve(count);
			std::transform(val, val + count, std::back_inserter(wval), conv);

			this->putTypeAt<WriteT>(wval, offset);
		}
	};
}	// namespace khutils

#if defined(KHUTILS_WRITERINTERFACE_IMPL)

void khutils::WriterInterface::put(void* data, size_t size)
{
	auto curPos = getCurrentOffset();
	write(data, size);
	jumpToOffset(curPos);
}

//----------------------------

void khutils::WriterInterface::writeAt(size_t offset, void* data, size_t size)
{
	jumpToOffset(offset);
	write(data, size);
}

//----------------------------

void khutils::WriterInterface::putAt(size_t offset, void* data, size_t size)
{
	auto curPos = getCurrentOffset();
	writeAt(offset, data, size);
	jumpToOffset(curPos);
}

#endif	// defined(KHUTILS_WRITERINTERFACE_IMPL)

#endif	// KHUTILS_WRITERINTERFACE_HPP_INC
