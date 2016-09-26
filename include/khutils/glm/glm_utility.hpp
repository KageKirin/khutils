#ifndef KHUTILS_GLM_UTILITY_HPP_INC
#define KHUTILS_GLM_UTILITY_HPP_INC

#include <glm/fwd.hpp>

namespace khutils
{
	glm::dvec3 genRandomColor();

}	// namespace khutils

#if defined(KHUTILS_GLM_UTILITY_IMPL)

#include "khutils/glm/glm_utility.hpp"

#include <glm/glm.hpp>

#include <random>

namespace khutils
{
	glm::dvec3 genRandomColor()
	{
		static std::random_device				rd;					 // obtain a random number from hardware
		static std::mt19937_64					eng(rd());			 // seed the generator
		static std::uniform_real_distribution<> distrR(0.0, 1.0);	// define the range
		static std::uniform_real_distribution<> distrG(0.0, 1.0);	// define the range
		static std::uniform_real_distribution<> distrB(0.0, 1.0);	// define the range

		return glm::dvec3{distrR(eng), distrG(eng), distrB(eng)};
	}

}	// namespace khutils

#endif	// defined (KHUTILS_GLM_UTILITY_IMPL)

#endif	// !KHUTILS_GLM_UTILITY_HPP_INC
