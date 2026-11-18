/// @file      OpUnaryPredefined.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-22

#pragma once

#include "AstGlobal.h"
#include "AstScript/ScriptAPI.hpp"

AST_NAMESPACE_BEGIN

class Value;


/// @brief 获取一元运算函数指针（void* 类型）
/// @param op 运算类型
/// @param type 运算数类型
/// @return 运算函数指针（void* 类型）
AST_SCRIPT_API void* opunary_get_funcptr(EOpUnaryType op, Class* type);

/// @brief 注册一元运算函数指针
/// @param op 运算类型
/// @param type 运算数类型
/// @param func 运算函数指针（void* 类型）
AST_SCRIPT_API void opunary_register_funcptr(EOpUnaryType op, Class* type, void* func);



/// @brief 获取一元运算函数指针
/// @param op 运算类型
/// @param type 运算数类型
/// @return 运算函数指针
AST_SCRIPT_API OpUnaryFunc opunary_get_func(EOpUnaryType op, Class* type);


/// @brief 注册一元运算函数
/// @param op 运算类型
/// @param type 运算数类型
/// @param func 运算函数指针
AST_SCRIPT_API void opunary_register_func(EOpUnaryType op, Class* type, OpUnaryFunc func);



/// @brief 执行一元运算
/// @param op 运算类型
/// @param value 运算数
/// @return 运算结果
AST_SCRIPT_API Value* opunary(EOpUnaryType op, Value* value);


AST_NAMESPACE_END