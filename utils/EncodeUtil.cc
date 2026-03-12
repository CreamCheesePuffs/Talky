#include "stdafx.h"
#include "EncodeUtil.h"
#include <windows.h>

namespace 
{

    bool MultiByteToWide(unsigned int codePage, const std::string& src, std::wstring& dst) {
        dst.clear();
        if (src.empty()) return true;

        int len = ::MultiByteToWideChar(codePage, 0, src.c_str(), -1, nullptr, 0);
        if (len <= 0) return false;

        std::wstring tmp(static_cast<size_t>(len), L'\0');
        int ret = ::MultiByteToWideChar(codePage, 0, src.c_str(), -1, &tmp[0], len);
        if (ret <= 0) return false;

        if (!tmp.empty() && tmp.back() == L'\0') tmp.pop_back();
        dst.swap(tmp);
        return true;
    }

    bool WideToMultiByte(unsigned int codePage, const std::wstring& src, std::string& dst) {
        dst.clear();
        if (src.empty()) return true;

        int len = ::WideCharToMultiByte(codePage, 0, src.c_str(), -1, nullptr, 0, nullptr, nullptr);
        if (len <= 0) return false;

        std::string tmp(static_cast<size_t>(len), '\0');
        int ret = ::WideCharToMultiByte(codePage, 0, src.c_str(), -1, &tmp[0], len, nullptr, nullptr);
        if (ret <= 0) return false;

        if (!tmp.empty() && tmp.back() == '\0') tmp.pop_back();
        dst.swap(tmp);
        return true;
    }

} // namespace

bool AnsiToUnicode(const std::string& ansi, std::wstring& unicode) {
    return MultiByteToWide(CP_ACP, ansi, unicode);
}

bool UnicodeToAnsi(const std::wstring& unicode, std::string& ansi) {
    return WideToMultiByte(CP_ACP, unicode, ansi);
}

bool Utf8ToUnicode(const std::string& utf8, std::wstring& unicode) {
    return MultiByteToWide(CP_UTF8, utf8, unicode);
}

bool UnicodeToUtf8(const std::wstring& unicode, std::string& utf8) {
    return WideToMultiByte(CP_UTF8, unicode, utf8);
}

bool AnsiToUtf8(const std::string& ansi, std::string& utf8) {
    std::wstring unicode;
    if (!AnsiToUnicode(ansi, unicode)) return false;
    return UnicodeToUtf8(unicode, utf8);
}

bool Utf8ToAnsi(const std::string& utf8, std::string& ansi) {
    std::wstring unicode;
    if (!Utf8ToUnicode(utf8, unicode)) return false;
    return UnicodeToAnsi(unicode, ansi);
}

std::wstring AnsiToUnicode(const std::string& ansi) {
    std::wstring out;
    AnsiToUnicode(ansi, out);
    return out;
}

std::string UnicodeToAnsi(const std::wstring& unicode) {
    std::string out;
    UnicodeToAnsi(unicode, out);
    return out;
}

std::wstring Utf8ToUnicode(const std::string& utf8) {
    std::wstring out;
    Utf8ToUnicode(utf8, out);
    return out;
}

std::string UnicodeToUtf8(const std::wstring& unicode) {
    std::string out;
    UnicodeToUtf8(unicode, out);
    return out;
}

std::string AnsiToUtf8(const std::string& ansi) {
    std::string out;
    AnsiToUtf8(ansi, out);
    return out;
}

std::string Utf8ToAnsi(const std::string& utf8) {
    std::string out;
    Utf8ToAnsi(utf8, out);
    return out;
}
