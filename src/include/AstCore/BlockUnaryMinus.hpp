/// @file      BlockUnaryMinus.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 一元负号块
class AST_CORE_API BlockUnaryMinus : public FuncBlock
{
public:
    BlockUnaryMinus();

    BlockUnaryMinus(const BlockUnaryMinus&) = delete;
    BlockUnaryMinus& operator=(const BlockUnaryMinus&) = delete;

    errc_t run(const SimTime &simTime) override;
protected:
    double* input_{nullptr};  // 输入值
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END