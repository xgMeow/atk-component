/// @file      BlockDivide.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 除法块
class AST_CORE_API BlockDivide : public FuncBlock
{
public:
    BlockDivide();

    BlockDivide(const BlockDivide&) = delete;
    BlockDivide& operator=(const BlockDivide&) = delete;

    errc_t run(const SimTime &simTime) override;
protected:
    double* numerator_{nullptr};  // 分子
    double* denominator_{nullptr};  // 分母
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END