#ifndef KHUTILS_GLM_LITTLE_ENDIAN_READER_HPP_INC
#define KHUTILS_GLM_LITTLE_ENDIAN_READER_HPP_INC

#include "khutils/glm/glm_endian_reverse.hpp"

#include "khutils/endian.hpp"
#include "khutils/filereader.hpp"
#include "khutils/memoryreader.hpp"
#include "khutils/reader_overload.hpp"
#include "khutils/streamreader.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>


namespace khutils
{
#define KUTILS_LITTLE_ENDIAN_READER_SEQ                                                                                \
	(little_endian_streamreader)(little_endian_filereader)(                                                            \
	  little_endian_memoryreader<char*>)(little_endian_memoryreader<uint8_t*>)(little_endian_memoryreader<             \
																			   std::vector<uint8_t>::iterator>)(little_endian_memoryreader<std::vector<uint8_t>::const_iterator>)

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::vec2, glm::vec2)
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::vec3, glm::vec3)
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::vec4, glm::vec4)
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::quat, glm::quat)

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dvec2, glm::dvec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dvec3, glm::dvec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dvec4, glm::dvec4);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dquat, glm::dquat);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::ivec2, glm::ivec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::ivec3, glm::ivec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::ivec4, glm::ivec4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::uvec2, glm::uvec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::uvec3, glm::uvec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::uvec4, glm::uvec4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i8vec2, glm::i8vec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i8vec3, glm::i8vec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i8vec4, glm::i8vec4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u8vec2, glm::u8vec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u8vec3, glm::u8vec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u8vec4, glm::u8vec4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i16vec2, glm::i16vec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i16vec3, glm::i16vec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i16vec4, glm::i16vec4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u16vec2, glm::u16vec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u16vec3, glm::u16vec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u16vec4, glm::u16vec4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat2x2, glm::mat2x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat2x3, glm::mat2x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat2x4, glm::mat2x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat3x2, glm::mat3x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat3x3, glm::mat3x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat3x4, glm::mat3x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat4x2, glm::mat4x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat4x3, glm::mat4x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat4x4, glm::mat4x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat2x2, glm::dmat2x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat2x3, glm::dmat2x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat2x4, glm::dmat2x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat3x2, glm::dmat3x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat3x3, glm::dmat3x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat3x4, glm::dmat3x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat4x2, glm::dmat4x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat4x3, glm::dmat4x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat4x4, glm::dmat4x4);

}	// namespace khutils

#if defined(KHUTILS_GLM_LITTLE_ENDIAN_READER_IMPL)

#include "khutils/glm/glm_little_endian_reader.hpp"

#include "khutils/filereader.hpp"
#include "khutils/memoryreader.hpp"
#include "khutils/streamreader.hpp"

