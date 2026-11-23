/// @file      ScriptContext.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-23

#pragma once

#include "AstGlobal.h"
#include <stdarg.h>   // for va_list, va_start, va_end

AST_NAMESPACE_BEGIN


class ISymbolScope;         ///< 符号作用域接口
class SymbolScope;          ///< 符号作用域
class StackFrame;           ///< 栈帧
class Interpreter;          ///< 解释器
class Expr;                 ///< 表达式
class Symbol;               ///< 符号


/*!
    @addtogroup Script
    @{
*/


/// @brief     获取解释器指针
/// @return    Interpreter* 解释器指针
AST_SCRIPT_CAPI Interpreter* aScript_GetInterpreter();


/// @brief     交换解释器指针
/// @details   交换当前解释器指针与传入指针，返回旧的解释器指针。
/// @param     interpreter 解释器指针
/// @return    Interpreter* 旧的解释器指针
AST_SCRIPT_CAPI Interpreter* aScript_SwapInterpreter(Interpreter* interpreter);


/// @brief     设置解释器指针
/// @param     interpreter 解释器指针
AST_SCRIPT_CAPI void aScript_SetInterpreter(Interpreter* interpreter);


/// @brief     移除解释器指针
/// @details   如果解释器指针与传入指针相同，则移除解释器指针，然后将解释器上下文切换为全局解释器。
/// @param     interpreter 解释器指针
AST_SCRIPT_CAPI void aScript_RemoveInterpreter(Interpreter* interpreter);


/// @brief     获取当前符号作用域
/// @details   
/// @return    符号作用域指针
AST_SCRIPT_CAPI ISymbolScope* aScript_CurrentSymbolScope();


/// @brief     添加符号
/// @details   
/// @param     var 变量指针
AST_SCRIPT_API void aScript_AddSymbol(Variable* var);


/// @brief     添加符号
/// @details   
/// @param     name 符号名
/// @param     expr 表达式指针
AST_SCRIPT_API void aScript_AddSymbol(StringView name, Expr* expr);


/// @brief     查找符号
/// @details   
/// @param     name 符号名
/// @return    Expr* 表达式指针
AST_SCRIPT_API Expr* aScript_FindSymbol(StringView name);


/// @brief     查找符号
/// @details   
/// @param     symbol 符号指针
/// @return    Expr* 表达式指针
AST_SCRIPT_API Expr* aScript_FindSymbol(const Symbol* symbol);



/// @brief     解析符号
/// @details   
/// @param     name 符号名
/// @return    Expr* 表达式指针
AST_SCRIPT_API Expr* aScript_ResolveSymbol(StringView name);


/// @brief     解析符号
/// @details   
/// @param     symbol 符号
/// @return    Expr* 表达式指针
AST_SCRIPT_API Expr* aScript_ResolveSymbol(const Symbol* symbol);


/// @brief     设置错误字符串
/// @details   
/// @param     err 错误字符串
AST_SCRIPT_CAPI void aScript_SetErrString(StringView err);


/// @brief     格式化错误字符串
/// @details   
/// @param     fmt 格式化字符串
/// @param     args 可变参数列表
AST_SCRIPT_CAPI void aScript_FormartErrStringV(StringView fmt, va_list args);


/// @brief     格式化错误字符串
/// @details   
/// @param     fmt 格式化字符串
/// @param     ... 可变参数
AST_SCRIPT_CAPI void aScript_FormatErrString(StringView fmt, ...);


/*! @} */

AST_NAMESPACE_END
