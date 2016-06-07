#ifndef KHUTILS_FLATBUFFER_CONTAINER_HPP_INC
#define KHUTILS_FLATBUFFER_CONTAINER_HPP_INC

#include "khutils/runtime_exceptions.hpp"
#include <flatbuffers/flatbuffers.h>

#include <cstdint>
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
										  //< technically, this could be improved with a shared_array<> if STL had it
										  //(Boost has it, though)

	public:
		FlatbufferContainer() = delete;
		FlatbufferContainer(const std::vector<uint8_t>& buffer) : m_buffer(buffer)
		{
			assert(verify());
			if (!verify())
			{
				throw FatalImportException("bad flatbuffer");
			}
		}
		FlatbufferContainer(uint8_t* data, size_t length)
			: FlatbufferContainer(std::vector<uint8_t>(data, data + length))
		{
		}
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
			assert(ptr_);
			return *ptr_;
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
	};

}	// namespace khutils

#endif	// !KHUTILS_FLATBUFFER_CONTAINER_HPP_INC
