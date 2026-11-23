/// @file      BlockDot.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 点积块
class AST_CORE_API BlockDot : public FuncBlock
{
public:
    BlockDot();

    BlockDot(const BlockDot&) = delete;
    BlockDot& operator=(const BlockDot&) = delete;

    errc_t run(const SimTime &simTime) override;
protected:
    double* vector1_{nullptr};  // 第一个向量
    double* vector2_{nullptr};  // 第二个向量
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
    size_t vectorSize_{3};  // 向量大小，默认为3（用于三维空间）
};

AST_NAMESPACE_END