#include "khutils/reader_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::vec2, glm::vec2, ({
									   return glm::vec2{
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::vec3, glm::vec3, ({
									   return glm::vec3{
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::vec4, glm::vec4, ({
									   return glm::vec4{
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::quat, glm::quat, ({
									   return glm::quat{
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dvec2, glm::dvec2, ({
									   return glm::dvec2{
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dvec3, glm::dvec3, ({
									   return glm::dvec3{
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dvec4, glm::dvec4, ({
									   return glm::dvec4{
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dquat, glm::dquat, ({
									   return glm::dquat{
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::ivec2, glm::ivec2, ({
									   return glm::ivec2{
										 read<int32_t>(),	//
										 read<int32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::ivec3, glm::ivec3, ({
									   return glm::ivec3{
										 read<int32_t>(),	//
										 read<int32_t>(),	//
										 read<int32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::ivec4, glm::ivec4, ({
									   return glm::ivec4{
										 read<int32_t>(),	//
										 read<int32_t>(),	//
										 read<int32_t>(),	//
										 read<int32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::uvec2, glm::uvec2, ({
									   return glm::uvec2{
										 read<uint32_t>(),	//
										 read<uint32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::uvec3, glm::uvec3, ({
									   return glm::uvec3{
										 read<uint32_t>(),	//
										 read<uint32_t>(),	//
										 read<uint32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::uvec4, glm::uvec4, ({
									   return glm::ivec4{
										 read<uint32_t>(),	//
										 read<uint32_t>(),	//
										 read<uint32_t>(),	//
										 read<uint32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i8vec2, glm::i8vec2, ({
									   return glm::i8vec2{
										 read<int8_t>(),	//
										 read<int8_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i8vec3, glm::i8vec3, ({
									   return glm::i8vec3{
										 read<int8_t>(),	//
										 read<int8_t>(),	//
										 read<int8_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i8vec4, glm::i8vec4, ({
									   return glm::i8vec4{
										 read<int8_t>(),	//
										 read<int8_t>(),	//
										 read<int8_t>(),	//
										 read<int8_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u8vec2, glm::u8vec2, ({
									   return glm::u8vec2{
										 read<uint8_t>(),	//
										 read<uint8_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u8vec3, glm::u8vec3, ({
									   return glm::u8vec3{
										 read<uint8_t>(),	//
										 read<uint8_t>(),	//
										 read<uint8_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u8vec4, glm::u8vec4, ({
									   return glm::i8vec4{
										 read<uint8_t>(),	//
										 read<uint8_t>(),	//
										 read<uint8_t>(),	//
										 read<uint8_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i16vec2, glm::i16vec2, ({
									   return glm::i16vec2{
										 read<int16_t>(),	//
										 read<int16_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i16vec3, glm::i16vec3, ({
									   return glm::i16vec3{
										 read<int16_t>(),	//
										 read<int16_t>(),	//
										 read<int16_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::i16vec4, glm::i16vec4, ({
									   return glm::i16vec4{
										 read<int16_t>(),	//
										 read<int16_t>(),	//
										 read<int16_t>(),	//
										 read<int16_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u16vec2, glm::u16vec2, ({
									   return glm::u16vec2{
										 read<uint16_t>(),	//
										 read<uint16_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u16vec3, glm::u16vec3, ({
									   return glm::u16vec3{
										 read<uint16_t>(),	//
										 read<uint16_t>(),	//
										 read<uint16_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::u16vec4, glm::u16vec4, ({
									   return glm::i16vec4{
										 read<uint16_t>(),	//
										 read<uint16_t>(),	//
										 read<uint16_t>(),	//
										 read<uint16_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat2x2, glm::mat2x2, ({
									   return glm::mat2x2{
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat2x3, glm::mat2x3, ({
									   return glm::mat2x3{
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat2x4, glm::mat2x4, ({
									   return glm::mat2x4{
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat3x2, glm::mat3x2, ({
									   return glm::mat3x2{
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat3x3, glm::mat3x3, ({
									   return glm::mat3x3{
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat3x4, glm::mat3x4, ({
									   return glm::mat3x4{

										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat4x2, glm::mat4x2, ({
									   return glm::mat4x2{
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat4x3, glm::mat4x3, ({
									   return glm::mat4x3{
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::mat4x4, glm::mat4x4, ({
									   return glm::mat4x4{
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat2x2, glm::dmat2x2, ({
									   return glm::dmat2x2{
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat2x3, glm::dmat2x3, ({
									   return glm::dmat2x3{
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat2x4, glm::dmat2x4, ({
									   return glm::dmat2x4{
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat3x2, glm::dmat3x2, ({
									   return glm::dmat3x2{
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat3x3, glm::dmat3x3, ({
									   return glm::dmat3x3{
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat3x4, glm::dmat3x4, ({
									   return glm::dmat3x4{

										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat4x2, glm::dmat4x2, ({
									   return glm::dmat4x2{
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat4x3, glm::dmat4x3, ({
									   return glm::dmat4x3{
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_READER_SEQ, glm::dmat4x4, glm::dmat4x4, ({
									   return glm::dmat4x4{
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>()		//
									   };
								   }));

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_LITTLE_ENDIAN_READER_IMPL)

#endif	// !KHUTILS_GLM_LITTLE_ENDIAN_READER_HPP_INC
