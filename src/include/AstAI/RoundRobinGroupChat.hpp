/// @file      RoundRobinGroupChat.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-14

#pragma once

#include "AstGlobal.h"
#include "BaseGroupChat.hpp"
#include "AstAI/ChatAgent.hpp"
#include "AstAI/ChatMessages.hpp"
#include "AstAI/TerminationCondition.hpp"
#include <memory>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class TerminationCondition;

/// @brief 轮询式群聊
/// @details 该类实现了轮询式的群聊逻辑，每个Agent按顺序处理消息，直到达到所设定的停止条件。
class AST_AI_API RoundRobinGroupChat : public BaseGroupChat
{
public:
    RoundRobinGroupChat() = default;
    ~RoundRobinGroupChat() = default;

    // —— Agent管理 ——

    /// @brief 添加Agent到群聊（非拥有指针，调用者负责生命周期）
    void addAgent(ChatAgent* agent);

    /// @brief 获取所有Agent
    const std::vector<ChatAgent*>& agents() const { return agents_; }

    // —— 终止条件 ——

    /// @brief 设置终止条件
    void setTerminationCondition(std::unique_ptr<TerminationCondition> condition);

    /// @brief 获取终止条件
    TerminationCondition* terminationCondition() const { return terminationCondition_.get(); }

    // —— 消息历史 ——

    /// @brief 获取消息历史（可修改）
    ChatMessages& messages() { return messages_; }

    /// @brief 获取消息历史（只读）
    const ChatMessages& messages() const { return messages_; }

    // —— 配置 ——

    /// @brief 设置最大轮次数（默认100，防止无限循环）
    void setMaxRounds(int maxRounds) { maxRounds_ = maxRounds; }

    /// @brief 获取最大轮次数
    int maxRounds() const { return maxRounds_; }

    // —— 执行 ——

    errc_t run(const ChatMessage& message, ChatMessage& response) override;

private:
    std::vector<ChatAgent*> agents_;
    ChatMessages messages_;
    std::unique_ptr<TerminationCondition> terminationCondition_;
    int maxRounds_ = 100;
};

/*! @} */

AST_NAMESPACE_END
