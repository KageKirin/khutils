// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_STRINGMAP_KHUTILS_HASHSTRING_MAP_H_
#define FLATBUFFERS_GENERATED_STRINGMAP_KHUTILS_HASHSTRING_MAP_H_

#include "flatbuffers/flatbuffers.h"

namespace khutils
{
	namespace hashstring_map
	{

		struct MapEntry;
		struct MapEntryT;

		struct Map;
		struct MapT;

		struct MapEntryT : public flatbuffers::NativeTable
		{
			typedef MapEntry						 TableType;
			static FLATBUFFERS_CONSTEXPR const char* GetFullyQualifiedName()
			{
				return "khutils.hashstring_map.MapEntryT";
			}
			uint64_t	id;
			std::string value;
			MapEntryT() : id(0)
			{
			}
		};

		/// simple hash LUT for Flatbuffers
		/// map entry
		/// maps a key to a value
		/// id: hash
		/// value: string
		struct MapEntry FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
		{
			typedef MapEntryT						 NativeTableType;
			static FLATBUFFERS_CONSTEXPR const char* GetFullyQualifiedName()
			{
				return "khutils.hashstring_map.MapEntry";
			}
			enum
			{
				VT_ID	= 4,
				VT_VALUE = 6
			};
			uint64_t id() const
			{
				return GetField<uint64_t>(VT_ID, 0);
			}
			bool KeyCompareLessThan(const MapEntry* o) const
			{
				return id() < o->id();
			}
			int KeyCompareWithValue(uint64_t val) const
			{
				return id() < val ? -1 : id() > val;
			}
			const flatbuffers::String* value() const
			{
				return GetPointer<const flatbuffers::String*>(VT_VALUE);
			}
			bool Verify(flatbuffers::Verifier& verifier) const
			{
				return VerifyTableStart(verifier) && VerifyField<uint64_t>(verifier, VT_ID)
					   && VerifyField<flatbuffers::uoffset_t>(verifier, VT_VALUE) && verifier.Verify(value())
					   && verifier.EndTable();
			}
			MapEntryT* UnPack(const flatbuffers::resolver_function_t* resolver = nullptr) const;
			static flatbuffers::Offset<MapEntry> Pack(flatbuffers::FlatBufferBuilder&		  _fbb,
													  const MapEntryT*						  _o,
													  const flatbuffers::rehasher_function_t* _rehasher = nullptr);
		};

		struct MapEntryBuilder
		{
			flatbuffers::FlatBufferBuilder& fbb_;
			flatbuffers::uoffset_t			start_;
			void add_id(uint64_t id)
			{
				fbb_.AddElement<uint64_t>(MapEntry::VT_ID, id, 0);
			}
			void add_value(flatbuffers::Offset<flatbuffers::String> value)
			{
				fbb_.AddOffset(MapEntry::VT_VALUE, value);
			}
			MapEntryBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb)
			{
				start_ = fbb_.StartTable();
			}
			MapEntryBuilder&			  operator=(const MapEntryBuilder&);
			flatbuffers::Offset<MapEntry> Finish()
			{
				auto o = flatbuffers::Offset<MapEntry>(fbb_.EndTable(start_, 2));
				return o;
			}
		};

		inline flatbuffers::Offset<MapEntry> CreateMapEntry(flatbuffers::FlatBufferBuilder&			 _fbb,
															uint64_t								 id	= 0,
															flatbuffers::Offset<flatbuffers::String> value = 0)
		{
			MapEntryBuilder builder_(_fbb);
			builder_.add_id(id);
			builder_.add_value(value);
			return builder_.Finish();
		}

		inline flatbuffers::Offset<MapEntry> CreateMapEntryDirect(flatbuffers::FlatBufferBuilder& _fbb,
																  uint64_t						  id	= 0,
																  const char*					  value = nullptr)
		{
			return CreateMapEntry(_fbb, id, value ? _fbb.CreateString(value) : 0);
		}

		inline flatbuffers::Offset<MapEntry> CreateMapEntry(flatbuffers::FlatBufferBuilder&			_fbb,
															const MapEntryT*						_o,
															const flatbuffers::rehasher_function_t* rehasher = nullptr);

