﻿#ifndef KHUTILS_GLM_COMPARISON_HPP_INC
#define KHUTILS_GLM_COMPARISON_HPP_INC

#include "khutils/comparison.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#if 0
//! disabled as constexpr incompatible with glm types
namespace std
{
	template <>
	constexpr glm::quat numeric_limits<glm::quat>::epsilon() noexcept
	{
		return glm::quat(numeric_limits<float>::epsilon(),
						 numeric_limits<float>::epsilon(),
						 numeric_limits<float>::epsilon(),
						 numeric_limits<float>::epsilon());
	}
	template <>
	const glm::vec2 numeric_limits<glm::vec2>::epsilon() noexcept
	{
		return glm::vec2(numeric_limits<float>::epsilon());
	}
	template <>
	const glm::vec3 numeric_limits<glm::vec3>::epsilon() noexcept
	{
		return glm::vec3(numeric_limits<float>::epsilon());
	}
	template <>
	const glm::vec4 numeric_limits<glm::vec4>::epsilon() noexcept
	{
		return glm::vec4(numeric_limits<float>::epsilon());
	}
	template <>
	const glm::mat4 numeric_limits<glm::mat4>::epsilon() noexcept
	{
		return glm::mat4(numeric_limits<float>::epsilon());
	}
	template <>
	const glm::dquat numeric_limits<glm::dquat>::epsilon() noexcept
	{
		return glm::dquat(numeric_limits<double>::epsilon());
	}
	template <>
	const glm::dvec2 numeric_limits<glm::dvec2>::epsilon() noexcept
	{
		return glm::dvec2(numeric_limits<double>::epsilon());
	}
	template <>
	const glm::dvec3 numeric_limits<glm::dvec3>::epsilon() noexcept
	{
		return glm::dvec3(numeric_limits<double>::epsilon());
	}
	template <>
	const glm::dvec4 numeric_limits<glm::dvec4>::epsilon() noexcept
	{
		return glm::dvec4(numeric_limits<double>::epsilon());
	}
	template <>
	const glm::dmat4 numeric_limits<glm::dmat4>::epsilon() noexcept
	{
		return glm::dmat4(numeric_limits<double>::epsilon());
	}
	template <>
	const glm::ivec2 numeric_limits<glm::ivec2>::epsilon() noexcept
	{
		return glm::ivec2(numeric_limits<int>::epsilon());
	}
	template <>
	const glm::ivec3 numeric_limits<glm::ivec3>::epsilon() noexcept
	{
		return glm::ivec3(numeric_limits<int>::epsilon());
	}
	template <>
	const glm::ivec4 numeric_limits<glm::ivec4>::epsilon() noexcept
	{
		return glm::ivec4(numeric_limits<int>::epsilon());
	}
}	// namespace std
#endif	// 0

namespace khutils
{
	bool compare(const glm::quat& lhv, const glm::quat& rhv);
	bool compare(const glm::vec2& lhv, const glm::vec2& rhv);
	bool compare(const glm::vec3& lhv, const glm::vec3& rhv);
	bool compare(const glm::vec4& lhv, const glm::vec4& rhv);
	bool compare(const glm::mat4& lhv, const glm::mat4& rhv);
	bool compare(const glm::dquat& lhv, const glm::dquat& rhv);
	bool compare(const glm::dvec2& lhv, const glm::dvec2& rhv);
	bool compare(const glm::dvec3& lhv, const glm::dvec3& rhv);
	bool compare(const glm::dvec4& lhv, const glm::dvec4& rhv);
	bool compare(const glm::dmat4& lhv, const glm::dmat4& rhv);
	bool compare(const glm::ivec2& lhv, const glm::ivec2& rhv);
	bool compare(const glm::ivec3& lhv, const glm::ivec3& rhv);
	bool compare(const glm::ivec4& lhv, const glm::ivec4& rhv);
	bool compare(const glm::uvec2& lhv, const glm::uvec2& rhv);
	bool compare(const glm::uvec3& lhv, const glm::uvec3& rhv);
	bool compare(const glm::uvec4& lhv, const glm::uvec4& rhv);
	bool compare(const glm::i8vec2& lhv, const glm::i8vec2& rhv);
	bool compare(const glm::i8vec3& lhv, const glm::i8vec3& rhv);
	bool compare(const glm::i8vec4& lhv, const glm::i8vec4& rhv);
	bool compare(const glm::u8vec2& lhv, const glm::u8vec2& rhv);
	bool compare(const glm::u8vec3& lhv, const glm::u8vec3& rhv);
	bool compare(const glm::u8vec4& lhv, const glm::u8vec4& rhv);
	bool compare(const glm::i16vec2& lhv, const glm::i16vec2& rhv);
	bool compare(const glm::i16vec3& lhv, const glm::i16vec3& rhv);
	bool compare(const glm::i16vec4& lhv, const glm::i16vec4& rhv);
	bool compare(const glm::u16vec2& lhv, const glm::u16vec2& rhv);
	bool compare(const glm::u16vec3& lhv, const glm::u16vec3& rhv);
	bool compare(const glm::u16vec4& lhv, const glm::u16vec4& rhv);

