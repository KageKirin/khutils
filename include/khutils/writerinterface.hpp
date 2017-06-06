#ifndef KHUTILS_WRITERINTERFACE_HPP_INC
#define KHUTILS_WRITERINTERFACE_HPP_INC

#define KHUTILS_ASSERTION_INLINE


#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/endian.hpp"
#include "khutils/handlerinterface.hpp"
#include "khutils/typeconversion.hpp"


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
		void write(const InT& val)
		{
			write(&val, sizeof(val));
			return endian_reverse<m_order, endian::native>(val);
		}

		// put 1 element of given type
		template <typename InT>
		void put(const InT& val)
		{
			put(&val, sizeof(val));
			return endian_reverse<m_order, endian::native>(val);
		}

		// write 1 element of given type at given offset
		template <typename InT>
		void writeAt(const InT& val, size_t offset)
		{
			writeAt(offset, &val, sizeof(val));
			return endian_reverse<m_order, endian::native>(val);
		}

		// put 1 element of given type at given offset
		template <typename InT>
		void putAt(const InT& val, size_t offset)
		{
			putAt(offset, &val, sizeof(val));
			return endian_reverse<m_order, endian::native>(val);
		}

		// write n elements of given type
		template <typename InT>
		void write(const std::vector<InT>& _val)
		{
			const std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			write(&val.front(), sizeof(val) * count);
			return val;
		}

		// put n elements of given type
		template <typename InT>
		void put(const std::vector<InT>& _val)
		{
			const std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			put(&val.front(), sizeof(val) * count);
			return val;
		}

		// write n elements of given type at given offset
		template <typename InT>
		void writeAt(const std::vector<InT>& _val, size_t offset)
		{
			const std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			writeAt(offset, &val.front(), sizeof(val) * count);
			return val;
		}

		// write n elements of given type at given offset
		template <typename InT>
		void putAt(const std::vector<InT>& _val, size_t offset)
		{
			const std::vector<InT> val;
			val.reserve(_val.size());
			std::transform(_val.begin(), _val.end(), std::back_inserter(val), [](auto& _v) {
				return endian_reverse<m_order, endian::native>(_v);
			});

			putAt(offset, &val.front(), sizeof(val) * count);
			return val;
		}

		//---

		template <typename InT, typename WriteT>
		using std::function<WriteT(InT)> ConversionFunc;

		// write 1 element of WriteT, return as InT
		template <typename InT, typename WriteT>
		void writeAs(const InT& val, ConversionFunc<InT, WriteT> conv)
		{
			this->write<WriteT>(conv(val));
		}

		// put 1 element of WriteT, return as InT
		template <typename InT, typename WriteT>
		void putAs(const InT& val, ConversionFunc<InT, WriteT> conv)
		{
			this->put<WriteT>(conv(val));
		}

		// write 1 element of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void writeAsAt(const InT& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			this->writeAt<WriteT>(conv(val), offset);
		}

		// put 1 element of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void putAsAt(const InT& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			this->putAt<WriteT>(conv(val), offset);
		}

		// write n elements of WriteT, return as InT
		template <typename InT, typename WriteT>
		void writeAs(const std::vector<InT>& val, ConversionFunc<InT, WriteT> conv)
		{
			const std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::tranform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->write<WriteT>(wval);
		}

		// put n elements of WriteT, return as InT
		template <typename InT, typename WriteT>
		void putAs(const std::vector<InT>& val, ConversionFunc<InT, WriteT> conv)
		{
			const std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::tranform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->put<WriteT>(wval);
		}

		// write n elements of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void writeAsAt(const std::vector<InT>& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			const std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::tranform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->writeAt<WriteT>(count, wval);
		}

		// write n elements of WriteT at given offset, return as InT
		template <typename InT, typename WriteT>
		void putAsAt(const std::vector<InT>& val, size_t offset, ConversionFunc<InT, WriteT> conv)
		{
			const std::vector<WriteT> wval;
			wval.reserve(val.size());
			std::tranform(val.begin(), val.end(), std::back_inserter(wval), conv);

			this->putAt<WriteT>(count, wval);
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
