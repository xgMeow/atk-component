/// @file      BlockIn.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 输入块
class AST_CORE_API BlockIn: public FuncBlock
{
public:
    BlockIn();

    BlockIn(const BlockIn&) = delete;
    BlockIn& operator=(const BlockIn&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 设置输入值
    /// @param value 输入值
    void setValue(double value);

    /// @brief 获取输入值
    /// @return 输入值
    double getValue() const;

protected:
    double value_{0.0};
    double* output_{&value_};
};

AST_NAMESPACE_END