	bool compareLiterally(const glm::quat& lhv, const glm::quat& rhv);
	bool compareLiterally(const glm::vec2& lhv, const glm::vec2& rhv);
	bool compareLiterally(const glm::vec3& lhv, const glm::vec3& rhv);
	bool compareLiterally(const glm::vec4& lhv, const glm::vec4& rhv);
	bool compareLiterally(const glm::mat4& lhv, const glm::mat4& rhv);
	bool compareLiterally(const glm::dquat& lhv, const glm::dquat& rhv);
	bool compareLiterally(const glm::dvec2& lhv, const glm::dvec2& rhv);
	bool compareLiterally(const glm::dvec3& lhv, const glm::dvec3& rhv);
	bool compareLiterally(const glm::dvec4& lhv, const glm::dvec4& rhv);
	bool compareLiterally(const glm::dmat4& lhv, const glm::dmat4& rhv);
	bool compareLiterally(const glm::ivec2& lhv, const glm::ivec2& rhv);
	bool compareLiterally(const glm::ivec3& lhv, const glm::ivec3& rhv);
	bool compareLiterally(const glm::ivec4& lhv, const glm::ivec4& rhv);
	bool compareLiterally(const glm::uvec2& lhv, const glm::uvec2& rhv);
	bool compareLiterally(const glm::uvec3& lhv, const glm::uvec3& rhv);
	bool compareLiterally(const glm::uvec4& lhv, const glm::uvec4& rhv);
	bool compareLiterally(const glm::i8vec2& lhv, const glm::i8vec2& rhv);
	bool compareLiterally(const glm::i8vec3& lhv, const glm::i8vec3& rhv);
	bool compareLiterally(const glm::i8vec4& lhv, const glm::i8vec4& rhv);
	bool compareLiterally(const glm::u8vec2& lhv, const glm::u8vec2& rhv);
	bool compareLiterally(const glm::u8vec3& lhv, const glm::u8vec3& rhv);
	bool compareLiterally(const glm::u8vec4& lhv, const glm::u8vec4& rhv);
	bool compareLiterally(const glm::i16vec2& lhv, const glm::i16vec2& rhv);
	bool compareLiterally(const glm::i16vec3& lhv, const glm::i16vec3& rhv);
	bool compareLiterally(const glm::i16vec4& lhv, const glm::i16vec4& rhv);
	bool compareLiterally(const glm::u16vec2& lhv, const glm::u16vec2& rhv);
	bool compareLiterally(const glm::u16vec3& lhv, const glm::u16vec3& rhv);
	bool compareLiterally(const glm::u16vec4& lhv, const glm::u16vec4& rhv);

	template <>
	bool compareEpsilon(const glm::quat& lhv, const glm::quat& rhv, glm::quat epsilon);
	template <>
	bool compareEpsilon(const glm::vec2& lhv, const glm::vec2& rhv, glm::vec2 epsilon);
	template <>
	bool compareEpsilon(const glm::vec3& lhv, const glm::vec3& rhv, glm::vec3 epsilon);
	template <>
	bool compareEpsilon(const glm::vec4& lhv, const glm::vec4& rhv, glm::vec4 epsilon);
	template <>
	bool compareEpsilon(const glm::mat4& lhv, const glm::mat4& rhv, glm::mat4 epsilon);
	template <>
	bool compareEpsilon(const glm::dquat& lhv, const glm::dquat& rhv, glm::dquat epsilon);
	template <>
	bool compareEpsilon(const glm::dvec2& lhv, const glm::dvec2& rhv, glm::dvec2 epsilon);
	template <>
	bool compareEpsilon(const glm::dvec3& lhv, const glm::dvec3& rhv, glm::dvec3 epsilon);
	template <>
	bool compareEpsilon(const glm::dvec4& lhv, const glm::dvec4& rhv, glm::dvec4 epsilon);
	template <>
	bool compareEpsilon(const glm::dmat4& lhv, const glm::dmat4& rhv, glm::dmat4 epsilon);

