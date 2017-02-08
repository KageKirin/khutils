#ifndef KHUTILS_PIMPLE_BASE_HPP_INC
#define KHUTILS_PIMPLE_BASE_HPP_INC

#include <memory>

namespace khutils
{
#ifndef KHUTILS_PIMPLE_PTR
#define KHUTILS_PIMPLE_PTR std::unique_ptr
#endif	// !KHUTILS_PIMPLE_PTR

	template <typename T>
	using pimpl_ptr = KHUTILS_PIMPLE_PTR<T>;

	template <typename T>
	class pimple_base
	{
	protected:
		pimpl_ptr<T> _pointer;

	public:
		pimple_base() = delete;


	protected:
		pimple_base(const pimple_base&) = default;
		pimple_base(pimple_base&&)		= default;
		pimple_base(const pimpl_ptr<T>& p) : _pointer(p)
		{
		}
		pimple_base(T* p) : _pointer(p)
		{
		}
		~pimple_base() = default;

		pimple_base operator=(const pimple_base&) = default;
		pimple_base operator=(pimple_base&&) = default;
	};

}	// namespace khutils

#endif	// !KHUTILS_PIMPLE_BASE_HPP_INC
