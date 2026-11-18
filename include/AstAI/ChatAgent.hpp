/// @file      AssistantAgent.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-14

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class ChatMessages;
class ChatEventHandler;

/// @brief 聊天智能体抽象基类
/// @details 定义所有聊天智能体的公共接口，包括名称标识和运行方法。
class AST_AI_API ChatAgent
{
public:
    virtual ~ChatAgent() = default;

    /// @brief 执行智能体逻辑
    /// @param messages 消息历史（可修改）
    /// @return 错误码，0表示成功
    virtual errc_t run(ChatMessages& messages) = 0;

    /// @brief 执行智能体逻辑（流式）
    /// @param messages 消息历史（可修改）
    /// @param handler  事件处理器（实时接收 delta 事件）
    /// @return 错误码，0表示成功
    virtual errc_t runStream(ChatMessages& messages, ChatEventHandler& handler) = 0;

    // —— 名称 ——

    /// @brief 设置智能体名称（用于多Agent场景下的标识）
    void setName(StringView name) { name_ = std::string(name); }

    /// @brief 获取智能体名称
    const std::string& name() const { return name_; }

protected:
    std::string name_{}; ///< 智能体名称
};

/*! @} */

AST_NAMESPACE_END
