/// @file      DeepSeek.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-25

#pragma once

#include "AstGlobal.h"
#include "OpenAI.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief     DeepSeek API客户端
/// @details   兼容OpenAI规范，默认使用DeepSeek API端点
class AST_AI_API DeepSeek: public OpenAI
{
public:
    /// @brief 默认构造函数
    /// @details 从环境变量读取API密钥，若未设置baseUrl则使用DeepSeek默认端点
    DeepSeek();
};

/*! @} */

AST_NAMESPACE_END
