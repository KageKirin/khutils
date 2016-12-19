#ifndef KHUTILS_WRITER_LAMBDA_HPP_INC
#define KHUTILS_WRITER_LAMBDA_HPP_INC

namespace khutils
{

	namespace writer_lambda
	{

		auto write
		  = [](auto otype, auto itype, auto& writer) { writer.template write<decltype(otype), decltype(itype)>(itype); };
		auto write_np = [](size_t count, auto otype, auto itype, auto& writer) {
			writer.template write<decltype(otype), decltype(*itype)>(count, itype);
		};
		auto write_n = [](auto otype, auto itype, auto& writer) {
			writer.template write<decltype(otype), decltype(itype)::value_type>(itype);
		};

		auto put
		  = [](auto otype, auto itype, auto& writer) { writer.template put<decltype(otype), decltype(itype)>(itype); };
		auto put_at = [](size_t writePos, auto otype, auto itype, auto& writer) {
			writer.template putAt<decltype(otype), decltype(itype)>(itype, writePos);
		};

		auto skip = [](auto stype, size_t count, auto& writer) { writer.template skip<decltype(stype)>(count); };

		auto current_off = [](auto& writer) { writer.getCurrentOffset(); };
		auto goto_off	= [](size_t pos, auto& writer) { writer.jumpToOffset(pos); };
		auto is_end		 = [](size_t pos, auto& writer) { writer.isEnd(); };

	}	// namespace writer_lambda

}	// namespace khutils

#endif	// !KHUTILS_WRITER_LAMBDA_HPP_INC
