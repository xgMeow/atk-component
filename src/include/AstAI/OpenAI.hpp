/// @file      OpenAI.hpp
/// @brief     OpenAI规范API调用接口
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-23

#pragma once

#include "AstGlobal.h"
#include "AstAI/LLMClient.hpp"
#include "AstAI/ChatMessage.hpp"
#include "AstAI/ChatTool.hpp"
#include "AstUtil/StringView.hpp"
#include <string>
#include <vector>
#include <map>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Chat
    @{
*/

class JsonValue;

/// @brief OpenAI客户端
class AST_AI_API OpenAI: public LLMClient {
public:
    /// @brief 默认构造函数
    /// 从环境变量中获取API密钥和基础URL
    OpenAI();

    /// @brief 构造函数
    /// @param apiKey API密钥
    /// @param baseUrl API基础URL
    OpenAI(const std::string& apiKey, const std::string& baseUrl);

    #if 0
    /// @brief 发送聊天请求
    /// @param model 模型名称
    /// @param messages 消息列表
    /// @param tools 工具列表
    /// @param temperature 温度参数
    /// @return 响应内容
    std::string chat(
        const std::string& model, const std::vector<ChatMessage>& messages, 
        const std::vector<ChatTool>& tools = {}, float temperature = 0.7f
    );
    #endif
public: // 底层json接口

    using LLMClient::chat;  // 引入基类便捷封装 chat(JsonValue)

    /// @brief 聊天
    /// @param request 请求参数
    /// @param response 响应参数
    /// @return 错误码
    errc_t chat(const JsonValue& request, JsonValue& response) override;

    /// @brief 流式聊天（SSE）
    /// @param request 请求参数（含 stream:true）
    /// @param handler 事件处理器
    /// @param accumulatedResult 累计响应（从 SSE deltas 重组的完整 JSON）
    /// @return 错误码
    errc_t chatStream(const JsonValue& request,
                      ChatEventHandler& handler,
                      JsonValue& accumulatedResult) override;

    /// @brief 设置API密钥
    /// @param apiKey API密钥
    void setApiKey(StringView apiKey){apiKey_ = std::string(apiKey);}

    /// @brief 设置API基础URL
    /// @param baseUrl API基础URL
    void setBaseUrl(StringView baseUrl){baseUrl_ = std::string(baseUrl);}
protected:
    const std::string& apiKey() const { return apiKey_; }
    const std::string& baseUrl() const { return baseUrl_; }
private:
    std::string apiKey_{};         ///< API密钥
    std::string baseUrl_{};        ///< API基础URL
};

/*! @} */

AST_NAMESPACE_END