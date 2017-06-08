#include <string>

extern const std::string datamap_embedded_schema; // for linker happiness
const std::string datamap_embedded_schema =
std::string(R"(
namespace khutils.data_map;

/// simple simili-map type for Flatbuffers

/// map entry
/// maps a key to a value
/// id: string
/// value: data
table MapEntry {
	id: string(key);
	value: [ubyte];
}

/// container for map entries
table Map {
	entries: [MapEntry];
}
)") +
"";
