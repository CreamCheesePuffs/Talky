#pragma once
#include <string>

// ACP <-> Unicode
bool AnsiToUnicode(const std::string& ansi, std::wstring& unicode);
bool UnicodeToAnsi(const std::wstring& unicode, std::string& ansi);

// UTF8 <-> Unicode
bool Utf8ToUnicode(const std::string& utf8, std::wstring& unicode);
bool UnicodeToUtf8(const std::wstring& unicode, std::string& utf8);

// ACP <-> UTF8
bool AnsiToUtf8(const std::string& ansi, std::string& utf8);
bool Utf8ToAnsi(const std::string& utf8, std::string& ansi);

// 便捷返回版（失败返回空串）
std::wstring AnsiToUnicode(const std::string& ansi);
std::string  UnicodeToAnsi(const std::wstring& unicode);
std::wstring Utf8ToUnicode(const std::string& utf8);
std::string  UnicodeToUtf8(const std::wstring& unicode);
std::string  AnsiToUtf8(const std::string& ansi);
std::string  Utf8ToAnsi(const std::string& utf8);
