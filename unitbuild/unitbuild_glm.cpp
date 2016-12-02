#define KHUTILS_GLM_BIG_ENDIAN_READER_IMPL
#define KHUTILS_GLM_BIG_ENDIAN_WRITER_IMPL
#define KHUTILS_GLM_LITTLE_ENDIAN_READER_IMPL
#define KHUTILS_GLM_LITTLE_ENDIAN_WRITER_IMPL
//!! native reader/writer conflicts with either big or little implementation
//!! reason: boost enum for endian::native takes either value
//#define KHUTILS_GLM_NATIVE_ENDIAN_READER_IMPL
//#define KHUTILS_GLM_NATIVE_ENDIAN_WRITER_IMPL
#define KHUTILS_GLM_COMPARISON_IMPL
#define KHUTILS_GLM_ISNAN_IMPL
#define KHUTILS_GLM_TO_FBX_IMPL
#define KHUTILS_GLM_TO_STRING_IMPL
#define KHUTILS_GLM_UTILITY_IMPL


#include "khutils/glm/glm_big_endian_reader.hpp"
#include "khutils/glm/glm_big_endian_writer.hpp"
#include "khutils/glm/glm_comparison.hpp"
#include "khutils/glm/glm_endian_reverse.hpp"
#include "khutils/glm/glm_euler_angles.hpp"
#include "khutils/glm/glm_isnan.hpp"
#include "khutils/glm/glm_little_endian_reader.hpp"
#include "khutils/glm/glm_little_endian_writer.hpp"
#include "khutils/glm/glm_native_endian_reader.hpp"
#include "khutils/glm/glm_native_endian_writer.hpp"
#include "khutils/glm/glm_reader.hpp"
#include "khutils/glm/glm_to_fbx.hpp"
#include "khutils/glm/glm_to_string.hpp"
#include "khutils/glm/glm_utility.hpp"
#include "khutils/glm/glm_writer.hpp"
