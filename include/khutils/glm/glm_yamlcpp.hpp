#ifndef KHUTILS_GLM_YAMLCPP_HPP_INC
#define KHUTILS_GLM_YAMLCPP_HPP_INC

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include <iosfwd>
#include <string>
#include <yaml-cpp/yaml.h>


#define KHUTILS_YAML_DECLARE_CONVERT(type)                                                                             \
	template <>                                                                                                        \
	struct convert<type>                                                                                               \
	{                                                                                                                  \
		static Node encode(const type&);                                                                               \
		static bool decode(const Node&, type&);                                                                        \
	};

#define KHUTILS_YAML_DECLARE_CONVERT_ENCODE(type) Node convert<type>::encode(const type& val)
#define KHUTILS_YAML_DECLARE_CONVERT_DECODE(type) bool convert<type>::decode(const Node& node, type& val)

namespace YAML
{
	KHUTILS_YAML_DECLARE_CONVERT(glm::quat);
	KHUTILS_YAML_DECLARE_CONVERT(glm::vec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::vec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::vec4);
	KHUTILS_YAML_DECLARE_CONVERT(glm::mat4);

	KHUTILS_YAML_DECLARE_CONVERT(glm::dquat);
	KHUTILS_YAML_DECLARE_CONVERT(glm::dvec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::dvec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::dvec4);
	KHUTILS_YAML_DECLARE_CONVERT(glm::dmat4);

	KHUTILS_YAML_DECLARE_CONVERT(glm::ivec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::ivec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::ivec4);

	KHUTILS_YAML_DECLARE_CONVERT(glm::uvec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::uvec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::uvec4);

	KHUTILS_YAML_DECLARE_CONVERT(glm::i8vec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::i8vec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::i8vec4);

	KHUTILS_YAML_DECLARE_CONVERT(glm::u8vec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::u8vec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::u8vec4);

	KHUTILS_YAML_DECLARE_CONVERT(glm::i16vec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::i16vec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::i16vec4);

	KHUTILS_YAML_DECLARE_CONVERT(glm::u16vec2);
	KHUTILS_YAML_DECLARE_CONVERT(glm::u16vec3);
	KHUTILS_YAML_DECLARE_CONVERT(glm::u16vec4);

}	// namespace YAML


#if defined(KHUTILS_GLM_YAMLCPP_IMPL)

#ifndef GLM_FORCE_SWIZZLE
#define GLM_FORCE_SWIZZLE
#endif	// !GLM_FORCE_SWIZZLE

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif	// !GLM_FORCE_RADIANS

#ifndef GLM_PRECISION_HIGHP_FLOAT
#define GLM_PRECISION_HIGHP_FLOAT
#endif	// !GLM_PRECISION_HIGHP_FLOAT

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

#define KHUTILS_YAML_IMPLEMENT_CONVERT(type, _subtype, _size)                                                          \
	KHUTILS_YAML_IMPLEMENT_CONVERT_ENCODE(type, _size)                                                                 \
	KHUTILS_YAML_IMPLEMENT_CONVERT_DECODE(type, _subtype, _size)


#define KHUTILS_YAML_IMPLEMENT_CONVERT_ENCODE(type, _size)                                                             \
	KHUTILS_YAML_DECLARE_CONVERT_ENCODE(type)                                                                          \
	{                                                                                                                  \
		Node node;                                                                                                     \
		for (size_t i = 0; i < _size; ++i)                                                                             \
		{                                                                                                              \
			node.push_back(val[i]);                                                                                    \
		}                                                                                                              \
		return node;                                                                                                   \
	}


#define KHUTILS_YAML_IMPLEMENT_CONVERT_DECODE(type, _subtype, _size)                                                   \
	KHUTILS_YAML_DECLARE_CONVERT_DECODE(type)                                                                          \
	{                                                                                                                  \
		if (!node.IsSequence() || node.size() != _size)                                                                \
		{                                                                                                              \
			return false;                                                                                              \
		}                                                                                                              \
		for (size_t i = 0; i < _size; ++i)                                                                             \
		{                                                                                                              \
			val[i] = node[i].as<_subtype>();                                                                           \
		}                                                                                                              \
		return true;                                                                                                   \
	}

namespace YAML
{
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::quat, float, 4);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::vec2, float, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::vec3, float, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::vec4, float, 4);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::mat4, glm::vec4, 4);

	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::dquat, double, 4);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::dvec2, double, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::dvec3, double, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::dvec4, double, 4);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::dmat4, glm::dvec4, 4);

	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::ivec2, int32_t, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::ivec3, int32_t, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::ivec4, int32_t, 4);

	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::uvec2, uint32_t, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::uvec3, uint32_t, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::uvec4, uint32_t, 4);

	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::i8vec2, int8_t, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::i8vec3, int8_t, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::i8vec4, int8_t, 4);

	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::u8vec2, uint8_t, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::u8vec3, uint8_t, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::u8vec4, uint8_t, 4);

	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::i16vec2, int16_t, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::i16vec3, int16_t, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::i16vec4, int16_t, 4);

	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::u16vec2, uint16_t, 2);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::u16vec3, uint16_t, 3);
	KHUTILS_YAML_IMPLEMENT_CONVERT(glm::u16vec4, uint16_t, 4);

}	// namespace YAML

#undef KHUTILS_YAML_IMPLEMENT_CONVERT
#undef KHUTILS_YAML_IMPLEMENT_CONVERT_ENCODE
#undef KHUTILS_YAML_IMPLEMENT_CONVERT_DECODE

#endif	// defined (KHUTILS_GLM_YAMLCPP_IMPL)

#endif	// !KHUTILS_GLM_YAMLCPP_HPP_INC
