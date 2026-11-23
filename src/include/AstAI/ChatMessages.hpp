/// @file      ChatMessages.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-25

#pragma once

#include "AstGlobal.h"
#include "ChatMessage.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

using MessageVector = std::vector<ChatMessage>;


/// @brief 聊天消息集合
class ChatMessages: public MessageVector
{
public:

    ChatMessages() = default;
    ~ChatMessages() = default;

    /// @brief 转换为JSON值
    /// @return JSON值
    AST_AI_API
    JsonValue toJson() const;

    /// @brief 添加消息
    /// @param message 消息
    void addMessage(const ChatMessage& message)
    {
        this->push_back(message);
    }

    /// @brief 添加系统提示消息
    /// @param content 系统提示
    void addSystemMessage(StringView content)
    {
        addMessage(ChatMessage::System(content));
    }

    /// @brief 添加用户消息
    /// @param content 用户消息内容
    void addUserMessage(StringView content)
    {
        addMessage(ChatMessage::User(content));
    }

    /// @brief 添加助手消息
    /// @param content 助手消息内容
    void addAssistantMessage(StringView content)
    {
        addMessage(ChatMessage::Assistant(content));
    }

    void addAssistantMessage(StringView content, const JsonValue& toolCalls)
    {
        addMessage(ChatMessage::Assistant(content, toolCalls));
    }

    /// @brief 添加工具消息
    /// @param content 工具消息内容
    /// @param toolCallId 工具调用ID
    void addToolMessage(StringView content, StringView toolCallId)
    {
        addMessage(ChatMessage::Tool(content, toolCallId));
    }


    /// @brief 设置系统提示
    /// @param systemPrompt 系统提示
    AST_AI_API
    void setSystemPrompt(StringView systemPrompt);
};

/*! @} */

/*! @} */

AST_NAMESPACE_END
