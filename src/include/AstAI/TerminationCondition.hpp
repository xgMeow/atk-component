/// @file      CancellationToken.hpp
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

class ChatMessages;

/// @brief 终止条件
/// @details 该类定义了一个终止条件的接口，用于在操作中判断是否应终止。
class AST_AI_API TerminationCondition
{
public:
    TerminationCondition() = default;

    virtual ~TerminationCondition() = default;

    /// @brief 检查是否应终止操作
    /// @param messages 消息历史
    /// @return 是否应终止操作
    virtual bool shouldTerminate(const ChatMessages& messages) const = 0;

};

/*! @} */

AST_NAMESPACE_END
