#ifndef KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC
#define KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC

#include <boost/config.hpp>
#include <boost/cstdint.hpp>

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

// overload function endian_reverse BEFORE including header
namespace boost
{
	namespace endian
	{
		inline glm::vec2 endian_reverse(glm::vec2 x) BOOST_NOEXCEPT;
		inline glm::vec3 endian_reverse(glm::vec3 x) BOOST_NOEXCEPT;
		inline glm::vec4 endian_reverse(glm::vec4 x) BOOST_NOEXCEPT;
		inline glm::quat endian_reverse(glm::quat x) BOOST_NOEXCEPT;
		inline glm::dvec2 endian_reverse(glm::dvec2 x) BOOST_NOEXCEPT;
		inline glm::dvec3 endian_reverse(glm::dvec3 x) BOOST_NOEXCEPT;
		inline glm::dvec4 endian_reverse(glm::dvec4 x) BOOST_NOEXCEPT;
		inline glm::dquat endian_reverse(glm::dquat x) BOOST_NOEXCEPT;
		inline glm::ivec2 endian_reverse(glm::ivec2 x) BOOST_NOEXCEPT;
		inline glm::ivec3 endian_reverse(glm::ivec3 x) BOOST_NOEXCEPT;
		inline glm::ivec4 endian_reverse(glm::ivec4 x) BOOST_NOEXCEPT;
		inline glm::uvec2 endian_reverse(glm::uvec2 x) BOOST_NOEXCEPT;
		inline glm::uvec3 endian_reverse(glm::uvec3 x) BOOST_NOEXCEPT;
		inline glm::uvec4 endian_reverse(glm::uvec4 x) BOOST_NOEXCEPT;
		inline glm::i8vec2 endian_reverse(glm::i8vec2 x) BOOST_NOEXCEPT;
		inline glm::i8vec3 endian_reverse(glm::i8vec3 x) BOOST_NOEXCEPT;
		inline glm::i8vec4 endian_reverse(glm::i8vec4 x) BOOST_NOEXCEPT;
		inline glm::u8vec2 endian_reverse(glm::u8vec2 x) BOOST_NOEXCEPT;
		inline glm::u8vec3 endian_reverse(glm::u8vec3 x) BOOST_NOEXCEPT;
		inline glm::u8vec4 endian_reverse(glm::u8vec4 x) BOOST_NOEXCEPT;
		inline glm::i16vec2 endian_reverse(glm::i16vec2 x) BOOST_NOEXCEPT;
		inline glm::i16vec3 endian_reverse(glm::i16vec3 x) BOOST_NOEXCEPT;
		inline glm::i16vec4 endian_reverse(glm::i16vec4 x) BOOST_NOEXCEPT;
		inline glm::u16vec2 endian_reverse(glm::u16vec2 x) BOOST_NOEXCEPT;
		inline glm::u16vec3 endian_reverse(glm::u16vec3 x) BOOST_NOEXCEPT;
		inline glm::u16vec4 endian_reverse(glm::u16vec4 x) BOOST_NOEXCEPT;
		inline glm::mat2x2 endian_reverse(glm::mat2x2 x) BOOST_NOEXCEPT;
		inline glm::mat2x3 endian_reverse(glm::mat2x3 x) BOOST_NOEXCEPT;
		inline glm::mat2x4 endian_reverse(glm::mat2x4 x) BOOST_NOEXCEPT;
		inline glm::mat3x2 endian_reverse(glm::mat3x2 x) BOOST_NOEXCEPT;
		inline glm::mat3x3 endian_reverse(glm::mat3x3 x) BOOST_NOEXCEPT;
		inline glm::mat3x4 endian_reverse(glm::mat3x4 x) BOOST_NOEXCEPT;
		inline glm::mat4x2 endian_reverse(glm::mat4x2 x) BOOST_NOEXCEPT;
		inline glm::mat4x3 endian_reverse(glm::mat4x3 x) BOOST_NOEXCEPT;
		inline glm::mat4x4 endian_reverse(glm::mat4x4 x) BOOST_NOEXCEPT;
		inline glm::dmat2x2 endian_reverse(glm::dmat2x2 x) BOOST_NOEXCEPT;
		inline glm::dmat2x3 endian_reverse(glm::dmat2x3 x) BOOST_NOEXCEPT;
		inline glm::dmat2x4 endian_reverse(glm::dmat2x4 x) BOOST_NOEXCEPT;
		inline glm::dmat3x2 endian_reverse(glm::dmat3x2 x) BOOST_NOEXCEPT;
		inline glm::dmat3x3 endian_reverse(glm::dmat3x3 x) BOOST_NOEXCEPT;
		inline glm::dmat3x4 endian_reverse(glm::dmat3x4 x) BOOST_NOEXCEPT;
		inline glm::dmat4x2 endian_reverse(glm::dmat4x2 x) BOOST_NOEXCEPT;
		inline glm::dmat4x3 endian_reverse(glm::dmat4x3 x) BOOST_NOEXCEPT;
		inline glm::dmat4x4 endian_reverse(glm::dmat4x4 x) BOOST_NOEXCEPT;

	}	// namespace endian
}	// namespace boost

