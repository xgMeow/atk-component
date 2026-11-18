/// @file      BlockSin.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-18

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 正弦块
class AST_CORE_API BlockSin : public FuncBlock
{
public:
    BlockSin();

    BlockSin(const BlockSin&) = delete;
    BlockSin& operator=(const BlockSin&) = delete;

    ~BlockSin() = default;

    errc_t run(const SimTime& simTime) final;
protected:
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END
