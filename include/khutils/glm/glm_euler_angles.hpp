#ifndef KHUTILS_GLM_EULER_ANGLES_HPP_INC
#define KHUTILS_GLM_EULER_ANGLES_HPP_INC

#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace glm
{

	//////////////////////////////////////////////////////////////////////////
	//! eulerAngles_projection
	//! computes eulerAngles by projecting rotated standard vector into plane
	//! perpendicular to PYR axis

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec3<T, P> eulerAngles_projection(tquat<T, P> const& q)
	{
		return tvec3<T, P>(pitch_projection(q), yaw_projection(q), roll_projection(q));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T roll_projection(tquat<T, P> const& q)
	{
		// roll axis (Z) -> XY plane
		tvec3<T, P> v(T(1), T(0), T(0));
		tvec3<T, P> v_r = rotate(q, v);

		T angle = acos(dot(normalize(v.xy()), normalize(v_r.xy())));

		if (v_r == v || v_r == -v)
		{
			return angle;
		}

		tvec3<T, P> n = cross(v, normalize(tvec3<T, P>(v_r.x, v_r.y, 0)));
		angle *= sign(n.z);
		return angle;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T pitch_projection(tquat<T, P> const& q)
	{
		// pitch axis (X) -> YZ plane
		tvec3<T, P> v(T(0), T(1), T(0));
		tvec3<T, P> v_r = rotate(q, v);

		T angle = acos(dot(normalize(v.yz()), normalize(v_r.yz())));

		if (v_r == v || v_r == -v)
		{
			return angle;
		}

		tvec3<T, P> n = cross(v, normalize(tvec3<T, P>(0, v_r.y, v_r.z)));
		angle *= sign(n.x);
		return angle;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T yaw_projection(tquat<T, P> const& q)
	{
		// yaw axis (Y) -> XZ plane
		tvec3<T, P> v(T(1), T(0), T(0));
		tvec3<T, P> v_r = rotate(q, v);

		T angle = acos(dot(normalize(v.xz()), normalize(v_r.xz())));

		if (v_r == v || v_r == -v)
		{
			return angle;
		}

		tvec3<T, P> n = cross(v, normalize(tvec3<T, P>(v_r.x, 0, v_r.z)));
		angle *= sign(n.y);
		return angle;
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace glm

#endif	// ! KHUTILS_GLM_EULER_ANGLES_HPP_INC
