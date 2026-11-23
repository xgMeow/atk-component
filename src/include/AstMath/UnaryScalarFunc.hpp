/// @file      UnaryScalarFunc.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-25

#pragma once

#include "AstGlobal.h"
#include "UnaryVectorFunc.hpp"

AST_NAMESPACE_BEGIN


/// @brief 一元标量值函数
class UnaryScalarFunc: public UnaryVectorFunc
{
public:
    virtual ~UnaryScalarFunc() = default;

    /// @brief 计算标量值
    /// @param x 输入值
    /// @param out 输出标量
    virtual void evaluate(double x, double* out) const override = 0;

    /// @brief 获取方程维度
    /// @return 方程维度
    int getDimension() const final{ return 1; }
};


/// @brief 泛型一元函数适配器
template<typename Func>
class UnaryScalarGenericFunc : public UnaryScalarFunc {
public:
    explicit UnaryScalarGenericFunc(Func func) 
        : func_(std::move(func)) 
    {}

    void evaluate(double x, double* out) const override {
        *out = func_(x);
    }

private:
    Func func_;
};

AST_NAMESPACE_END
