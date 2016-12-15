#ifndef KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC
#define KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC

#include "khutils/glm/glm_endian_reverse.hpp"

#include "khutils/base_handler.hpp"
#include <bandit/bandit.h>
#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

template <typename WriterT, typename ReaderT, typename ValueT, typename GetWriterT, typename GetReaderT>
void it_singleWriteAndRead(const char* name, ValueT value, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return it(name, [&]() {
		WriterT writer = getWriter();
		writer.template write<decltype(value)>(value);

		ReaderT reader = getReader();
		auto	read   = reader.template read<decltype(value)>();

		AssertThat(read, Equals(value));
	});
};

template <typename WriterT, typename ReaderT, typename ValueT, typename ValueT2, typename GetWriterT, typename GetReaderT>
void it_doubleWriteAndRead(const char* name, ValueT value, ValueT2 value2, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return it(name, [&]() {
		WriterT writer = getWriter();
		writer.template write<decltype(value)>(value);
		writer.template write<decltype(value2)>(value2);

		ReaderT reader = getReader();
		auto	read   = reader.template read<decltype(value)>();
		auto	read2  = reader.template read<decltype(value2)>();

		AssertThat(read, Equals(value));
		AssertThat(read2, Equals(value2));
	});
};

template <typename WriterT, typename ReaderT, typename ValueT, typename GetWriterT, typename GetReaderT>
void it_writeFetchAndRead(const char* name, ValueT value, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return it(name, [&]() {
		WriterT writer = getWriter();
		writer.template write<decltype(value)>(value);

		ReaderT reader = getReader();
		auto	fetch  = reader.template fetch<decltype(value)>();
		auto	read   = reader.template read<decltype(value)>();

		AssertThat(fetch, Equals(value));
		AssertThat(read, Equals(value));
		AssertThat(fetch, Equals(read));
	});
};

template <typename WriterT, typename ReaderT, typename ValueT, typename ValueT2, typename ValueT3, typename GetWriterT, typename GetReaderT>
void it_skipAndAlign(const char* name, ValueT value, ValueT2 value2, ValueT3 value3, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return it(name, [&]() {
		WriterT writer = getWriter();
		writer.template write<decltype(value)>(value);
		writer.template skip<decltype(value)>();
		writer.template write<decltype(value2)>(value2);
		writer.template alignToNext<16>();
		writer.template write<decltype(value3)>(value3);

		ReaderT reader = getReader();
		auto	read   = reader.template read<decltype(value)>();
		reader.template skip<decltype(value)>();
		auto read2 = reader.template read<decltype(value2)>();
		reader.template alignToNext<16>();
		auto read3 = reader.template read<decltype(value3)>();

		AssertThat(read, Equals(value));
		AssertThat(read2, Equals(value2));
		AssertThat(read3, Equals(value3));
	});
};

///

