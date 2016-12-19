#ifndef KHUTILS_READER_LAMBDA_HPP_INC
#define KHUTILS_READER_LAMBDA_HPP_INC

namespace khutils
{

	namespace reader_lambda
	{

		auto read
		  = [](auto otype, auto itype, auto& reader) { return reader.template read<decltype(otype), decltype(itype)>(); };
		auto fetch = [](auto otype, auto itype, auto& reader) {
			return reader.template fetch<decltype(otype), decltype(itype)>();
		};
		auto fetch_at = [](size_t readPos, auto otype, auto itype, auto& reader) {
			return reader.template fetch_at<decltype(otype), decltype(itype)>(readPos);
		};

		auto read_n = [](size_t count, auto otype, auto itype, auto& reader) {
			return reader.template read<decltype(otype), decltype(itype)>(count);
		};
		auto fetch_n = [](size_t count, auto otype, auto itype, auto& reader) {
			return reader.template fetch<decltype(otype), decltype(itype)>(count);
		};
		auto fetch_n_at = [](size_t readPos, size_t count, auto otype, auto itype, auto& reader) {
			return reader.template fetch_at<decltype(otype), decltype(itype)>(readPos, count);
		};

		auto skip = [](auto stype, size_t count, auto& reader) { reader.template skip<decltype(stype)>(count); };

		auto current_off = [](auto& reader) { reader.getCurrentOffset(); };
		auto goto_off	= [](size_t pos, auto& reader) { reader.jumpToOffset(pos); };
		auto is_end		 = [](size_t pos, auto& reader) { reader.isEnd(); };

	}	// namespace reader_lambda

}	// namespace khutils

#endif	// !KHUTILS_READER_LAMBDA_HPP_INC
