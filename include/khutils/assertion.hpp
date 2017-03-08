#ifndef KHUTILS_ASSERTION_HPP_INC
#define KHUTILS_ASSERTION_HPP_INC

#include <bandit/assertion_frameworks/snowhouse/snowhouse/snowhouse.h>
#include <memory>

#ifdef KHUTILS_ASSERTION_WITH_VALUE_PTR
#include <value_ptr/value_ptr.hpp>
#endif	// KHUTILS_ASSERTION_WITH_VALUE_PTR

namespace khutils
{
	void Assert(const bool cond, const char* _file, const int _line);

	template <typename T>
	void Assert(const T& var, const T& val, const char* _file, const int _line);

	template <typename T>
	void AssertNot(const T& var, const T& val, const char* _file, const int _line);

	template <typename T, typename Expression>
	void Assert(const T& var, Expression expression, const char* _file, const int _line);

	template <typename T>
	void AssertNullPtr(const T* ptr, const char* _file, const int _line);

	template <typename T>
	void AssertValidPtr(const T* ptr, const char* _file, const int _line);

	template <typename T>
	void AssertValidSharedPtr(const std::shared_ptr<T>& ptr, const char* _file, const int _line);

	template <typename T, typename D>
	void AssertValidUniquePtr(const std::unique_ptr<T, D>& ptr, const char* _file, const int _line);

#ifdef KHUTILS_ASSERTION_WITH_VALUE_PTR
	template <typename T>
	void AssertValidValuePtr(const smart_pointer::value_ptr<T>& ptr, const char* _file, const int _line);
#endif	// KHUTILS_ASSERTION_WITH_VALUE_PTR

}	// namespace khutils

#define KHUTILS_ASSERT(cond) khutils::Assert(bool((cond)), __FILE__, __LINE__);
#define KHUTILS_ASSERT_EQUALS(variable, value) khutils::Assert((variable), (value), __FILE__, __LINE__);
#define KHUTILS_ASSERT_NOT(variable, value) khutils::AssertNot((variable), (value), __FILE__, __LINE__);
#define KHUTILS_ASSERT_NULLPTR(pointer) khutils::AssertNullPtr((pointer), __FILE__, __LINE__);
#define KHUTILS_ASSERT_PTR(pointer) khutils::AssertValidPtr((pointer), __FILE__, __LINE__);
#define KHUTILS_ASSERT_SPTR(pointer) khutils::AssertValidSharedPtr((pointer), __FILE__, __LINE__);
#define KHUTILS_ASSERT_UPTR(pointer) khutils::AssertValidUniquePtr((pointer), __FILE__, __LINE__);

#define KHUTILS_ASSERT_EXPR(variable, expr)                                                                            \
	{                                                                                                                  \
		using namespace snowhouse;                                                                                     \
		khutils::Assert((variable), (expr), __FILE__, __LINE__);                                                       \
	};

#define KHUTILS_ASSERT_GREATER(variable, val) KHUTILS_ASSERT_EXPR(variable, Is().GreaterThan(val))
#define KHUTILS_ASSERT_GREATEREQ(variable, val) KHUTILS_ASSERT_EXPR(variable, Is().GreaterThanOrEqualTo(val))
#define KHUTILS_ASSERT_LESSER(variable, val) KHUTILS_ASSERT_EXPR(variable, Is().LessThan(val))
#define KHUTILS_ASSERT_LESSEREQ(variable, val) KHUTILS_ASSERT_EXPR(variable, Is().LessThanOrEqualTo(val))
#define KHUTILS_ASSERT_IN_RANGE(variable, valm, valM)                                                                  \
	KHUTILS_ASSERT_EXPR(variable, Is().GreaterThanOrEqualTo(valm).And().LessThanOrEqualTo(valM))
#define KHUTILS_ASSERT_IN_RANGE_EX(variable, valm, valM)                                                               \
	KHUTILS_ASSERT_EXPR(variable, Is().GreaterThan(valm).And().LessThan(valM))
