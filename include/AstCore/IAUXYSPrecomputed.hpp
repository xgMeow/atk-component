/// @file      IAUXYSPrecomputed.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-22

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/// @brief     预计算的XYS系数
/// @details   该接口定义了获取预计算的XYS系数的方法。
class AST_CORE_API IAUXYSPrecomputed
{
public:
    IAUXYSPrecomputed();

    /// @brief 获取预计算的XYS系数
    /// @param tp 时间点
    /// @param xys 输出XYS系数
    errc_t getValue(const TimePoint& tp, array3d& xys) const;

    /// @brief 获取预计算的XYS系数（TT时间）
    /// @param jed 儒略日
    /// @param xys 输出XYS系数
    errc_t getValueTT(const JulianDate& jdTT, array3d& xys) const;

    /// @brief 加载预计算的XYS系数文件
    /// @param filepath 文件路径
    errc_t load(StringView filepath);


    /// @brief 加载默认预计算的XYS系数文件
    errc_t loadDefault();

    /// @brief 预计算XYS系数
    /// @param start_jed 开始时间（儒略日）
    /// @param stop_jed 结束时间（儒略日）
    /// @param step_size 时间步长
    void precompute(double start_jed, double stop_jed, double step_size);

    /// @brief 获取预计算的XYS系数参考时间（儒略日）
    double getRefEpochJED() const { return refepoch_jed_; }

    /// @brief 获取预计算的XYS系数时间步长（天）
    double getStepSize() const { return step_size_; }

    /// @brief 获取预计算的XYS系数时间点数量
    int getNumPoints() const { return (int)xys_points_.size(); }

    /// @brief 获取预计算的XYS系数插值阶数
    int getInterpOrder() const { return interp_order_; }

    /// @brief 设置预计算的XYS系数插值阶数
    void setInterpOrder(int order);
private:
    /// @brief 初始化插值
    /// @details 初始化插值系数，包括计算分母数组。
    void initInterpolation();

    A_DISABLE_COPY(IAUXYSPrecomputed)
protected:
    // int num_points_{0};
    int num_columns_{0};
    int interp_order_{0};
    double step_size_{0.0};
    double refepoch_jed_{0.0};
    std::vector<array3d> xys_points_;
private:
    std::vector<double> denom_array_;   ///< 分母数组
    std::vector<double> time_array_;    ///< 时间数组
};

AST_NAMESPACE_END
