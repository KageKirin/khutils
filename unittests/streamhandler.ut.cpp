#include "khutils/streamreader.h"
#include <sstream>

int main(int argc, const char**() argv)
{
	std::stringstream s;

	int _i = 42;
	s.write(reinterpret_cast<char*>(&_i), sizeof(int));
	float _f = 0.85f;
	s.write(reinterpret_cast<char*>(&_f), sizeof(float));

	streamreader sr(s);

	endian_streamreader<endianness::big_endian> reader(s);

	int __i = reader.read<int, int>();

	assert(__i == -_i);

	float __f = reader.read<float, float>();

	assert(__f == -_f);

	return 0;
}
