/// @file      IteratePredefined.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-26

#pragma once

#include "AstGlobal.h"
#include "AstScript/ScriptAPI.hpp"

AST_NAMESPACE_BEGIN



/// @brief 获取迭代函数指针
/// @param type 迭代对象类型
/// @return 迭代函数指针
AST_SCRIPT_API IterateFunc iterate_get_func(Class* type);


/// @brief 迭代器开始
/// @param container 迭代对象
/// @param index 迭代索引
/// @return 迭代器开始值
AST_SCRIPT_API Value* iterate_begin(Value* container, int& index);

/// @brief 迭代器下一个
/// @param container 迭代对象
/// @param index 迭代索引
/// @return 迭代器下一个值
AST_SCRIPT_API Value* iterate_next(Value* container, int& index);


AST_NAMESPACE_END
