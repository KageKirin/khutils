#####################################################################
# include this file in your master makefile

KHUTILS_FLATC_CPP_FLAGS=\
	--cpp --scoped-enums --gen-name-strings --gen-object-api \
	-o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/ \
	-I $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas


gen_flatbuffer_khutils_headers:
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/map.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/multimap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamultimap.fbs
	clang-format -i $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/*_generated.h

gen_flatbuffer_embedded_khutils_schemas:
	@xxd -i $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/map.fbs $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/map_embedded_schema.xxd.h
	@xxd -i $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/multimap.fbs $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/multimap_embedded_schema.xxd.h
	@xxd -i $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamap.fbs $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/datamap_embedded_schema.xxd.h
	@xxd -i $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamultimap.fbs $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/datamultimap_embedded_schema.xxd.h
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2c -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/map.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/map_embedded_schema.bin.h -n map_embedded_schema
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2c -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/multimap.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/multimap_embedded_schema.bin.h -n multimap_embedded_schema
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2c -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamap.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/datamap_embedded_schema.bin.h -n datamap_embedded_schema
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2c -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamultimap.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/datamultimap_embedded_schema.bin.h -n datamultimap_embedded_schema

