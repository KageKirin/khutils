#include "khutils/logging.hpp"

#include <bandit/bandit.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace bandit;
using namespace khutils;


go_bandit([]() {
	//////////////////////////////////////////////////////////////////////////
	// logger
	describe("logging styles", []() {
		it("log", []() {
			khutils::logger::debug() << "Debug message" << std::endl;
			khutils::logger::log() << "Log message" << std::endl;
			khutils::logger::warn() << "Warning message" << std::endl;
			khutils::logger::error() << "Error message" << std::endl;
			AssertThat(true, Equals(true));
		});
	});
});
