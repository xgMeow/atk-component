/// @file      BrentOptimizer.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-17

#pragma once

#include "AstGlobal.h"
#include "AstMath/UnaryOptimizer.hpp"


AST_NAMESPACE_BEGIN

/// @brief Brent法求解器
/// @details 在单峰区间 [min, max] 内寻找一元函数的极小值点，
///          结合反抛物线插值与黄金分割搜索，收敛速度快于黄金分割法
/// @ingroup Optim
class AST_MATH_API BrentOptimizer : public UnaryOptimizer
{
public:
    using UnaryOptimizer::UnaryOptimizer;
    BrentOptimizer() = default;
    ~BrentOptimizer() = default;
    using UnaryOptimizer::solve;
    errc_t solve(UnaryScalarFunc& func, double min, double max, double& result, double* funcValue = nullptr) override;
};


/// @brief Brent法自由函数：寻找一元函数在 [min, max] 内的极小值点（支持lambda）
/// @tparam Func lambda或可调用对象类型
/// @param func 目标函数
/// @param min 搜索下限
/// @param max 搜索上限
/// @param result 输出极小值点横坐标
/// @param funcValue 输出极小值点处的函数值（可为空）
/// @param absTol 绝对误差容限
/// @param relTol 相对误差容限
/// @param maxIter 最大迭代次数
/// @return 错误码
template<typename Func>
errc_t aBrentMinimize(Func func, double min, double max, double& result,
                      double* funcValue = nullptr,
                      double absTol = kDefaultAbsTol, double relTol = kDefaultRelTol,
                      int maxIter = kDefaultMaxIter)
{
    BrentOptimizer solver(relTol, absTol, maxIter);
    return solver.solve(func, min, max, result, funcValue);
}

/// @brief Brent法自由函数：寻找一元函数在 [min, max] 内的极小值点
/// @param func 目标函数
/// @param min 搜索下限
/// @param max 搜索上限
/// @param result 输出极小值点横坐标
/// @param funcValue 输出极小值点处的函数值（可为空）
/// @param absTol 绝对误差容限
/// @param relTol 相对误差容限
/// @param maxIter 最大迭代次数
/// @return 错误码
AST_MATH_API errc_t aBrentMinimize(UnaryScalarFunc& func, double min, double max, double& result,
                                   double* funcValue = nullptr,
                                   double absTol = kDefaultAbsTol, double relTol = kDefaultRelTol,
                                   int maxIter = kDefaultMaxIter);


AST_NAMESPACE_END
