/// @file      Macro.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/Value.hpp"

AST_NAMESPACE_BEGIN


/// @brief 宏对象基类
/// @details
/// 宏对象用于表示脚本中的宏定义，可以包含参数和宏体。
/// 宏是一种特殊的值对象
/// 宏的特点是“可以被调用，且会将输入的表达式转换为另一个表达式”
/// @ingroup Script
class AST_SCRIPT_API Macro: public Value
{
public:
    AST_EXPR(Macro)

};


AST_NAMESPACE_END
