/// @file      UnaryOptimizer.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-17

#pragma once

#include "AstGlobal.h"
#include "AstMath/Function.hpp"
#include "AstMath/SolverStats.h"
#include <type_traits>


AST_NAMESPACE_BEGIN


/// @brief 一元函数极小值求解器接口
/// @ingroup Optim
class AST_MATH_API IUnaryOptimizer
{
public:
    virtual ~IUnaryOptimizer() = default;

    /// @brief 求解一元函数在区间内的极小值点
    /// @param func 目标函数
    /// @param min 搜索下限
    /// @param max 搜索上限
    /// @param result 输出极小值点横坐标
    /// @param funcValue 输出极小值点处的函数值（可为空）
    virtual errc_t solve(UnaryScalarFunc& func, double min, double max, double& result, double* funcValue = nullptr) = 0;
};


/// @brief 一元函数极小值求解器基类
/// @details 提供求解器容差、统计信息等公共设施
/// @ingroup Optim
class AST_MATH_API UnaryOptimizer : public IUnaryOptimizer
{
public:
    using IUnaryOptimizer::solve;

    UnaryOptimizer();
    /// @brief 构造函数
    /// @param relTol 相对误差容限
    /// @param absTol 绝对误差容限
    /// @param maxIter 最大迭代次数
    UnaryOptimizer(double relTol, double absTol, int maxIter);

    /// @brief 构造函数
    /// @param absTol 绝对误差容限
    explicit UnaryOptimizer(double absTol);

    ~UnaryOptimizer() override = default;

    /// @brief 获取相对误差容限
    double getRelTol() const { return relTol_; };
    /// @brief 获取绝对误差容限
    double getAbsTol() const { return absTol_; };
    /// @brief 获取最大迭代次数
    int getMaxIter() const { return maxIter_; };

    /// @brief 设置相对误差容限
    void setRelTol(double relTol) { relTol_ = relTol; };
    /// @brief 设置绝对误差容限
    void setAbsTol(double absTol) { absTol_ = absTol; };
    /// @brief 设置最大迭代次数
    void setMaxIter(int maxIter) { maxIter_ = maxIter; };

    /// @brief 获取求解器统计信息
    const SolverStats& getStats() const { return stats_; };

    /// @brief 求解一元函数极小值点（支持lambda函数）
    /// @tparam Func lambda或可调用对象类型
    /// @param func lambda函数
    /// @param min 搜索下限
    /// @param max 搜索上限
    /// @param result 输出极小值点横坐标
    /// @param funcValue 输出极小值点处的函数值（可为空）
    template<typename Func>
    typename std::enable_if<!std::is_base_of<UnaryScalarFunc, typename std::remove_pointer<Func>::type>::value, errc_t>::type
    solve(Func func, double min, double max, double& result, double* funcValue = nullptr) {
        UnaryScalarGenericFunc<Func> adapter(std::move(func));
        return this->solve(adapter, min, max, result, funcValue);
    }

protected:
    double relTol_;         ///< 相对误差容限
    double absTol_;         ///< 绝对误差容限
    int maxIter_;           ///< 最大迭代次数
    SolverStats stats_{};   ///< 求解器统计信息
};


AST_NAMESPACE_END
