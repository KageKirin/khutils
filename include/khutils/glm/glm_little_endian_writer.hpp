#ifndef KHUTILS_GLM_LITTLE_ENDIAN_WRITER_HPP_INC
#define KHUTILS_GLM_LITTLE_ENDIAN_WRITER_HPP_INC

#include "khutils/glm/glm_endian_reverse.hpp"

#include "khutils/filewriter.hpp"
#include "khutils/memorywriter.hpp"
#include "khutils/streamwriter.hpp"

#include "khutils/writer_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{
	using boost::endian::order;

#define KUTILS_LITTLE_ENDIAN_WRITER_SEQ                                                                                \
	(little_endian_streamwriter)(little_endian_filewriter)(                                                            \
	  little_endian_memorywriter<char*>)(little_endian_memorywriter<uint8_t*>)(little_endian_memorywriter<std::vector<uint8_t>::iterator>)

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::vec2, glm::vec2)
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::vec3, glm::vec3)
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::vec4, glm::vec4)
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::quat, glm::quat)

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dvec2, glm::dvec2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dvec3, glm::dvec3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dvec4, glm::dvec4);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dquat, glm::dquat);

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::ivec2, glm::ivec2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::ivec3, glm::ivec3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::ivec4, glm::ivec4);

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat2x2, glm::mat2x2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat2x3, glm::mat2x3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat2x4, glm::mat2x4);

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat3x2, glm::mat3x2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat3x3, glm::mat3x3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat3x4, glm::mat3x4);

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat4x2, glm::mat4x2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat4x3, glm::mat4x3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat4x4, glm::mat4x4);

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat2x2, glm::dmat2x2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat2x3, glm::dmat2x3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat2x4, glm::dmat2x4);

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat3x2, glm::dmat3x2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat3x3, glm::dmat3x3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat3x4, glm::dmat3x4);

	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat4x2, glm::dmat4x2);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat4x3, glm::dmat4x3);
	KUTILS_OVERLOAD_WRITERSEQ_DECL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat4x4, glm::dmat4x4);

}	// namespace khutils

#if defined(KHUTILS_GLM_LITTLE_ENDIAN_WRITER_IMPL)

#include "khutils/glm/glm_little_endian_writer.hpp"