template <typename WriterT, typename ReaderT, typename GetWriterT, typename GetReaderT>
void desc_singleWriteAndRead(const char* desc, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return describe(desc, [&]() {
		it_singleWriteAndRead<WriterT, ReaderT>("int", 42, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("float", 0.65f, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("double", 2.56094, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("glm::vec2", glm::vec2{0.3f, 1.5f}, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("glm::dvec2", glm::vec2{0.3, 1.5}, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("glm::ivec2", glm::vec2{3, 15}, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("glm::vec3", glm::vec3{0.3f, 1.5f, -0.7f}, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("glm::dvec3", glm::vec3{0.3, 1.5, -0.7}, getWriter, getReader);
		it_singleWriteAndRead<WriterT, ReaderT>("glm::ivec3", glm::vec3{3, 15, -7}, getWriter, getReader);
	});
};

template <typename WriterT, typename ReaderT, typename GetWriterT, typename GetReaderT>
void desc_doubleWriteAndRead(const char* desc, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return describe(desc, [&]() {
		it_doubleWriteAndRead<WriterT, ReaderT>("int, int", 42, 87, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("float, float", 0.65f, 1.12f, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("double, double", 0.654245, 1.128745, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::vec2, glm::vec2", glm::vec2{0.3f, 1.5f}, glm::vec2{-1.45f, 40.2f}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::dvec2, glm::dvec2", glm::dvec2{0.3, 1.5}, glm::dvec2{-1.45, 40.2}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::ivec2, glm::ivec2", glm::ivec2{3, 15}, glm::ivec2{-145, 402}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>(
		  "glm::vec3, glm::vec3", glm::vec3{0.3f, 1.5f, -0.7f}, glm::vec3{-1.45f, 40.2f, 3.54f}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>(
		  "glm::dvec3, glm::dvec3", glm::dvec3{0.3, 1.5, -0.7}, glm::dvec3{-1.45, 40.2, 3.54}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::ivec3, glm::ivec3", glm::ivec3{3, 15, -7}, glm::ivec3{-145, 402, 354}, getWriter, getReader);
	});
};

template <typename WriterT, typename ReaderT, typename GetWriterT, typename GetReaderT>
void desc_mixedWriteAndRead(const char* desc, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return describe(desc, [&]() {
		it_doubleWriteAndRead<WriterT, ReaderT>("int, float", 42, 1.12f, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("float, int", 0.65f, 87, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("float, double", 0.65f, 1.128745, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::ivec2, glm::vec2", glm::ivec2{3, 15}, glm::vec2{-1.45f, 40.2f}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::vec2, glm::ivec2", glm::vec2{0.3f, 1.5f}, glm::ivec2{-145, 402}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::vec2, glm::dvec2", glm::vec2{0.3f, 1.5f}, glm::dvec2{-1.45345, 40.2134}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>("glm::ivec3, glm::vec3", glm::ivec3{3, 15, -7}, glm::vec3{-1.45f, 40.2f, 3.54f}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>(
		  "glm::vec3, glm::ivec3", glm::vec3{0.3f, 1.5f, -0.7f}, glm::ivec3{-145, 402, 354}, getWriter, getReader);
		it_doubleWriteAndRead<WriterT, ReaderT>(
		  "glm::vec3, glm::dvec3", glm::vec3{0.3f, 1.5f, -0.7f}, glm::dvec3{-1.45345, 40.2134, 3.5401}, getWriter, getReader);
	});
};

template <typename WriterT, typename ReaderT, typename GetWriterT, typename GetReaderT>
void desc_writeFetchAndRead(const char* desc, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return describe(desc, [&]() {
		it_writeFetchAndRead<WriterT, ReaderT>("int", 42, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("float", 0.65f, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("double", 2.56094, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("glm::vec2", glm::vec2{0.3f, 1.5f}, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("glm::dvec2", glm::vec2{0.3, 1.5}, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("glm::ivec2", glm::vec2{3, 15}, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("glm::vec3", glm::vec3{0.3f, 1.5f, -0.7f}, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("glm::dvec3", glm::vec3{0.3, 1.5, -0.7}, getWriter, getReader);
		it_writeFetchAndRead<WriterT, ReaderT>("glm::ivec3", glm::vec3{3, 15, -7}, getWriter, getReader);
	});
};

template <typename WriterT, typename ReaderT, typename GetWriterT, typename GetReaderT>
void desc_skipAndAlign(const char* desc, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return describe(desc, [&]() {
		it_skipAndAlign<WriterT, ReaderT>("int, int, int", 42, 87, 456, getWriter, getReader);
		it_skipAndAlign<WriterT, ReaderT>("float, float, float", 0.65f, 1.12f, 75.545f, getWriter, getReader);
		it_skipAndAlign<WriterT, ReaderT>("double, double, double", 0.654245, 1.128745, 345.54509, getWriter, getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::vec2, glm::vec2, glm::vec2",
										  glm::vec2{0.3f, 1.5f},
										  glm::vec2{-1.45f, 40.2f},
										  glm::vec2{3.56f, -5.43f},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::dvec2, glm::dvec2, glm::dvec2",
										  glm::dvec2{0.3, 1.5},
										  glm::dvec2{-1.45, 40.2},
										  glm::dvec2{3.56, -5.43},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::ivec2, glm::ivec2, glm::ivec2",
										  glm::ivec2{3, 15},
										  glm::ivec2{-145, 402},
										  glm::ivec2{356, -543},	//
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::vec3, glm::vec3, glm::vec3",
										  glm::vec3{0.3f, 1.5f, -0.7f},
										  glm::vec3{-1.45f, 40.2f, 3.54f},
										  glm::vec3{3.56f, -5.43f, -1.45f},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::dvec3, glm::dvec3, glm::dvec3",
										  glm::dvec3{0.3, 1.5, -0.7},
										  glm::dvec3{-1.45, 40.2, 3.54},
										  glm::dvec3{3.56, -5.43, -1.45},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::ivec3, glm::ivec3, glm::ivec3",
										  glm::ivec3{3, 15, -7},
										  glm::ivec3{-145, 402, 354},
										  glm::ivec3{356, -543, -145},	//
										  getWriter,
										  getReader);

		it_skipAndAlign<WriterT, ReaderT>("int, float, double", 42, 1.12f, 345.54509, getWriter, getReader);
		it_skipAndAlign<WriterT, ReaderT>("float, int, double", 0.65f, 87, 345.54509, getWriter, getReader);
		it_skipAndAlign<WriterT, ReaderT>("double, float, int", 0.654245, 1.12f, 345.54509, getWriter, getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::ivec2, glm::vec2, glm::dvec2",
										  glm::ivec2{3, 15},
										  glm::vec2{-1.45f, 40.2f},
										  glm::dvec2{3.56, -5.43},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::vec2, glm::ivec2, glm::dvec2",
										  glm::vec2{0.3f, 1.5f},
										  glm::ivec2{-145, 402},
										  glm::dvec2{3.56, -5.43},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::dvec2, glm::vec2, glm::ivec2",
										  glm::dvec2{0.3, 1.5},
										  glm::vec2{-1.45f, 40.2f},
										  glm::ivec2{356, -543},	//
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::ivec3, glm::vec3, glm::dvec3",
										  glm::ivec3{3, 15, -0.7},
										  glm::vec3{-1.45f, 40.2f, 3.54f},
										  glm::dvec3{3.56, -5.43, 1.45},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::vec3, glm::ivec3, glm::dvec3",
										  glm::vec3{0.3f, 1.5f, -0.7f},
										  glm::ivec3{-145, 402, 354},
										  glm::dvec3{3.56, -5.43, 1.45},
										  getWriter,
										  getReader);
		it_skipAndAlign<WriterT, ReaderT>("glm::dvec3, glm::vec3, glm::ivec3",
										  glm::dvec3{0.3, 1.5, -0.7},
										  glm::vec3{-1.45f, 40.2f, 3.54f},
										  glm::ivec3{356, -543, 145},	//
										  getWriter,
										  getReader);
	});
};

///
template <typename WriterT, typename ReaderT, typename GetWriterT, typename GetReaderT>
void desc_testGroup(const char* desc, GetWriterT getWriter, GetReaderT getReader)
{
	using namespace bandit;

	return describe(desc, [&]() {
		desc_singleWriteAndRead<WriterT, ReaderT>("writing once, reading once", getWriter, getReader);
		desc_doubleWriteAndRead<WriterT, ReaderT>("writing twice, reading twice", getWriter, getReader);
		desc_mixedWriteAndRead<WriterT, ReaderT>("writing mixed, reading mixed", getWriter, getReader);
		desc_writeFetchAndRead<WriterT, ReaderT>("fetching", getWriter, getReader);
		desc_skipAndAlign<WriterT, ReaderT>("skip and alignment", getWriter, getReader);
	});
};

#endif	// ! KHUTILS_UNITTESTS_HANDLER_UT_HPP_INC
