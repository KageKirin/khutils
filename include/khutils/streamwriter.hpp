#ifndef KHUTILS_STREAMWRITER_HPP_INC
#define KHUTILS_STREAMWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/base_handler.hpp"
#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>
#include <ostream>
#include <vector>

namespace khutils
{
	using boost::endian::order;

	//! stream writer
	//! wraps ostream.write in an endian-aware
	//! and bitstream-fitting manner
	//! usage: use typedef'ed version (see below)
	template <order _order>
	struct _streamwriter;

	using streamwriter				 = _streamwriter<order::native>;
	using little_endian_streamwriter = _streamwriter<order::little>;
	using big_endian_streamwriter	= _streamwriter<order::big>;

	template <order _order>
	struct _streamwriter
	{
		std::ostream& m_os;

		_streamwriter()						= delete;
		_streamwriter(const _streamwriter&) = default;
		_streamwriter(_streamwriter&&)		= default;
		_streamwriter(std::ostream& os) : m_os(os)
		{
		}

		_streamwriter& operator=(const _streamwriter&) = default;
		_streamwriter& operator=(_streamwriter&&) = default;

		//! writes WriteT into ostream after converting and end0an-swapping provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT>
		void write(InT t, SwapConversionFuncT<WriteT, InT> swapConv = base_handler_trait<_order>::template swap_after_convert<WriteT, InT>)
		{
			WriteT r = swapConv(t);
			m_os.write(reinterpret_cast<char*>(&r), sizeof(WriteT));
		}

		//! writes count * WriteT into ostream after converting and end0an-swapping
		//! provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT>
		void write(const InT* t,
				   size_t	 count,
				   SwapConversionFuncT<WriteT, InT> swapConv = base_handler_trait<_order>::template swap_after_convert<WriteT, InT>)

		{
			std::vector<WriteT> r(count);
			std::transform(t, t + count, r.begin(), swapConv);
			m_os.write(reinterpret_cast<char*>(&r[0]), sizeof(WriteT) * r.size());
		}

		//! writes WriteT into ostream after converting and end0an-swapping provided
		//! InT
		//! optional convert function can be used to downsample InT into bytewise
		//! smaller WriteT
		//! e.g. to write F32 as U16
		template <typename WriteT, typename InT>
		void write(const std::vector<InT>& t,
				   SwapConversionFuncT<WriteT, InT> swapConv = base_handler_trait<_order>::template swap_after_convert<WriteT, InT>)
		{
			write(t.data(), t.size(), swapConv);
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			const char c = 0;
			for (size_t i = 0; i < sizeof(_SkipT) * count; ++i)
			{
				m_os.write(&c, 1);
			}
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= m_os.tellp();
			auto nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;

			skip<char>(nextAlignedPos - pos);
		}

		std::ostream& getStream()
		{
			return m_os;
		}

		size_t getCurrentOffset()
		{
			return m_os.tellp();
		}
	};

}	// namespace khutils

#endif	// KHUTILS_STREAMWRITER_HPP_INC
