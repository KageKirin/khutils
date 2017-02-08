#include <string>

const std::string datamultimap_embedded_schema(
R"(
namespace khutils.data_multimap;

/// container for random data
table Data
{
data:
	[ubyte];
}

/// simple simili-multimap type for Flatbuffers
/// maps a key to a number of values
/// key: string
/// values: array of Data
table MapEntry
{
key:
	string(key);
values:
	[Data];
}

/// container for multimap entries
table Map
{
entries:
	[MapEntry];
}

)");
