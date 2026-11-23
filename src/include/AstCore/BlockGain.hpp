/// @file      BlockGain.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-18

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"



AST_NAMESPACE_BEGIN

/// @brief 增益块
class AST_CORE_API BlockGain : public FuncBlock
{
public:
    BlockGain();

    BlockGain(const BlockGain&) = delete;
    BlockGain& operator=(const BlockGain&) = delete;

    ~BlockGain() = default;

    errc_t run(const SimTime& simTime) override;

    void setGain(double gain){ gain_ = gain; }
PROPERTIES:
    double gain_{1.0};
protected:
    double* input_{nullptr};
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};



AST_NAMESPACE_END
