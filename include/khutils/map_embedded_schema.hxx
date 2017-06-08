#include <string>

extern const std::string map_embedded_schema; // for linker happiness
const std::string map_embedded_schema =
std::string(R"(
namespace khutils.string_map;

/// simple simili-map type for Flatbuffers

/// map entry
/// maps a key to a value
/// id: string
/// value: string
table MapEntry {
	id: string(key);
	value: string;
}

/// container for map entries
table Map {
	entries: [MapEntry];
}
)") +
"";
