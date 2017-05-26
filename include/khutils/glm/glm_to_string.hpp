#ifndef KHUTILS_GLM_TO_STRING_HPP_INC
#define KHUTILS_GLM_TO_STRING_HPP_INC

#include <glm/fwd.hpp>
#include <glm/gtx/dual_quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include <iosfwd>
#include <string>

namespace khutils
{
	const std::string to_string(const glm::quat& q);
	const std::string to_string(const glm::dualquat& dq);
	const std::string to_string(const glm::vec2& v);
	const std::string to_string(const glm::vec3& v);
	const std::string to_string(const glm::vec4& v);
	const std::string to_string(const glm::mat3& m);
	const std::string to_string(const glm::mat4& m);

	const std::string to_string(const glm::dquat& q);
	const std::string to_string(const glm::ddualquat& dq);
	const std::string to_string(const glm::dvec2& v);
	const std::string to_string(const glm::dvec3& v);
	const std::string to_string(const glm::dvec4& v);
	const std::string to_string(const glm::dmat3& m);
	const std::string to_string(const glm::dmat4& m);

	const std::string to_string(const glm::ivec2& v);
	const std::string to_string(const glm::ivec3& v);
	const std::string to_string(const glm::ivec4& v);

	const std::string to_string(const glm::uvec2& v);
	const std::string to_string(const glm::uvec3& v);
	const std::string to_string(const glm::uvec4& v);

	const std::string to_string(const glm::i8vec2& v);
	const std::string to_string(const glm::i8vec3& v);
	const std::string to_string(const glm::i8vec4& v);

	const std::string to_string(const glm::u8vec2& v);
	const std::string to_string(const glm::u8vec3& v);
	const std::string to_string(const glm::u8vec4& v);

	const std::string to_string(const glm::i16vec2& v);
	const std::string to_string(const glm::i16vec3& v);
	const std::string to_string(const glm::i16vec4& v);

	const std::string to_string(const glm::u16vec2& v);
	const std::string to_string(const glm::u16vec3& v);
	const std::string to_string(const glm::u16vec4& v);

	std::ostream& operator<<(std::ostream& os, const glm::quat& q);
	std::ostream& operator<<(std::ostream& os, const glm::dualquat& dq);
	std::ostream& operator<<(std::ostream& os, const glm::vec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::vec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::vec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::mat3& m);
	std::ostream& operator<<(std::ostream& os, const glm::mat4& m);
	std::ostream& operator<<(std::ostream& os, const glm::dquat& q);
	std::ostream& operator<<(std::ostream& os, const glm::ddualquat& dq);
	std::ostream& operator<<(std::ostream& os, const glm::dvec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::dvec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::dvec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::dmat3& m);
	std::ostream& operator<<(std::ostream& os, const glm::dmat4& m);
	std::ostream& operator<<(std::ostream& os, const glm::ivec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::ivec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::ivec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::uvec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::uvec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::uvec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::i8vec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::i8vec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::i8vec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::u8vec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::u8vec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::u8vec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::i16vec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::i16vec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::i16vec4& v);
	std::ostream& operator<<(std::ostream& os, const glm::u16vec2& v);
	std::ostream& operator<<(std::ostream& os, const glm::u16vec3& v);
	std::ostream& operator<<(std::ostream& os, const glm::u16vec4& v);

}	// namespace khutils

#if defined(KHUTILS_GLM_TO_STRING_IMPL)

#ifndef GLM_FORCE_SWIZZLE
#define GLM_FORCE_SWIZZLE
#endif	// !GLM_FORCE_SWIZZLE

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif	// !GLM_FORCE_RADIANS

#ifndef GLM_PRECISION_HIGHP_FLOAT
#define GLM_PRECISION_HIGHP_FLOAT
#endif	// !GLM_PRECISION_HIGHP_FLOAT

#include <fmt/format.h>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/dual_quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include <iostream>
#include <string>

namespace khutils
{
	using namespace fmt::literals;

	//////////////////////////////////////////////////////////////////////////

	const std::string to_string(const glm::quat& q)
	{
		return "({0} i + {1} j + {2} k + {3})\n"_format(q.x, q.y, q.z, q.w);
	}

	const std::string to_string(const glm::dualquat& dq)
	{
		return "(({0}) + ({1}))\n"_format(to_string(dq.real), to_string(dq.dual));
	}