#include "khutils/typeconversion.hpp"

namespace boost
{
	namespace endian
	{

		glm::vec2 endian_reverse(glm::vec2 x) BOOST_NOEXCEPT
		{
			return glm::vec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::vec3 endian_reverse(glm::vec3 x) BOOST_NOEXCEPT
		{
			return glm::vec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::vec4 endian_reverse(glm::vec4 x) BOOST_NOEXCEPT
		{
			return glm::vec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::quat endian_reverse(glm::quat x) BOOST_NOEXCEPT
		{
			return glm::quat{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::dvec2 endian_reverse(glm::dvec2 x) BOOST_NOEXCEPT
		{
			return glm::dvec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::dvec3 endian_reverse(glm::dvec3 x) BOOST_NOEXCEPT
		{
			return glm::dvec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::dvec4 endian_reverse(glm::dvec4 x) BOOST_NOEXCEPT
		{
			return glm::dvec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::dquat endian_reverse(glm::dquat x) BOOST_NOEXCEPT
		{
			return glm::dquat{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::ivec2 endian_reverse(glm::ivec2 x) BOOST_NOEXCEPT
		{
			return glm::ivec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::ivec3 endian_reverse(glm::ivec3 x) BOOST_NOEXCEPT
		{
			return glm::ivec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::ivec4 endian_reverse(glm::ivec4 x) BOOST_NOEXCEPT
		{
			return glm::ivec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::uvec2 endian_reverse(glm::uvec2 x) BOOST_NOEXCEPT
		{
			return glm::uvec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::uvec3 endian_reverse(glm::uvec3 x) BOOST_NOEXCEPT
		{
			return glm::uvec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::uvec4 endian_reverse(glm::uvec4 x) BOOST_NOEXCEPT
		{
			return glm::uvec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::i8vec2 endian_reverse(glm::i8vec2 x) BOOST_NOEXCEPT
		{
			return glm::i8vec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::i8vec3 endian_reverse(glm::i8vec3 x) BOOST_NOEXCEPT
		{
			return glm::i8vec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::i8vec4 endian_reverse(glm::i8vec4 x) BOOST_NOEXCEPT
		{
			return glm::i8vec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::u8vec2 endian_reverse(glm::u8vec2 x) BOOST_NOEXCEPT
		{
			return glm::u8vec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::u8vec3 endian_reverse(glm::u8vec3 x) BOOST_NOEXCEPT
		{
			return glm::u8vec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::u8vec4 endian_reverse(glm::u8vec4 x) BOOST_NOEXCEPT
		{
			return glm::u8vec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::i16vec2 endian_reverse(glm::i16vec2 x) BOOST_NOEXCEPT
		{
			return glm::i16vec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::i16vec3 endian_reverse(glm::i16vec3 x) BOOST_NOEXCEPT
		{
			return glm::i16vec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::i16vec4 endian_reverse(glm::i16vec4 x) BOOST_NOEXCEPT
		{
			return glm::i16vec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::u16vec2 endian_reverse(glm::u16vec2 x) BOOST_NOEXCEPT
		{
			return glm::u16vec2{
			  endian_reverse(x.x),
			  endian_reverse(x.y)	//
			};
		}

		glm::u16vec3 endian_reverse(glm::u16vec3 x) BOOST_NOEXCEPT
		{
			return glm::u16vec3{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z)	//
			};
		}

		glm::u16vec4 endian_reverse(glm::u16vec4 x) BOOST_NOEXCEPT
		{
			return glm::u16vec4{
			  endian_reverse(x.x),
			  endian_reverse(x.y),
			  endian_reverse(x.z),
			  endian_reverse(x.w)	//
			};
		}

		glm::mat2x2 endian_reverse(glm::mat2x2 x) BOOST_NOEXCEPT
		{
			return glm::mat2x2{
			  endian_reverse(x[0]),
			  endian_reverse(x[1])	//
			};
		}

		glm::mat2x3 endian_reverse(glm::mat2x3 x) BOOST_NOEXCEPT
		{
			return glm::mat2x3{
			  endian_reverse(x[0]),
			  endian_reverse(x[1])	//
			};
		}

		glm::mat2x4 endian_reverse(glm::mat2x4 x) BOOST_NOEXCEPT
		{
			return glm::mat2x4{
			  endian_reverse(x[0]),
			  endian_reverse(x[1])	//
			};
		}

		glm::mat3x2 endian_reverse(glm::mat3x2 x) BOOST_NOEXCEPT
		{
			return glm::mat3x2{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2])	//
			};
		}

		glm::mat3x3 endian_reverse(glm::mat3x3 x) BOOST_NOEXCEPT
		{
			return glm::mat3x3{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2])	//
			};
		}

		glm::mat3x4 endian_reverse(glm::mat3x4 x) BOOST_NOEXCEPT
		{
			return glm::mat3x4{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2])	//
			};
		}

		glm::mat4x2 endian_reverse(glm::mat4x2 x) BOOST_NOEXCEPT
		{
			return glm::mat4x2{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2]),
			  endian_reverse(x[3])	//
			};
		}

		glm::mat4x3 endian_reverse(glm::mat4x3 x) BOOST_NOEXCEPT
		{
			return glm::mat4x3{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2]),
			  endian_reverse(x[3])	//
			};
		}

		glm::mat4x4 endian_reverse(glm::mat4x4 x) BOOST_NOEXCEPT
		{
			return glm::mat4x4{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2]),
			  endian_reverse(x[3])	//
			};
		}

		glm::dmat2x2 endian_reverse(glm::dmat2x2 x) BOOST_NOEXCEPT
		{
			return glm::dmat2x2{
			  endian_reverse(x[0]),
			  endian_reverse(x[1])	//
			};
		}

		glm::dmat2x3 endian_reverse(glm::dmat2x3 x) BOOST_NOEXCEPT
		{
			return glm::dmat2x3{
			  endian_reverse(x[0]),
			  endian_reverse(x[1])	//
			};
		}

		glm::dmat2x4 endian_reverse(glm::dmat2x4 x) BOOST_NOEXCEPT
		{
			return glm::dmat2x4{
			  endian_reverse(x[0]),
			  endian_reverse(x[1])	//
			};
		}

		glm::dmat3x2 endian_reverse(glm::dmat3x2 x) BOOST_NOEXCEPT
		{
			return glm::dmat3x2{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2])	//
			};
		}

		glm::dmat3x3 endian_reverse(glm::dmat3x3 x) BOOST_NOEXCEPT
		{
			return glm::dmat3x3{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2])	//
			};
		}

		glm::dmat3x4 endian_reverse(glm::dmat3x4 x) BOOST_NOEXCEPT
		{
			return glm::dmat3x4{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2])	//
			};
		}

		glm::dmat4x2 endian_reverse(glm::dmat4x2 x) BOOST_NOEXCEPT
		{
			return glm::dmat4x2{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2]),
			  endian_reverse(x[3])	//
			};
		}

		glm::dmat4x3 endian_reverse(glm::dmat4x3 x) BOOST_NOEXCEPT
		{
			return glm::dmat4x3{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2]),
			  endian_reverse(x[3])	//
			};
		}

		glm::dmat4x4 endian_reverse(glm::dmat4x4 x) BOOST_NOEXCEPT
		{
			return glm::dmat4x4{
			  endian_reverse(x[0]),
			  endian_reverse(x[1]),
			  endian_reverse(x[2]),
			  endian_reverse(x[3])	//
			};
		}

	}	// namespace endian
}	// namespace boost

#endif	// KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC
