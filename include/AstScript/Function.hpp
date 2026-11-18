/// @file      Function.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/Macro.hpp"

AST_NAMESPACE_BEGIN

/// @brief 函数对象基类
/// @details
/// 函数对象用于表示脚本中的函数定义，可以包含参数和函数体。
/// 函数是一种特殊的值对象
/// 函数的特点是“可以被调用，且会将输入的值转换为另一个值”
/// 因为值也是一种表达式，所以函数是一种特殊的宏，其输出的表达式是一个值对象
/// @ingroup Script
class AST_SCRIPT_API Function: public Macro
{
public:
    AST_EXPR(Function)

    using Macro::Macro;
    ~Function() override = default;
};



AST_NAMESPACE_END
