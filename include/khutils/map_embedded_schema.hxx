#include <string>

extern const std::string map_embedded_schema; // for linker happiness
const std::string map_embedded_schema(
R"(
namespace khutils.string_map;

/// simple simili-map type for Flatbuffers

/// map entry
/// maps a key to a value
/// key: string
/// value: string
table MapEntry
{
	key : string(key);
	value : string;
}

/// container for map entries
table Map
{
	entries : [MapEntry];
}

)");
