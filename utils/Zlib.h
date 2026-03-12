#pragma once

#include <string>

// 压缩：src -> dst，成功返回 true
bool Compress(const std::string& src, std::string& dst);

// 解压：src(压缩数据) -> dst(原文)，需要传原始长度
bool Decompress(const std::string& src, std::string& dst, size_t originalSize);
