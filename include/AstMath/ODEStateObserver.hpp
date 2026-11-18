/// @file      ODEStepObserver.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-28

#pragma once

#include "AstGlobal.h"
#include "AstUtil/TypeTraits.hpp"

AST_NAMESPACE_BEGIN

class ODEIntegrator;

enum EODEAction
{
    eContinue = 0,
    eStop = 1,
};

/// @brief ODE状态量观察者
/// @ingroup ODE
class AST_MATH_API ODEStateObserver
{
public:
    virtual ~ODEStateObserver() = default;

    /// @brief 状态更新处理函数
    /// @param y 当前状态向量
    /// @param x 当前积分变量
    virtual EODEAction onStateUpdate(double* y, double& x, ODEIntegrator* integrator) = 0;

};

#ifndef SWIG

/// @brief 泛型ODE状态量观察者助手类
class ODEStateObserverGenericHelper
{
public:
    // 版本1: 支持 func_(y, x, integrator)
    template<typename F>
    static A_ALWAYS_INLINE auto call_func(F& func, double* y, double& x, ODEIntegrator* integrator) 
        -> typename std::enable_if<is_callable<F, double*, double&, ODEIntegrator*>::value, decltype(std::declval<F>()(y, x, integrator))>::type
    {
        return func(y, x, integrator);
    }

    // 版本2: 支持 func_(y, x)
    template<typename F>
    static A_ALWAYS_INLINE auto call_func(F& func, double* y, double& x, ODEIntegrator* integrator) 
        -> typename std::enable_if<is_callable<F, double*, double&>::value, decltype(std::declval<F>()(y, x))>::type
    {
        return func(y, x);
    }

    // 版本3: 支持 func_(y)
    template<typename F>
    static A_ALWAYS_INLINE auto call_func(F& func, double* y, double& x, ODEIntegrator* integrator) 
        -> typename std::enable_if<is_callable<F, double*>::value, decltype(std::declval<F>()(y))>::type
    {
        return func(y);
    }
};

/// @brief 泛型ODE状态量观察者
template<typename Func>
class ODEStateObserverGeneric: public ODEStateObserver
{
public:
    using Self = ODEStateObserverGeneric<Func>;
    using FuncType = Func;
    explicit ODEStateObserverGeneric(Func func) 
        : func_(std::move(func)) 
    {}

    EODEAction onStateUpdate(double* y, double& x, ODEIntegrator* integrator) override {
        return this->operator()(y, x, integrator);
    }

private:
    Func func_;
private:
    // 处理不同的返回类型
    template<typename F = FuncType>
    A_ALWAYS_INLINE
    typename std::enable_if<!std::is_void<decltype(
        ODEStateObserverGenericHelper::call_func
        (std::declval<F&>(), std::declval<double*>(), std::declval<double&>(), std::declval<ODEIntegrator*>()))>::value, EODEAction>::type
    operator()(double* y, double& x, ODEIntegrator* integrator) {
        return ODEStateObserverGenericHelper::call_func(func_, y, x, integrator);
    }

    template<typename F = FuncType>
    A_ALWAYS_INLINE
    typename std::enable_if<std::is_void<decltype(
        ODEStateObserverGenericHelper::call_func
        (std::declval<F&>(), std::declval<double*>(), std::declval<double&>(), std::declval<ODEIntegrator*>()))>::value, EODEAction>::type
    operator()(double* y, double& x, ODEIntegrator* integrator) {
        ODEStateObserverGenericHelper::call_func(func_, y, x, integrator);
        return EODEAction::eContinue;
    }
};

#endif

AST_NAMESPACE_END
