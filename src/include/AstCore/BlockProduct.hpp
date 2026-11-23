/// @file      BlockProduct.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 乘积块
class AST_CORE_API BlockProduct: public FuncBlock
{
public:
    BlockProduct();

    BlockProduct(const BlockProduct&) = delete;
    BlockProduct& operator=(const BlockProduct&) = delete;

    errc_t run(const SimTime &simTime) override;

protected:
    double* input1_{nullptr};
    double* input2_{nullptr};
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END