	template <>
	bool compareEpsilon(const glm::ivec2& lhv, const glm::ivec2& rhv, glm::ivec2 epsilon);
	template <>
	bool compareEpsilon(const glm::ivec3& lhv, const glm::ivec3& rhv, glm::ivec3 epsilon);
	template <>
	bool compareEpsilon(const glm::ivec4& lhv, const glm::ivec4& rhv, glm::ivec4 epsilon);
	template <>
	bool compareEpsilon(const glm::uvec2& lhv, const glm::uvec2& rhv, glm::uvec2 epsilon);
	template <>
	bool compareEpsilon(const glm::uvec3& lhv, const glm::uvec3& rhv, glm::uvec3 epsilon);
	template <>
	bool compareEpsilon(const glm::uvec4& lhv, const glm::uvec4& rhv, glm::uvec4 epsilon);
	template <>
	bool compareEpsilon(const glm::i8vec2& lhv, const glm::i8vec2& rhv, glm::i8vec2 epsilon);
	template <>
	bool compareEpsilon(const glm::i8vec3& lhv, const glm::i8vec3& rhv, glm::i8vec3 epsilon);
	template <>
	bool compareEpsilon(const glm::i8vec4& lhv, const glm::i8vec4& rhv, glm::i8vec4 epsilon);
	template <>
	bool compareEpsilon(const glm::u8vec2& lhv, const glm::u8vec2& rhv, glm::u8vec2 epsilon);
	template <>
	bool compareEpsilon(const glm::u8vec3& lhv, const glm::u8vec3& rhv, glm::u8vec3 epsilon);
	template <>
	bool compareEpsilon(const glm::u8vec4& lhv, const glm::u8vec4& rhv, glm::u8vec4 epsilon);
	template <>
	bool compareEpsilon(const glm::i16vec2& lhv, const glm::i16vec2& rhv, glm::i16vec2 epsilon);
	template <>
	bool compareEpsilon(const glm::i16vec3& lhv, const glm::i16vec3& rhv, glm::i16vec3 epsilon);
	template <>
	bool compareEpsilon(const glm::i16vec4& lhv, const glm::i16vec4& rhv, glm::i16vec4 epsilon);
	template <>
	bool compareEpsilon(const glm::u16vec2& lhv, const glm::u16vec2& rhv, glm::u16vec2 epsilon);
	template <>
	bool compareEpsilon(const glm::u16vec3& lhv, const glm::u16vec3& rhv, glm::u16vec3 epsilon);
	template <>
	bool compareEpsilon(const glm::u16vec4& lhv, const glm::u16vec4& rhv, glm::u16vec4 epsilon);

	bool operator==(const glm::quat& lhv, const glm::quat& rhv);
	bool operator==(const glm::vec2& lhv, const glm::vec2& rhv);
	bool operator==(const glm::vec3& lhv, const glm::vec3& rhv);
	bool operator==(const glm::vec4& lhv, const glm::vec4& rhv);
	bool operator==(const glm::mat4& lhv, const glm::mat4& rhv);
	bool operator==(const glm::dquat& lhv, const glm::dquat& rhv);
	bool operator==(const glm::dvec2& lhv, const glm::dvec2& rhv);
	bool operator==(const glm::dvec3& lhv, const glm::dvec3& rhv);
	bool operator==(const glm::dvec4& lhv, const glm::dvec4& rhv);
	bool operator==(const glm::dmat4& lhv, const glm::dmat4& rhv);

