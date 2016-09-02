#ifndef KHUTILS_READER_NE_GLM_HPP_INC
#define KHUTILS_READER_NE_GLM_HPP_INC

#include "khutils/glm_endian.hpp"

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

#define KUTILS_NATIVE_ENDIAN_READER_SEQ                                                                                \
	(streamreader)(filereader)(                                                                                        \
	  memoryreader<char*>)(memoryreader<uint8_t*>)(memoryreader<std::vector<uint8_t>::iterator>)(memoryreader<std::vector<uint8_t>::const_iterator>)

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::vec2, glm::vec2)
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::vec3, glm::vec3)
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::vec4, glm::vec4)
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::quat, glm::quat)

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dvec2, glm::dvec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dvec3, glm::dvec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dvec4, glm::dvec4);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dquat, glm::dquat);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::ivec2, glm::ivec2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::ivec3, glm::ivec3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::ivec4, glm::ivec4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat2x2, glm::mat2x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat2x3, glm::mat2x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat2x4, glm::mat2x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat3x2, glm::mat3x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat3x3, glm::mat3x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat3x4, glm::mat3x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat4x2, glm::mat4x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat4x3, glm::mat4x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat4x4, glm::mat4x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat2x2, glm::dmat2x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat2x3, glm::dmat2x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat2x4, glm::dmat2x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat3x2, glm::dmat3x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat3x3, glm::dmat3x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat3x4, glm::dmat3x4);

	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat4x2, glm::dmat4x2);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat4x3, glm::dmat4x3);
	KUTILS_OVERLOAD_READERSEQ_DECL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat4x4, glm::dmat4x4);

}	// namespace khutils

#if defined(KHUTILS_READER_NE_GLM_IMPL)

#include "khutils/reader_ne_glm.hpp"

#include "khutils/filereader.hpp"
#include "khutils/memoryreader.hpp"
#include "khutils/streamreader.hpp"

#include "khutils/reader_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::vec2, glm::vec2, ({
									   return glm::vec2{
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::vec3, glm::vec3, ({
									   return glm::vec3{
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::vec4, glm::vec4, ({
									   return glm::vec4{
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::quat, glm::quat, ({
									   return glm::quat{
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>(),	//
										 read<float, int32_t>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dvec2, glm::dvec2, ({
									   return glm::dvec2{
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dvec3, glm::dvec3, ({
									   return glm::dvec3{
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dvec4, glm::dvec4, ({
									   return glm::dvec4{
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dquat, glm::dquat, ({
									   return glm::dquat{
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>(),	//
										 read<double, int64_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::ivec2, glm::ivec2, ({
									   return glm::ivec2{
										 read<int32_t>(),	//
										 read<int32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::ivec3, glm::ivec3, ({
									   return glm::ivec3{
										 read<int32_t>(),	//
										 read<int32_t>(),	//
										 read<int32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::ivec4, glm::ivec4, ({
									   return glm::ivec4{
										 read<int32_t>(),	//
										 read<int32_t>(),	//
										 read<int32_t>(),	//
										 read<int32_t>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat2x2, glm::mat2x2, ({
									   return glm::mat2x2{
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat2x3, glm::mat2x3, ({
									   return glm::mat2x3{
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat2x4, glm::mat2x4, ({
									   return glm::mat2x4{
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat3x2, glm::mat3x2, ({
									   return glm::mat3x2{
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat3x3, glm::mat3x3, ({
									   return glm::mat3x3{
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat3x4, glm::mat3x4, ({
									   return glm::mat3x4{

										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat4x2, glm::mat4x2, ({
									   return glm::mat4x2{
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>(),	//
										 read<glm::vec2, glm::vec2>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat4x3, glm::mat4x3, ({
									   return glm::mat4x3{
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>(),	//
										 read<glm::vec3, glm::vec3>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::mat4x4, glm::mat4x4, ({
									   return glm::mat4x4{
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>(),	//
										 read<glm::vec4, glm::vec4>()	 //
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat2x2, glm::dmat2x2, ({
									   return glm::dmat2x2{
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat2x3, glm::dmat2x3, ({
									   return glm::dmat2x3{
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat2x4, glm::dmat2x4, ({
									   return glm::dmat2x4{
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat3x2, glm::dmat3x2, ({
									   return glm::dmat3x2{
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat3x3, glm::dmat3x3, ({
									   return glm::dmat3x3{
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat3x4, glm::dmat3x4, ({
									   return glm::dmat3x4{

										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat4x2, glm::dmat4x2, ({
									   return glm::dmat4x2{
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>(),	//
										 read<glm::dvec2, glm::dvec2>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat4x3, glm::dmat4x3, ({
									   return glm::dmat4x3{
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>(),	//
										 read<glm::dvec3, glm::dvec3>()		//
									   };
								   }));

	KUTILS_OVERLOAD_READERSEQ_IMPL(KUTILS_NATIVE_ENDIAN_READER_SEQ, glm::dmat4x4, glm::dmat4x4, ({
									   return glm::dmat4x4{
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>(),	//
										 read<glm::dvec4, glm::dvec4>()		//
									   };
								   }));

}	// namespace khutils

#endif	// defined (KHUTILS_READER_NE_GLM_IMPL)

#endif	// !KHUTILS_READER_NE_GLM_HPP_INC
