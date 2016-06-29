﻿// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_MULTIMAP_ KHUTILS_STRING_MULTIMAP_H_
#define FLATBUFFERS_GENERATED_MULTIMAP_ KHUTILS_STRING_MULTIMAP_H_

#include "flatbuffers/flatbuffers.h"

namespace khutils
{
	namespace string_multimap
	{

		struct MapEntry;

		struct Map;

		/// simple simili-multimap type for Flatbuffers
		/// maps a key to a number of values
		/// key: string
		/// values: array of strings
		struct MapEntry FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
		{
			enum
			{
				VT_KEY	= 4,
				VT_VALUES = 6
			};
			const flatbuffers::String* key() const
			{
				return GetPointer<const flatbuffers::String*>(VT_KEY);
			}
			bool KeyCompareLessThan(const MapEntry* o) const
			{
				return *key() < *o->key();
			}
			int KeyCompareWithValue(const char* val) const
			{
				return strcmp(key()->c_str(), val);
			}
			const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>* values() const
			{
				return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>*>(VT_VALUES);
			}
			bool Verify(flatbuffers::Verifier& verifier) const
			{
				return VerifyTableStart(verifier) && VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_KEY)
					   && verifier.Verify(key()) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_VALUES)
					   && verifier.Verify(values()) && verifier.VerifyVectorOfStrings(values()) && verifier.EndTable();
			}
		};

		struct MapEntryBuilder
		{
			flatbuffers::FlatBufferBuilder& fbb_;
			flatbuffers::uoffset_t			start_;
			void add_key(flatbuffers::Offset<flatbuffers::String> key)
			{
				fbb_.AddOffset(MapEntry::VT_KEY, key);
			}
			void add_values(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> values)
			{
				fbb_.AddOffset(MapEntry::VT_VALUES, values);
			}
			MapEntryBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb)
			{
				start_ = fbb_.StartTable();
			}
			MapEntryBuilder&			  operator=(const MapEntryBuilder&);
			flatbuffers::Offset<MapEntry> Finish()
			{
				auto o = flatbuffers::Offset<MapEntry>(fbb_.EndTable(start_, 2));
				fbb_.Required(o, MapEntry::VT_KEY);	// key
				return o;
			}
		};

		inline flatbuffers::Offset<MapEntry>
		CreateMapEntry(flatbuffers::FlatBufferBuilder&													  _fbb,
					   flatbuffers::Offset<flatbuffers::String>											  key	= 0,
					   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> values = 0)
		{
			MapEntryBuilder builder_(_fbb);
			builder_.add_values(values);
			builder_.add_key(key);
			return builder_.Finish();
		}

		/// container for multimap entries
		struct Map FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
		{
			enum
			{
				VT_ENTRIES = 4
			};
			const flatbuffers::Vector<flatbuffers::Offset<MapEntry>>* entries() const
			{
				return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<MapEntry>>*>(VT_ENTRIES);
			}
			bool Verify(flatbuffers::Verifier& verifier) const
			{
				return VerifyTableStart(verifier) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_ENTRIES)
					   && verifier.Verify(entries()) && verifier.VerifyVectorOfTables(entries()) && verifier.EndTable();
			}
		};

		struct MapBuilder
		{
			flatbuffers::FlatBufferBuilder& fbb_;
			flatbuffers::uoffset_t			start_;
			void add_entries(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<MapEntry>>> entries)
			{
				fbb_.AddOffset(Map::VT_ENTRIES, entries);
			}
			MapBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb)
			{
				start_ = fbb_.StartTable();
			}
			MapBuilder&				 operator=(const MapBuilder&);
			flatbuffers::Offset<Map> Finish()
			{
				auto o = flatbuffers::Offset<Map>(fbb_.EndTable(start_, 1));
				return o;
			}
		};

		inline flatbuffers::Offset<Map> CreateMap(flatbuffers::FlatBufferBuilder& _fbb,
												  flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<MapEntry>>> entries = 0)
		{
			MapBuilder builder_(_fbb);
			builder_.add_entries(entries);
			return builder_.Finish();
		}

	}	// namespace string_multimap
}	// namespace khutils

#endif	// FLATBUFFERS_GENERATED_MULTIMAP_ KHUTILS_STRING_MULTIMAP_H_