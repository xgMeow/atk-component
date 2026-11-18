/// @file      SolverStats.h
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-28

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/// @brief 求解器统计信息
/// @details 包含求解器调用次数、迭代次数、错误次数等统计信息
/// @ingroup NLE
typedef struct SolverStats{
    int funcalls;
    int iterations;
    int error_num;
} SolverStats;

AST_NAMESPACE_END
