#ifndef KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC
#define KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC

#include "khutils/endian.hpp"
#include "khutils/typeconversion.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{
	template <endian::order order_out, endian::order order_in = endian::native>
	glm::vec2 endian_reverse(glm::vec2 x)
	{
		return glm::vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::vec3 endian_reverse(glm::vec3 x)
	{
		return glm::vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::vec4 endian_reverse(glm::vec4 x)
	{
		return glm::vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::quat endian_reverse(glm::quat x)
	{
		return glm::quat{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dvec2 endian_reverse(glm::dvec2 x)
	{
		return glm::dvec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dvec3 endian_reverse(glm::dvec3 x)
	{
		return glm::dvec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dvec4 endian_reverse(glm::dvec4 x)
	{
		return glm::dvec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dquat endian_reverse(glm::dquat x)
	{
		return glm::dquat{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::ivec2 endian_reverse(glm::ivec2 x)
	{
		return glm::ivec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::ivec3 endian_reverse(glm::ivec3 x)
	{
		return glm::ivec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::ivec4 endian_reverse(glm::ivec4 x)
	{
		return glm::ivec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::uvec2 endian_reverse(glm::uvec2 x)
	{
		return glm::uvec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::uvec3 endian_reverse(glm::uvec3 x)
	{
		return glm::uvec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::uvec4 endian_reverse(glm::uvec4 x)
	{
		return glm::uvec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::i8vec2 endian_reverse(glm::i8vec2 x)
	{
		return glm::i8vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::i8vec3 endian_reverse(glm::i8vec3 x)
	{
		return glm::i8vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::i8vec4 endian_reverse(glm::i8vec4 x)
	{
		return glm::i8vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::u8vec2 endian_reverse(glm::u8vec2 x)
	{
		return glm::u8vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::u8vec3 endian_reverse(glm::u8vec3 x)
	{
		return glm::u8vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::u8vec4 endian_reverse(glm::u8vec4 x)
	{
		return glm::u8vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::i16vec2 endian_reverse(glm::i16vec2 x)
	{
		return glm::i16vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::i16vec3 endian_reverse(glm::i16vec3 x)
	{
		return glm::i16vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::i16vec4 endian_reverse(glm::i16vec4 x)
	{
		return glm::i16vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::u16vec2 endian_reverse(glm::u16vec2 x)
	{
		return glm::u16vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::u16vec3 endian_reverse(glm::u16vec3 x)
	{
		return glm::u16vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::u16vec4 endian_reverse(glm::u16vec4 x)
	{
		return glm::u16vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat2x2 endian_reverse(glm::mat2x2 x)
	{
		return glm::mat2x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat2x3 endian_reverse(glm::mat2x3 x)
	{
		return glm::mat2x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat2x4 endian_reverse(glm::mat2x4 x)
	{
		return glm::mat2x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat3x2 endian_reverse(glm::mat3x2 x)
	{
		return glm::mat3x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat3x3 endian_reverse(glm::mat3x3 x)
	{
		return glm::mat3x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat3x4 endian_reverse(glm::mat3x4 x)
	{
		return glm::mat3x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat4x2 endian_reverse(glm::mat4x2 x)
	{
		return glm::mat4x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat4x3 endian_reverse(glm::mat4x3 x)
	{
		return glm::mat4x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::mat4x4 endian_reverse(glm::mat4x4 x)
	{
		return glm::mat4x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat2x2 endian_reverse(glm::dmat2x2 x)
	{
		return glm::dmat2x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat2x3 endian_reverse(glm::dmat2x3 x)
	{
		return glm::dmat2x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat2x4 endian_reverse(glm::dmat2x4 x)
	{
		return glm::dmat2x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat3x2 endian_reverse(glm::dmat3x2 x)
	{
		return glm::dmat3x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat3x3 endian_reverse(glm::dmat3x3 x)
	{
		return glm::dmat3x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat3x4 endian_reverse(glm::dmat3x4 x)
	{
		return glm::dmat3x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat4x2 endian_reverse(glm::dmat4x2 x)
	{
		return glm::dmat4x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat4x3 endian_reverse(glm::dmat4x3 x)
	{
		return glm::dmat4x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	glm::dmat4x4 endian_reverse(glm::dmat4x4 x)
	{
		return glm::dmat4x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

}	// namespace khutils

#endif	// KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC
