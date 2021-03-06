#ifndef KHUTILS_FLATBUFFER_CONTAINER_HPP_INC
#define KHUTILS_FLATBUFFER_CONTAINER_HPP_INC

#include "khutils/assertion.hpp"
#include "khutils/file.hpp"
#include "khutils/logging.hpp"
#include "khutils/runtime_exceptions.hpp"

#include <flatbuffers/flatbuffers.h>
#include <flatbuffers/idl.h>

#include <cstdint>
#include <cstdio>
#include <initializer_list>
#include <tuple>
#include <vector>

namespace khutils
{
	template <typename _T>
	class FlatbufferContainer
	{
	public:
		typedef _T FlatbufferType;

	private:
		std::vector<uint8_t> m_buffer;	//< holds the flatbuffer data
										  //< technically, this could be improved with a std::unique_ptr<>

	public:
		FlatbufferContainer() = delete;
		FlatbufferContainer(std::vector<uint8_t>&& buffer) : m_buffer(buffer)
		{
			KHUTILS_ASSERT(verify());
			if (!verify())
			{
				throw FatalImportException("bad flatbuffer");
			}
		}
		FlatbufferContainer(const std::vector<uint8_t>& buffer) : m_buffer(buffer)
		{
		}
		FlatbufferContainer(const uint8_t* data, size_t length)
			: FlatbufferContainer(std::vector<uint8_t>(data, data + length))
		{
		}
		FlatbufferContainer(const flatbuffers::FlatBufferBuilder& builder)
			: FlatbufferContainer(builder.GetBufferPointer(), builder.GetSize())
		{
		}

		// FlatbufferContainer(const _T* ptr){}
		// no need to verify buffer, as it already has been verified when creating rhv
		FlatbufferContainer(const FlatbufferContainer& rhv) = default;
		FlatbufferContainer(FlatbufferContainer&& rhv)		= default;
		~FlatbufferContainer()								= default;

		FlatbufferContainer& operator=(const FlatbufferContainer& rhv) = default;
		FlatbufferContainer& operator=(FlatbufferContainer&& rhv) = default;

		inline const FlatbufferType* ptr() const
		{
			return flatbuffers::GetRoot<FlatbufferType>(m_buffer.data());
		}

		inline const FlatbufferType& ref() const
		{
			auto ptr_ = ptr();
			KHUTILS_ASSERT_PTR(ptr_);
			return *ptr_;
		}

		inline const std::vector<uint8_t>& buf() const
		{
			return m_buffer;
		}

		inline const uint8_t* const raw() const
		{
			return m_buffer.data();
		}

		inline size_t size() const
		{
			return m_buffer.size();
		}

		inline bool verify() const
		{
			flatbuffers::Verifier verifier(m_buffer.data(), m_buffer.size());
			return ptr()->Verify(verifier);
		}

		[[deprecated]] inline void dump(FILE* fptr) const
		{
			KHUTILS_ASSERT_PTR(fptr);
			fwrite(raw(), size(), 1, fptr);
		}
	};

	/// handles a flatbuffer on given memory
	template <typename _T>
	class FlatbufferHandler
	{
	public:
		typedef _T FlatbufferType;

	private:
		const uint8_t* const m_data;
		const size_t		 m_length;

	public:
		FlatbufferHandler() = delete;

		FlatbufferHandler(const uint8_t* data, size_t length)	//
			: m_data(data), m_length(length)
		{
			KHUTILS_ASSERT_PTR(m_data);
			KHUTILS_ASSERT(m_length > 0);
			KHUTILS_ASSERT(verify());
			if (!verify())
			{
				throw FatalImportException("bad flatbuffer");
			}
		}
		FlatbufferHandler(const std::vector<uint8_t>& data)	//
			: FlatbufferHandler(data.data(), data.size())
		{
		}

		// no need to verify buffer, as it already has been verified when creating rhv
		FlatbufferHandler(const FlatbufferHandler& rhv) = default;
		FlatbufferHandler(FlatbufferHandler&& rhv)		= default;
		~FlatbufferHandler()							= default;

		FlatbufferHandler& operator=(const FlatbufferHandler& rhv) = default;
		FlatbufferHandler& operator=(FlatbufferHandler&& rhv) = default;

		inline const FlatbufferType* ptr() const
		{
			return flatbuffers::GetRoot<FlatbufferType>(m_data);
		}

		inline const FlatbufferType& ref() const
		{
			auto ptr_ = ptr();
			KHUTILS_ASSERT_PTR(ptr_);
			return *ptr_;
		}

		inline const uint8_t* const raw() const
		{
			return m_data;
		}

		inline size_t size() const
		{
			return m_length;
		}

		inline bool verify() const
		{
			flatbuffers::Verifier verifier(m_data, m_length);
			return ptr()->Verify(verifier);
		}
	};

	template <typename FBType, typename FBTypeT>
	FlatbufferContainer<FBType> buildFlatbuffer(const FBTypeT*					obj,
												flatbuffers::FlatBufferBuilder& fbb,
												flatbuffers::Offset<FBType> (*create)(flatbuffers::FlatBufferBuilder&,
																					  const FBTypeT*,
																					  const flatbuffers::rehasher_function_t*),
												void (*finish)(flatbuffers::FlatBufferBuilder&, flatbuffers::Offset<FBType>))
	{
		finish(fbb, create(fbb, obj, nullptr));
		return FlatbufferContainer<FBType>(fbb);
	}

	template <typename FBType>
	void dumpFlatbuffer(const FlatbufferContainer<FBType>& fb, const std::string& filename)
	{
		dumpBufferToFile(fb.buf(), openLocalFilePtr(filename, "wb"));
	}

	template <typename FBType>
	void dumpFlatbuffer(const FlatbufferHandler<FBType>& fb, const std::string& filename)
	{
		dumpBufferToFile(fb.raw(), fb.size(), openLocalFilePtr(filename, "wb"));
	}

	template <typename FBType>
	FlatbufferContainer<FBType> loadFlatbuffer(const std::string& filename)
	{
		return FlatbufferContainer<FBType>{openLocalFileBuffer(filename)};
	}

	template <typename FBType>
	FlatbufferContainer<FBType> loadFlatbuffer(std::istream& ins)
	{
		return FlatbufferContainer<FBType>{openBufferFromStream(ins)};
	}


	inline bool initializeParser(flatbuffers::Parser& parser,
								 // maps: schema -> source
								 std::initializer_list<std::tuple<const char*, const char*>> namedSchemas,
								 const char** include_dirs = nullptr)
	{
		return std::all_of(namedSchemas.begin(), namedSchemas.end(), [&parser, &include_dirs](auto& _namedSchema) {
			logger::debug() << "parsing schema: " << std::get<0>(_namedSchema);
			auto parseOk = parser.Parse(std::get<1>(_namedSchema), include_dirs, std::get<0>(_namedSchema));
			if (!parseOk)
			{
				logger::debug() << "schema source: " << std::endl << std::get<1>(_namedSchema);
			}
			KHUTILS_ASSERT(parseOk);
			return parseOk;
		});
	}

}	// namespace khutils

#endif	// !KHUTILS_FLATBUFFER_CONTAINER_HPP_INC
