#ifndef KHUTILS_READER_GLM_HPP_INC
#define KHUTILS_READER_GLM_HPP_INC

#include "khutils/filereader.hpp"
#include "khutils/memoryreader.hpp"
#include "khutils/streamreader.hpp"

#include "khutils/reader_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include <boost/endian/conversion.hpp>

namespace khutils
{
	using boost::endian::order;

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::vec2, glm::vec2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::vec3, glm::vec3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::vec4, glm::vec4);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::quat, glm::quat);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dvec2, glm::dvec2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dvec3, glm::dvec3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dvec4, glm::dvec4);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dquat, glm::dquat);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::ivec2, glm::ivec2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::ivec3, glm::ivec3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::ivec4, glm::ivec4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat2x2, glm::mat2x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat2x3, glm::mat2x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat2x4, glm::mat2x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat3x2, glm::mat3x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat3x3, glm::mat3x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat3x4, glm::mat3x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat4x2, glm::mat4x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat4x3, glm::mat4x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::mat4x4, glm::mat4x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat2x2, glm::dmat2x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat2x3, glm::dmat2x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat2x4, glm::dmat2x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat3x2, glm::dmat3x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat3x3, glm::dmat3x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat3x4, glm::dmat3x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat4x2, glm::dmat4x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat4x3, glm::dmat4x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(streamreader, glm::dmat4x4, glm::dmat4x4);

#if 0
		/// _memoryreader<ByteForwardIterator>

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::vec2, glm::vec2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::vec3, glm::vec3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::vec4, glm::vec4);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::quat, glm::quat);

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dvec2, glm::dvec2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dvec3, glm::dvec3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dvec4, glm::dvec4);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dquat, glm::dquat);

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::ivec2, glm::ivec2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::ivec3, glm::ivec3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::ivec4, glm::ivec4);


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat2x2, glm::mat2x2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat2x3, glm::mat2x3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat2x4, glm::mat2x4);

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat3x2, glm::mat3x2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat3x3, glm::mat3x3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat3x4, glm::mat3x4);

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat4x2, glm::mat4x2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat4x3, glm::mat4x3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::mat4x4, glm::mat4x4);


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat2x2, glm::dmat2x2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat2x3, glm::dmat2x3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat2x4, glm::dmat2x4);

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat3x2, glm::dmat3x2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat3x3, glm::dmat3x3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat3x4, glm::dmat3x4);

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat4x2, glm::dmat4x2);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat4x3, glm::dmat4x3);
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_DECL(memoryreader<ByteForwardIterator>, glm::dmat4x4, glm::dmat4x4);
#endif	// 0
	/// _filereader

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::vec2, glm::vec2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::vec3, glm::vec3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::vec4, glm::vec4);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::quat, glm::quat);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dvec2, glm::dvec2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dvec3, glm::dvec3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dvec4, glm::dvec4);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dquat, glm::dquat);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::ivec2, glm::ivec2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::ivec3, glm::ivec3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::ivec4, glm::ivec4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat2x2, glm::mat2x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat2x3, glm::mat2x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat2x4, glm::mat2x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat3x2, glm::mat3x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat3x3, glm::mat3x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat3x4, glm::mat3x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat4x2, glm::mat4x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat4x3, glm::mat4x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::mat4x4, glm::mat4x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat2x2, glm::dmat2x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat2x3, glm::dmat2x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat2x4, glm::dmat2x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat3x2, glm::dmat3x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat3x3, glm::dmat3x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat3x4, glm::dmat3x4);

	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat4x2, glm::dmat4x2);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat4x3, glm::dmat4x3);
	template <>
	KUTILS_OVERLOAD_READER_DECL(filereader, glm::dmat4x4, glm::dmat4x4);

	////

}	// namespace khutils

#if defined(KHUTILS_READER_GLM_IMPL)

#include "khutils/reader_glm.hpp"

#include "khutils/filereader.hpp"
#include "khutils/memoryreader.hpp"
#include "khutils/streamreader.hpp"

