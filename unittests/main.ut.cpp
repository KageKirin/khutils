#include <bandit/bandit.h>
#include <cstdlib>

using namespace bandit;

int main(int argc, char* argv[])
{
	setenv("XcodeColors", "YES", 0);	// Enables XcodeColors (you obviously have to install it too)

	return bandit::run(argc, argv);
}
