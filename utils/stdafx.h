#pragma once

// ---- Windows/CRT macros ----
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#ifndef WINVER
#define WINVER 0x0601
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif

// ---- C++ STL ----
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <mutex>
#include <thread>
#include <atomic>
#include <functional>
#include <chrono>

// ---- WinSock/Windows ----
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment(lib, "Ws2_32.lib")

// ---- Qt (按需保留，避免过多 include) ----
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QByteArray>
#include <QtCore/QVariant>
#include <QtCore/QVariantMap>
#include <QtCore/QDateTime>
#include <QtCore/QTimer>
#include <QtCore/QThread>
#include <QtCore/QMetaObject>
#include <QtNetwork/QTcpSocket>

// ---- helpers ----
#ifndef DELETE_PTR
#define DELETE_PTR(p) \
    if ((p) != nullptr) { \
        delete (p); \
        (p) = nullptr; \
    }
#endif