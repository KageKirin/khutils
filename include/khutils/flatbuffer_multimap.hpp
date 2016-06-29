#ifndef KHUTILS_FLATBUFFER_MULTIMAP_HPP_INC
#define KHUTILS_FLATBUFFER_MULTIMAP_HPP_INC

#include "multimap_generated.h"

#include <map>
#include <string>
#include <vector>

//!! specificly NOT std::multimap, but map<key, vector<value>>

namespace khutils
{

	//! extract key-values-pair from flatbuffer MapEntry
	std::map<std::string, std::vector<std::string>>::value_type from_flatbuffer(const string_multimap::MapEntry* ff);

	//! extract map from flatbuffer Map
	std::map<std::string, std::vector<std::string>> from_flatbuffer(const string_multimap::Map* ff);

	//! produce flatbuffer MapEntry from key-values-pair
	flatbuffers::Offset<string_multimap::MapEntry> to_flatbuffer_builder(
	  flatbuffers::FlatBufferBuilder& _fbb, const std::map<std::string, std::vector<std::string>>::value_type& dd);

	//! produce flatbuffer Map from map
	flatbuffers::Offset<string_multimap::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																	const std::map<std::string, std::vector<std::string>>& dd);

}	// namespace khutils

#if defined(KHUTILS_FLATBUFFER_MULTIMAP_IMPL)

#include "khutils/assertion.hpp"
#include "khutils/flatbuffer_multimap.hpp"

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace khutils
{

	//////////////////////////////////////////////////////////////////////////

	std::map<std::string, std::vector<std::string>>::value_type from_flatbuffer(const string_multimap::MapEntry* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->key());
		KHUTILS_ASSERT_PTR(ff->values());

		std::map<std::string, std::vector<std::string>>::value_type rr{ff->key()->str(), {}};
		rr.second.resize(ff->values()->size());

		std::transform(ff->values()->begin(), ff->values()->end(), rr.second.begin(), [](const auto& _v) {
			return _v->str();
		});

		return rr;
	}

	//////////////////////////////////////////////////////////////////////////

	std::map<std::string, std::vector<std::string>> from_flatbuffer(const string_multimap::Map* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->entries());

		std::map<std::string, std::vector<std::string>> rr;

		std::for_each(ff->entries()->begin(), ff->entries()->end(), [&rr](const auto& _f) {
			rr.insert(from_flatbuffer(_f));
		});

		return rr;
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<string_multimap::MapEntry> to_flatbuffer_builder(
	  flatbuffers::FlatBufferBuilder& _fbb, const std::map<std::string, std::vector<std::string>>::value_type& dd)
	{
		std::vector<flatbuffers::Offset<flatbuffers::String>> values(dd.second.size());
		std::transform(dd.second.begin(), dd.second.end(), values.begin(), [&_fbb](const auto& _v) {
			return _fbb.CreateSharedString(_v);
		});

		return string_multimap::CreateMapEntry(_fbb, _fbb.CreateSharedString(dd.first), _fbb.CreateVector(values));
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<string_multimap::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																	const std::map<std::string, std::vector<std::string>>& dd)
	{
		std::vector<flatbuffers::Offset<string_multimap::MapEntry>> entries(dd.size());
		std::transform(dd.begin(), dd.end(), entries.begin(), [&_fbb](const auto& _d) {
			return to_flatbuffer_builder(_fbb, _d);
		});

		return string_multimap::CreateMap(_fbb, _fbb.CreateVector(entries));
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MULTIMAP_IMPL)

#if defined(KHUTILS_FLATBUFFER_MULTIMAP_IMPL)

#endif	// defined (KHUTILS_FLATBUFFER_MULTIMAP_IMPL)

#endif	// !KHUTILS_FLATBUFFER_MULTIMAP_HPP_INC