		struct MapT : public flatbuffers::NativeTable
		{
			typedef Map								 TableType;
			static FLATBUFFERS_CONSTEXPR const char* GetFullyQualifiedName()
			{
				return "khutils.hashstring_map.MapT";
			}
			std::vector<smart_pointer::value_ptr<MapEntryT>> entries;
			MapT()
			{
			}
		};

		/// container for map entries
		struct Map FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
		{
			typedef MapT							 NativeTableType;
			static FLATBUFFERS_CONSTEXPR const char* GetFullyQualifiedName()
			{
				return "khutils.hashstring_map.Map";
			}
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
			MapT* UnPack(const flatbuffers::resolver_function_t* resolver = nullptr) const;
			static flatbuffers::Offset<Map> Pack(flatbuffers::FlatBufferBuilder&		 _fbb,
												 const MapT*							 _o,
												 const flatbuffers::rehasher_function_t* _rehasher = nullptr);
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

		inline flatbuffers::Offset<Map> CreateMapDirect(flatbuffers::FlatBufferBuilder&					  _fbb,
														const std::vector<flatbuffers::Offset<MapEntry>>* entries = nullptr)
		{
			return CreateMap(_fbb, entries ? _fbb.CreateVector<flatbuffers::Offset<MapEntry>>(*entries) : 0);
		}

		inline flatbuffers::Offset<Map> CreateMap(flatbuffers::FlatBufferBuilder&		  _fbb,
												  const MapT*							  _o,
												  const flatbuffers::rehasher_function_t* rehasher = nullptr);

		inline MapEntryT* MapEntry::UnPack(const flatbuffers::resolver_function_t* resolver) const
		{
			(void)resolver;
			auto _o = new MapEntryT();
			{
				auto _e = id();
				_o->id  = _e;
			};
			{
				auto _e = value();
				if (_e)
					_o->value = _e->str();
			};
			return _o;
		}

		inline flatbuffers::Offset<MapEntry> MapEntry::Pack(flatbuffers::FlatBufferBuilder&			_fbb,
															const MapEntryT*						_o,
															const flatbuffers::rehasher_function_t* _rehasher)
		{
			return CreateMapEntry(_fbb, _o, _rehasher);
		}

		inline flatbuffers::Offset<MapEntry> CreateMapEntry(flatbuffers::FlatBufferBuilder&			_fbb,
															const MapEntryT*						_o,
															const flatbuffers::rehasher_function_t* rehasher)
		{
			(void)rehasher;
			return CreateMapEntry(_fbb, _o->id, _o->value.size() ? _fbb.CreateString(_o->value) : 0);
		}

		inline MapT* Map::UnPack(const flatbuffers::resolver_function_t* resolver) const
		{
			(void)resolver;
			auto _o = new MapT();
			{
				auto _e = entries();
				if (_e)
				{
					for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++)
					{
						_o->entries.push_back(smart_pointer::value_ptr<MapEntryT>(_e->Get(_i)->UnPack(resolver)));
					}
				}
			};
			return _o;
		}

		inline flatbuffers::Offset<Map> Map::Pack(flatbuffers::FlatBufferBuilder&		  _fbb,
												  const MapT*							  _o,
												  const flatbuffers::rehasher_function_t* _rehasher)
		{
			return CreateMap(_fbb, _o, _rehasher);
		}

		inline flatbuffers::Offset<Map> CreateMap(flatbuffers::FlatBufferBuilder&		  _fbb,
												  const MapT*							  _o,
												  const flatbuffers::rehasher_function_t* rehasher)
		{
			(void)rehasher;
			return CreateMap(_fbb,
							 _o->entries.size() ?
							   _fbb.CreateVector<flatbuffers::Offset<MapEntry>>(
								 _o->entries.size(),
								 [&](size_t i) { return CreateMapEntry(_fbb, _o->entries[i].get(), rehasher); }) :
							   0);
		}

	}	// namespace hashstring_map
}	// namespace khutils

#endif	// FLATBUFFERS_GENERATED_STRINGMAP_KHUTILS_HASHSTRING_MAP_H_
