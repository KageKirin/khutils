#ifndef KHUTILS_FLATBUFFER_CONTAINER_HPP_INC
#define KHUTILS_FLATBUFFER_CONTAINER_HPP_INC

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
		}
		FlatbufferContainer(uint8_t* data, size_t length) : m_buffer(data, data + length)
		{
		}
		FlatbufferContainer(const FlatbufferContainer& rhv) = default;	//: FlatbufferContainer(rhv.m_buffer){}
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
			auto ptr = ptr();
			assert(ptr);
			return *ptr;
		}

		inline size_t size() const
		{
			return m_buffer.size();
		}
	};

}	// namespace khutils

#endif	// !KHUTILS_FLATBUFFER_CONTAINER_HPP_INC
