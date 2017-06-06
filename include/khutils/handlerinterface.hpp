#ifndef KHUTILS_HANDLERINTERFACE_HPP_INC
#define KHUTILS_HANDLERINTERFACE_HPP_INC

#define KHUTILS_ASSERTION_INLINE

#include "khutils/assertion.hpp"

namespace khutils
{
	struct HandlerInterface
	{
		// returns current offset
		virtual size_t getCurrentOffset() = 0;

		// jumps to given offset
		virtual void jumpToOffset(size_t pos) = 0;

		// skips n bytes
		virtual void skip(size_t bytes) = 0;

		// skips n elements of _SkipT
		template <typename _SkipT>
		inline void skipType(size_t count = 1)
		{
			skip(sizeof(_SkipT) * count);
		}

		// aligns to next alignment
		virtual void align(size_t alignment);

		// returns true if EOF/end of buffer
		virtual bool isEnd() = 0;
	};
}	// namespace khutils


#if defined(KHUTILS_HANDLERINTERFACE_IMPL)

void khutils::HandlerInterface::align(size_t alignment)
{
	auto pos			= getCurrentOffset();
	auto nextAlignedPos = pos + (pos % alignment);
	skip<char>(nextAlignedPos - pos);
}

#endif	// defined(KHUTILS_HANDLERINTERFACE_IMPL)

#endif	// ! KHUTILS_HANDLERINTERFACE_HPP_INC
