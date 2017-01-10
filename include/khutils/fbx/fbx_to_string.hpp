#ifndef KHUTILS_FBX_TO_STRING_HPP_INC
#define KHUTILS_FBX_TO_STRING_HPP_INC

#include <fbxsdk.h>
#include <iosfwd>
#include <string>

namespace khutils
{
	const std::string to_string(const FbxVector4& v);
	const std::string to_string(const FbxVector2& v);
	const std::string to_string(const FbxDouble4& v);
	const std::string to_string(const FbxDouble3& v);
	const std::string to_string(const FbxDouble2& v);
	const std::string to_string(const FbxAMatrix& m);
	const std::string to_string(const FbxMatrix::kDouble44& m);


	std::ostream& operator<<(std::ostream& os, FbxVector4& v);
	std::ostream& operator<<(std::ostream& os, FbxVector2& v);
	std::ostream& operator<<(std::ostream& os, FbxDouble4& v);
	std::ostream& operator<<(std::ostream& os, FbxDouble3& v);
	std::ostream& operator<<(std::ostream& os, FbxDouble2& v);
	std::ostream& operator<<(std::ostream& os, FbxAMatrix& m);
	std::ostream& operator<<(std::ostream& os, FbxMatrix::kDouble44& m);

}	// namespace khutils

#if defined(KHUTILS_FBX_TO_STRING_IMPL)

#include <fmt/format.h>
#include <iostream>
#include <string>

namespace khutils
{
	using namespace fmt::literals;

	//////////////////////////////////////////////////////////////////////////

	const std::string to_string(const FbxVector4& v)
	{
		return "<{0}, {1}, {2}, {3}>\n"_format(v[0], v[1], v[2], v[3]);
	}

	const std::string to_string(const FbxVector2& v)
	{
		return "<{0}, {1}>\n"_format(v[0], v[1]);
	}

	const std::string to_string(const FbxDouble4& v)
	{
		return "<{0}, {1}, {2}, {3}>\n"_format(v[0], v[1], v[2], v[3]);
	}

	const std::string to_string(const FbxDouble3& v)
	{
		return "<{0}, {1}, {2}>\n"_format(v[0], v[1], v[2]);
	}

	const std::string to_string(const FbxDouble2& v)
	{
		return "<{0}, {1}>\n"_format(v[0], v[1]);
	}


	const std::string to_string(const FbxAMatrix& m)
	{
		static const char* linefmt = "{0}, {1}, {2}, {3}";

		return "<{0},\n{1},\n{2},\n{3}>"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0], m[3][0]),
												fmt::format(linefmt, m[0][1], m[1][1], m[2][1], m[3][1]),
												fmt::format(linefmt, m[0][2], m[1][2], m[2][2], m[3][2]),
												fmt::format(linefmt, m[0][3], m[1][3], m[2][3], m[3][3]));
	}

	const std::string to_string(const FbxMatrix::kDouble44& m)
	{
		static const char* linefmt = "{0}, {1}, {2}, {3}";

		return "<{0},\n{1},\n{2},\n{3}>"_format(fmt::format(linefmt, m[0][0], m[1][0], m[2][0], m[3][0]),
												fmt::format(linefmt, m[0][1], m[1][1], m[2][1], m[3][1]),
												fmt::format(linefmt, m[0][2], m[1][2], m[2][2], m[3][2]),
												fmt::format(linefmt, m[0][3], m[1][3], m[2][3], m[3][3]));
	}

	//////////////////////////////////////////////////////////////////////////

	std::ostream& operator<<(std::ostream& os, FbxVector4& v)
	{
		os << "FbxVector4" << to_string(v);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, FbxVector2& v)
	{
		os << "FbxVector2" << to_string(v);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, FbxDouble4& v)
	{
		os << "FbxDouble4" << to_string(v);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, FbxDouble3& v)
	{
		os << "FbxDouble3" << to_string(v);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, FbxDouble2& v)
	{
		os << "FbxDouble2" << to_string(v);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, FbxAMatrix& m)
	{
		os << "FbxAMatrix" << to_string(m);
		return os;
	}

	std::ostream& operator<<(std::ostream& os, FbxMatrix::kDouble44& m)
	{
		os << "kDouble44" << to_string(m);
		return os;
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FBX_TO_STRING_IMPL)

#endif	// !KHUTILS_FBX_TO_STRING_HPP_INC
