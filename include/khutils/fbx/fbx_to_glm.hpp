#ifndef KHUTILS_FBX_TO_GLM_HPP_INC
#define KHUTILS_FBX_TO_GLM_HPP_INC

#include <fbxsdk.h>

#include "khutils/fbx/fbx_to_string.hpp"

#include <glm/glm.hpp>
#include <string>
#include <tuple>
#include <vector>

namespace khutils
{
	glm::dvec4 FbxVector4ToGlmVec4(const FbxVector4& vec);
	glm::dvec2 FbxVector2ToGlmVec2(const FbxVector2& vec);
	glm::dvec4 FbxDouble4ToGlmVec4(const FbxDouble4& vec);
	glm::dvec4 FbxDouble3ToGlmVec4(const FbxDouble3& vec);
	glm::dvec3 FbxDouble3ToGlmVec3(const FbxDouble3& vec);
	glm::dvec2 FbxDouble2ToGlmVec2(const FbxDouble2& vec);

	glm::dmat4 FbxAMatrixToGlmMat4x4(const FbxAMatrix& matrix);

	FbxAMatrix getFbxNodeGlobalTransformInverse(FbxNode* node);
	glm::dmat4 getFbxNodeGlobalTransformInverse_GlmMat4x4(FbxNode* node);

	//! inverts given UVs using the given function
	template <typename UVInverter>
	glm::dvec2 FbxVector2ToGlmVec2_invertUV(const FbxVector2& vec, UVInverter invert)
	{
		return invert(FbxVector2ToGlmVec2(vec));
	}

}	// namespace khutils

#if defined(KHUTILS_FBX_TO_GLM_IMPL)

#ifndef GLM_SWIZZLE
#define GLM_SWIZZLE 1
#endif	// !GLM_SWIZZLE

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS 1
#endif	// !GLM_FORCE_RADIANS

#ifndef GLM_PRECISION_HIGHP_FLOAT
#define GLM_PRECISION_HIGHP_FLOAT 1
#endif	// !GLM_PRECISION_HIGHP_FLOAT

namespace khutils
{
	glm::dvec4 FbxVector4ToGlmVec4(const FbxVector4& vec)
	{
		return glm::dvec4{vec[0], vec[1], vec[2], vec[3]};
	}

	glm::dvec2 FbxVector2ToGlmVec2(const FbxVector2& vec)
	{
		return glm::dvec2{vec[0], vec[1]};
	}

	glm::dvec4 FbxDouble4ToGlmVec4(const FbxDouble4& vec)
	{
		return glm::dvec4{vec[0], vec[1], vec[2], vec[3]};
	}

	glm::dvec4 FbxDouble3ToGlmVec4(const FbxDouble3& vec)
	{
		return glm::dvec4{vec[0], vec[1], vec[2], 1};
	}

	glm::dvec3 FbxDouble3ToGlmVec3(const FbxDouble3& vec)
	{
		return glm::dvec3{vec[0], vec[1], vec[2]};
	}

	glm::dvec2 FbxDouble2ToGlmVec2(const FbxDouble2& vec)
	{
		return glm::dvec2{vec[0], vec[1]};
	}

	//////////////////////////////////////////////////////////////////////////

	/// FbxAMatrix Matrices are defined using the Column Major scheme.
	/// When a FbxAMatrix represents a transformation(translation, rotation and
	/// scale),
	/// the last row of the matrix represents the translation part of the
	/// transformation.

	glm::dmat4 FbxAMatrixToGlmMat4x4(const FbxAMatrix& matrix)
	{
		const auto& md = matrix.Transpose().Double44();	//<< Fbx is the transpose of GLM matrices

		// order is col-major: cf. ctor
		// GLM_FUNC_DECL tmat4x4(
		//	T const & x0, T const & y0, T const & z0, T const & w0,
		//	T const & x1, T const & y1, T const & z1, T const & w1,
		//	T const & x2, T const & y2, T const & z2, T const & w2,
		//	T const & x3, T const & y3, T const & z3, T const & w3);

		// clang-format off
				return glm::dmat4(
					md[0][0], md[1][0], md[2][0], md[3][0],
					md[0][1], md[1][1], md[2][1], md[3][1],
					md[0][2], md[1][2], md[2][2], md[3][2],
					md[0][3], md[1][3], md[2][3], md[3][3]
					);
		// clang-format on
	}

	FbxAMatrix getFbxNodeGlobalTransformInverse(FbxNode* node)
	{
		KHUTILS_ASSERT_PTR(node);

		FbxAMatrix& npMat = node->EvaluateGlobalTransform();
		return npMat.Inverse();
	}

	glm::dmat4 getFbxNodeGlobalTransformInverse_GlmMat4x4(FbxNode* node)
	{
		KHUTILS_ASSERT_PTR(node);

		return FbxAMatrixToGlmMat4x4(getFbxNodeGlobalTransformInverse(node));
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FBX_TO_GLM_IMPL)

#endif	// !KHUTILS_FBX_TO_GLM_HPP_INC
