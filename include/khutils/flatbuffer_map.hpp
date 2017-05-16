#ifndef KHUTILS_FLATBUFFER_MAP_HPP_INC
#define KHUTILS_FLATBUFFER_MAP_HPP_INC

#include "khutils/datamap_generated.h"
#include "khutils/datamultimap_generated.h"
#include "khutils/map_generated.h"
#include "khutils/multimap_generated.h"
#include "khutils/stringmap_generated.h"

#include <boost/container/flat_map.hpp>
#include <string>
#include <vector>

namespace khutils
{
	typedef string_map::MapEntryT			 StringMapEntryT;
	typedef std::unique_ptr<StringMapEntryT> StringMapEntry;
	typedef std::vector<StringMapEntry>		 StringMapEntries;
	typedef string_map::MapT				 StringMapT;
	typedef std::unique_ptr<StringMapT>		 StringMap;

	typedef boost::container::flat_map<std::string, std::string> NativeStringMap;
	typedef NativeStringMap::value_type NativeStringMapEntry;


	typedef data_map::MapEntryT			   DataMapEntryT;
	typedef std::unique_ptr<DataMapEntryT> DataMapEntry;
	typedef std::vector<DataMapEntry>	  DataMapEntries;
	typedef data_map::MapT				   DataMapT;
	typedef std::unique_ptr<DataMapT>	  DataMap;

	typedef boost::container::flat_map<std::string, std::vector<uint8_t>> NativeDataMap;
	typedef NativeDataMap::value_type NativeDataMapEntry;


	typedef hashstring_map::MapEntryT			 HashStringMapEntryT;
	typedef std::unique_ptr<HashStringMapEntryT> HashStringMapEntry;
	typedef std::vector<StringMapEntry>			 HashStringMapEntries;
	typedef hashstring_map::MapT				 HashStringMapT;
	typedef std::unique_ptr<HashStringMapT>		 HashStringMap;

	typedef boost::container::flat_map<uint64_t, std::string> NativeHashStringMap;
	typedef NativeHashStringMap::value_type NativeHashStringMapEntry;


	typedef string_multimap::MapEntryT			  StringMultiMapEntryT;
	typedef std::unique_ptr<StringMultiMapEntryT> StringMultiMapEntry;
	typedef std::vector<StringMultiMapEntry>	  MultiMapEntries;
	typedef string_multimap::MapT				  StringMultiMapT;
	typedef std::unique_ptr<StringMultiMapT>	  StringMultiMap;

	typedef boost::container::flat_map<std::string, std::vector<std::string>> NativeStringMultiMap;
	typedef NativeStringMultiMap::value_type NativeStringMultiMapEntry;


	typedef data_multimap::DataT					DataMultiMapEntryDataT;
	typedef std::unique_ptr<DataMultiMapEntryDataT> DataMultiMapEntryData;
	typedef data_multimap::MapEntryT				DataMultiMapEntryT;
	typedef std::unique_ptr<DataMultiMapEntryT>		DataMultiMapEntry;
	typedef std::vector<DataMultiMapEntry>			DataMultiMapEntries;
	typedef data_multimap::MapT						DataMultiMapT;
	typedef std::unique_ptr<DataMultiMapT>			DataMultiMap;

	typedef boost::container::flat_map<std::string, std::vector<std::vector<uint8_t>>> NativeDataMultiMap;
	typedef NativeDataMultiMap::value_type NativeDataMultiMapEntry;
	typedef std::vector<uint8_t>		   NativeDataMultiMapEntryData;

	//----------------------------------------------------------

	StringMapEntry		  createStringMapEntry();
	StringMap			  createStringMap();
	DataMapEntry		  createDataMapEntry();
	DataMap				  createDataMap();
	HashStringMapEntry	createHashStringMapEntry();
	HashStringMap		  createHashStringMap();
	StringMultiMapEntry   createStringMultiMapEntry();
	StringMultiMap		  createStringMultiMap();
	DataMultiMapEntryData createDataMultiMapEntryData();
	DataMultiMapEntry	 createDataMultiMapEntry();
	DataMultiMap		  createDataMultiMap();

