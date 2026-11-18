/// @file      NLESolver.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-25

#pragma once

#include "AstGlobal.h"
#include "AstMath/Function.hpp"
#include "AstMath/SolverStats.h"
#include <type_traits>


AST_NAMESPACE_BEGIN



/// @brief 判断两个数是否接近
/// @param a 第一个数
/// @param b 第二个数
/// @param relTol 相对误差容限
/// @param absTol 绝对误差容限
/// @return 如果两个数接近，则返回true；否则返回false
AST_MATH_CAPI bool aIsClose(double a, double b, double relTol = kDefaultRelTol, double absTol = kDefaultAbsTol);



/// @brief 一元方程求解器接口
/// @ingroup NLE
class AST_MATH_API IUnarySolver
{
public:
    virtual ~IUnarySolver() = default;

    /// @brief 求解一元方程
    /// @param func 方程函数
    /// @param min 搜索下限
    /// @param max 搜索上限
    /// @param result 输出解，长度需大于等于方程维度
    virtual errc_t solve(UnaryScalarFunc& func, double min, double max, double& result) = 0;
};


/// @brief 一元方程求解器
/// @details 提供一元方程求解功能的接口
/// @ingroup NLE
class AST_MATH_API UnarySolver: public IUnarySolver
{
public:
    using IUnarySolver::solve;

    UnarySolver();
    /// @brief 构造函数
    /// @param relTol 相对误差容限
    /// @param absTol 绝对误差容限
    /// @param maxIter 最大迭代次数
    UnarySolver(double relTol, double absTol, int maxIter);

    /// @brief 构造函数
    /// @param absTol 绝对误差容限
    explicit UnarySolver(double absTol);

    ~UnarySolver() override = default;

    /// @brief 获取相对误差容限
    double getRelTol() const{return relTol_;};
    /// @brief 获取绝对误差容限
    double getAbsTol() const{return absTol_;};
    /// @brief 获取最大迭代次数
    int getMaxIter() const{return maxIter_;};

    /// @brief 设置相对误差容限
    void setRelTol(double relTol){relTol_ = relTol;};
    /// @brief 设置绝对误差容限
    void setAbsTol(double absTol){absTol_ = absTol;};
    /// @brief 设置最大迭代次数
    void setMaxIter(int maxIter){maxIter_ = maxIter;};

    /// @brief 获取求解器统计信息
    const SolverStats& getStats() const{return stats_;};

    /// @brief 求解一元方程（支持lambda函数）
    /// @tparam Func lambda或可调用对象类型
    /// @param func lambda函数
    /// @param min 搜索下限
    /// @param max 搜索上限
    /// @param result 输出解
    template<typename Func>
    typename std::enable_if<!std::is_base_of<UnaryScalarFunc, typename std::remove_pointer<Func>::type>::value, errc_t>::type
    solve(Func func, double min, double max, double& result) {
        UnaryScalarGenericFunc<Func> adapter(std::move(func));
        return this->solve(adapter, min, max, result);
    }
protected:
    static double unarycfunc(double x, void* params);
protected:
    double relTol_;         ///< 相对误差容限
    double absTol_;         ///< 绝对误差容限
    int maxIter_;           ///< 最大迭代次数
    SolverStats stats_{};   ///< 求解器统计信息
};

using UnaryScalarSolver = UnarySolver;


AST_NAMESPACE_END
