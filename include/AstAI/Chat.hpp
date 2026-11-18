/// @file      Chat.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-25

#pragma once

#include "AstGlobal.h"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 聊天接口
/// @param message 消息内容
/// @note 该接口会阻塞调用，直到收到响应或超时
/// @return 响应内容
AST_AI_API std::string aChat(StringView message);

/// @brief 聊天接口
/// @param message 消息内容
/// @param response 响应内容
/// @return 错误码
/// @note 该接口会阻塞调用，直到收到响应或超时
AST_AI_API errc_t aChat(StringView message, std::string& response);


/// @brief 清除聊天消息历史
/// @note 该接口会清空所有聊天消息，不包括系统提示
AST_AI_API void aChatClearMessages();


/// @brief 清除所有聊天消息
/// @note 该接口会清空所有聊天消息，包括系统提示
AST_AI_API void aChatClearAllMessages();



/*! @} */

AST_NAMESPACE_END
