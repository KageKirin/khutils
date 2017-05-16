#####################################################################
# include this file in your master makefile

KHUTILS_FLATC_CPP_FLAGS=\
	--cpp --scoped-enums --gen-name-strings --gen-object-api --no-includes \
	-o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/ \
	-I $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas

KHUTILS_FLATC_GO_FLAGS=\
	--go --scoped-enums --gen-name-strings --gen-object-api --no-includes --gen-onefile \
	-I $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas \
	-o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/go



gen_flatbuffer_khutils_headers:
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/map.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/multimap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamultimap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_CPP_FLAGS) $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/stringmap.fbs
	clang-format -i $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/*_generated.h

gen_flatbuffer_khutils_go:
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_GO_FLAGS)/map/ $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/map.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_GO_FLAGS)/multimap/ $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/multimap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_GO_FLAGS)/datamap/ $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_GO_FLAGS)/datamultimap/ $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamultimap.fbs
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/flatc $(KHUTILS_FLATC_GO_FLAGS)/stringmap/ $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/stringmap.fbs

gen_flatbuffer_embedded_khutils_schemas:
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2cppstring -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/map.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/map_embedded_schema.hxx -n map_embedded_schema
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2cppstring -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/multimap.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/multimap_embedded_schema.hxx -n multimap_embedded_schema
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2cppstring -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamap.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/datamap_embedded_schema.hxx -n datamap_embedded_schema
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2cppstring -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/datamultimap.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/datamultimap_embedded_schema.hxx -n datamultimap_embedded_schema
	@$(PROJECT_SCAFFOLDING)/tools/bin/darwin/bin2cppstring -f $(PROJECT_SCAFFOLDING)/thirdparty/khutils/schemas/stringmap.fbs -o $(PROJECT_SCAFFOLDING)/thirdparty/khutils/include/khutils/stringmap_embedded_schema.hxx -n stringmap_embedded_schema

gen_khutils_flatbuffers: \
	gen_flatbuffer_khutils_headers \
	gen_flatbuffer_embedded_khutils_schemas \
	gen_flatbuffer_khutils_go \
	;
