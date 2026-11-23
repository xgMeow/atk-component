/// @file      Zeros.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-29

#pragma once

#include "AstGlobal.h"
#include "zeros.h"

AST_NAMESPACE_BEGIN

namespace detail{
    template<typename Func>
    A_ALWAYS_INLINE double callback_func(double x, void* func)
    {
        return (*(Func*)func)(x);
    }
}

/*!
    @addtogroup NLE
    @{
*/


/// @brief 二分法求解器
/// @tparam Func 函数对象
/// @param f 函数对象
/// @param xa 区间下限
/// @param xb 区间上限
/// @param xtol 绝对误差 tolerance
/// @param rtol 相对误差 tolerance
/// @param iter 最大迭代次数
/// @param solver_stats 求解器统计信息
/// @return 根近似值
template<typename Func>
double bisect(Func f, double xa, double xb, double xtol, double rtol, int iter, scipy_zeros_info &solver_stats)
{
    return ::bisect(detail::callback_func<Func>, xa, xb, xtol, rtol, iter, &f, &solver_stats);
}


/// @brief Ridder 方法求解器
/// @tparam Func 函数对象
/// @param f 函数对象
/// @param xa 区间下限
/// @param xb 区间上限
/// @param xtol 绝对误差 tolerance
/// @param rtol 相对误差 tolerance
/// @param iter 最大迭代次数
/// @param solver_stats 求解器统计信息
/// @return 根近似值
template<typename Func>
double ridder(Func f, double xa, double xb, double xtol, double rtol, int iter, scipy_zeros_info &solver_stats)
{
    return ::ridder(detail::callback_func<Func>, xa, xb, xtol, rtol, iter, &f, &solver_stats);
}


/// @brief Brenth法求解器
/// @tparam Func 函数对象
/// @param f 函数对象
/// @param xa 区间下限
/// @param xb 区间上限
/// @param xtol 绝对误差 tolerance
/// @param rtol 相对误差 tolerance
/// @param iter 最大迭代次数
/// @param solver_stats 求解器统计信息
/// @return 根近似值
template<typename Func>
double brenth(Func f, double xa, double xb, double xtol, double rtol, int iter, scipy_zeros_info &solver_stats)
{
    return ::brenth(detail::callback_func<Func>, xa, xb, xtol, rtol, iter, &f, &solver_stats);
}


/// @brief Brentq法求解器
/// @tparam Func 函数对象
/// @param f 函数对象
/// @param xa 区间下限
/// @param xb 区间上限
/// @param xtol 绝对误差 tolerance
/// @param rtol 相对误差 tolerance
/// @param iter 最大迭代次数
/// @param solver_stats 求解器统计信息
/// @return 根近似值
template<typename Func>
double brentq(Func f, double xa, double xb, double xtol, double rtol, int iter, scipy_zeros_info &solver_stats)
{
    return ::brentq(detail::callback_func<Func>, xa, xb, xtol, rtol, iter, &f, &solver_stats);
}


/// @brief 割线法求解器
/// @tparam Func 函数对象
/// @param f 函数对象
/// @param xa 区间下限
/// @param xb 区间上限
/// @param xtol 绝对误差 tolerance
/// @param rtol 相对误差 tolerance
/// @param iter 最大迭代次数
/// @param solver_stats 求解器统计信息
/// @return 根近似值
template<typename Func>
double secant(Func f, double xa, double xb, double xtol, double rtol, int iter, scipy_zeros_info &solver_stats)
{
    return ::secant(detail::callback_func<Func>, xa, xb, xtol, rtol, iter, &f, &solver_stats);
}


/*! @} */

AST_NAMESPACE_END
