/// @file      ChatToolsDefault.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-27

#pragma once

#include "AstGlobal.h"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ChatTools;
class ChatSession;
class JsonValue;





/// @brief 初始化智能体工具集合
/// @param tools 工具集合
void aInitAgentTools(ChatTools& tools);


/// @brief 初始化智能体会话
/// @param session 会话
/// @details 初始化智能体会话
void aInitAgentSession(ChatSession& session);


/// @brief 获取智能体系统提示
/// @return 智能体系统提示
const char* aAgentSystemPrompt();


/// @brief 获取默认的智能体工具集合
AST_AI_API ChatTools& aAgentTools();

/// @brief 获取默认的智能体工具集合的JSON表示
AST_AI_API JsonValue aAgentToolsJson();

/// @brief 获取默认的智能体工具集合的JSON字符串表示
AST_AI_API std::string aAgentToolsJsonStr();

/// @brief 使用智能体工具集合处理单次工具调用
AST_AI_API std::string aAgentToolsHandleToolCall(const JsonValue& toolCall);

/// @brief 使用智能体工具集合处理单次工具调用
AST_AI_API std::string aAgentToolsHandleToolCall(const std::string& toolCallStr);


/*! @} */

AST_NAMESPACE_END