#define KHUTILS_ASSERT_IN_RANGE_LO(variable, valm, valM)                                                               \
	KHUTILS_ASSERT_EXPR(variable, Is().GreaterThan(valm).And().LessThanOrEqualTo(valM))
#define KHUTILS_ASSERT_IN_RANGE_HO(variable, valm, valM)                                                               \
	KHUTILS_ASSERT_EXPR(variable, Is().GreaterThanOrEqualTo(valm).And().LessThan(valM))

#ifdef KHUTILS_ASSERTION_WITH_VALUE_PTR
#define KHUTILS_ASSERT_VPTR(pointer) khutils::AssertValidValuePtr((pointer), __FILE__, __LINE__);
#endif	// KHUTILS_ASSERTION_WITH_VALUE_PTR

#if defined(KHUTILS_ASSERTION_INLINE) || defined(KHUTILS_ASSERTION_IMPL)

#include "khutils/logging.hpp"
#include <iostream>
// keep this space to force order of includes
#include <bandit/assertion_frameworks/snowhouse/snowhouse/fluent/expressionbuilder.h>

//#define WITH_CASSERT

#ifdef WITH_CASSERT
#include <cassert>
#define CASSERT(x) assert(x)
#else
#define CASSERT(x)
#endif	// WITH_CASSERT


namespace khutils
{
	template <typename T>
	void Assert(const T& var, const T& val, const char* _file, const int _line)
	{
		CASSERT(var == val);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That(var, Is().EqualTo(val), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}

	template <typename T>
	void AssertNot(const T& var, const T& val, const char* _file, const int _line)
	{
		CASSERT(var != val);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That(var, Is().Not().EqualTo(val), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}

	template <typename T, typename Expression>
	void Assert(const T& var, Expression expression, const char* _file, const int _line)
	{
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That(var, expression, _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}

	template <typename T>
	void AssertNullPtr(const T* ptr, const char* _file, const int _line)
	{
		CASSERT(ptr == (T*)nullptr);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That(ptr, Is().EqualTo((T*)nullptr), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}

	template <typename T>
	void AssertValidPtr(const T* ptr, const char* _file, const int _line)
	{
		CASSERT(ptr != (T*)nullptr);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That(ptr, Is().Not().EqualTo((T*)nullptr), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}

	template <typename T>
	void AssertValidSharedPtr(const std::shared_ptr<T>& ptr, const char* _file, const int _line)
	{
		CASSERT((bool)ptr);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That((bool)ptr, IsTrue(), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}

	template <typename T, typename D>
	void AssertValidUniquePtr(const std::unique_ptr<T, D>& ptr, const char* _file, const int _line)
	{
		CASSERT((bool)ptr);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That((bool)ptr, IsTrue(), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}


#ifdef KHUTILS_ASSERTION_WITH_VALUE_PTR
	template <typename T>
	void AssertValidValuePtr(const smart_pointer::value_ptr<T>& ptr, const char* _file, const int _line)
	{
		CASSERT((bool)ptr);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That((bool)ptr, IsTrue(), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}
#endif	// KHUTILS_ASSERTION_WITH_VALUE_PTR

}	// namespace khutils

#endif	// defined(KHUTILS_ASSERTION_INLINE) || defined(KHUTILS_ASSERTION_IMPL)


#if defined(KHUTILS_ASSERTION_IMPL)

#include "khutils/runtime_exceptions.hpp"

namespace khutils
{
	void Assert(const bool cond, const char* _file, const int _line)
	{
		CASSERT(cond);
		try
		{
			using namespace snowhouse;
			ConfigurableAssert<DefaultFailureHandler>::That(cond, IsTrue(), _file, _line);
		}
		catch (...)
		{
			logger::error() << "assertion in " << _file << " at line " << _line;
			throw;
		}
	}

}	// namespace khutils

#endif	// defined (KHUTILS_ASSERTION_IMPL)

#endif	// !KHUTILS_ASSERTION_HPP_INC
