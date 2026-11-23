/// @file      BlockSum.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-18

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN


/// @brief 加法块
class AST_CORE_API BlockSum: public FuncBlock
{
public:
    BlockSum();

    BlockSum(const BlockSum&) = delete;
    BlockSum& operator=(const BlockSum&) = delete;

    errc_t run(const SimTime &simTime) override;
protected:
    double* input1_{nullptr};
    double* input2_{nullptr};
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

using BlockAdd = BlockSum;

AST_NAMESPACE_END
