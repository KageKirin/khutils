#ifndef KHUTILS_WRITER_GLM_HPP_INC
#define KHUTILS_WRITER_GLM_HPP_INC

#include "khutils/filewriter.hpp"
#include "khutils/memorywriter.hpp"
#include "khutils/streamwriter.hpp"
#include "khutils/writer_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::vec2, glm::vec2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::vec3, glm::vec3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::vec4, glm::vec4);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::quat, glm::quat);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dvec2, glm::dvec2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dvec3, glm::dvec3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dvec4, glm::dvec4);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dquat, glm::dquat);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::ivec2, glm::ivec2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::ivec3, glm::ivec3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::ivec4, glm::ivec4);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat2x2, glm::mat2x2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat2x3, glm::mat2x3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat2x4, glm::mat2x4);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat3x2, glm::mat3x2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat3x3, glm::mat3x3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat3x4, glm::mat3x4);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat4x2, glm::mat4x2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat4x3, glm::mat4x3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::mat4x4, glm::mat4x4);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat2x2, glm::dmat2x2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat2x3, glm::dmat2x3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat2x4, glm::dmat2x4);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat3x2, glm::dmat3x2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat3x3, glm::dmat3x3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat3x4, glm::dmat3x4);

	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat4x2, glm::dmat4x2);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat4x3, glm::dmat4x3);
	template <>
	KUTILS_OVERLOAD_WRITER_DECL(streamwriter, glm::dmat4x4, glm::dmat4x4);

}	// namespace khutils

#if defined(KHUTILS_WRITER_GLM_IMPL)

#include "khutils/writer_glm.hpp"