	StringMapEntry		  createStringMapEntry(const StringMapEntry&);
	StringMap			  createStringMap(const StringMap&);
	DataMapEntry		  createDataMapEntry(const DataMapEntry&);
	DataMap				  createDataMap(const DataMap&);
	HashStringMapEntry	createHashStringMapEntry(const HashStringMapEntry&);
	HashStringMap		  createHashStringMap(const HashStringMap&);
	StringMultiMapEntry   createStringMultiMapEntry(const StringMultiMapEntry&);
	StringMultiMap		  createStringMultiMap(const StringMultiMap&);
	DataMultiMapEntryData createDataMultiMapEntryData(const DataMultiMapEntryData&);
	DataMultiMapEntry	 createDataMultiMapEntry(const DataMultiMapEntry&);
	DataMultiMap		  createDataMultiMap(const DataMultiMap&);

	StringMapEntry		  createStringMapEntry(const NativeStringMapEntry&);
	StringMap			  createStringMap(const NativeStringMap&);
	DataMapEntry		  createDataMapEntry(const NativeDataMapEntry&);
	DataMap				  createDataMap(const NativeDataMap&);
	HashStringMapEntry	createHashStringMapEntry(const NativeHashStringMapEntry&);
	HashStringMap		  createHashStringMap(const NativeHashStringMap&);
	StringMultiMapEntry   createStringMultiMapEntry(const NativeStringMultiMapEntry&);
	StringMultiMap		  createStringMultiMap(const NativeStringMultiMap&);
	DataMultiMapEntryData createDataMultiMapEntryData(const NativeDataMultiMapEntryData&);
	DataMultiMapEntry	 createDataMultiMapEntry(const NativeDataMultiMapEntry&);
	DataMultiMap		  createDataMultiMap(const NativeDataMultiMap&);


	NativeStringMapEntry	  to_native(const StringMapEntry&);
	NativeStringMap			  to_native(const StringMap&);
	NativeDataMapEntry		  to_native(const DataMapEntry&);
	NativeDataMap			  to_native(const DataMap&);
	NativeHashStringMapEntry  to_native(const HashStringMapEntry&);
	NativeHashStringMap		  to_native(const HashStringMap&);
	NativeStringMultiMapEntry to_native(const StringMultiMapEntry&);
	NativeStringMultiMap	  to_native(const StringMultiMap&);