	bool operator==(const glm::ivec2& lhv, const glm::ivec2& rhv);
	bool operator==(const glm::ivec3& lhv, const glm::ivec3& rhv);
	bool operator==(const glm::ivec4& lhv, const glm::ivec4& rhv);
	bool operator==(const glm::uvec2& lhv, const glm::uvec2& rhv);
	bool operator==(const glm::uvec3& lhv, const glm::uvec3& rhv);
	bool operator==(const glm::uvec4& lhv, const glm::uvec4& rhv);
	bool operator==(const glm::i8vec2& lhv, const glm::i8vec2& rhv);
	bool operator==(const glm::i8vec3& lhv, const glm::i8vec3& rhv);
	bool operator==(const glm::i8vec4& lhv, const glm::i8vec4& rhv);
	bool operator==(const glm::u8vec2& lhv, const glm::u8vec2& rhv);
	bool operator==(const glm::u8vec3& lhv, const glm::u8vec3& rhv);
	bool operator==(const glm::u8vec4& lhv, const glm::u8vec4& rhv);
	bool operator==(const glm::i16vec2& lhv, const glm::i16vec2& rhv);
	bool operator==(const glm::i16vec3& lhv, const glm::i16vec3& rhv);
	bool operator==(const glm::i16vec4& lhv, const glm::i16vec4& rhv);
	bool operator==(const glm::u16vec2& lhv, const glm::u16vec2& rhv);
	bool operator==(const glm::u16vec3& lhv, const glm::u16vec3& rhv);
	bool operator==(const glm::u16vec4& lhv, const glm::u16vec4& rhv);

}	// namespace khutils

#if defined(KHUTILS_GLM_COMPARISON_IMPL)

