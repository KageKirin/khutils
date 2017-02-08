#include <string>

extern const std::string datamultimap_embedded_schema; // for linker happiness
const std::string datamultimap_embedded_schema(
R"(
namespace khutils.data_multimap;

/// simple simili-multimap type for Flatbuffers

/// container for random data
table Data
{
	data : [ubyte];
}

/// map entry
/// maps a key to a number of values
/// key: string
/// values: array of Data
table MapEntry
{
	key : string(key);
	values : [Data];
}

/// container for multimap entries
table Map
{
	entries : [MapEntry];
}

)");