#include "khutils/filewriter.hpp"
#include "khutils/memorywriter.hpp"
#include "khutils/streamwriter.hpp"
#include "khutils/writer_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{
	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::vec2, glm::vec2, ({
									write<int32_t, float>(t.x);
									write<int32_t, float>(t.y);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::vec3, glm::vec3, ({
									write<int32_t, float>(t.x);
									write<int32_t, float>(t.y);
									write<int32_t, float>(t.z);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::vec4, glm::vec4, ({
									write<int32_t, float>(t.x);
									write<int32_t, float>(t.y);
									write<int32_t, float>(t.z);
									write<int32_t, float>(t.w);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::quat, glm::quat, ({
									write<int32_t, float>(t.x);
									write<int32_t, float>(t.y);
									write<int32_t, float>(t.z);
									write<int32_t, float>(t.w);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dvec2, glm::dvec2, ({
									write<int64_t, double>(t.x);
									write<int64_t, double>(t.y);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dvec3, glm::dvec3, ({
									write<int64_t, double>(t.x);
									write<int64_t, double>(t.y);
									write<int64_t, double>(t.z);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dvec4, glm::dvec4, ({
									write<int64_t, double>(t.x);
									write<int64_t, double>(t.y);
									write<int64_t, double>(t.z);
									write<int64_t, double>(t.w);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dquat, glm::dquat, ({
									write<int64_t, double>(t.x);
									write<int64_t, double>(t.y);
									write<int64_t, double>(t.z);
									write<int64_t, double>(t.w);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::ivec2, glm::ivec2, ({
									write<int32_t>(t.x);
									write<int32_t>(t.y);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::ivec3, glm::ivec3, ({
									write<int32_t>(t.x);
									write<int32_t>(t.y);
									write<int32_t>(t.z);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::ivec4, glm::ivec4, ({
									write<int32_t>(t.x);
									write<int32_t>(t.y);
									write<int32_t>(t.z);
									write<int32_t>(t.w);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat2x2, glm::mat2x2, ({
									write<glm::vec2, glm::vec2>(t[0]);
									write<glm::vec2, glm::vec2>(t[1]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat2x3, glm::mat2x3, ({
									write<glm::vec3, glm::vec3>(t[0]);
									write<glm::vec3, glm::vec3>(t[1]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat2x4, glm::mat2x4, ({
									write<glm::vec4, glm::vec4>(t[0]);
									write<glm::vec4, glm::vec4>(t[1]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat3x2, glm::mat3x2, ({
									write<glm::vec2, glm::vec2>(t[0]);
									write<glm::vec2, glm::vec2>(t[1]);
									write<glm::vec2, glm::vec2>(t[2]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat3x3, glm::mat3x3, ({
									write<glm::vec3, glm::vec3>(t[0]);
									write<glm::vec3, glm::vec3>(t[1]);
									write<glm::vec3, glm::vec3>(t[2]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat3x4, glm::mat3x4, ({
									write<glm::vec4, glm::vec4>(t[0]);
									write<glm::vec4, glm::vec4>(t[1]);
									write<glm::vec4, glm::vec4>(t[2]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat4x2, glm::mat4x2, ({
									write<glm::vec2, glm::vec2>(t[0]);
									write<glm::vec2, glm::vec2>(t[1]);
									write<glm::vec2, glm::vec2>(t[2]);
									write<glm::vec2, glm::vec2>(t[3]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat4x3, glm::mat4x3, ({
									write<glm::vec3, glm::vec3>(t[0]);
									write<glm::vec3, glm::vec3>(t[1]);
									write<glm::vec3, glm::vec3>(t[2]);
									write<glm::vec3, glm::vec3>(t[3]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::mat4x4, glm::mat4x4, ({
									write<glm::vec4, glm::vec4>(t[0]);
									write<glm::vec4, glm::vec4>(t[1]);
									write<glm::vec4, glm::vec4>(t[2]);
									write<glm::vec4, glm::vec4>(t[3]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat2x2, glm::dmat2x2, ({
									write<glm::dvec2, glm::dvec2>(t[0]);
									write<glm::dvec2, glm::dvec2>(t[1]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat2x3, glm::dmat2x3, ({
									write<glm::dvec3, glm::dvec3>(t[0]);
									write<glm::dvec3, glm::dvec3>(t[1]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat2x4, glm::dmat2x4, ({
									write<glm::dvec4, glm::dvec4>(t[0]);
									write<glm::dvec4, glm::dvec4>(t[1]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat3x2, glm::dmat3x2, ({
									write<glm::dvec2, glm::dvec2>(t[0]);
									write<glm::dvec2, glm::dvec2>(t[1]);
									write<glm::dvec2, glm::dvec2>(t[2]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat3x3, glm::dmat3x3, ({
									write<glm::dvec3, glm::dvec3>(t[0]);
									write<glm::dvec3, glm::dvec3>(t[1]);
									write<glm::dvec3, glm::dvec3>(t[2]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat3x4, glm::dmat3x4, ({
									write<glm::dvec4, glm::dvec4>(t[0]);
									write<glm::dvec4, glm::dvec4>(t[1]);
									write<glm::dvec4, glm::dvec4>(t[2]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat4x2, glm::dmat4x2, ({
									write<glm::dvec2, glm::dvec2>(t[0]);
									write<glm::dvec2, glm::dvec2>(t[1]);
									write<glm::dvec2, glm::dvec2>(t[2]);
									write<glm::dvec2, glm::dvec2>(t[3]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat4x3, glm::dmat4x3, ({
									write<glm::dvec3, glm::dvec3>(t[0]);
									write<glm::dvec3, glm::dvec3>(t[1]);
									write<glm::dvec3, glm::dvec3>(t[2]);
									write<glm::dvec3, glm::dvec3>(t[3]);
								}));

	template <>
	KUTILS_OVERLOAD_WRITER_IMPL(streamwriter, glm::dmat4x4, glm::dmat4x4, ({
									write<glm::dvec4, glm::dvec4>(t[0]);
									write<glm::dvec4, glm::dvec4>(t[1]);
									write<glm::dvec4, glm::dvec4>(t[2]);
									write<glm::dvec4, glm::dvec4>(t[3]);
								}));

}	// namespace khutils

#endif	// defined (KHUTILS_WRITER_GLM_IMPL)

#endif	// !KHUTILS_WRITER_GLM_HPP_INC
