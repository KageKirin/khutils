#ifndef KHUTILS_GLM_EULER_ANGLES_HPP_INC
#define KHUTILS_GLM_EULER_ANGLES_HPP_INC

#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace glm
{
	//! eulerAngles2
	//! computes eulerAngles from quaternion using atan2 to avoid losing range
	//! beyond +/- PI/2
	//! @see
	//! https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec3<T, P> eulerAngles2(tquat<T, P> const& q)
	{
		return tvec3<T, P>(pitch2(q), yaw2(q), roll2(q));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T roll2(tquat<T, P> const& q)
	{
		return T(atan2(							   //
		  T(2) * q.w * q.x + q.y * q.z,			   //
		  T(1) - T(2) * (q.x * q.x + q.y * q.y)	//
		  ));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T pitch2(tquat<T, P> const& q)
	{
		return T(atan2(							   //
		  T(2) * (q.w * q.z + q.x * q.y),		   //
		  T(1) - T(2) * (q.y * q.y + q.z * q.z)	//
		  ));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T yaw2(tquat<T, P> const& q)
	{
		return asin(T(2) * (q.w * q.y - q.z * q.x));
	}

}	// namespace glm

// formulas from wikipedia, replaced with this table
// q.w <=> q0
// q.x <=> q1
// q.y <=> q2
// q.z <=> q3

#endif	// ! KHUTILS_GLM_EULER_ANGLES_HPP_INC
