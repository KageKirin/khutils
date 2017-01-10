#ifndef KHUTILS_GLM_ISNAN_HPP_INC
#define KHUTILS_GLM_ISNAN_HPP_INC

#include <glm/fwd.hpp>

namespace khutils
{
	void check_NaN(const double& d);
	void check_NaN(const glm::dvec3& v);
	void check_NaN(const glm::dvec4& v);
	void check_NaN(const glm::dmat4& mat);
	void check_NaN(const glm::dquat& q);

	void check_NaN(const float& d);
	void check_NaN(const glm::vec3& v);
	void check_NaN(const glm::vec4& v);
	void check_NaN(const glm::mat4& mat);
	void check_NaN(const glm::quat& q);

}	// namespace khutils

#if defined(KHUTILS_GLM_ISNAN_IMPL)

#ifndef GLM_SWIZZLE
#define GLM_SWIZZLE 1
#endif // !GLM_SWIZZLE

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS 1
#endif // !GLM_FORCE_RADIANS

#ifndef GLM_PRECISION_HIGHP_FLOAT
#define GLM_PRECISION_HIGHP_FLOAT 1
#endif // !GLM_PRECISION_HIGHP_FLOAT

#include "khutils/glm/glm_isnan.hpp"

#include "khutils/assertion.hpp"
#include "khutils/logging.hpp"

#include <CppLinq/cpplinq.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace khutils
{
	void check_NaN(const float& d)
	{
		KHUTILS_ASSERT(!isnan(d));
	}

	void check_NaN(const double& d)
	{
		KHUTILS_ASSERT(!isnan(d));
	}

	void check_NaN(const glm::dvec3& v)
	{
		check_NaN(v.x);
		check_NaN(v.y);
		check_NaN(v.z);
	}

	void check_NaN(const glm::dvec4& v)
	{
		check_NaN(v.x);
		check_NaN(v.y);
		check_NaN(v.z);
		check_NaN(v.w);
	}

	void check_NaN(const glm::dmat4& mat)
	{
		check_NaN(mat[0]);
		check_NaN(mat[1]);
		check_NaN(mat[2]);
		check_NaN(mat[3]);
	}

	void check_NaN(const glm::dquat& q)
	{
		check_NaN(q.x);
		check_NaN(q.y);
		check_NaN(q.z);
		check_NaN(q.w);
	}

	void check_NaN(const glm::vec3& v)
	{
		check_NaN(v.x);
		check_NaN(v.y);
		check_NaN(v.z);
	}

	void check_NaN(const glm::vec4& v)
	{
		check_NaN(v.x);
		check_NaN(v.y);
		check_NaN(v.z);
		check_NaN(v.w);
	}

	void check_NaN(const glm::mat4& mat)
	{
		check_NaN(mat[0]);
		check_NaN(mat[1]);
		check_NaN(mat[2]);
		check_NaN(mat[3]);
	}

	void check_NaN(const glm::quat& q)
	{
		check_NaN(q.x);
		check_NaN(q.y);
		check_NaN(q.z);
		check_NaN(q.w);
	}

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_ISNAN_IMPL)

#endif	// !KHUTILS_GLM_ISNAN_HPP_INC
