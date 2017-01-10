#ifndef KHUTILS_FBX_ISNAN_HPP_INC
#define KHUTILS_FBX_ISNAN_HPP_INC

#include "../isnan.hpp"
#include <fbxsdk.h>

namespace khutils
{
	void check_NaN(const FbxVector4& v);
	void check_NaN(const FbxVector2& v);
	void check_NaN(const FbxDouble4& v);
	void check_NaN(const FbxDouble3& v);
	void check_NaN(const FbxDouble2& v);

	void check_NaN(const FbxAMatrix& m);
	void check_NaN(const FbxMatrix::kDouble44& m);

}	// namespace khutils

#if defined(KHUTILS_FBX_ISNAN_IMPL)

namespace khutils
{
	void check_NaN(const FbxVector4& v)
	{
		check_NaN(v[0]);
		check_NaN(v[1]);
		check_NaN(v[2]);
		check_NaN(v[3]);
	}

	void check_NaN(const FbxVector2& v)
	{
		check_NaN(v[0]);
		check_NaN(v[1]);
	}

	void check_NaN(const FbxDouble4& v)
	{
		check_NaN(v[0]);
		check_NaN(v[1]);
		check_NaN(v[2]);
		check_NaN(v[3]);
	}

	void check_NaN(const FbxDouble3& v)
	{
		check_NaN(v[0]);
		check_NaN(v[1]);
		check_NaN(v[2]);
	}

	void check_NaN(const FbxDouble2& v)
	{
		check_NaN(v[0]);
		check_NaN(v[1]);
	}

	void check_NaN(const FbxAMatrix& m)
	{
		check_NaN(m.Double44());
	}

	void check_NaN(const FbxMatrix::kDouble44& m)
	{
		for (size_t x = 0; x < 4; ++x)
		{
			for (size_t y = 0; y < 4; ++y)
			{
				check_NaN(m[x][y]);
			}
		}
	}
}	// namespace khutils

#endif	// defined (KHUTILS_FBX_ISNAN_IMPL)

#endif	// !KHUTILS_FBX_ISNAN_HPP_INC
