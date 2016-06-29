#ifndef KHUTILS_ASSERTION_HPP_INC﻿
#define KHUTILS_ASSERTION_HPP_INC

#include <memory>

namespace khutils
{

	template <typename T>
	void Assert(const T& var, const T& val, const char* _file, const int _line);

	template <typename T>
	void AssertNullPtr(const T* ptr, const char* _file, const int _line);

	template <typename T>
	void AssertValidPtr(const T* ptr, const char* _file, const int _line);

	template <typename T>
	void AssertValidSharedPtr(const std::shared_ptr<T>& ptr, const char* _file, const int _line);

}	// namespace khutils

#define KHUTILS_ASSERT(variable, value) khutils::Assert(variable, value, __FILE__, __LINE__);
#define KHUTILS_ASSERT_NULLPTR(pointer) khutils::AssertNullPtr(pointer, __FILE__, __LINE__);
#define KHUTILS_ASSERT_PTR(pointer) khutils::AssertValidPtr(pointer, __FILE__, __LINE__);
#define KHUTILS_ASSERT_SPTR(pointer) khutils::AssertValidSharedPtr(pointer, __FILE__, __LINE__);

#include "khutils/assertion.inl"

#if defined(KHUTILS_ASSERTION_IMPL)

#include "khutils/runtime_exceptions.hpp"

namespace khutils
{
}	// namespace khutils

#endif	// defined (KHUTILS_ASSERTION_IMPL)

#if defined(KHUTILS_ASSERTION_IMPL)

#include <bandit/assertion_frameworks/snowhouse/snowhouse/snowhouse.h>﻿

#include <bandit/assertion_frameworks/snowhouse/snowhouse/fluent/expressionbuilder.h>

namespace khutils
{
	template <typename T>
	void Assert(const T& var, const T& val, const char* _file, const int _line)
	{
		using namespace snowhouse;
		ConfigurableAssert<DefaultFailureHandler>::That(var, Is().EqualTo(val), _file, _line);
	}

	template <typename T>
	void AssertNullPtr(const T* ptr, const char* _file, const int _line)
	{
		using namespace snowhouse;
		ConfigurableAssert<DefaultFailureHandler>::That(ptr, Is().EqualTo(nullptr), _file, _line);
	}

	template <typename T>
	void AssertValidPtr(const T* ptr, const char* _file, const int _line)
	{
		using namespace snowhouse;
		ConfigurableAssert<DefaultFailureHandler>::That(ptr, Is().Not().EqualTo(nullptr), _file, _line);
	}

	template <typename T>
	void AssertValidSharedPtr(const std::shared_ptr<T>& ptr, const char* _file, const int _line)
	{
		using namespace snowhouse;
		ConfigurableAssert<DefaultFailureHandler>::That((bool)ptr, IsTrue(), _file, _line);
	}

}	// namespace khutils

#endif	// defined (KHUTILS_ASSERTION_IMPL)

#endif	// !KHUTILS_ASSERTION_HPP_INC
