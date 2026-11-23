/// @file      BlockSubtract.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 减法块
class AST_CORE_API BlockSubtract : public FuncBlock
{
public:
    BlockSubtract();

    BlockSubtract(const BlockSubtract&) = delete;
    BlockSubtract& operator=(const BlockSubtract&) = delete;

    errc_t run(const SimTime &simTime) override;
protected:
    double* input1_{nullptr};  // 被减数
    double* input2_{nullptr};  // 减数
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END