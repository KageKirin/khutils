#ifndef KHUTILS_GLM_TO_FBX_HPP_INC
#define KHUTILS_GLM_TO_FBX_HPP_INC

#include <fbxsdk.h>

#include "khutils/glm/glm_to_string.hpp"

#include <glm/glm.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace khutils
{
	FbxVector4 glmVec4toFbxVector4(const glm::dvec4& vec);
	FbxVector4 glmVec3toFbxVector4(const glm::dvec3& vec);
	FbxVector2 glmVec2toFbxVector2(const glm::dvec2& vec);
	FbxDouble4 glmVec4toFbxDouble4(const glm::dvec4& vec);
	FbxDouble4 glmVec3toFbxDouble4(const glm::dvec3& vec);
	FbxDouble3 glmVec3toFbxDouble3(const glm::dvec3& vec);
	FbxDouble2 glmVec2toFbxDouble2(const glm::dvec2& vec);

	//! inverts given UVs using the given function
	template <typename UVInverter>
	FbxVector2 glmVec2toFbxVector2_invertUV(const glm::dvec2& vec, UVInverter invert)
	{
		return glmVec2toFbxVector2(invert(vec));
	}

}	// namespace khutils

#if defined(KHUTILS_GLM_TO_FBX_IMPL)

#define GLM_SWIZZLE
#define GLM_FORCE_RADIANS
#define GLM_PRECISION_HIGHP_FLOAT

#include "khutils/glm/glm_to_fbx.hpp"

namespace khutils
{
	FbxVector4 glmVec4toFbxVector4(const glm::dvec4& vec)
	{
		return FbxVector4{vec.x, vec.y, vec.z, vec.w};
	}

	FbxVector4 glmVec3toFbxVector4(const glm::dvec3& vec)
	{
		return FbxVector4{vec.x, vec.y, vec.z};
	}

	FbxVector2 glmVec2toFbxVector2(const glm::dvec2& vec)
	{
		return FbxVector2{vec.x, vec.y};
	}

	FbxDouble4 glmVec4toFbxDouble4(const glm::dvec4& vec)
	{
		return FbxDouble4{vec.x, vec.y, vec.z, vec.w};
	}

	FbxDouble4 glmVec3toFbxDouble4(const glm::dvec3& vec)
	{
		return FbxDouble4{vec.x, vec.y, vec.z, 1};
	}

	FbxDouble3 glmVec3toFbxDouble3(const glm::dvec3& vec)
	{
		return FbxDouble3{vec.x, vec.y, vec.z};
	}

	FbxDouble2 glmVec2toFbxDouble2(const glm::dvec2& vec)
	{
		return FbxDouble2{vec.x, vec.y};
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_TO_FBX_IMPL)

#endif	// !KHUTILS_GLM_TO_FBX_HPP_INC
