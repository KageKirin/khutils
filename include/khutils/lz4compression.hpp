#ifndef KHUTILS_LZ4_COMPRESSION_HPP_INC
#define KHUTILS_LZ4_COMPRESSION_HPP_INC

#include <cctype>
#include <vector>

namespace khutils
{
	//-------------------------------------------------------------------------
	// decompress

	std::vector<uint8_t> lz4_decompress(const std::vector<uint8_t>& cmprData, size_t maxDecompressedSize);

	//-------------------------------------------------------------------------
	// compress

	std::vector<uint8_t> lz4_compress(const std::vector<uint8_t>& data);

	//-------------------------------------------------------------------------

}	// namespace khutils


#if defined(KHUTILS_LZ4_COMPRESSION_IMPL)

#include <lz4.h>

namespace khutils
{
	std::vector<uint8_t> lz4_decompress(const std::vector<uint8_t>& cmprData, size_t outSize)
	{
		std::vector<uint8_t> outBuf(outSize, 0);
		outSize = LZ4_decompress_safe((const char*)cmprData.data(), (char*)&outBuf.front(), cmprData.size(), outBuf.size());
		// TODO handle error!
		outBuf.resize(outSize);
		return outBuf;
	}

	std::vector<uint8_t> lz4_compress(const std::vector<uint8_t>& data)
	{
		auto				 outSize = LZ4_compressBound(data.size());
		std::vector<uint8_t> outBuf(outSize, 0);
		outSize = LZ4_compress_default((const char*)data.data(), (char*)&outBuf.front(), data.size(), outBuf.size());
		// TODO handle error!
		outBuf.resize(outSize);
		return outBuf;
	}

}	// namespace khutils

#endif	// defined(KHUTILS_LZ4_COMPRESSION_IMPL)

#endif	// !KHUTILS_LZ4_COMPRESSION_HPP_INC
