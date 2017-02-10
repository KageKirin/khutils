#include <string>

extern const std::string multimap_embedded_schema; // for linker happiness
const std::string multimap_embedded_schema(
R"(
namespace khutils.string_multimap;

/// simple simili-multimap type for Flatbuffers

/// map entry
/// maps a key to a number of values
/// id: string
/// values: array of strings
table MapEntry {
	id: string(key);
	values: [string];
}

/// container for multimap entries
table Map {
	entries: [MapEntry];
}

)");
