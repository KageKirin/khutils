#ifndef KHUTILS_ASSERTION_HPP_INC﻿
#define KHUTILS_ASSERTION_HPP_INC

#if defined(KHUTILS_UNITTEST)
#include <bandit/bandit.h>	//TODO: change to header for assertion only

#define KHUTILS_ASSERT(variable, value) bandit::AssertThat((variable), Equals((value)))
#define KHUTILS_ASSERT_PTR((ptr)) bandit::AssertThat((ptr), NotEquals(nullptr))

#else
#include <cassert>

#define KHUTILS_ASSERT(variable, value) assert((variable) == (value))
#define KHUTILS_ASSERT_PTR(ptr) assert((ptr) != nullptr)

// TODO: implement own assert, maybe?

#endif	// defined(KHUTILS_UNITTEST)

#if defined(KHUTILS_ASSERTION_IMPL)

#endif	// defined (KHUTILS_ASSERTION_IMPL)

#endif	// !KHUTILS_ASSERTION_HPP_INC
