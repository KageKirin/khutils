#ifndef KHUTILS_FLATBUFFER_MULTIMAP_HPP_INC
#define KHUTILS_FLATBUFFER_MULTIMAP_HPP_INC

#include "khutils/datamultimap_generated.h"
#include "khutils/multimap_generated.h"

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

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::string>>::value_type
	modify(const std::map<std::string, std::vector<std::string>>::value_type& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::string>> modify(const std::map<std::string, std::vector<std::string>>& kvps,
														   KeyModifier   modifyKey,
														   ValueModifier modifyValue);

	///

	//! extract values from flatbuffer Map
	std::vector<uint8_t> from_flatbluffer(const data_multimap::Data* ff);

	//! extract key-values-pair from flatbuffer MapEntry
	std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type from_flatbuffer(const data_multimap::MapEntry* ff);

	//! extract map from flatbuffer Map
	std::map<std::string, std::vector<std::vector<uint8_t>>> from_flatbuffer(const data_multimap::Map* ff);

	//! produce flatbuffer MapEntry from key-values-pair
	flatbuffers::Offset<data_multimap::Data> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																   const std::vector<uint8_t>&	 dd);

	//! produce flatbuffer MapEntry from key-values-pair
	flatbuffers::Offset<data_multimap::MapEntry> to_flatbuffer_builder(
	  flatbuffers::FlatBufferBuilder& _fbb, const std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type& dd);

	//! produce flatbuffer Map from map
	flatbuffers::Offset<data_multimap::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																  const std::map<std::string, std::vector<std::vector<uint8_t>>>& dd);

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type
	modify(const std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::vector<uint8_t>>>
	modify(const std::map<std::string, std::vector<std::vector<uint8_t>>>& kvps, KeyModifier modifyKey, ValueModifier modifyValue);

}	// namespace khutils

#if defined(KHUTILS_FLATBUFFER_MULTIMAP_INLINE)

namespace khutils
{

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::string>>::value_type
	modify(const std::map<std::string, std::vector<std::string>>::value_type& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto r = std::remove_reference<std::remove_const<decltype(kv)>::type>::type{modifyKey(kv.first), {}};
		std::map<std::string, std::vector<std::string>>::value_type ret{modifyKey(kv.first), {}};
		ret.second.resize(kv.second.size());
		std::transform(kv.second.begin(), kv.second.end(), ret.second.begin(), modifyValue);

		return ret;
	}

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::string>> modify(const std::map<std::string, std::vector<std::string>>& kvps,
														   KeyModifier   modifyKey,
														   ValueModifier modifyValue)
	{
		auto ret = std::map<std::string, std::vector<std::string>>{};

		for (const auto& kv : kvps)
		{
			ret.insert(modify(kv, modifyKey, modifyValue));
		}

		return ret;
	}

	///

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type
	modify(const std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto r = std::remove_reference<std::remove_const<decltype(kv)>::type>::type{modifyKey(kv.first), {}};
		std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type ret{modifyKey(kv.first), {}};
		ret.second.resize(kv.second.size());
		std::transform(kv.second.begin(), kv.second.end(), ret.second.begin(), modifyValue);

		return ret;
	}

	template <typename KeyModifier, typename ValueModifier>
	std::map<std::string, std::vector<std::vector<uint8_t>>>
	modify(const std::map<std::string, std::vector<std::vector<uint8_t>>>& kvps, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto ret = std::map<std::string, std::vector<std::vector<uint8_t>>>{};

		for (const auto& kv : kvps)
		{
			ret.insert(modify(kv, modifyKey, modifyValue));
		}

		return ret;
	}

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MULTIMAP_INLINE)

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
	//////////////////////////////////////////////////////////////////////////

	std::vector<uint8_t> from_flatbluffer(const data_multimap::Data* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->data());

		return std::vector<uint8_t>{ff->data()->begin(), ff->data()->end()};
	}

	//////////////////////////////////////////////////////////////////////////

	std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type from_flatbuffer(const data_multimap::MapEntry* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->key());
		KHUTILS_ASSERT_PTR(ff->values());

		std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type rr{ff->key()->str(), {}};
		rr.second.resize(ff->values()->size());

		std::transform(ff->values()->begin(), ff->values()->end(), rr.second.begin(), [](const auto& _v) {
			return from_flatbluffer(_v);
		});

		return rr;
	}

	//////////////////////////////////////////////////////////////////////////

	std::map<std::string, std::vector<std::vector<uint8_t>>> from_flatbuffer(const data_multimap::Map* ff)
	{
		KHUTILS_ASSERT_PTR(ff);
		KHUTILS_ASSERT_PTR(ff->entries());

		std::map<std::string, std::vector<std::vector<uint8_t>>> rr;

		std::for_each(ff->entries()->begin(), ff->entries()->end(), [&rr](const auto& _f) {
			rr.insert(from_flatbuffer(_f));
		});

		return rr;
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<data_multimap::Data> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																   const std::vector<uint8_t>&	 dd)
	{
		return data_multimap::CreateData(_fbb, _fbb.CreateVector(dd));
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<data_multimap::MapEntry> to_flatbuffer_builder(
	  flatbuffers::FlatBufferBuilder& _fbb, const std::map<std::string, std::vector<std::vector<uint8_t>>>::value_type& dd)
	{
		std::vector<flatbuffers::Offset<data_multimap::Data>> values(dd.second.size());
		std::transform(dd.second.begin(), dd.second.end(), values.begin(), [&_fbb](const auto& _v) {
			return to_flatbuffer_builder(_fbb, _v);
		});

		return data_multimap::CreateMapEntry(_fbb, _fbb.CreateSharedString(dd.first), _fbb.CreateVector(values));
	}

	//////////////////////////////////////////////////////////////////////////

	flatbuffers::Offset<data_multimap::Map> to_flatbuffer_builder(flatbuffers::FlatBufferBuilder& _fbb,
																  const std::map<std::string, std::vector<std::vector<uint8_t>>>& dd)
	{
		std::vector<flatbuffers::Offset<data_multimap::MapEntry>> entries(dd.size());
		std::transform(dd.begin(), dd.end(), entries.begin(), [&_fbb](const auto& _d) {
			return to_flatbuffer_builder(_fbb, _d);
		});

		return data_multimap::CreateMap(_fbb, _fbb.CreateVector(entries));
	}

	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MULTIMAP_IMPL)

#endif	// !KHUTILS_FLATBUFFER_MULTIMAP_HPP_INC
