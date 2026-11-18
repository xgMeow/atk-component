/// @file      BlockTerminator.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 终止块
class AST_CORE_API BlockTerminator: public FuncBlock
{
public:
    BlockTerminator();

    BlockTerminator(const BlockTerminator&) = delete;
    BlockTerminator& operator=(const BlockTerminator&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 获取输入值
    /// @return 输入值
    double getValue() const;

protected:
    double* input_{nullptr};
    double value_{0.0};
};

AST_NAMESPACE_END