#include "khutils/reader_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{
	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::vec2, glm::vec2, ({
									return glm::vec2{
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::vec3, glm::vec3, ({
									return glm::vec3{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::vec4, glm::vec4, ({
									return glm::vec4{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::quat, glm::quat, ({
									return glm::quat{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dvec2, glm::dvec2, ({
									return glm::dvec2{
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dvec3, glm::dvec3, ({
									return glm::dvec3{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dvec4, glm::dvec4, ({
									return glm::dvec4{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dquat, glm::dquat, ({
									return glm::dquat{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::ivec2, glm::ivec2, ({
									return glm::ivec2{
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::ivec3, glm::ivec3, ({
									return glm::ivec3{
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::ivec4, glm::ivec4, ({
									return glm::ivec4{
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat2x2, glm::mat2x2, ({
									return glm::mat2x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat2x3, glm::mat2x3, ({
									return glm::mat2x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat2x4, glm::mat2x4, ({
									return glm::mat2x4{
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat3x2, glm::mat3x2, ({
									return glm::mat3x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat3x3, glm::mat3x3, ({
									return glm::mat3x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat3x4, glm::mat3x4, ({
									return glm::mat3x4{

									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat4x2, glm::mat4x2, ({
									return glm::mat4x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat4x3, glm::mat4x3, ({
									return glm::mat4x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::mat4x4, glm::mat4x4, ({
									return glm::mat4x4{
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat2x2, glm::dmat2x2, ({
									return glm::dmat2x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat2x3, glm::dmat2x3, ({
									return glm::dmat2x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat2x4, glm::dmat2x4, ({
									return glm::dmat2x4{
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat3x2, glm::dmat3x2, ({
									return glm::dmat3x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat3x3, glm::dmat3x3, ({
									return glm::dmat3x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat3x4, glm::dmat3x4, ({
									return glm::dmat3x4{

									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat4x2, glm::dmat4x2, ({
									return glm::dmat4x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat4x3, glm::dmat4x3, ({
									return glm::dmat4x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(streamreader, glm::dmat4x4, glm::dmat4x4, ({
									return glm::dmat4x4{
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));

///
#if 0
		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::vec2, glm::vec2, ({
									return glm::vec2{
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::vec3, glm::vec3, ({
									return glm::vec3{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::vec4, glm::vec4, ({
									return glm::vec4{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::quat, glm::quat, ({
									return glm::quat{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dvec2, glm::dvec2, ({
									return glm::dvec2{
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dvec3, glm::dvec3, ({
									return glm::dvec3{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dvec4, glm::dvec4, ({
									return glm::dvec4{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dquat, glm::dquat, ({
									return glm::dquat{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::ivec2, glm::ivec2, ({
									return glm::ivec2{
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::ivec3, glm::ivec3, ({
									return glm::ivec3{
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::ivec4, glm::ivec4, ({
									return glm::ivec4{
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat2x2, glm::mat2x2, ({
									return glm::mat2x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat2x3, glm::mat2x3, ({
									return glm::mat2x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat2x4, glm::mat2x4, ({
									return glm::mat2x4{
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat3x2, glm::mat3x2, ({
									return glm::mat3x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat3x3, glm::mat3x3, ({
									return glm::mat3x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat3x4, glm::mat3x4, ({
									return glm::mat3x4{

									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat4x2, glm::mat4x2, ({
									return glm::mat4x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat4x3, glm::mat4x3, ({
									return glm::mat4x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::mat4x4, glm::mat4x4, ({
									return glm::mat4x4{
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat2x2, glm::dmat2x2, ({
									return glm::dmat2x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat2x3, glm::dmat2x3, ({
									return glm::dmat2x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat2x4, glm::dmat2x4, ({
									return glm::dmat2x4{
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat3x2, glm::dmat3x2, ({
									return glm::dmat3x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat3x3, glm::dmat3x3, ({
									return glm::dmat3x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat3x4, glm::dmat3x4, ({
									return glm::dmat3x4{

									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));


		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat4x2, glm::dmat4x2, ({
									return glm::dmat4x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat4x3, glm::dmat4x3, ({
									return glm::dmat4x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

		template <typename ByteForwardIterator>
		KUTILS_OVERLOAD_READER_IMPL(memoyreader<ByteForwardIterator>, glm::dmat4x4, glm::dmat4x4, ({
									return glm::dmat4x4{
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));
#endif
	///

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::vec2, glm::vec2, ({
									return glm::vec2{
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::vec3, glm::vec3, ({
									return glm::vec3{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::vec4, glm::vec4, ({
									return glm::vec4{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::quat, glm::quat, ({
									return glm::quat{
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>(),	//
									  read<float, int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dvec2, glm::dvec2, ({
									return glm::dvec2{
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dvec3, glm::dvec3, ({
									return glm::dvec3{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dvec4, glm::dvec4, ({
									return glm::dvec4{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dquat, glm::dquat, ({
									return glm::dquat{
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>(),	//
									  read<double, int64_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::ivec2, glm::ivec2, ({
									return glm::ivec2{
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::ivec3, glm::ivec3, ({
									return glm::ivec3{
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::ivec4, glm::ivec4, ({
									return glm::ivec4{
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>(),	//
									  read<int32_t>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat2x2, glm::mat2x2, ({
									return glm::mat2x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat2x3, glm::mat2x3, ({
									return glm::mat2x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat2x4, glm::mat2x4, ({
									return glm::mat2x4{
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat3x2, glm::mat3x2, ({
									return glm::mat3x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat3x3, glm::mat3x3, ({
									return glm::mat3x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat3x4, glm::mat3x4, ({
									return glm::mat3x4{

									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat4x2, glm::mat4x2, ({
									return glm::mat4x2{
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>(),	//
									  read<glm::vec2, glm::vec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat4x3, glm::mat4x3, ({
									return glm::mat4x3{
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>(),	//
									  read<glm::vec3, glm::vec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::mat4x4, glm::mat4x4, ({
									return glm::mat4x4{
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>(),	//
									  read<glm::vec4, glm::vec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat2x2, glm::dmat2x2, ({
									return glm::dmat2x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat2x3, glm::dmat2x3, ({
									return glm::dmat2x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat2x4, glm::dmat2x4, ({
									return glm::dmat2x4{
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat3x2, glm::dmat3x2, ({
									return glm::dmat3x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat3x3, glm::dmat3x3, ({
									return glm::dmat3x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat3x4, glm::dmat3x4, ({
									return glm::dmat3x4{

									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat4x2, glm::dmat4x2, ({
									return glm::dmat4x2{
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>(),	//
									  read<glm::dvec2, glm::dvec2>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat4x3, glm::dmat4x3, ({
									return glm::dmat4x3{
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>(),	//
									  read<glm::dvec3, glm::dvec3>()	 //
									};
								}));

	template <>
	KUTILS_OVERLOAD_READER_IMPL(filereader, glm::dmat4x4, glm::dmat4x4, ({
									return glm::dmat4x4{
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>(),	//
									  read<glm::dvec4, glm::dvec4>()	 //
									};
								}));

	////

}	// namespace khutils

#endif	// defined (KHUTILS_READER_GLM_IMPL)

#endif	// !KHUTILS_READER_GLM_HPP_INC
