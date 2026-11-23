/// @file      BlockSign.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 符号函数块
class AST_CORE_API BlockSign : public FuncBlock
{
public:
    BlockSign();

    BlockSign(const BlockSign&) = delete;
    BlockSign& operator=(const BlockSign&) = delete;

    errc_t run(const SimTime &simTime) override;
protected:
    double* input_{nullptr};  // 输入值
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END