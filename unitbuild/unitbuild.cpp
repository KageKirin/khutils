#define KHUTILS_ASSERTION_INLINE
#define KHUTILS_ASSERTION_IMPL
#define KHUTILS_COMPARISON_IMPL
#define KHUTILS_FLATBUFFER_MAP_IMPL
#define KHUTILS_FLATBUFFER_MAP_IMPL
#define KHUTILS_FLATBUFFER_MULTIMAP_IMPL
#define KHUTILS_FLATBUFFER_MULTIMAP_IMPL
#define KHUTILS_LOGGING_IMPL
#define KHUTILS_ISNAN_IMPL
//#define KHUTILS_COLOR_LOG
#define KHUTILS_RUNTIME_EXCEPTIONS_IMPL
#define KHUTILS_SPIRITUAL_CAST_IMPL
#define KHUTILS_SPIRITUAL_COMPARE_IMPL
//#define KHUTILS_UTF8STRING_IMPL
#define KHUTILS_CYCLIC_REDUNDANCY_IMPL
#define KHUTILS_Z_COMPRESSION_IMPL
//#define KHUTILS_Z_COMPRESSION_IMPL_USING_ZLIB
#define KHUTILS_Z_COMPRESSION_IMPL_USING_ZSTD
#define KHUTILS_LZ4_COMPRESSION_IMPL

#include <value_ptr/value_ptr.hpp>


#include "khutils/algorithm_index.hpp"
#include "khutils/assertion.hpp"
#include "khutils/base_handler.hpp"
#include "khutils/comparison.hpp"
#include "khutils/cyclic_redundancy.hpp"
#include "khutils/filehandler.hpp"
#include "khutils/filereader.hpp"
#include "khutils/filewriter.hpp"
#include "khutils/flatbuffer_container.hpp"
#include "khutils/flatbuffer_map.hpp"
#include "khutils/flatbuffer_multimap.hpp"
#include "khutils/isnan.hpp"
#include "khutils/logging.hpp"
#include "khutils/lz4compression.hpp"
#include "khutils/memoryhandler.hpp"
#include "khutils/memoryreader.hpp"
#include "khutils/memorywriter.hpp"
#include "khutils/pixelalgorithm.hpp"
#include "khutils/pixelhandler.hpp"
#include "khutils/pixelreader.hpp"
#include "khutils/pixelwriter.hpp"
#include "khutils/reader_overload.hpp"
#include "khutils/runtime_exceptions.hpp"
#include "khutils/spiritual_cast.hpp"
#include "khutils/spiritual_compare.hpp"
#include "khutils/streamhandler.hpp"
#include "khutils/streamreader.hpp"
#include "khutils/streamwriter.hpp"
#include "khutils/tlv.hpp"
#include "khutils/tlvreader.hpp"
#include "khutils/tlvwriter.hpp"
#include "khutils/typeconversion.hpp"
#include "khutils/writer_overload.hpp"
#include "khutils/zcompression.hpp"
//#include "khutils/utf8/utf8string.hpp"


//!! file.hpp and file_http.hpp conflict (on purpose!)
//!! include either and define its _IMPL
//!! you can use both, but as separate libs (e.g. dynamically linked)
//!! Rationale: they expose the same API in order to allow the same code
//!! to work with either local or remote (http) files
//#define KHUTILS_FILE_IMPL
//#include "khutils/file.hpp"

//#define KHUTILS_FILE_HTTP_IMPL
//#include "khutils/file_http.hpp"
