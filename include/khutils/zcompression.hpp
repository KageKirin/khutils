#ifndef KHUTILS_Z_COMPRESSION_HPP_INC
#define KHUTILS_Z_COMPRESSION_HPP_INC

#include <cctype>
#include <vector>

namespace khutils
{
	//-------------------------------------------------------------------------
	// inflate (decompress)

	struct ZInflateContext;
	std::vector<uint8_t> z_inflate(const std::vector<uint8_t>& cmprData, size_t maxDecompressedSize, const ZInflateContext&);

	//-------------------------------------------------------------------------
	// deflate (compress)

	struct ZDeflateContext;
	std::vector<uint8_t> z_deflate(const std::vector<uint8_t>& data, const ZDeflateContext&);

//-------------------------------------------------------------------------

#if defined(KHTUILS_Z_COMPRESSION_CONTEXT)
	struct ZInflateContext
	{
		bool ignore_adler32 = true;	// ignore Adler32 checksum if true

		// use custom zlib decoder instead of built in one (default: null)
		unsigned (*custom_zlib)(unsigned char**, size_t*, const unsigned char*, size_t, const ZInflateContext*) = nullptr;

		// use custom deflate decoder instead of built in one (default: null)
		// if custom_zlib is used, custom_deflate is ignored since only the built in
		// zlib function will call custom_deflate*/
		unsigned (*custom_inflate)(unsigned char**, size_t*, const unsigned char*, size_t, const ZInflateContext*) = nullptr;

		// optional custom settings for custom functions
		const void* custom_context = nullptr;
	};

	struct ZDeflateContext
	{
		bool	use_lz77   = true;	// whether or not to use LZ77. Should be 1 for proper compression.
		uint8_t lz77_btype = 2;		  // the block type for LZ (0, 1, 2 or 3, see zlib standard). Should be 2 for proper
									  // compression.
		uint16_t lz77_windowsize
		  = 2048;	// must be a power of two <= 32768. higher compresses more but is slower. Default:
		// 2048.
		uint16_t lz77_minmatch
		  = 0;	// mininum lz77 length. 3 is normally best, 6 can be better for some PNGs. Default: 0
		uint16_t lz77_nicematch
		  = 128;	// stop searching if >= this length found. Set to 258 for best compression. Default: 128
		bool lz77_use_lazymatching = true;	// use lazy matching: better compression but a bit slower. Default: true

		// use custom zlib encoder instead of built in one (default: null)
		unsigned (*custom_zlib)(unsigned char**, size_t*, const unsigned char*, size_t, const ZDeflateContext*) = nullptr;

		// use custom deflate encoder instead of built in one (default: null)
		// if custom_zlib is used, custom_deflate is ignored since only the built in
		// zlib function will call custom_deflate
		unsigned (*custom_deflate)(unsigned char**, size_t*, const unsigned char*, size_t, const ZDeflateContext*) = nullptr;

		// optional custom settings for custom functions
		const void* custom_context = nullptr;
	};

#else	//! defined(KHTUILS_Z_COMPRESSION_CONTEXT)
	struct ZInflateContext
	{
	};
	struct ZDeflateContext
	{
	};

#endif	// defined(KHTUILS_Z_COMPRESSION_CONTEXT)

}	// namespace khutils


#if defined(KHUTILS_Z_COMPRESSION_IMPL)

//-------------------------------------------------------------------------
// ZLIB VARIANT

#if defined(KHUTILS_Z_COMPRESSION_IMPL_USING_ZLIB)
#include <zlib.h>

namespace khutils
{
	std::vector<uint8_t> z_inflate(const std::vector<uint8_t>& cmprData, size_t outSize, const ZInflateContext&)
	{
		std::vector<uint8_t> outBuf(outSize, 0);
		auto				 err = uncompress(&outBuf.front(), &outSize, cmprData.data(), cmprData.size());
		// TODO handle error!
		outBuf.resize(outSize);
		return outBuf;
	}
	std::vector<uint8_t> z_deflate(const std::vector<uint8_t>& data, const ZDeflateContext&)
	{
		size_t				 outSize = compressBound(data.size());
		std::vector<uint8_t> outBuf(outSize, 0);
		auto				 err = compress2(&outBuf.front(), &outSize, data.data(), data.size(), 9);
		// TODO handle error!
		outBuf.resize(outSize);
		return outBuf;
	}

}	// namespace khutils
#endif	// defined(KHUTILS_Z_COMPRESSION_IMPL_USING_ZLIB)


//-------------------------------------------------------------------------
// ZSTD VARIANT

#if defined(KHUTILS_Z_COMPRESSION_IMPL_USING_ZSTD)
#include <zstd.h>

namespace khutils
{
	std::vector<uint8_t> z_inflate(const std::vector<uint8_t>& cmprData, size_t outSize, const ZInflateContext&)
	{
		std::vector<uint8_t> outBuf(outSize, 0);
		outSize = ZSTD_decompress(&outBuf.front(), outSize, cmprData.data(), cmprData.size());
		// TODO handle error!
		outBuf.resize(outSize);
		return outBuf;
	}

	std::vector<uint8_t> z_deflate(const std::vector<uint8_t>& data, const ZDeflateContext&)
	{
		size_t				 outSize = ZSTD_compressBound(data.size());
		std::vector<uint8_t> outBuf(2 * outSize, 0);
		outSize = ZSTD_compress(&outBuf.front(), outSize, data.data(), data.size(), 9);
		// TODO handle error!
		outBuf.resize(outSize);
		return outBuf;
	}

}	// namespace khutils
#endif	// defined(KHUTILS_Z_COMPRESSION_IMPL_USING_ZSTD)


//-------------------------------------------------------------------------
// ZOPFLI VARIANT

#if defined(KHUTILS_Z_COMPRESSION_IMPL_USING_ZOPFLI)
#include <zopfli.h>

namespace khutils
{
	std::vector<uint8_t> z_inflate(const std::vector<uint8_t>& cmprData, size_t outSize, const ZInflateContext&)
	{
	}

	std::vector<uint8_t> z_deflate(const std::vector<uint8_t>& data, const ZDeflateContext&)
	{
	}

}	// namespace khutils
#endif	// defined(KHUTILS_Z_COMPRESSION_IMPL_USING_ZOPFLI)


//-------------------------------------------------------------------------

#endif	// defined(KHUTILS_Z_COMPRESSION_IMPL)

#endif	// !KHUTILS_Z_COMPRESSION_HPP_INC
