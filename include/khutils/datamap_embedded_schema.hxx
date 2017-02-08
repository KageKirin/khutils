#include <string>

extern const std::string datamap_embedded_schema; // for linker happiness
const std::string datamap_embedded_schema(
R"(
namespace khutils.data_map;

/// simple simili-map type for Flatbuffers

/// map entry
/// maps a key to a value
/// key: string
/// value: data
table MapEntry
{
	key : string(key);
	data : [ubyte];
}

/// container for map entries
table Map
{
	entries : [MapEntry];
}

)");
