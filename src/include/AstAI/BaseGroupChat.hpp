/// @file      BaseGroupChat.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-14

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ChatMessage;

class AST_AI_API BaseGroupChat
{
public:
    virtual ~BaseGroupChat() = default;

    /// @brief 运行一次聊天，返回最终的响应消息，过程中会处理工具调用、多个Agent交互等逻辑
    /// @param message 输入消息
    /// @param response 输出消息
    /// @return errc_t 
    virtual errc_t run(const ChatMessage& message, ChatMessage& response) = 0;
};


/*! @} */

AST_NAMESPACE_END