#include "khutils/filewriter.hpp"
#include "khutils/memorywriter.hpp"
#include "khutils/streamwriter.hpp"
#include "khutils/writer_overload.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{
	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::vec2, glm::vec2, ({
									   write<int32_t, float>(t.x);
									   write<int32_t, float>(t.y);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::vec3, glm::vec3, ({
									   write<int32_t, float>(t.x);
									   write<int32_t, float>(t.y);
									   write<int32_t, float>(t.z);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::vec4, glm::vec4, ({
									   write<int32_t, float>(t.x);
									   write<int32_t, float>(t.y);
									   write<int32_t, float>(t.z);
									   write<int32_t, float>(t.w);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::quat, glm::quat, ({
									   write<int32_t, float>(t.x);
									   write<int32_t, float>(t.y);
									   write<int32_t, float>(t.z);
									   write<int32_t, float>(t.w);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dvec2, glm::dvec2, ({
									   write<int64_t, double>(t.x);
									   write<int64_t, double>(t.y);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dvec3, glm::dvec3, ({
									   write<int64_t, double>(t.x);
									   write<int64_t, double>(t.y);
									   write<int64_t, double>(t.z);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dvec4, glm::dvec4, ({
									   write<int64_t, double>(t.x);
									   write<int64_t, double>(t.y);
									   write<int64_t, double>(t.z);
									   write<int64_t, double>(t.w);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dquat, glm::dquat, ({
									   write<int64_t, double>(t.x);
									   write<int64_t, double>(t.y);
									   write<int64_t, double>(t.z);
									   write<int64_t, double>(t.w);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::ivec2, glm::ivec2, ({
									   write<int32_t>(t.x);
									   write<int32_t>(t.y);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::ivec3, glm::ivec3, ({
									   write<int32_t>(t.x);
									   write<int32_t>(t.y);
									   write<int32_t>(t.z);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::ivec4, glm::ivec4, ({
									   write<int32_t>(t.x);
									   write<int32_t>(t.y);
									   write<int32_t>(t.z);
									   write<int32_t>(t.w);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat2x2, glm::mat2x2, ({
									   write<glm::vec2, glm::vec2>(t[0]);
									   write<glm::vec2, glm::vec2>(t[1]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat2x3, glm::mat2x3, ({
									   write<glm::vec3, glm::vec3>(t[0]);
									   write<glm::vec3, glm::vec3>(t[1]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat2x4, glm::mat2x4, ({
									   write<glm::vec4, glm::vec4>(t[0]);
									   write<glm::vec4, glm::vec4>(t[1]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat3x2, glm::mat3x2, ({
									   write<glm::vec2, glm::vec2>(t[0]);
									   write<glm::vec2, glm::vec2>(t[1]);
									   write<glm::vec2, glm::vec2>(t[2]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat3x3, glm::mat3x3, ({
									   write<glm::vec3, glm::vec3>(t[0]);
									   write<glm::vec3, glm::vec3>(t[1]);
									   write<glm::vec3, glm::vec3>(t[2]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat3x4, glm::mat3x4, ({
									   write<glm::vec4, glm::vec4>(t[0]);
									   write<glm::vec4, glm::vec4>(t[1]);
									   write<glm::vec4, glm::vec4>(t[2]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat4x2, glm::mat4x2, ({
									   write<glm::vec2, glm::vec2>(t[0]);
									   write<glm::vec2, glm::vec2>(t[1]);
									   write<glm::vec2, glm::vec2>(t[2]);
									   write<glm::vec2, glm::vec2>(t[3]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat4x3, glm::mat4x3, ({
									   write<glm::vec3, glm::vec3>(t[0]);
									   write<glm::vec3, glm::vec3>(t[1]);
									   write<glm::vec3, glm::vec3>(t[2]);
									   write<glm::vec3, glm::vec3>(t[3]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::mat4x4, glm::mat4x4, ({
									   write<glm::vec4, glm::vec4>(t[0]);
									   write<glm::vec4, glm::vec4>(t[1]);
									   write<glm::vec4, glm::vec4>(t[2]);
									   write<glm::vec4, glm::vec4>(t[3]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat2x2, glm::dmat2x2, ({
									   write<glm::dvec2, glm::dvec2>(t[0]);
									   write<glm::dvec2, glm::dvec2>(t[1]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat2x3, glm::dmat2x3, ({
									   write<glm::dvec3, glm::dvec3>(t[0]);
									   write<glm::dvec3, glm::dvec3>(t[1]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat2x4, glm::dmat2x4, ({
									   write<glm::dvec4, glm::dvec4>(t[0]);
									   write<glm::dvec4, glm::dvec4>(t[1]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat3x2, glm::dmat3x2, ({
									   write<glm::dvec2, glm::dvec2>(t[0]);
									   write<glm::dvec2, glm::dvec2>(t[1]);
									   write<glm::dvec2, glm::dvec2>(t[2]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat3x3, glm::dmat3x3, ({
									   write<glm::dvec3, glm::dvec3>(t[0]);
									   write<glm::dvec3, glm::dvec3>(t[1]);
									   write<glm::dvec3, glm::dvec3>(t[2]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat3x4, glm::dmat3x4, ({
									   write<glm::dvec4, glm::dvec4>(t[0]);
									   write<glm::dvec4, glm::dvec4>(t[1]);
									   write<glm::dvec4, glm::dvec4>(t[2]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat4x2, glm::dmat4x2, ({
									   write<glm::dvec2, glm::dvec2>(t[0]);
									   write<glm::dvec2, glm::dvec2>(t[1]);
									   write<glm::dvec2, glm::dvec2>(t[2]);
									   write<glm::dvec2, glm::dvec2>(t[3]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat4x3, glm::dmat4x3, ({
									   write<glm::dvec3, glm::dvec3>(t[0]);
									   write<glm::dvec3, glm::dvec3>(t[1]);
									   write<glm::dvec3, glm::dvec3>(t[2]);
									   write<glm::dvec3, glm::dvec3>(t[3]);
								   }));

	KUTILS_OVERLOAD_WRITERSEQ_IMPL(KUTILS_LITTLE_ENDIAN_WRITER_SEQ, glm::dmat4x4, glm::dmat4x4, ({
									   write<glm::dvec4, glm::dvec4>(t[0]);
									   write<glm::dvec4, glm::dvec4>(t[1]);
									   write<glm::dvec4, glm::dvec4>(t[2]);
									   write<glm::dvec4, glm::dvec4>(t[3]);
								   }));

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_LITTLE_ENDIAN_WRITER_IMPL)

#endif	// !KHUTILS_GLM_LITTLE_ENDIAN_WRITER_HPP_INC
