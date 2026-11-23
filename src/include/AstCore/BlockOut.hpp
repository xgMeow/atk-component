/// @file      BlockOut.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 输出块
class AST_CORE_API BlockOut: public FuncBlock
{
public:
    BlockOut();

    BlockOut(const BlockOut&) = delete;
    BlockOut& operator=(const BlockOut&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 获取输出值
    /// @return 输出值
    double getValue() const;

protected:
    double* input_{nullptr};
    double value_{0.0};
};

AST_NAMESPACE_END