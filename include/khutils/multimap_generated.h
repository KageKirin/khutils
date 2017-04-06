// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MULTIMAP_KHUTILS_STRING_MULTIMAP_H_
#define FLATBUFFERS_GENERATED_MULTIMAP_KHUTILS_STRING_MULTIMAP_H_

#include "flatbuffers/flatbuffers.h"

namespace khutils
{
	namespace string_multimap
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
				return "khutils.string_multimap.MapEntryT";
			}
			std::string				 id;
			std::vector<std::string> values;
			MapEntryT()
			{
			}
		};

		/// simple simili-multimap type for Flatbuffers
		/// map entry
		/// maps a key to a number of values
		/// id: string
		/// values: array of strings
		struct MapEntry FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
		{
			typedef MapEntryT						 NativeTableType;
			static FLATBUFFERS_CONSTEXPR const char* GetFullyQualifiedName()
			{
				return "khutils.string_multimap.MapEntry";
			}
			enum
			{
				VT_ID	 = 4,
				VT_VALUES = 6
			};
			const flatbuffers::String* id() const
			{
				return GetPointer<const flatbuffers::String*>(VT_ID);
			}
			bool KeyCompareLessThan(const MapEntry* o) const
			{
				return *id() < *o->id();
			}
			int KeyCompareWithValue(const char* val) const
			{
				return strcmp(id()->c_str(), val);
			}
			const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>* values() const
			{
				return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>*>(VT_VALUES);
			}
			bool Verify(flatbuffers::Verifier& verifier) const
			{
				return VerifyTableStart(verifier) && VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_ID)
					   && verifier.Verify(id()) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_VALUES)
					   && verifier.Verify(values()) && verifier.VerifyVectorOfStrings(values()) && verifier.EndTable();
			}
			MapEntryT* UnPack(const flatbuffers::resolver_function_t* _resolver = nullptr) const;
			void UnPackTo(MapEntryT* _o, const flatbuffers::resolver_function_t* _resolver = nullptr) const;
			static flatbuffers::Offset<MapEntry> Pack(flatbuffers::FlatBufferBuilder&		  _fbb,
													  const MapEntryT*						  _o,
													  const flatbuffers::rehasher_function_t* _rehasher = nullptr);
		};

		struct MapEntryBuilder
		{
			flatbuffers::FlatBufferBuilder& fbb_;
			flatbuffers::uoffset_t			start_;
			void add_id(flatbuffers::Offset<flatbuffers::String> id)
			{
				fbb_.AddOffset(MapEntry::VT_ID, id);
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
				const auto end = fbb_.EndTable(start_, 2);
				auto	   o   = flatbuffers::Offset<MapEntry>(end);
				fbb_.Required(o, MapEntry::VT_ID);
				return o;
			}
		};

		inline flatbuffers::Offset<MapEntry>
		CreateMapEntry(flatbuffers::FlatBufferBuilder&													  _fbb,
					   flatbuffers::Offset<flatbuffers::String>											  id	 = 0,
					   flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> values = 0)
		{
			MapEntryBuilder builder_(_fbb);
			builder_.add_values(values);
			builder_.add_id(id);
			return builder_.Finish();
		}

		inline flatbuffers::Offset<MapEntry> CreateMapEntryDirect(flatbuffers::FlatBufferBuilder& _fbb,
																  const char*					  id = nullptr,
																  const std::vector<flatbuffers::Offset<flatbuffers::String>>* values
																  = nullptr)
		{
			return khutils::string_multimap::CreateMapEntry(
			  _fbb, id ? _fbb.CreateString(id) : 0, values ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*values) : 0);
		}

		flatbuffers::Offset<MapEntry> CreateMapEntry(flatbuffers::FlatBufferBuilder&		 _fbb,
													 const MapEntryT*						 _o,
													 const flatbuffers::rehasher_function_t* _rehasher = nullptr);

		struct MapT : public flatbuffers::NativeTable
		{
			typedef Map								 TableType;
			static FLATBUFFERS_CONSTEXPR const char* GetFullyQualifiedName()
			{
				return "khutils.string_multimap.MapT";
			}
			std::vector<smart_pointer::value_ptr<MapEntryT>> entries;
			MapT()
			{
			}
		};

		/// container for multimap entries
		struct Map FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
		{
			typedef MapT							 NativeTableType;
			static FLATBUFFERS_CONSTEXPR const char* GetFullyQualifiedName()
			{
				return "khutils.string_multimap.Map";
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
			MapT* UnPack(const flatbuffers::resolver_function_t* _resolver = nullptr) const;
			void UnPackTo(MapT* _o, const flatbuffers::resolver_function_t* _resolver = nullptr) const;
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
				const auto end = fbb_.EndTable(start_, 1);
				auto	   o   = flatbuffers::Offset<Map>(end);
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
			return khutils::string_multimap::CreateMap(_fbb, entries ? _fbb.CreateVector<flatbuffers::Offset<MapEntry>>(*entries) : 0);
		}

		flatbuffers::Offset<Map> CreateMap(flatbuffers::FlatBufferBuilder&		   _fbb,
										   const MapT*							   _o,
										   const flatbuffers::rehasher_function_t* _rehasher = nullptr);

		inline MapEntryT* MapEntry::UnPack(const flatbuffers::resolver_function_t* _resolver) const
		{
			auto _o = new MapEntryT();
			UnPackTo(_o, _resolver);
			return _o;
		}

		inline void MapEntry::UnPackTo(MapEntryT* _o, const flatbuffers::resolver_function_t* _resolver) const
		{
			(void)_o;
			(void)_resolver;
			{
				auto _e = id();
				if (_e)
					_o->id = _e->str();
			};
			{
				auto _e = values();
				if (_e)
				{
					_o->values.resize(_e->size());
					for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++)
					{
						_o->values[_i] = _e->Get(_i)->str();
					}
				}
			};
		}

		inline flatbuffers::Offset<MapEntry> MapEntry::Pack(flatbuffers::FlatBufferBuilder&			_fbb,
															const MapEntryT*						_o,
															const flatbuffers::rehasher_function_t* _rehasher)
		{
			return CreateMapEntry(_fbb, _o, _rehasher);
		}

		inline flatbuffers::Offset<MapEntry> CreateMapEntry(flatbuffers::FlatBufferBuilder&			_fbb,
															const MapEntryT*						_o,
															const flatbuffers::rehasher_function_t* _rehasher)
		{
			(void)_rehasher;
			(void)_o;
			auto _id	 = _fbb.CreateString(_o->id);
			auto _values = _o->values.size() ? _fbb.CreateVectorOfStrings(_o->values) : 0;
			return khutils::string_multimap::CreateMapEntry(_fbb, _id, _values);
		}

		inline MapT* Map::UnPack(const flatbuffers::resolver_function_t* _resolver) const
		{
			auto _o = new MapT();
			UnPackTo(_o, _resolver);
			return _o;
		}

		inline void Map::UnPackTo(MapT* _o, const flatbuffers::resolver_function_t* _resolver) const
		{
			(void)_o;
			(void)_resolver;
			{
				auto _e = entries();
				if (_e)
				{
					_o->entries.resize(_e->size());
					for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++)
					{
						_o->entries[_i] = smart_pointer::value_ptr<MapEntryT>(_e->Get(_i)->UnPack(_resolver));
					}
				}
			};
		}

		inline flatbuffers::Offset<Map> Map::Pack(flatbuffers::FlatBufferBuilder&		  _fbb,
												  const MapT*							  _o,
												  const flatbuffers::rehasher_function_t* _rehasher)
		{
			return CreateMap(_fbb, _o, _rehasher);
		}

		inline flatbuffers::Offset<Map> CreateMap(flatbuffers::FlatBufferBuilder&		  _fbb,
												  const MapT*							  _o,
												  const flatbuffers::rehasher_function_t* _rehasher)
		{
			(void)_rehasher;
			(void)_o;
			auto _entries
			  = _o->entries.size() ?
				  _fbb.CreateVector<flatbuffers::Offset<MapEntry>>(
					_o->entries.size(), [&](size_t i) { return CreateMapEntry(_fbb, _o->entries[i].get(), _rehasher); }) :
				  0;
			return khutils::string_multimap::CreateMap(_fbb, _entries);
		}

	}	// namespace string_multimap
}	// namespace khutils

#endif	// FLATBUFFERS_GENERATED_MULTIMAP_KHUTILS_STRING_MULTIMAP_H_
