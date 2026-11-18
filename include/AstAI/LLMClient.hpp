/// @file      LLMClient.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-26

#pragma once

#include "AstGlobal.h"
#include "AstUtil/JsonValue.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Chat
    @{
*/

class JsonValue;
class ChatEventHandler;

/// @brief     大语言模型客户端接口
/// @details   子类只需实现一个纯虚方法即可完成对接
class AST_AI_API LLMClient
{
public:
    LLMClient() = default;
    virtual ~LLMClient() = default;

    /// @brief 发送聊天请求（纯虚接口，子类必须实现）
    /// @param request 请求参数（JSON格式，包含messages、model、temperature等字段）
    /// @param response 响应参数
    /// @return 错误码，0表示成功
    virtual errc_t chat(const JsonValue& request, JsonValue& response) = 0;

    /// @brief 发送流式聊天请求
    /// @param request 请求参数（JSON格式，含 stream:true）
    /// @param handler 事件处理器（实时接收 delta 事件）
    /// @param accumulatedResult 累计响应（从 SSE deltas 重组的完整 JSON，与非流式格式相同）
    /// @return 错误码，0表示成功
    virtual errc_t chatStream(const JsonValue& request, ChatEventHandler& handler,
                              JsonValue& accumulatedResult);

    /// @brief 发送聊天请求（便捷封装，内部调用上面的虚方法）
    /// @param request 请求参数
    /// @return 响应内容，失败时返回包含error字段的JsonValue
    JsonValue chat(const JsonValue& request);


};

/*! @} */

AST_NAMESPACE_END
