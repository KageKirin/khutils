#ifndef KHUTILS_ENDIAN_HPP_INC
#define KHUTILS_ENDIAN_HPP_INC

#include <cctype>
#include <cstdint>

namespace khutils
{
	namespace endian
	{
		enum class order : uint16_t
		{
			little = 0x0001,
			big	= 0x0100,
		};


		constexpr order static_endian_order()
		{
			return (order)0xFFFF & 1;
		}

		constexpr order native = static_endian_order();
	}	// namespace endian

	template <endian::order order_out, endian::order order_in = endian::native>
	inline uint8_t endian_reverse(uint8_t val)
	{
		return val;
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	inline int8_t endian_reverse(int8_t val)
	{
		return val;
	}

	template <endian::order order_out, endian::order order_in = endian::native>
	uint16_t endian_reverse(uint16_t val);

	template <endian::order order_out, endian::order order_in = endian::native>
	int16_t endian_reverse(int16_t val);

	template <endian::order order_out, endian::order order_in = endian::native>
	uint32_t endian_reverse(uint32_t val);

	template <endian::order order_out, endian::order order_in = endian::native>
	int32_t endian_reverse(int32_t val);

	template <endian::order order_out, endian::order order_in = endian::native>
	uint64_t endian_reverse(uint64_t val);

	template <endian::order order_out, endian::order order_in = endian::native>
	int64_t endian_reverse(int64_t val);

	template <endian::order order_out, endian::order order_in = endian::native>
	float endian_reverse(float val);

	template <endian::order order_out, endian::order order_in = endian::native>
	double endian_reverse(double val);

	template <endian::order order_out, endian::order order_in = endian::native>
	long double endian_reverse(long double val);


	// helper
	template <typename T>
	inline T flip_bytes(T val)
	{
		auto buf_in  = reinterpret_cast<uint8_t*>(&val);
		T	ret	 = (T)0;
		auto buf_out = reinterpret_cast<uint8_t*>(&ret);

		for (size_t i = 0; i < sizeof(T); ++i)
		{
			buf_out[i] = buf_in[sizeof(T) - 1 + i];
		}

		return ret;
	}


	// overload: little -> little
	template <>
	inline uint16_t endian_reverse<endian::order::little, endian::order::little>(uint16_t val)
	{
		return val;
	}

	template <>
	inline int16_t endian_reverse<endian::order::little, endian::order::little>(int16_t val)
	{
		return val;
	}

	template <>
	inline uint32_t endian_reverse<endian::order::little, endian::order::little>(uint32_t val)
	{
		return val;
	}

	template <>
	inline int32_t endian_reverse<endian::order::little, endian::order::little>(int32_t val)
	{
		return val;
	}

	template <>
	inline uint64_t endian_reverse<endian::order::little, endian::order::little>(uint64_t val)
	{
		return val;
	}

	template <>
	inline int64_t endian_reverse<endian::order::little, endian::order::little>(int64_t val)
	{
		return val;
	}

	template <>
	inline float endian_reverse<endian::order::little, endian::order::little>(float val)
	{
		return val;
	}

	template <>
	inline double endian_reverse<endian::order::little, endian::order::little>(double val)
	{
		return val;
	}

	template <>
	inline long double endian_reverse<endian::order::little, endian::order::little>(long double val)
	{
		return val;
	}

	// overload: big -> big
	template <>
	inline uint16_t endian_reverse<endian::order::big, endian::order::big>(uint16_t val)
	{
		return val;
	}

	template <>
	inline int16_t endian_reverse<endian::order::big, endian::order::big>(int16_t val)
	{
		return val;
	}

	template <>
	inline uint32_t endian_reverse<endian::order::big, endian::order::big>(uint32_t val)
	{
		return val;
	}

	template <>
	inline int32_t endian_reverse<endian::order::big, endian::order::big>(int32_t val)
	{
		return val;
	}

	template <>
	inline uint64_t endian_reverse<endian::order::big, endian::order::big>(uint64_t val)
	{
		return val;
	}

	template <>
	inline int64_t endian_reverse<endian::order::big, endian::order::big>(int64_t val)
	{
		return val;
	}

	template <>
	inline float endian_reverse<endian::order::big, endian::order::big>(float val)
	{
		return val;
	}

	template <>
	inline double endian_reverse<endian::order::big, endian::order::big>(double val)
	{
		return val;
	}

	template <>
	inline long double endian_reverse<endian::order::big, endian::order::big>(long double val)
	{
		return val;
	}

	// overload: little -> big
	template <>
	inline uint16_t endian_reverse<endian::order::big, endian::order::little>(uint16_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline int16_t endian_reverse<endian::order::big, endian::order::little>(int16_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline uint32_t endian_reverse<endian::order::big, endian::order::little>(uint32_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline int32_t endian_reverse<endian::order::big, endian::order::little>(int32_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline uint64_t endian_reverse<endian::order::big, endian::order::little>(uint64_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline int64_t endian_reverse<endian::order::big, endian::order::little>(int64_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline float endian_reverse<endian::order::big, endian::order::little>(float val)
	{
		return flip_bytes(val);
	}

	template <>
	inline double endian_reverse<endian::order::big, endian::order::little>(double val)
	{
		return flip_bytes(val);
	}

	template <>
	inline long double endian_reverse<endian::order::big, endian::order::little>(long double val)
	{
		return flip_bytes(val);
	}


	// overload: big -> little
	template <>
	inline uint16_t endian_reverse<endian::order::little, endian::order::big>(uint16_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline int16_t endian_reverse<endian::order::little, endian::order::big>(int16_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline uint32_t endian_reverse<endian::order::little, endian::order::big>(uint32_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline int32_t endian_reverse<endian::order::little, endian::order::big>(int32_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline uint64_t endian_reverse<endian::order::little, endian::order::big>(uint64_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline int64_t endian_reverse<endian::order::little, endian::order::big>(int64_t val)
	{
		return flip_bytes(val);
	}

	template <>
	inline float endian_reverse<endian::order::little, endian::order::big>(float val)
	{
		return flip_bytes(val);
	}

	template <>
	inline double endian_reverse<endian::order::little, endian::order::big>(double val)
	{
		return flip_bytes(val);
	}

	template <>
	inline long double endian_reverse<endian::order::little, endian::order::big>(long double val)
	{
		return flip_bytes(val);
	}

}	// namespace khutils

#endif	// !KHUTILS_ENDIAN_HPP_INC
