/// @file      UnaryVectorFunc.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-25

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


/// @brief 一元向量值函数
class UnaryVectorFunc
{
public:
    virtual ~UnaryVectorFunc() = default;

    /// @brief 计算向量方程值
    /// @param x 输入值
    /// @param out 输出向量，长度需大于等于向量维度
    virtual void evaluate(double x, double* out) const = 0;

    /// @brief 获取方程维度
    /// @return 方程维度
    virtual int getDimension() const = 0;
};

AST_NAMESPACE_END
