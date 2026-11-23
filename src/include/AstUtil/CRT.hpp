/// @file      CRT.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


struct args_t {
    int argc;
    char** argv;
};


/// @brief 获取命令行参数
/// @return args_t 命令行参数结构体
// AST_UTIL_API args_t aArgsGet();


AST_NAMESPACE_END
