/// @file      BlockConstant.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 常量块
class AST_CORE_API BlockConstant: public FuncBlock
{
public:
    explicit BlockConstant(double value = 0.0);

    BlockConstant(const BlockConstant&) = delete;
    BlockConstant& operator=(const BlockConstant&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 设置常量值
    /// @param value 常量值
    void setValue(double value);

    /// @brief 获取常量值
    /// @return 常量值
    double getValue() const;

protected:
    double value_{0.0};
    double* output_{&value_};
};

AST_NAMESPACE_END