	const std::string to_string(const glm::vec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::vec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::vec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::mat3& m)
	{
		static const char* linefmt = "{0}, {1}, {2}";

		return "({0},\n{1},\n{2}\n)"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0]),
											fmt::format(linefmt, m[0][1], m[1][1], m[2][1]),
											fmt::format(linefmt, m[0][2], m[1][2], m[2][2]),
											fmt::format(linefmt, m[0][3], m[1][3], m[2][3]));
	}

	const std::string to_string(const glm::mat4& m)
	{
		static const char* linefmt = "{0}, {1}, {2}, {3}";

		return "({0},\n{1},\n{2},\n{3})"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0], m[3][0]),
												fmt::format(linefmt, m[0][1], m[1][1], m[2][1], m[3][1]),
												fmt::format(linefmt, m[0][2], m[1][2], m[2][2], m[3][2]),
												fmt::format(linefmt, m[0][3], m[1][3], m[2][3], m[3][3]));
	}

	const std::string to_string(const glm::dquat& q)
	{
		return "({0} i + {1} j + {2} k + {3})\n"_format(q.x, q.y, q.z, q.w);
	}

	const std::string to_string(const glm::ddualquat& dq)
	{
		return "(({0}) + ({1}))\n"_format(to_string(dq.real), to_string(dq.dual));
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

	const std::string to_string(const glm::dmat3& m)
	{
		static const char* linefmt = "{0}, {1}, {2}";

		return "({0},\n{1},\n{2})"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0]),
										  fmt::format(linefmt, m[0][1], m[1][1], m[2][1]),
										  fmt::format(linefmt, m[0][2], m[1][2], m[2][2]),
										  fmt::format(linefmt, m[0][3], m[1][3], m[2][3]));
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

	const std::string to_string(const glm::ivec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::ivec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::ivec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::uvec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::uvec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::uvec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::i8vec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::i8vec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::i8vec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::u8vec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::u8vec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::u8vec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::i16vec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::i16vec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::i16vec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	const std::string to_string(const glm::u16vec2& v)
	{
		return "({0}, {1})\n"_format(v.x, v.y);
	}

	const std::string to_string(const glm::u16vec3& v)
	{
		return "({0}, {1}, {2})\n"_format(v.x, v.y, v.z);
	}

	const std::string to_string(const glm::u16vec4& v)
	{
		return "({0}, {1}, {2}, {3})\n"_format(v.x, v.y, v.z, v.w);
	}

	//////////////////////////////////////////////////////////////////////////

	std::ostream& operator<<(std::ostream& os, const glm::quat& q)
	{
		os << "glm::quat" << to_string(q);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dualquat& dq)
	{
		os << "glm::dualquat" << to_string(dq);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::vec2& v)
	{
		os << "glm::vec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::vec3& v)
	{
		os << "glm::vec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::vec4& v)
	{
		os << "glm::vec4" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::mat3& m)
	{
		os << "glm::mat3" << to_string(m);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::mat4& m)
	{
		os << "glm::mat4" << to_string(m);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dquat& q)
	{
		os << "glm::dquat" << to_string(q);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::ddualquat& dq)
	{
		os << "glm::ddualquat" << to_string(dq);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dvec2& v)
	{
		os << "glm::dvec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dvec3& v)
	{
		os << "glm::dvec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dvec4& v)
	{
		os << "glm::dvec4" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dmat3& m)
	{
		os << "glm::dmat3" << to_string(m);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::dmat4& m)
	{
		os << "glm::dmat4" << to_string(m);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const glm::ivec2& v)
	{
		os << "glm::ivec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::ivec3& v)
	{
		os << "glm::ivec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::ivec4& v)
	{
		os << "glm::ivec4" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::uvec2& v)
	{
		os << "glm::uvec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::uvec3& v)
	{
		os << "glm::uvec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::uvec4& v)
	{
		os << "glm::uvec4" << to_string(v);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const glm::i8vec2& v)
	{
		os << "glm::i8vec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::i8vec3& v)
	{
		os << "glm::i8vec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::i8vec4& v)
	{
		os << "glm::i8vec4" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::u8vec2& v)
	{
		os << "glm::u8vec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::u8vec3& v)
	{
		os << "glm::u8vec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::u8vec4& v)
	{
		os << "glm::u8vec4" << to_string(v);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const glm::i16vec2& v)
	{
		os << "glm::i16vec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::i16vec3& v)
	{
		os << "glm::i16vec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::i16vec4& v)
	{
		os << "glm::i16vec4" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::u16vec2& v)
	{
		os << "glm::u16vec2" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::u16vec3& v)
	{
		os << "glm::u16vec3" << to_string(v);
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const glm::u16vec4& v)
	{
		os << "glm::u16vec4" << to_string(v);
		return os;
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_TO_STRING_IMPL)

#endif	// !KHUTILS_GLM_TO_STRING_HPP_INC
