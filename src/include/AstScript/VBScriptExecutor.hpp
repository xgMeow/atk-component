/// @file      VBScriptExecutor.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-29

#pragma once

#include "AstGlobal.h"
#include "ActiveScriptExecutor.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_SCRIPT_API VBScriptExecutor final: public ActiveScriptExecutor
{
public:
    VBScriptExecutor();
    #ifdef _WIN32
    // 下面这些重载会隐藏基类同名的其他重载（含字符串字面量重载），需要显式引回
    using ScriptExecutor::setVariable;

    errc_t setVariable(StringView name, StringView value) override;
    errc_t setVariable(StringView name, double value) override;
    errc_t setVariable(StringView name, int value) override;
    errc_t setVariable(StringView name, bool value) override;
    #endif
};


/*! @} */

AST_NAMESPACE_END
