#ifndef KHUTILS_FLATBUFFER_MAP_HPP_INC
#define KHUTILS_FLATBUFFER_MAP_HPP_INC

#include "khutils/datamap_generated.h"
#include "khutils/map_generated.h"

#include <boost/container/flat_map.hpp>
#include <string>

namespace khutils
{

	//! extract key-value-pair from flatbuffer MapEntry
	boost::container::flat_map<std::string, std::string>::value_type from_flatbuffer(const string_map::MapEntry* ff);

	//! extract map from flatbuffer Map
	boost::container::flat_map<std::string, std::string> from_flatbuffer(const string_map::Map* ff);

	//! produce flatbuffer MapEntry from key-value-pair
	flatbuffers::Offset<string_map::MapEntry> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																	const boost::container::flat_map<std::string, std::string>::value_type& dd);

	//! produce flatbuffer Map from map
	flatbuffers::Offset<string_map::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
															   const boost::container::flat_map<std::string, std::string>& dd);

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::string>::value_type modify(const boost::container::flat_map<std::string, std::string>::value_type& kv,
														  KeyModifier   modifyKey,
														  ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::string> modify(const boost::container::flat_map<std::string, std::string>& kvps, KeyModifier modifyKey, ValueModifier modifyValue);

	///

	//! extract key-value-pair from flatbuffer MapEntry
	boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type from_flatbuffer(const data_map::MapEntry* ff);

	//! extract map from flatbuffer Map
	boost::container::flat_map<std::string, std::vector<uint8_t>> from_flatbuffer(const data_map::Map* ff);

	//! produce flatbuffer MapEntry from key-value-pair
	flatbuffers::Offset<data_map::MapEntry> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																  const boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type& dd);

	//! produce flatbuffer Map from map
	flatbuffers::Offset<data_map::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
															 const boost::container::flat_map<std::string, std::vector<uint8_t>>& dd);

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type modify(const boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type& kv,
																   KeyModifier   modifyKey,
																   ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::vector<uint8_t>> modify(const boost::container::flat_map<std::string, std::vector<uint8_t>>& kvps,
													   KeyModifier   modifyKey,
													   ValueModifier modifyValue);

}	// namespace khutils

#if defined(KHUTILS_FLATBUFFER_MAP_INLINE)

namespace khutils
{

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::string>::value_type modify(const boost::container::flat_map<std::string, std::string>::value_type& kv,
														  KeyModifier   modifyKey,
														  ValueModifier modifyValue)
	{
		return boost::container::flat_map<std::string, std::string>::value_type{modifyKey(kv.first), modifyValue(kv.second)};
	}

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::string> modify(const boost::container::flat_map<std::string, std::string>& kvps, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		boost::container::flat_map<std::string, std::string> ret;
		for (const auto& kv : kvps)
		{
			ret.insert(modify(kv, modifyKey, modifyValue));
		}
	}

	///

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type
	modify(const boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type{modifyKey(kv.first), modifyValue(kv.second)};
	}

	template <typename KeyModifier, typename ValueModifier>
	boost::container::flat_map<std::string, std::vector<uint8_t>> modify(const boost::container::flat_map<std::string, std::vector<uint8_t>>& kvps,
													   KeyModifier   modifyKey,
													   ValueModifier modifyValue)
	{
		boost::container::flat_map<std::string, std::vector<uint8_t>> ret;
		for (const auto& kv : kvps)
		{
			ret.insert(modify(kv, modifyKey, modifyValue));
		}
	}

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MAP_INLINE)

#if defined(KHUTILS_FLATBUFFER_MAP_IMPL)

#include "khutils/assertion.hpp"
#include "khutils/flatbuffer_map.hpp"

#include <algorithm>
#include <boost/container/flat_map.hpp>
#include <string>
#include <vector>

namespace khutils
{

	//////////////////////////////////////////////////////////////////////////

	boost::container::flat_map<std::string, std::string>::value_type from_flatbuffer(const string_map::MapEntry* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->id());
		KHUTILS_ASSERT_PTR(ff->value());

		return boost::container::flat_map<std::string, std::string>::value_type{ff->id()->str(), ff->value()->str()};
	}

	//////////////////////////////////////////////////////////////////////////

	boost::container::flat_map<std::string, std::string> from_flatbuffer(const string_map::Map* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->entries());

		boost::container::flat_map<std::string, std::string> rr;

		std::for_each(ff->entries()->begin(), ff->entries()->end(), [&rr](const auto& _f) {
			rr.insert(from_flatbuffer(_f));
		});

		return rr;
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<string_map::MapEntry> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																	const boost::container::flat_map<std::string, std::string>::value_type& dd)
	{
		return string_map::CreateMapEntry(_fbb, _fbb.CreateSharedString(dd.first), _fbb.CreateSharedString(dd.second));
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<string_map::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
															   const boost::container::flat_map<std::string, std::string>& dd)
	{
		std::vector<flatbuffers::Offset<string_map::MapEntry>> entries(dd.size());
		std::transform(dd.begin(), dd.end(), entries.begin(), [&_fbb](const auto& _d) {
			return to_flatbuffer_builder(_fbb, _d);
		});

		return string_map::CreateMap(_fbb, _fbb.CreateVector(entries));
	}

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type from_flatbuffer(const data_map::MapEntry* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->id());
		KHUTILS_ASSERT_PTR(ff->data());

		return boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type{ff->id()->str(), {ff->data()->begin(), ff->data()->end()}};
	}

	//////////////////////////////////////////////////////////////////////////

	boost::container::flat_map<std::string, std::vector<uint8_t>> from_flatbuffer(const data_map::Map* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->entries());

		boost::container::flat_map<std::string, std::vector<uint8_t>> rr;

		std::for_each(ff->entries()->begin(), ff->entries()->end(), [&rr](const auto& _f) {
			rr.insert(from_flatbuffer(_f));
		});

		return rr;
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<data_map::MapEntry> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																  const boost::container::flat_map<std::string, std::vector<uint8_t>>::value_type& dd)
	{
		return data_map::CreateMapEntry(_fbb, _fbb.CreateSharedString(dd.first), _fbb.CreateVector(dd.second));
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<data_map::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
															 const boost::container::flat_map<std::string, std::vector<uint8_t>>& dd)
	{
		std::vector<flatbuffers::Offset<data_map::MapEntry>> entries(dd.size());
		std::transform(dd.begin(), dd.end(), entries.begin(), [&_fbb](const auto& _d) {
			return to_flatbuffer_builder(_fbb, _d);
		});

		return data_map::CreateMap(_fbb, _fbb.CreateVector(entries));
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MAP_IMPL)

#endif	// !KHUTILS_FLATBUFFER_MAP_HPP_INC
