#include <string>

extern const std::string stringmap_embedded_schema; // for linker happiness
const std::string stringmap_embedded_schema(
R"(namespace khutils.hashstring_map;

/// simple hash LUT for Flatbuffers

/// map entry
/// maps a key to a value
/// id: hash
/// value: string
table MapEntry {
	id: ulong(key, hash: "fnv1_64");
	value: string;
}

/// container for map entries
table Map {
	entries: [MapEntry];
}
)"
);
