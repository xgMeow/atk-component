/// @file      OrdinaryDifferentialEquation.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-16

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/// @class     OrdinaryDifferentialEquation
/// @brief     常微分方程基接口
/// @details   该类定义了常微分方程的接口，包括获取维度和计算导数。
///            参考orekit的OrdinaryDifferentialEquation类
/// @ingroup ODE
class AST_MATH_API OrdinaryDifferentialEquation
{
public:
    virtual ~OrdinaryDifferentialEquation() = default;

    /// @brief 获取微分方程的维度。
    /// @return 微分方程的维度。
    virtual int getDimension() const = 0;

    /// @brief 计算常微分方程在给定时间点和状态下的导数。
    /// @details 
    /// 为什么将时间作为最后一个参数
    /// 1. 在很多情况下，ODE 系统是自洽系统（时间无关）
    /// 2. 与 Boost.Odeint 库的接口设计保持一致
    /// 3. 与 Julia 语言的ODE求解器设计保持一致
    /// @param y 状态向量。
    /// @param dy 输出导数向量。
    /// @param t 时间点。
    /// @return 错误码。
    virtual errc_t evaluate(const double* y, double* dy, double t) = 0;

    /// 兼容性处理
    A_ALWAYS_INLINE 
    errc_t evaluate(const double t,const double* y, double* dy){return evaluate(y, dy, t);}
};

using ODE = OrdinaryDifferentialEquation;       ///< 常微分方程别名



/// @brief 泛型常微分方程
template<typename Func>
class ODEGeneric: public ODE
{
public:
    ODEGeneric(Func func, int dim) 
        : func_(std::move(func))
        , dim_(dim) 
    {}

    int getDimension() const override {
        return dim_;
    }

    errc_t evaluate(const double* y, double* dy, double t) override {
        return func_(y, dy, t);
    }

private:
    Func func_;
    int dim_;
};


/// @brief 创建一个常微分方程
/// @ingroup ODE
template<typename Func>
ODEGeneric<Func> make_ode(Func func, int dim) {
    return ODEGeneric<Func>(func, dim);
}

/// @brief 创建一个常微分方程
/// @ingroup ODE
template<typename Func>
ODEGeneric<Func> make_ode(int dim, Func func) {
    return ODEGeneric<Func>(func, dim);
}

AST_NAMESPACE_END
