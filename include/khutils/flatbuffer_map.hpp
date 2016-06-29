#ifndef KHUTILS_FLATBUFFER_MAP_HPP_INC
#define KHUTILS_FLATBUFFER_MAP_HPP_INC

#include "khutils/map_generated.h"

#include <map>
#include <string>

namespace khutils
{

	//! extract key-value-pair from flatbuffer MapEntry
	std::map<std::string, std::string>::value_type from_flatbuffer(const string_map::MapEntry* ff);

	//! extract map from flatbuffer Map
	std::map<std::string, std::string> from_flatbuffer(const string_map::Map* ff);

	//! produce flatbuffer MapEntry from key-value-pair
	flatbuffers::Offset<string_map::MapEntry> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																	const std::map<std::string, std::string>::value_type& dd);

	//! produce flatbuffer Map from map
	flatbuffers::Offset<string_map::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
															   const std::map<std::string, std::string>& dd);

}	// namespace khutils

#if defined(KHUTILS_FLATBUFFER_MAP_IMPL)

#include "khutils/assertion.hpp"
#include "khutils/flatbuffer_map.hpp"

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace khutils
{

	//////////////////////////////////////////////////////////////////////////

	std::map<std::string, std::string>::value_type from_flatbuffer(const string_map::MapEntry* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->key());
		KHUTILS_ASSERT_PTR(ff->value());

		return std::map<std::string, std::string>::value_type{ff->key()->str(), ff->value()->str()};
	}

	//////////////////////////////////////////////////////////////////////////

	std::map<std::string, std::string> from_flatbuffer(const string_map::Map* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->entries());

		std::map<std::string, std::string> rr;

		std::for_each(ff->entries()->begin(), ff->entries()->end(), [&rr](const auto& _f) {
			rr.insert(from_flatbuffer(_f));
		});

		return rr;
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<string_map::MapEntry> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																	const std::map<std::string, std::string>::value_type& dd)
	{
		return string_map::CreateMapEntry(_fbb, _fbb.CreateSharedString(dd.first), _fbb.CreateSharedString(dd.second));
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<string_map::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
															   const std::map<std::string, std::string>& dd)
	{
		std::vector<flatbuffers::Offset<string_map::MapEntry>> entries(dd.size());
		std::transform(dd.begin(), dd.end(), entries.begin(), [&_fbb](const auto& _d) {
			return to_flatbuffer_builder(_fbb, _d);
		});

		return string_map::CreateMap(_fbb, _fbb.CreateVector(entries));
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MAP_IMPL)

#if defined(KHUTILS_FLATBUFFER_MAP_IMPL)

#endif	// defined (KHUTILS_FLATBUFFER_MAP_IMPL)

#endif	// !KHUTILS_FLATBUFFER_MAP_HPP_INC
