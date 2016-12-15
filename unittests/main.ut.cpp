#include <bandit/bandit.h>
#include <cstdlib>

using namespace bandit;

int main(int argc, char* argv[])
{
#ifndef _WIN32
	setenv("XcodeColors", "YES", 0);	// Enables XcodeColors (you obviously have to install it too)
#endif									//_WIN32

	return bandit::run(argc, argv);
}