#include "khutils/comparison.hpp"
#include "khutils/glm/glm_comparison.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace khutils
{
	bool compare(const glm::quat& lhv, const glm::quat& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y) &&	//
		  compare(lhv.z, rhv.z) &&	//
		  compare(lhv.w, rhv.w);
	}

	bool compare(const glm::vec2& lhv, const glm::vec2& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y);
	}

	bool compare(const glm::vec3& lhv, const glm::vec3& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y) &&	//
		  compare(lhv.z, rhv.z);
	}

	bool compare(const glm::vec4& lhv, const glm::vec4& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y) &&	//
		  compare(lhv.z, rhv.z) &&	//
		  compare(lhv.w, rhv.w);
	}

	bool compare(const glm::mat4& lhv, const glm::mat4& rhv)
	{
		return							//
		  compare(lhv[0], rhv[0]) &&	//
		  compare(lhv[1], rhv[1]) &&	//
		  compare(lhv[2], rhv[2]) &&	//
		  compare(lhv[3], rhv[3]);
	}

	bool compare(const glm::dquat& lhv, const glm::dquat& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y) &&	//
		  compare(lhv.z, rhv.z) &&	//
		  compare(lhv.w, rhv.w);
	}

	bool compare(const glm::dvec2& lhv, const glm::dvec2& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y);
	}

	bool compare(const glm::dvec3& lhv, const glm::dvec3& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y) &&	//
		  compare(lhv.z, rhv.z);
	}

	bool compare(const glm::dvec4& lhv, const glm::dvec4& rhv)
	{
		return						  //
		  compare(lhv.x, rhv.x) &&	//
		  compare(lhv.y, rhv.y) &&	//
		  compare(lhv.z, rhv.z) &&	//
		  compare(lhv.w, rhv.w);
	}

	bool compare(const glm::dmat4& lhv, const glm::dmat4& rhv)
	{
		return							//
		  compare(lhv[0], rhv[0]) &&	//
		  compare(lhv[1], rhv[1]) &&	//
		  compare(lhv[2], rhv[2]) &&	//
		  compare(lhv[3], rhv[3]);
	}

	bool compare(const glm::ivec2& lhv, const glm::ivec2& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y;
	}

	bool compare(const glm::ivec3& lhv, const glm::ivec3& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z;
	}

	bool compare(const glm::ivec4& lhv, const glm::ivec4& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z &&	//
		  lhv.w == rhv.w;
	}

	bool compare(const glm::uvec2& lhv, const glm::uvec2& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y;
	}

	bool compare(const glm::uvec3& lhv, const glm::uvec3& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z;
	}

	bool compare(const glm::uvec4& lhv, const glm::uvec4& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z &&	//
		  lhv.w == rhv.w;
	}

	bool compare(const glm::i8vec2& lhv, const glm::i8vec2& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y;
	}

	bool compare(const glm::i8vec3& lhv, const glm::i8vec3& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z;
	}

	bool compare(const glm::i8vec4& lhv, const glm::i8vec4& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z &&	//
		  lhv.w == rhv.w;
	}

	bool compare(const glm::u8vec2& lhv, const glm::u8vec2& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y;
	}

	bool compare(const glm::u8vec3& lhv, const glm::u8vec3& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z;
	}

	bool compare(const glm::u8vec4& lhv, const glm::u8vec4& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z &&	//
		  lhv.w == rhv.w;
	}

	bool compare(const glm::i16vec2& lhv, const glm::i16vec2& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y;
	}

	bool compare(const glm::i16vec3& lhv, const glm::i16vec3& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z;
	}

	bool compare(const glm::i16vec4& lhv, const glm::i16vec4& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z &&	//
		  lhv.w == rhv.w;
	}

	bool compare(const glm::u16vec2& lhv, const glm::u16vec2& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y;
	}

	bool compare(const glm::u16vec3& lhv, const glm::u16vec3& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z;
	}

	bool compare(const glm::u16vec4& lhv, const glm::u16vec4& rhv)
	{
		return				   //
		  lhv.x == rhv.x &&	//
		  lhv.y == rhv.y &&	//
		  lhv.z == rhv.z &&	//
		  lhv.w == rhv.w;
	}

	bool compareLiterally(const glm::quat& lhv, const glm::quat& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::vec2& lhv, const glm::vec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::vec3& lhv, const glm::vec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::vec4& lhv, const glm::vec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::mat4& lhv, const glm::mat4& rhv)
	{
		return									 //
		  compareLiterally(lhv[0], rhv[0]) &&	//
		  compareLiterally(lhv[1], rhv[1]) &&	//
		  compareLiterally(lhv[2], rhv[2]) &&	//
		  compareLiterally(lhv[3], rhv[3]);
	}

	bool compareLiterally(const glm::dquat& lhv, const glm::dquat& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::dvec2& lhv, const glm::dvec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::dvec3& lhv, const glm::dvec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::dvec4& lhv, const glm::dvec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::dmat4& lhv, const glm::dmat4& rhv)
	{
		return									 //
		  compareLiterally(lhv[0], rhv[0]) &&	//
		  compareLiterally(lhv[1], rhv[1]) &&	//
		  compareLiterally(lhv[2], rhv[2]) &&	//
		  compareLiterally(lhv[3], rhv[3]);
	}

	bool compareLiterally(const glm::ivec2& lhv, const glm::ivec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::ivec3& lhv, const glm::ivec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::ivec4& lhv, const glm::ivec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::uvec2& lhv, const glm::uvec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::uvec3& lhv, const glm::uvec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::uvec4& lhv, const glm::uvec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::i8vec2& lhv, const glm::i8vec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::i8vec3& lhv, const glm::i8vec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::i8vec4& lhv, const glm::i8vec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::u8vec2& lhv, const glm::u8vec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::u8vec3& lhv, const glm::u8vec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::u8vec4& lhv, const glm::u8vec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::i16vec2& lhv, const glm::i16vec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::i16vec3& lhv, const glm::i16vec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::i16vec4& lhv, const glm::i16vec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	bool compareLiterally(const glm::u16vec2& lhv, const glm::u16vec2& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y);
	}

	bool compareLiterally(const glm::u16vec3& lhv, const glm::u16vec3& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z);
	}

	bool compareLiterally(const glm::u16vec4& lhv, const glm::u16vec4& rhv)
	{
		return								   //
		  compareLiterally(lhv.x, rhv.x) &&	//
		  compareLiterally(lhv.y, rhv.y) &&	//
		  compareLiterally(lhv.z, rhv.z) &&	//
		  compareLiterally(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::quat& lhv, const glm::quat& rhv, glm::quat epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::vec2& lhv, const glm::vec2& rhv, glm::vec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::vec3& lhv, const glm::vec3& rhv, glm::vec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::vec4& lhv, const glm::vec4& rhv, glm::vec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::mat4& lhv, const glm::mat4& rhv, glm::mat4 epsilon)
	{
		return								   //
		  compareEpsilon(lhv[0], rhv[0]) &&	//
		  compareEpsilon(lhv[1], rhv[1]) &&	//
		  compareEpsilon(lhv[2], rhv[2]) &&	//
		  compareEpsilon(lhv[3], rhv[3]);
	}

	template <>
	bool compareEpsilon(const glm::dquat& lhv, const glm::dquat& rhv, glm::dquat epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::dvec2& lhv, const glm::dvec2& rhv, glm::dvec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::dvec3& lhv, const glm::dvec3& rhv, glm::dvec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::dvec4& lhv, const glm::dvec4& rhv, glm::dvec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::dmat4& lhv, const glm::dmat4& rhv, glm::dmat4 epsilon)
	{
		return								   //
		  compareEpsilon(lhv[0], rhv[0]) &&	//
		  compareEpsilon(lhv[1], rhv[1]) &&	//
		  compareEpsilon(lhv[2], rhv[2]) &&	//
		  compareEpsilon(lhv[3], rhv[3]);
	}

	template <>
	bool compareEpsilon(const glm::ivec2& lhv, const glm::ivec2& rhv, glm::ivec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::ivec3& lhv, const glm::ivec3& rhv, glm::ivec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::ivec4& lhv, const glm::ivec4& rhv, glm::ivec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::uvec2& lhv, const glm::uvec2& rhv, glm::uvec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::uvec3& lhv, const glm::uvec3& rhv, glm::uvec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::uvec4& lhv, const glm::uvec4& rhv, glm::uvec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::i8vec2& lhv, const glm::i8vec2& rhv, glm::i8vec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::i8vec3& lhv, const glm::i8vec3& rhv, glm::i8vec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::i8vec4& lhv, const glm::i8vec4& rhv, glm::i8vec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::u8vec2& lhv, const glm::u8vec2& rhv, glm::u8vec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::u8vec3& lhv, const glm::u8vec3& rhv, glm::u8vec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::u8vec4& lhv, const glm::u8vec4& rhv, glm::u8vec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::i16vec2& lhv, const glm::i16vec2& rhv, glm::i16vec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::i16vec3& lhv, const glm::i16vec3& rhv, glm::i16vec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::i16vec4& lhv, const glm::i16vec4& rhv, glm::i16vec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	template <>
	bool compareEpsilon(const glm::u16vec2& lhv, const glm::u16vec2& rhv, glm::u16vec2 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y);
	}

	template <>
	bool compareEpsilon(const glm::u16vec3& lhv, const glm::u16vec3& rhv, glm::u16vec3 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z);
	}

	template <>
	bool compareEpsilon(const glm::u16vec4& lhv, const glm::u16vec4& rhv, glm::u16vec4 epsilon)
	{
		return								 //
		  compareEpsilon(lhv.x, rhv.x) &&	//
		  compareEpsilon(lhv.y, rhv.y) &&	//
		  compareEpsilon(lhv.z, rhv.z) &&	//
		  compareEpsilon(lhv.w, rhv.w);
	}

	bool operator==(const glm::quat& lhv, const glm::quat& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::vec2& lhv, const glm::vec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::vec3& lhv, const glm::vec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::vec4& lhv, const glm::vec4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::mat4& lhv, const glm::mat4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::dquat& lhv, const glm::dquat& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::dvec2& lhv, const glm::dvec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::dvec3& lhv, const glm::dvec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::dvec4& lhv, const glm::dvec4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::dmat4& lhv, const glm::dmat4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::ivec2& lhv, const glm::ivec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::ivec3& lhv, const glm::ivec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::ivec4& lhv, const glm::ivec4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::uvec2& lhv, const glm::uvec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::uvec3& lhv, const glm::uvec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::uvec4& lhv, const glm::uvec4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::i8vec2& lhv, const glm::i8vec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::i8vec3& lhv, const glm::i8vec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::i8vec4& lhv, const glm::i8vec4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::u8vec2& lhv, const glm::u8vec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::u8vec3& lhv, const glm::u8vec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::u8vec4& lhv, const glm::u8vec4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::i16vec2& lhv, const glm::i16vec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::i16vec3& lhv, const glm::i16vec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::i16vec4& lhv, const glm::i16vec4& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::u16vec2& lhv, const glm::u16vec2& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::u16vec3& lhv, const glm::u16vec3& rhv)
	{
		return compare(lhv, rhv);
	}

	bool operator==(const glm::u16vec4& lhv, const glm::u16vec4& rhv)
	{
		return compare(lhv, rhv);
	}

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_COMPARISON_IMPL)

#endif	// !KHUTILS_GLM_COMPARISON_HPP_INC