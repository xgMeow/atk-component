/// @file      AgentSession.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-27

#pragma once

#include "AstGlobal.h"
#include "AstAI/ChatSession.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 智能体会话
class AST_AI_API AgentSession : public ChatSession
{
public:
    AgentSession();
    ~AgentSession() = default;
};

/*! @} */

AST_NAMESPACE_END