	NativeDataMultiMapEntryData to_native(const DataMultiMapEntryData&);
	NativeDataMultiMapEntry		to_native(const DataMultiMapEntry&);
	NativeDataMultiMap			to_native(const DataMultiMap&);

	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	StringMapEntry modify(const StringMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	StringMap modify(const StringMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	DataMapEntry modify(const DataMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	DataMap modify(const DataMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	HashStringMapEntry modify(const HashStringMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	HashStringMap modify(const HashStringMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	StringMultiMapEntry modify(const StringMultiMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	StringMultiMap modify(const StringMultiMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	DataMultiMapEntry modify(const DataMultiMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	DataMultiMap modify(const DataMultiMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);

	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	NativeStringMapEntry modify(const NativeStringMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	NativeStringMap modify(const NativeStringMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	NativeDataMapEntry modify(const NativeDataMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	NativeDataMap modify(const NativeDataMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	NativeHashStringMapEntry modify(const NativeHashStringMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	NativeHashStringMap modify(const NativeHashStringMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	NativeStringMultiMapEntry modify(const NativeStringMultiMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	NativeStringMultiMap modify(const NativeStringMultiMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);


	template <typename KeyModifier, typename ValueModifier>
	NativeDataMultiMapEntry modify(const NativeDataMultiMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue);

	template <typename KeyModifier, typename ValueModifier>
	NativeDataMultiMap modify(const NativeDataMultiMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue);

}	// namespace khutils


#if defined(KHUTILS_FLATBUFFER_MAP_INLINE)

namespace khutils
{
	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	StringMapEntry modify(const StringMapEntry& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createStringMapEntry(modify(to_native(arg), modifyKey, modifyValue));
	}

	template <typename KeyModifier, typename ValueModifier>
	StringMap modify(const StringMap& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createStringMap(modify(to_native(arg), modifyKey, modifyValue));
	}


	template <typename KeyModifier, typename ValueModifier>
	DataMapEntry modify(const DataMapEntry& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createDataMapEntry(modify(to_native(arg), modifyKey, modifyValue));
	}

	template <typename KeyModifier, typename ValueModifier>
	DataMap modify(const DataMap& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createDataMap(modify(to_native(arg), modifyKey, modifyValue));
	}


	template <typename KeyModifier, typename ValueModifier>
	HashStringMapEntry modify(const HashStringMapEntry& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createHashStringMapEntry(modify(to_native(arg), modifyKey, modifyValue));
	}

	template <typename KeyModifier, typename ValueModifier>
	HashStringMap modify(const HashStringMap& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createHashStringMap(modify(to_native(arg), modifyKey, modifyValue));
	}


	template <typename KeyModifier, typename ValueModifier>
	StringMultiMapEntry modify(const StringMultiMapEntry& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createStringMultiMapEntry(modify(to_native(arg), modifyKey, modifyValue));
	}

	template <typename KeyModifier, typename ValueModifier>
	StringMultiMap modify(const StringMultiMap& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createStringMultiMap(modify(to_native(arg), modifyKey, modifyValue));
	}


	template <typename KeyModifier, typename ValueModifier>
	DataMultiMapEntry modify(const DataMultiMapEntry& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createDataMultiMapEntry(modify(to_native(arg), modifyKey, modifyValue));
	}

	template <typename KeyModifier, typename ValueModifier>
	DataMultiMap modify(const DataMultiMap& arg, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return createDataMultiMap(modify(to_native(arg), modifyKey, modifyValue));
	}

	//----------------------------------------------------------
	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	NativeStringMapEntry modify(const NativeStringMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return NativeStringMapEntry{modifyKey(kv.first), modifyValue(kv.second)};
	}

	template <typename KeyModifier, typename ValueModifier>
	NativeStringMap modify(const NativeStringMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto ret = NativeStringMap{};
		ret.reserve(kvps.size());

		std::transform(kvps.begin(), kvps.end(), std::inserter(ret, ret.begin()), [&modifyKey, &modifyValue](auto& e) {
			return modify(e, modifyKey, modifyValue);
		});

		return ret;
	}

	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	NativeDataMapEntry modify(const NativeDataMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return NativeDataMapEntry{modifyKey(kv.first), modifyValue(kv.second)};
	}

	template <typename KeyModifier, typename ValueModifier>
	NativeDataMap modify(const NativeDataMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto ret = NativeDataMap{};
		ret.reserve(kvps.size());

		std::transform(kvps.begin(), kvps.end(), std::inserter(ret, ret.begin()), [&modifyKey, &modifyValue](auto& e) {
			return modify(e, modifyKey, modifyValue);
		});

		return ret;
	}

	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	NativeHashStringMapEntry modify(const NativeHashStringMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		return NativeHashStringMapEntry{modifyKey(kv.first), modifyValue(kv.second)};
	}

	template <typename KeyModifier, typename ValueModifier>
	NativeHashStringMap modify(const NativeHashStringMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto ret = NativeHashStringMap{};
		ret.reserve(kvps.size());

		std::transform(kvps.begin(), kvps.end(), std::inserter(ret, ret.begin()), [&modifyKey, &modifyValue](auto& e) {
			return modify(e, modifyKey, modifyValue);
		});

		return ret;
	}

	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	NativeStringMultiMapEntry modify(const NativeStringMultiMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto r = std::remove_reference<std::remove_const<decltype(kv)>::type>::type{modifyKey(kv.first), {}};
		NativeStringMultiMapEntry ret{modifyKey(kv.first), {}};
		ret.second.reserve(kv.second.size());
		std::transform(kv.second.begin(), kv.second.end(), std::back_inserter(ret.second), modifyValue);

		return ret;
	}

	template <typename KeyModifier, typename ValueModifier>
	NativeStringMultiMap modify(const NativeStringMultiMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto ret = NativeStringMultiMap{};
		ret.reserve(kvps.size());

		std::transform(kvps.begin(), kvps.end(), std::inserter(ret, ret.begin()), [&modifyKey, &modifyValue](auto& e) {
			return modify(e, modifyKey, modifyValue);
		});

		return ret;
	}

	//----------------------------------------------------------

	template <typename KeyModifier, typename ValueModifier>
	NativeDataMultiMapEntry modify(const NativeDataMultiMapEntry& kv, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto r = std::remove_reference<std::remove_const<decltype(kv)>::type>::type{modifyKey(kv.first), {}};

		NativeDataMultiMapEntry ret{modifyKey(kv.first), {}};
		ret.second.reserve(kv.second.size());
		std::transform(kv.second.begin(), kv.second.end(), std::back_inserter(ret.second), modifyValue);

		return ret;
	}

	template <typename KeyModifier, typename ValueModifier>
	NativeDataMultiMap modify(const NativeDataMultiMap& kvps, KeyModifier modifyKey, ValueModifier modifyValue)
	{
		auto ret = NativeDataMultiMap{};
		ret.reserve(kvps.size());

		std::transform(kvps.begin(), kvps.end(), std::inserter(ret, ret.begin()), [&modifyKey, &modifyValue](auto& e) {
			return modify(e, modifyKey, modifyValue);
		});

		return ret;
	}

	//----------------------------------------------------------

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MAP_INLINE)

#if defined(KHUTILS_FLATBUFFER_MAP_IMPL)

#include "khutils/assertion.hpp"

#include <boost/container/flat_map.hpp>

#include <algorithm>
#include <string>
#include <vector>

namespace khutils
{
	//////////////////////////////////////////////////////////////////////////

	StringMapEntry createStringMapEntry()
	{
		return StringMapEntry{new StringMapEntryT()};
	}

	//---

	StringMap createStringMap()
	{
		return StringMap{new StringMapT()};
	}

	//---

	DataMapEntry createDataMapEntry()
	{
		return DataMapEntry{new DataMapEntryT()};
	}

	//---

	DataMap createDataMap()
	{
		return DataMap{new DataMapT()};
	}

	//---

	HashStringMapEntry createHashStringMapEntry()
	{
		return HashStringMapEntry{new HashStringMapEntryT()};
	}

	//---

	HashStringMap createHashStringMap()
	{
		return HashStringMap{new HashStringMapT()};
	}


	StringMultiMapEntry createStringMultiMapEntry()
	{
		return StringMultiMapEntry{new StringMultiMapEntryT()};
	}

	//---

	StringMultiMap createStringMultiMap()
	{
		return StringMultiMap{new StringMultiMapT()};
	}

	//---

	DataMultiMapEntryData createDataMultiMapEntryData()
	{
		return DataMultiMapEntryData{new DataMultiMapEntryDataT()};
	}

	DataMultiMapEntry createDataMultiMapEntry()
	{
		return DataMultiMapEntry{new DataMultiMapEntryT()};
	}

	//---

	DataMultiMap createDataMultiMap()
	{
		return DataMultiMap{new DataMultiMapT()};
	}

	//---

	//////////////////////////////////////////////////////////////////////////

	StringMapEntry createStringMapEntry(const StringMapEntry& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createStringMapEntry();
		KHUTILS_ASSERT_PTR(clone);

		clone->id	= ref->id;
		clone->value = ref->value;

		return clone;
	}

	//---

	StringMap createStringMap(const StringMap& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createStringMap();
		KHUTILS_ASSERT_PTR(clone);

		clone->entries.reserve(ref->entries.size());
		std::transform(ref->entries.begin(), ref->entries.end(), std::back_inserter(clone->entries), [](auto& e) {
			return createStringMapEntry(e);
		});

		return clone;
	}

	//---

	DataMapEntry createDataMapEntry(const DataMapEntry& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createDataMapEntry();
		KHUTILS_ASSERT_PTR(clone);

		clone->id	= ref->id;
		clone->value = ref->value;

		return clone;
	}

	//---

	DataMap createDataMap(const DataMap& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createDataMap();
		KHUTILS_ASSERT_PTR(clone);

		clone->entries.reserve(ref->entries.size());
		std::transform(ref->entries.begin(), ref->entries.end(), std::back_inserter(clone->entries), [](auto& e) {
			return createDataMapEntry(e);
		});

		return clone;
	}

	//---

	HashStringMapEntry createHashStringMapEntry(const HashStringMapEntry& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createHashStringMapEntry();
		KHUTILS_ASSERT_PTR(clone);

		clone->id	= ref->id;
		clone->value = ref->value;

		return clone;
	}

	//---

	HashStringMap createHashStringMap(const HashStringMap& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createHashStringMap();
		KHUTILS_ASSERT_PTR(clone);

		clone->entries.reserve(ref->entries.size());
		std::transform(ref->entries.begin(), ref->entries.end(), std::back_inserter(clone->entries), [](auto& e) {
			return createHashStringMapEntry(e);
		});

		return clone;
	}

	//---

	StringMultiMapEntry createStringMultiMapEntry(const StringMultiMapEntry& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createStringMultiMapEntry();
		KHUTILS_ASSERT_PTR(clone);

		clone->id = ref->id;
		clone->values.reserve(ref->values.size());
		std::copy(ref->values.begin(), ref->values.end(), std::back_inserter(clone->values));

		return clone;
	}

	//---

	StringMultiMap createStringMultiMap(const StringMultiMap& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createStringMultiMap();
		KHUTILS_ASSERT_PTR(clone);

		clone->entries.reserve(ref->entries.size());
		std::transform(ref->entries.begin(), ref->entries.end(), std::back_inserter(clone->entries), [](auto& e) {
			return createStringMultiMapEntry(e);
		});

		return clone;
	}

	//---

	DataMultiMapEntryData createDataMultiMapEntryData(const DataMultiMapEntryData& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createDataMultiMapEntryData();
		KHUTILS_ASSERT_PTR(clone);

		clone->data.reserve(ref->data.size());
		std::copy(ref->data.begin(), ref->data.end(), std::back_inserter(clone->data));

		return clone;
	}

	//---

	DataMultiMapEntry createDataMultiMapEntry(const DataMultiMapEntry& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createDataMultiMapEntry();
		KHUTILS_ASSERT_PTR(clone);

		clone->id = ref->id;
		clone->values.reserve(ref->values.size());
		std::transform(ref->values.begin(), ref->values.end(), std::back_inserter(clone->values), [](auto& d) {
			return createDataMultiMapEntryData(d);
		});

		return clone;
	}

	//---

	DataMultiMap createDataMultiMap(const DataMultiMap& ref)
	{
		KHUTILS_ASSERT_PTR(ref);
		auto clone = createDataMultiMap();
		KHUTILS_ASSERT_PTR(clone);

		clone->entries.reserve(ref->entries.size());
		std::transform(ref->entries.begin(), ref->entries.end(), std::back_inserter(clone->entries), [](auto& e) {
			return createDataMultiMapEntry(e);
		});

		return clone;
	}

	//---


	//////////////////////////////////////////////////////////////////////////

	StringMapEntry createStringMapEntry(const NativeStringMapEntry& native)
	{
		auto m   = createStringMapEntry();
		m->id	= native.first;
		m->value = native.second;

		return m;
	}

	NativeStringMapEntry to_native(const StringMapEntry& m)
	{
		return NativeStringMapEntry{m->id, m->value};
	}

	//---

	StringMap createStringMap(const NativeStringMap& native)
	{
		auto m = createStringMap();
		m->entries.reserve(native.size());
		std::transform(native.begin(), native.end(), std::back_inserter(m->entries), [](auto& e) {
			return createStringMapEntry(e);
		});
		std::sort(m->entries.begin(), m->entries.end());

		return m;
	}

	NativeStringMap to_native(const StringMap& m)
	{
		NativeStringMap native;
		native.reserve(m->entries.size());
		std::transform(m->entries.begin(), m->entries.end(), std::inserter(native, native.begin()), [](auto& e) {
			return to_native(e);
		});

		return native;
	}

	//////////////////////////////////////////////////////////////////////////

	DataMapEntry createDataMapEntry(const NativeDataMapEntry& native)
	{
		auto m   = createDataMapEntry();
		m->id	= native.first;
		m->value = native.second;

		return m;
	}

	NativeDataMapEntry to_native(const DataMapEntry& m)
	{
		return NativeDataMapEntry{m->id, m->value};
	}

	//---

	DataMap createDataMap(const NativeDataMap& native)
	{
		auto m = createDataMap();
		m->entries.reserve(native.size());
		std::transform(native.begin(), native.end(), std::back_inserter(m->entries), [](auto& e) {
			return createDataMapEntry(e);
		});
		std::sort(m->entries.begin(), m->entries.end());

		return m;
	}

	NativeDataMap to_native(const DataMap& m)
	{
		NativeDataMap native;
		native.reserve(m->entries.size());
		std::transform(m->entries.begin(), m->entries.end(), std::inserter(native, native.begin()), [](auto& e) {
			return to_native(e);
		});

		return native;
	}

	//////////////////////////////////////////////////////////////////////////

	StringMultiMapEntry createStringMultiMapEntry(const NativeStringMultiMapEntry& native)
	{
		auto m	= createStringMultiMapEntry();
		m->id	 = native.first;
		m->values = decltype(m->values){native.second.begin(), native.second.end()};

		return m;
	}


	NativeStringMultiMapEntry to_native(const StringMultiMapEntry& m)
	{
		return NativeStringMultiMapEntry{m->id, m->values};
	}

	//---

	StringMultiMap createStringMultiMap(const NativeStringMultiMap& native)
	{
		auto m = createStringMultiMap();
		m->entries.reserve(native.size());
		std::transform(native.begin(), native.end(), std::back_inserter(m->entries), [](auto& e) {
			return createStringMultiMapEntry(e);
		});
		std::sort(m->entries.begin(), m->entries.end());

		return m;
	}

	NativeStringMultiMap to_native(const StringMultiMap& m)
	{
		NativeStringMultiMap native;
		native.reserve(m->entries.size());
		std::transform(m->entries.begin(), m->entries.end(), std::inserter(native, native.begin()), [](auto& e) {
			return to_native(e);
		});

		return native;
	}

	//////////////////////////////////////////////////////////////////////////

	DataMultiMapEntryData createDataMultiMapEntryData(const NativeDataMultiMapEntryData& native)
	{
		auto m = createDataMultiMapEntryData();
		m->data.reserve(native.size());
		std::copy(native.begin(), native.end(), std::back_inserter(m->data));

		return m;
	}

	NativeDataMultiMapEntryData to_native(const DataMultiMapEntryData& m)
	{
		return m->data;
	}

	//---

	DataMultiMapEntry createDataMultiMapEntry(const NativeDataMultiMapEntry& native)
	{
		auto m = createDataMultiMapEntry();
		m->id  = native.first;
		m->values.reserve(native.second.size());
		std::transform(native.second.begin(), native.second.end(), std::back_inserter(m->values), [](auto& e) {
			return createDataMultiMapEntryData(e);
		});

		return m;
	}

	NativeDataMultiMapEntry to_native(const DataMultiMapEntry& m)
	{
		NativeDataMultiMapEntry native{m->id, {}};
		native.second.reserve(m->values.size());
		std::transform(m->values.begin(), m->values.end(), std::inserter(native.second, native.second.begin()), [](auto& e) {
			return to_native(e);
		});

		return native;
	}

	//---

	DataMultiMap createDataMultiMap(const NativeDataMultiMap& native)
	{
		auto m = createDataMultiMap();
		m->entries.reserve(native.size());
		std::transform(native.begin(), native.end(), std::back_inserter(m->entries), [](auto& e) {
			return createDataMultiMapEntry(e);
		});
		std::sort(m->entries.begin(), m->entries.end());

		return m;
	}

	NativeDataMultiMap to_native(const DataMultiMap& m)
	{
		NativeDataMultiMap native;
		native.reserve(m->entries.size());
		std::transform(m->entries.begin(), m->entries.end(), std::inserter(native, native.begin()), [](auto& e) {
			return to_native(e);
		});

		return native;
	}

	//////////////////////////////////////////////////////////////////////////

	HashStringMapEntry createHashStringMapEntry(const NativeHashStringMapEntry& native)
	{
		auto m   = createHashStringMapEntry();
		m->id	= native.first;
		m->value = native.second;

		return m;
	}

	NativeHashStringMapEntry to_native(const HashStringMapEntry& m)
	{
		return NativeHashStringMapEntry{m->id, m->value};
	}

	//---

	HashStringMap createHashStringMap(const NativeHashStringMap& native)
	{
		auto m = createHashStringMap();
		m->entries.reserve(native.size());
		std::transform(native.begin(), native.end(), std::back_inserter(m->entries), [](auto& e) {
			return createHashStringMapEntry(e);
		});
		std::sort(m->entries.begin(), m->entries.end());

		return m;
	}

	NativeHashStringMap to_native(const HashStringMap& m)
	{
		NativeHashStringMap native;
		native.reserve(m->entries.size());
		std::transform(m->entries.begin(), m->entries.end(), std::inserter(native, native.begin()), [](auto& e) {
			return to_native(e);
		});

		return native;
	}

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

}	// namespace khutils

#endif	// defined (KHUTILS_FLATBUFFER_MAP_IMPL)

#endif	// !KHUTILS_FLATBUFFER_MAP_HPP_INC
