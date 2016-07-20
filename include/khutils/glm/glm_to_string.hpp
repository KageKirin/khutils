#ifndef KHUTILS_GLM_TO_STRING_HPP_INC
#define KHUTILS_GLM_TO_STRING_HPP_INC

#include <glm/fwd.hpp>
#include <string>

namespace khutils
{
	const std::string to_string(const glm::dquat& q);
	const std::string to_string(const glm::dvec2& v);
	const std::string to_string(const glm::dvec3& v);
	const std::string to_string(const glm::dvec4& v);
	const std::string to_string(const glm::dmat4& m);

}	// namespace khutils

#if defined(KHUTILS_GLM_TO_STRING_IMPL)

#define GLM_SWIZZLE
#define GLM_FORCE_RADIANS
#define GLM_PRECISION_HIGHP_FLOAT
#include <fmt/format.h>

#include "khutils/glm/glm_to_string.hpp"
#include <glm/glm.hpp>

#include <string>

namespace khutils
{
	using namespace fmt::literals;

	//////////////////////////////////////////////////////////////////////////

	const std::string to_string(const glm::dquat& q)
	{
		return "({0} i + {1} j + {2} k + {3})\n"_format(q.x, q.y, q.z, q.w);
	}

	const std::string to_string(const glm::dvec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::dvec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::dvec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::dmat4& m)
	{
		static const char* linefmt = "{0}, {1}, {2}, {3}";

		return "({0},\n{1},\n{2},\n{3})"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0], m[3][0]),
												fmt::format(linefmt, m[0][1], m[1][1], m[2][1], m[3][1]),
												fmt::format(linefmt, m[0][2], m[1][2], m[2][2], m[3][2]),
												fmt::format(linefmt, m[0][3], m[1][3], m[2][3], m[3][3]));
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_TO_STRING_IMPL)

#endif	// !KHUTILS_GLM_TO_STRING_HPP_INC
