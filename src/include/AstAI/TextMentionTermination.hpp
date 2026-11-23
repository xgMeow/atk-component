/// @file      TextMentionTermination.hpp
/// @brief     文本提及终止条件
/// @details   当最后一条消息内容中包含指定文本时终止
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-14

#pragma once

#include "AstGlobal.h"
#include "TerminationCondition.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Chat
    @{
*/

/// @brief 文本提及终止条件
/// @details 当最后一条消息内容中包含指定文本时，判定应终止。
///          常用于让Agent在达成一致时输出特定关键词（如 "APPROVED"）来结束对话。
class AST_AI_API TextMentionTermination : public TerminationCondition
{
public:
    /// @brief 构造函数
    /// @param text 触发终止的文本
    explicit TextMentionTermination(StringView text);

    /// @brief 检查是否应终止
    /// @param messages 消息历史
    /// @return 若最后一条消息内容包含指定文本则返回true
    bool shouldTerminate(const ChatMessages& messages) const override;

    /// @brief 设置触发终止的文本
    void setText(StringView text);

    /// @brief 获取触发终止的文本
    const std::string& text() const;

private:
    std::string text_;
};

/*! @} */

AST_NAMESPACE_END
