#pragma once

#include <cstdint>
#include <string>

#pragma pack(push, 1)
//协议头
typedef struct MsgHeader
{
    char     compressflag;     //压缩标志，如果为1，则启用压缩，反之不启用压缩
    int32_t  originsize;       //包体压缩前大小
    int32_t  compresssize;     //包体压缩后大小
    char     reserved[16];
} MsgHeader;
#pragma pack(pop)

enum class Cmd : int32_t {
    RegisterReq  = 1001,
    LoginReq     = 1002,
    FindFriendReq = 1003,
    AddFriendReq = 1004,
    SendTextReq  = 1004,

    RegisterRsp  = 2001,
    LoginRsp     = 2002,
    AddFriendRsp = 2003,
    SendTextRsp  = 2004,
    PushText     = 3001,
    Heartbeat    = 9001
};

struct UserInfo {
    int32_t userId{0};
    std::string username;
    std::string nickname;
};

struct ChatMsg {
    int32_t fromUserId{0};
    int32_t toUserId{0};
    std::string text;
    int64_t timestamp{0};
};

struct RegisterReq {
    std::string username, nickname, password;
};

struct LoginReq {
    std::string username, password;
    int32_t status{1};
};

struct AddFriendReq {
    int32_t targetUserId{0};
};

struct SendTextReq {
    int32_t toUserId{0};
    std::string text;
};
