/// @file      ScriptingToolProfileLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-30

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ScriptingToolProfile;

/// @brief 加载脚本工具配置
/// @param value JSON值
/// @param profile 脚本工具配置
/// @return 错误码
/// @note 该函数用于从JSON值中加载脚本工具配置
errc_t aLoadScriptingToolProfile(const Value& value, ScriptingToolProfile& profile);

/*! @} */

AST_NAMESPACE_END

