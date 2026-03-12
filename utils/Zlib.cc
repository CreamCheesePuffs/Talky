#include "stdafx.h"
#include "zlib1.2.11/zlib.h"
#include "Zlib.h"

#include <vector>


bool Compress(const std::string& src, std::string& dst)
{
    if (src.empty()) {
        return false;
    }

    uLongf outLen = compressBound(static_cast<uLong>(src.size()));
    if (outLen == 0) {
        return false;
    }

    std::vector<char> outBuf(outLen);
    int ret = compress(
        reinterpret_cast<Bytef*>(outBuf.data()),
        &outLen,
        reinterpret_cast<const Bytef*>(src.data()),
        static_cast<uLong>(src.size()));

    if (ret != Z_OK) {
        return false;
    }

    dst.assign(outBuf.data(), outLen);
    return true;
}

bool Decompress(const std::string& src, std::string& dst, size_t originalSize)
{
    if (src.empty() || originalSize == 0) {
        return false;
    }

    uLongf outLen = static_cast<uLongf>(originalSize);
    std::vector<char> outBuf(outLen);

    int ret = uncompress(
        reinterpret_cast<Bytef*>(outBuf.data()),
        &outLen,
        reinterpret_cast<const Bytef*>(src.data()),
        static_cast<uLong>(src.size()));

    if (ret != Z_OK) {
        return false;
    }

    dst.assign(outBuf.data(), outLen);
    return true;
}
