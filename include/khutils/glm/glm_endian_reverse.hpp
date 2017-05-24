#ifndef KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC
#define KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC

#include "khutils/endian.hpp"
#include "khutils/typeconversion.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace khutils
{
	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::vec2 endian_reverse(glm::vec2 x)
	{
		return glm::vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::vec3 endian_reverse(glm::vec3 x)
	{
		return glm::vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::vec4 endian_reverse(glm::vec4 x)
	{
		return glm::vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::quat endian_reverse(glm::quat x)
	{
		return glm::quat{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dvec2 endian_reverse(glm::dvec2 x)
	{
		return glm::dvec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dvec3 endian_reverse(glm::dvec3 x)
	{
		return glm::dvec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dvec4 endian_reverse(glm::dvec4 x)
	{
		return glm::dvec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dquat endian_reverse(glm::dquat x)
	{
		return glm::dquat{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::ivec2 endian_reverse(glm::ivec2 x)
	{
		return glm::ivec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::ivec3 endian_reverse(glm::ivec3 x)
	{
		return glm::ivec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::ivec4 endian_reverse(glm::ivec4 x)
	{
		return glm::ivec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::uvec2 endian_reverse(glm::uvec2 x)
	{
		return glm::uvec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::uvec3 endian_reverse(glm::uvec3 x)
	{
		return glm::uvec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::uvec4 endian_reverse(glm::uvec4 x)
	{
		return glm::uvec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::i8vec2 endian_reverse(glm::i8vec2 x)
	{
		return glm::i8vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::i8vec3 endian_reverse(glm::i8vec3 x)
	{
		return glm::i8vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::i8vec4 endian_reverse(glm::i8vec4 x)
	{
		return glm::i8vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::u8vec2 endian_reverse(glm::u8vec2 x)
	{
		return glm::u8vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::u8vec3 endian_reverse(glm::u8vec3 x)
	{
		return glm::u8vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::u8vec4 endian_reverse(glm::u8vec4 x)
	{
		return glm::u8vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::i16vec2 endian_reverse(glm::i16vec2 x)
	{
		return glm::i16vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::i16vec3 endian_reverse(glm::i16vec3 x)
	{
		return glm::i16vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::i16vec4 endian_reverse(glm::i16vec4 x)
	{
		return glm::i16vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::u16vec2 endian_reverse(glm::u16vec2 x)
	{
		return glm::u16vec2{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y)	 //
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::u16vec3 endian_reverse(glm::u16vec3 x)
	{
		return glm::u16vec3{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::u16vec4 endian_reverse(glm::u16vec4 x)
	{
		return glm::u16vec4{
		  endian_reverse<order_out, order_in>(x.x),	//
		  endian_reverse<order_out, order_in>(x.y),
		  endian_reverse<order_out, order_in>(x.z),
		  endian_reverse<order_out, order_in>(x.w)	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat2x2 endian_reverse(glm::mat2x2 x)
	{
		return glm::mat2x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat2x3 endian_reverse(glm::mat2x3 x)
	{
		return glm::mat2x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat2x4 endian_reverse(glm::mat2x4 x)
	{
		return glm::mat2x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat3x2 endian_reverse(glm::mat3x2 x)
	{
		return glm::mat3x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat3x3 endian_reverse(glm::mat3x3 x)
	{
		return glm::mat3x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat3x4 endian_reverse(glm::mat3x4 x)
	{
		return glm::mat3x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat4x2 endian_reverse(glm::mat4x2 x)
	{
		return glm::mat4x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat4x3 endian_reverse(glm::mat4x3 x)
	{
		return glm::mat4x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::mat4x4 endian_reverse(glm::mat4x4 x)
	{
		return glm::mat4x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat2x2 endian_reverse(glm::dmat2x2 x)
	{
		return glm::dmat2x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat2x3 endian_reverse(glm::dmat2x3 x)
	{
		return glm::dmat2x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat2x4 endian_reverse(glm::dmat2x4 x)
	{
		return glm::dmat2x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1])		//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat3x2 endian_reverse(glm::dmat3x2 x)
	{
		return glm::dmat3x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat3x3 endian_reverse(glm::dmat3x3 x)
	{
		return glm::dmat3x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat3x4 endian_reverse(glm::dmat3x4 x)
	{
		return glm::dmat3x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat4x2 endian_reverse(glm::dmat4x2 x)
	{
		return glm::dmat4x2{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat4x3 endian_reverse(glm::dmat4x3 x)
	{
		return glm::dmat4x3{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline glm::dmat4x4 endian_reverse(glm::dmat4x4 x)
	{
		return glm::dmat4x4{
		  endian_reverse<order_out, order_in>(x[0]),	//
		  endian_reverse<order_out, order_in>(x[1]),
		  endian_reverse<order_out, order_in>(x[2]),
		  endian_reverse<order_out, order_in>(x[3])	//
		};
	}


	/// _tpl overloads

	template <>
	inline glm::vec2 endian_reverse_tpl<glm::vec2, endian::order::little, endian::order::big>(glm::vec2 x)
	{
		return glm::vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::vec3 endian_reverse_tpl<glm::vec3, endian::order::little, endian::order::big>(glm::vec3 x)
	{
		return glm::vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::vec4 endian_reverse_tpl<glm::vec4, endian::order::little, endian::order::big>(glm::vec4 x)
	{
		return glm::vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::quat endian_reverse_tpl<glm::quat, endian::order::little, endian::order::big>(glm::quat x)
	{
		return glm::quat{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::dvec2 endian_reverse_tpl<glm::dvec2, endian::order::little, endian::order::big>(glm::dvec2 x)
	{
		return glm::dvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::dvec3 endian_reverse_tpl<glm::dvec3, endian::order::little, endian::order::big>(glm::dvec3 x)
	{
		return glm::dvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::dvec4 endian_reverse_tpl<glm::dvec4, endian::order::little, endian::order::big>(glm::dvec4 x)
	{
		return glm::dvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::dquat endian_reverse_tpl<glm::dquat, endian::order::little, endian::order::big>(glm::dquat x)
	{
		return glm::dquat{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::ivec2 endian_reverse_tpl<glm::ivec2, endian::order::little, endian::order::big>(glm::ivec2 x)
	{
		return glm::ivec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::ivec3 endian_reverse_tpl<glm::ivec3, endian::order::little, endian::order::big>(glm::ivec3 x)
	{
		return glm::ivec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::ivec4 endian_reverse_tpl<glm::ivec4, endian::order::little, endian::order::big>(glm::ivec4 x)
	{
		return glm::ivec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::uvec2 endian_reverse_tpl<glm::uvec2, endian::order::little, endian::order::big>(glm::uvec2 x)
	{
		return glm::uvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::uvec3 endian_reverse_tpl<glm::uvec3, endian::order::little, endian::order::big>(glm::uvec3 x)
	{
		return glm::uvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::uvec4 endian_reverse_tpl<glm::uvec4, endian::order::little, endian::order::big>(glm::uvec4 x)
	{
		return glm::uvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::i8vec2 endian_reverse_tpl<glm::i8vec2, endian::order::little, endian::order::big>(glm::i8vec2 x)
	{
		return glm::i8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::i8vec3 endian_reverse_tpl<glm::i8vec3, endian::order::little, endian::order::big>(glm::i8vec3 x)
	{
		return glm::i8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::i8vec4 endian_reverse_tpl<glm::i8vec4, endian::order::little, endian::order::big>(glm::i8vec4 x)
	{
		return glm::i8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::u8vec2 endian_reverse_tpl<glm::u8vec2, endian::order::little, endian::order::big>(glm::u8vec2 x)
	{
		return glm::u8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::u8vec3 endian_reverse_tpl<glm::u8vec3, endian::order::little, endian::order::big>(glm::u8vec3 x)
	{
		return glm::u8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::u8vec4 endian_reverse_tpl<glm::u8vec4, endian::order::little, endian::order::big>(glm::u8vec4 x)
	{
		return glm::u8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::i16vec2 endian_reverse_tpl<glm::i16vec2, endian::order::little, endian::order::big>(glm::i16vec2 x)
	{
		return glm::i16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::i16vec3 endian_reverse_tpl<glm::i16vec3, endian::order::little, endian::order::big>(glm::i16vec3 x)
	{
		return glm::i16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::i16vec4 endian_reverse_tpl<glm::i16vec4, endian::order::little, endian::order::big>(glm::i16vec4 x)
	{
		return glm::i16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::u16vec2 endian_reverse_tpl<glm::u16vec2, endian::order::little, endian::order::big>(glm::u16vec2 x)
	{
		return glm::u16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::u16vec3 endian_reverse_tpl<glm::u16vec3, endian::order::little, endian::order::big>(glm::u16vec3 x)
	{
		return glm::u16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::u16vec4 endian_reverse_tpl<glm::u16vec4, endian::order::little, endian::order::big>(glm::u16vec4 x)
	{
		return glm::u16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::mat2x2 endian_reverse_tpl<glm::mat2x2, endian::order::little, endian::order::big>(glm::mat2x2 x)
	{
		return glm::mat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x3 endian_reverse_tpl<glm::mat2x3, endian::order::little, endian::order::big>(glm::mat2x3 x)
	{
		return glm::mat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x4 endian_reverse_tpl<glm::mat2x4, endian::order::little, endian::order::big>(glm::mat2x4 x)
	{
		return glm::mat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::mat3x2 endian_reverse_tpl<glm::mat3x2, endian::order::little, endian::order::big>(glm::mat3x2 x)
	{
		return glm::mat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x3 endian_reverse_tpl<glm::mat3x3, endian::order::little, endian::order::big>(glm::mat3x3 x)
	{
		return glm::mat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x4 endian_reverse_tpl<glm::mat3x4, endian::order::little, endian::order::big>(glm::mat3x4 x)
	{
		return glm::mat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::mat4x2 endian_reverse_tpl<glm::mat4x2, endian::order::little, endian::order::big>(glm::mat4x2 x)
	{
		return glm::mat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x3 endian_reverse_tpl<glm::mat4x3, endian::order::little, endian::order::big>(glm::mat4x3 x)
	{
		return glm::mat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x4 endian_reverse_tpl<glm::mat4x4, endian::order::little, endian::order::big>(glm::mat4x4 x)
	{
		return glm::mat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::dmat2x2 endian_reverse_tpl<glm::dmat2x2, endian::order::little, endian::order::big>(glm::dmat2x2 x)
	{
		return glm::dmat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x3 endian_reverse_tpl<glm::dmat2x3, endian::order::little, endian::order::big>(glm::dmat2x3 x)
	{
		return glm::dmat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x4 endian_reverse_tpl<glm::dmat2x4, endian::order::little, endian::order::big>(glm::dmat2x4 x)
	{
		return glm::dmat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::dmat3x2 endian_reverse_tpl<glm::dmat3x2, endian::order::little, endian::order::big>(glm::dmat3x2 x)
	{
		return glm::dmat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x3 endian_reverse_tpl<glm::dmat3x3, endian::order::little, endian::order::big>(glm::dmat3x3 x)
	{
		return glm::dmat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x4 endian_reverse_tpl<glm::dmat3x4, endian::order::little, endian::order::big>(glm::dmat3x4 x)
	{
		return glm::dmat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::dmat4x2 endian_reverse_tpl<glm::dmat4x2, endian::order::little, endian::order::big>(glm::dmat4x2 x)
	{
		return glm::dmat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x3 endian_reverse_tpl<glm::dmat4x3, endian::order::little, endian::order::big>(glm::dmat4x3 x)
	{
		return glm::dmat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x4 endian_reverse_tpl<glm::dmat4x4, endian::order::little, endian::order::big>(glm::dmat4x4 x)
	{
		return glm::dmat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::big>(x[3])	//
		};
	}


	template <>
	inline glm::vec2 endian_reverse_tpl<glm::vec2, endian::order::big, endian::order::little>(glm::vec2 x)
	{
		return glm::vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::vec3 endian_reverse_tpl<glm::vec3, endian::order::big, endian::order::little>(glm::vec3 x)
	{
		return glm::vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::vec4 endian_reverse_tpl<glm::vec4, endian::order::big, endian::order::little>(glm::vec4 x)
	{
		return glm::vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::quat endian_reverse_tpl<glm::quat, endian::order::big, endian::order::little>(glm::quat x)
	{
		return glm::quat{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::dvec2 endian_reverse_tpl<glm::dvec2, endian::order::big, endian::order::little>(glm::dvec2 x)
	{
		return glm::dvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::dvec3 endian_reverse_tpl<glm::dvec3, endian::order::big, endian::order::little>(glm::dvec3 x)
	{
		return glm::dvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::dvec4 endian_reverse_tpl<glm::dvec4, endian::order::big, endian::order::little>(glm::dvec4 x)
	{
		return glm::dvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::dquat endian_reverse_tpl<glm::dquat, endian::order::big, endian::order::little>(glm::dquat x)
	{
		return glm::dquat{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::ivec2 endian_reverse_tpl<glm::ivec2, endian::order::big, endian::order::little>(glm::ivec2 x)
	{
		return glm::ivec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::ivec3 endian_reverse_tpl<glm::ivec3, endian::order::big, endian::order::little>(glm::ivec3 x)
	{
		return glm::ivec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::ivec4 endian_reverse_tpl<glm::ivec4, endian::order::big, endian::order::little>(glm::ivec4 x)
	{
		return glm::ivec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::uvec2 endian_reverse_tpl<glm::uvec2, endian::order::big, endian::order::little>(glm::uvec2 x)
	{
		return glm::uvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::uvec3 endian_reverse_tpl<glm::uvec3, endian::order::big, endian::order::little>(glm::uvec3 x)
	{
		return glm::uvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::uvec4 endian_reverse_tpl<glm::uvec4, endian::order::big, endian::order::little>(glm::uvec4 x)
	{
		return glm::uvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::i8vec2 endian_reverse_tpl<glm::i8vec2, endian::order::big, endian::order::little>(glm::i8vec2 x)
	{
		return glm::i8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::i8vec3 endian_reverse_tpl<glm::i8vec3, endian::order::big, endian::order::little>(glm::i8vec3 x)
	{
		return glm::i8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::i8vec4 endian_reverse_tpl<glm::i8vec4, endian::order::big, endian::order::little>(glm::i8vec4 x)
	{
		return glm::i8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::u8vec2 endian_reverse_tpl<glm::u8vec2, endian::order::big, endian::order::little>(glm::u8vec2 x)
	{
		return glm::u8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::u8vec3 endian_reverse_tpl<glm::u8vec3, endian::order::big, endian::order::little>(glm::u8vec3 x)
	{
		return glm::u8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::u8vec4 endian_reverse_tpl<glm::u8vec4, endian::order::big, endian::order::little>(glm::u8vec4 x)
	{
		return glm::u8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::i16vec2 endian_reverse_tpl<glm::i16vec2, endian::order::big, endian::order::little>(glm::i16vec2 x)
	{
		return glm::i16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::i16vec3 endian_reverse_tpl<glm::i16vec3, endian::order::big, endian::order::little>(glm::i16vec3 x)
	{
		return glm::i16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::i16vec4 endian_reverse_tpl<glm::i16vec4, endian::order::big, endian::order::little>(glm::i16vec4 x)
	{
		return glm::i16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::u16vec2 endian_reverse_tpl<glm::u16vec2, endian::order::big, endian::order::little>(glm::u16vec2 x)
	{
		return glm::u16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::u16vec3 endian_reverse_tpl<glm::u16vec3, endian::order::big, endian::order::little>(glm::u16vec3 x)
	{
		return glm::u16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::u16vec4 endian_reverse_tpl<glm::u16vec4, endian::order::big, endian::order::little>(glm::u16vec4 x)
	{
		return glm::u16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::mat2x2 endian_reverse_tpl<glm::mat2x2, endian::order::big, endian::order::little>(glm::mat2x2 x)
	{
		return glm::mat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x3 endian_reverse_tpl<glm::mat2x3, endian::order::big, endian::order::little>(glm::mat2x3 x)
	{
		return glm::mat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x4 endian_reverse_tpl<glm::mat2x4, endian::order::big, endian::order::little>(glm::mat2x4 x)
	{
		return glm::mat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::mat3x2 endian_reverse_tpl<glm::mat3x2, endian::order::big, endian::order::little>(glm::mat3x2 x)
	{
		return glm::mat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x3 endian_reverse_tpl<glm::mat3x3, endian::order::big, endian::order::little>(glm::mat3x3 x)
	{
		return glm::mat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x4 endian_reverse_tpl<glm::mat3x4, endian::order::big, endian::order::little>(glm::mat3x4 x)
	{
		return glm::mat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::mat4x2 endian_reverse_tpl<glm::mat4x2, endian::order::big, endian::order::little>(glm::mat4x2 x)
	{
		return glm::mat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x3 endian_reverse_tpl<glm::mat4x3, endian::order::big, endian::order::little>(glm::mat4x3 x)
	{
		return glm::mat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x4 endian_reverse_tpl<glm::mat4x4, endian::order::big, endian::order::little>(glm::mat4x4 x)
	{
		return glm::mat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::dmat2x2 endian_reverse_tpl<glm::dmat2x2, endian::order::big, endian::order::little>(glm::dmat2x2 x)
	{
		return glm::dmat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x3 endian_reverse_tpl<glm::dmat2x3, endian::order::big, endian::order::little>(glm::dmat2x3 x)
	{
		return glm::dmat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x4 endian_reverse_tpl<glm::dmat2x4, endian::order::big, endian::order::little>(glm::dmat2x4 x)
	{
		return glm::dmat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::dmat3x2 endian_reverse_tpl<glm::dmat3x2, endian::order::big, endian::order::little>(glm::dmat3x2 x)
	{
		return glm::dmat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x3 endian_reverse_tpl<glm::dmat3x3, endian::order::big, endian::order::little>(glm::dmat3x3 x)
	{
		return glm::dmat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x4 endian_reverse_tpl<glm::dmat3x4, endian::order::big, endian::order::little>(glm::dmat3x4 x)
	{
		return glm::dmat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::dmat4x2 endian_reverse_tpl<glm::dmat4x2, endian::order::big, endian::order::little>(glm::dmat4x2 x)
	{
		return glm::dmat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x3 endian_reverse_tpl<glm::dmat4x3, endian::order::big, endian::order::little>(glm::dmat4x3 x)
	{
		return glm::dmat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x4 endian_reverse_tpl<glm::dmat4x4, endian::order::big, endian::order::little>(glm::dmat4x4 x)
	{
		return glm::dmat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::little>(x[3])	//
		};
	}


	template <>
	inline glm::vec2 endian_reverse_tpl<glm::vec2, endian::order::little, endian::order::little>(glm::vec2 x)
	{
		return glm::vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::vec3 endian_reverse_tpl<glm::vec3, endian::order::little, endian::order::little>(glm::vec3 x)
	{
		return glm::vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::vec4 endian_reverse_tpl<glm::vec4, endian::order::little, endian::order::little>(glm::vec4 x)
	{
		return glm::vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::quat endian_reverse_tpl<glm::quat, endian::order::little, endian::order::little>(glm::quat x)
	{
		return glm::quat{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::dvec2 endian_reverse_tpl<glm::dvec2, endian::order::little, endian::order::little>(glm::dvec2 x)
	{
		return glm::dvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::dvec3 endian_reverse_tpl<glm::dvec3, endian::order::little, endian::order::little>(glm::dvec3 x)
	{
		return glm::dvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::dvec4 endian_reverse_tpl<glm::dvec4, endian::order::little, endian::order::little>(glm::dvec4 x)
	{
		return glm::dvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::dquat endian_reverse_tpl<glm::dquat, endian::order::little, endian::order::little>(glm::dquat x)
	{
		return glm::dquat{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::ivec2 endian_reverse_tpl<glm::ivec2, endian::order::little, endian::order::little>(glm::ivec2 x)
	{
		return glm::ivec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::ivec3 endian_reverse_tpl<glm::ivec3, endian::order::little, endian::order::little>(glm::ivec3 x)
	{
		return glm::ivec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::ivec4 endian_reverse_tpl<glm::ivec4, endian::order::little, endian::order::little>(glm::ivec4 x)
	{
		return glm::ivec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::uvec2 endian_reverse_tpl<glm::uvec2, endian::order::little, endian::order::little>(glm::uvec2 x)
	{
		return glm::uvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::uvec3 endian_reverse_tpl<glm::uvec3, endian::order::little, endian::order::little>(glm::uvec3 x)
	{
		return glm::uvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::uvec4 endian_reverse_tpl<glm::uvec4, endian::order::little, endian::order::little>(glm::uvec4 x)
	{
		return glm::uvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::i8vec2 endian_reverse_tpl<glm::i8vec2, endian::order::little, endian::order::little>(glm::i8vec2 x)
	{
		return glm::i8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::i8vec3 endian_reverse_tpl<glm::i8vec3, endian::order::little, endian::order::little>(glm::i8vec3 x)
	{
		return glm::i8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::i8vec4 endian_reverse_tpl<glm::i8vec4, endian::order::little, endian::order::little>(glm::i8vec4 x)
	{
		return glm::i8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::u8vec2 endian_reverse_tpl<glm::u8vec2, endian::order::little, endian::order::little>(glm::u8vec2 x)
	{
		return glm::u8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::u8vec3 endian_reverse_tpl<glm::u8vec3, endian::order::little, endian::order::little>(glm::u8vec3 x)
	{
		return glm::u8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::u8vec4 endian_reverse_tpl<glm::u8vec4, endian::order::little, endian::order::little>(glm::u8vec4 x)
	{
		return glm::u8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::i16vec2 endian_reverse_tpl<glm::i16vec2, endian::order::little, endian::order::little>(glm::i16vec2 x)
	{
		return glm::i16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::i16vec3 endian_reverse_tpl<glm::i16vec3, endian::order::little, endian::order::little>(glm::i16vec3 x)
	{
		return glm::i16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::i16vec4 endian_reverse_tpl<glm::i16vec4, endian::order::little, endian::order::little>(glm::i16vec4 x)
	{
		return glm::i16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::u16vec2 endian_reverse_tpl<glm::u16vec2, endian::order::little, endian::order::little>(glm::u16vec2 x)
	{
		return glm::u16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y)	 //
		};
	}

	template <>
	inline glm::u16vec3 endian_reverse_tpl<glm::u16vec3, endian::order::little, endian::order::little>(glm::u16vec3 x)
	{
		return glm::u16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z)	//
		};
	}

	template <>
	inline glm::u16vec4 endian_reverse_tpl<glm::u16vec4, endian::order::little, endian::order::little>(glm::u16vec4 x)
	{
		return glm::u16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::little, endian::order::little>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::little, endian::order::little>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::little, endian::order::little>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::little, endian::order::little>(x.w)	//
		};
	}

	template <>
	inline glm::mat2x2 endian_reverse_tpl<glm::mat2x2, endian::order::little, endian::order::little>(glm::mat2x2 x)
	{
		return glm::mat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x3 endian_reverse_tpl<glm::mat2x3, endian::order::little, endian::order::little>(glm::mat2x3 x)
	{
		return glm::mat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x4 endian_reverse_tpl<glm::mat2x4, endian::order::little, endian::order::little>(glm::mat2x4 x)
	{
		return glm::mat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::mat3x2 endian_reverse_tpl<glm::mat3x2, endian::order::little, endian::order::little>(glm::mat3x2 x)
	{
		return glm::mat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x3 endian_reverse_tpl<glm::mat3x3, endian::order::little, endian::order::little>(glm::mat3x3 x)
	{
		return glm::mat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x4 endian_reverse_tpl<glm::mat3x4, endian::order::little, endian::order::little>(glm::mat3x4 x)
	{
		return glm::mat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::mat4x2 endian_reverse_tpl<glm::mat4x2, endian::order::little, endian::order::little>(glm::mat4x2 x)
	{
		return glm::mat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x3 endian_reverse_tpl<glm::mat4x3, endian::order::little, endian::order::little>(glm::mat4x3 x)
	{
		return glm::mat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x4 endian_reverse_tpl<glm::mat4x4, endian::order::little, endian::order::little>(glm::mat4x4 x)
	{
		return glm::mat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::dmat2x2 endian_reverse_tpl<glm::dmat2x2, endian::order::little, endian::order::little>(glm::dmat2x2 x)
	{
		return glm::dmat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x3 endian_reverse_tpl<glm::dmat2x3, endian::order::little, endian::order::little>(glm::dmat2x3 x)
	{
		return glm::dmat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x4 endian_reverse_tpl<glm::dmat2x4, endian::order::little, endian::order::little>(glm::dmat2x4 x)
	{
		return glm::dmat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1])		//
		};
	}

	template <>
	inline glm::dmat3x2 endian_reverse_tpl<glm::dmat3x2, endian::order::little, endian::order::little>(glm::dmat3x2 x)
	{
		return glm::dmat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x3 endian_reverse_tpl<glm::dmat3x3, endian::order::little, endian::order::little>(glm::dmat3x3 x)
	{
		return glm::dmat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x4 endian_reverse_tpl<glm::dmat3x4, endian::order::little, endian::order::little>(glm::dmat3x4 x)
	{
		return glm::dmat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2])	//
		};
	}

	template <>
	inline glm::dmat4x2 endian_reverse_tpl<glm::dmat4x2, endian::order::little, endian::order::little>(glm::dmat4x2 x)
	{
		return glm::dmat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x3 endian_reverse_tpl<glm::dmat4x3, endian::order::little, endian::order::little>(glm::dmat4x3 x)
	{
		return glm::dmat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::little>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x4 endian_reverse_tpl<glm::dmat4x4, endian::order::little, endian::order::little>(glm::dmat4x4 x)
	{
		return glm::dmat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::little, endian::order::little>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::little, endian::order::little>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::little, endian::order::little>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::little, endian::order::little>(x[3])	//
		};
	}


	template <>
	inline glm::vec2 endian_reverse_tpl<glm::vec2, endian::order::big, endian::order::big>(glm::vec2 x)
	{
		return glm::vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::vec3 endian_reverse_tpl<glm::vec3, endian::order::big, endian::order::big>(glm::vec3 x)
	{
		return glm::vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::vec4 endian_reverse_tpl<glm::vec4, endian::order::big, endian::order::big>(glm::vec4 x)
	{
		return glm::vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::quat endian_reverse_tpl<glm::quat, endian::order::big, endian::order::big>(glm::quat x)
	{
		return glm::quat{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::dvec2 endian_reverse_tpl<glm::dvec2, endian::order::big, endian::order::big>(glm::dvec2 x)
	{
		return glm::dvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::dvec3 endian_reverse_tpl<glm::dvec3, endian::order::big, endian::order::big>(glm::dvec3 x)
	{
		return glm::dvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::dvec4 endian_reverse_tpl<glm::dvec4, endian::order::big, endian::order::big>(glm::dvec4 x)
	{
		return glm::dvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::dquat endian_reverse_tpl<glm::dquat, endian::order::big, endian::order::big>(glm::dquat x)
	{
		return glm::dquat{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::ivec2 endian_reverse_tpl<glm::ivec2, endian::order::big, endian::order::big>(glm::ivec2 x)
	{
		return glm::ivec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::ivec3 endian_reverse_tpl<glm::ivec3, endian::order::big, endian::order::big>(glm::ivec3 x)
	{
		return glm::ivec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::ivec4 endian_reverse_tpl<glm::ivec4, endian::order::big, endian::order::big>(glm::ivec4 x)
	{
		return glm::ivec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::uvec2 endian_reverse_tpl<glm::uvec2, endian::order::big, endian::order::big>(glm::uvec2 x)
	{
		return glm::uvec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::uvec3 endian_reverse_tpl<glm::uvec3, endian::order::big, endian::order::big>(glm::uvec3 x)
	{
		return glm::uvec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::uvec4 endian_reverse_tpl<glm::uvec4, endian::order::big, endian::order::big>(glm::uvec4 x)
	{
		return glm::uvec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::i8vec2 endian_reverse_tpl<glm::i8vec2, endian::order::big, endian::order::big>(glm::i8vec2 x)
	{
		return glm::i8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::i8vec3 endian_reverse_tpl<glm::i8vec3, endian::order::big, endian::order::big>(glm::i8vec3 x)
	{
		return glm::i8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::i8vec4 endian_reverse_tpl<glm::i8vec4, endian::order::big, endian::order::big>(glm::i8vec4 x)
	{
		return glm::i8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::u8vec2 endian_reverse_tpl<glm::u8vec2, endian::order::big, endian::order::big>(glm::u8vec2 x)
	{
		return glm::u8vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::u8vec3 endian_reverse_tpl<glm::u8vec3, endian::order::big, endian::order::big>(glm::u8vec3 x)
	{
		return glm::u8vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::u8vec4 endian_reverse_tpl<glm::u8vec4, endian::order::big, endian::order::big>(glm::u8vec4 x)
	{
		return glm::u8vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::i16vec2 endian_reverse_tpl<glm::i16vec2, endian::order::big, endian::order::big>(glm::i16vec2 x)
	{
		return glm::i16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::i16vec3 endian_reverse_tpl<glm::i16vec3, endian::order::big, endian::order::big>(glm::i16vec3 x)
	{
		return glm::i16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::i16vec4 endian_reverse_tpl<glm::i16vec4, endian::order::big, endian::order::big>(glm::i16vec4 x)
	{
		return glm::i16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::u16vec2 endian_reverse_tpl<glm::u16vec2, endian::order::big, endian::order::big>(glm::u16vec2 x)
	{
		return glm::u16vec2{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y)	 //
		};
	}

	template <>
	inline glm::u16vec3 endian_reverse_tpl<glm::u16vec3, endian::order::big, endian::order::big>(glm::u16vec3 x)
	{
		return glm::u16vec3{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z)	//
		};
	}

	template <>
	inline glm::u16vec4 endian_reverse_tpl<glm::u16vec4, endian::order::big, endian::order::big>(glm::u16vec4 x)
	{
		return glm::u16vec4{
		  endian_reverse_tpl<decltype(x.x), endian::order::big, endian::order::big>(x.x),	//
		  endian_reverse_tpl<decltype(x.y), endian::order::big, endian::order::big>(x.y),
		  endian_reverse_tpl<decltype(x.z), endian::order::big, endian::order::big>(x.z),
		  endian_reverse_tpl<decltype(x.w), endian::order::big, endian::order::big>(x.w)	//
		};
	}

	template <>
	inline glm::mat2x2 endian_reverse_tpl<glm::mat2x2, endian::order::big, endian::order::big>(glm::mat2x2 x)
	{
		return glm::mat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x3 endian_reverse_tpl<glm::mat2x3, endian::order::big, endian::order::big>(glm::mat2x3 x)
	{
		return glm::mat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::mat2x4 endian_reverse_tpl<glm::mat2x4, endian::order::big, endian::order::big>(glm::mat2x4 x)
	{
		return glm::mat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::mat3x2 endian_reverse_tpl<glm::mat3x2, endian::order::big, endian::order::big>(glm::mat3x2 x)
	{
		return glm::mat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x3 endian_reverse_tpl<glm::mat3x3, endian::order::big, endian::order::big>(glm::mat3x3 x)
	{
		return glm::mat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::mat3x4 endian_reverse_tpl<glm::mat3x4, endian::order::big, endian::order::big>(glm::mat3x4 x)
	{
		return glm::mat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::mat4x2 endian_reverse_tpl<glm::mat4x2, endian::order::big, endian::order::big>(glm::mat4x2 x)
	{
		return glm::mat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x3 endian_reverse_tpl<glm::mat4x3, endian::order::big, endian::order::big>(glm::mat4x3 x)
	{
		return glm::mat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::mat4x4 endian_reverse_tpl<glm::mat4x4, endian::order::big, endian::order::big>(glm::mat4x4 x)
	{
		return glm::mat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::dmat2x2 endian_reverse_tpl<glm::dmat2x2, endian::order::big, endian::order::big>(glm::dmat2x2 x)
	{
		return glm::dmat2x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x3 endian_reverse_tpl<glm::dmat2x3, endian::order::big, endian::order::big>(glm::dmat2x3 x)
	{
		return glm::dmat2x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::dmat2x4 endian_reverse_tpl<glm::dmat2x4, endian::order::big, endian::order::big>(glm::dmat2x4 x)
	{
		return glm::dmat2x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1])		//
		};
	}

	template <>
	inline glm::dmat3x2 endian_reverse_tpl<glm::dmat3x2, endian::order::big, endian::order::big>(glm::dmat3x2 x)
	{
		return glm::dmat3x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x3 endian_reverse_tpl<glm::dmat3x3, endian::order::big, endian::order::big>(glm::dmat3x3 x)
	{
		return glm::dmat3x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::dmat3x4 endian_reverse_tpl<glm::dmat3x4, endian::order::big, endian::order::big>(glm::dmat3x4 x)
	{
		return glm::dmat3x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2])	//
		};
	}

	template <>
	inline glm::dmat4x2 endian_reverse_tpl<glm::dmat4x2, endian::order::big, endian::order::big>(glm::dmat4x2 x)
	{
		return glm::dmat4x2{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x3 endian_reverse_tpl<glm::dmat4x3, endian::order::big, endian::order::big>(glm::dmat4x3 x)
	{
		return glm::dmat4x3{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::big>(x[3])	//
		};
	}

	template <>
	inline glm::dmat4x4 endian_reverse_tpl<glm::dmat4x4, endian::order::big, endian::order::big>(glm::dmat4x4 x)
	{
		return glm::dmat4x4{
		  endian_reverse_tpl<decltype(x[0]), endian::order::big, endian::order::big>(x[0]),	//
		  endian_reverse_tpl<decltype(x[1]), endian::order::big, endian::order::big>(x[1]),
		  endian_reverse_tpl<decltype(x[2]), endian::order::big, endian::order::big>(x[2]),
		  endian_reverse_tpl<decltype(x[3]), endian::order::big, endian::order::big>(x[3])	//
		};
	}

}	// namespace khutils

#endif	// KHUTILS_GLM_ENDIAN_REVERSE_HPP_INC
