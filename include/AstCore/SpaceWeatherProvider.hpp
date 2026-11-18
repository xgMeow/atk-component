/// @file      SpaceWeatherProvider.hpp
/// @brief     空间天气数据提供者抽象接口
/// @details   定义了空间天气指数查询的抽象接口，遵循依赖注入的Provider模式。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-27

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/

/// @brief 空间天气数据提供者抽象接口
/// @details
/// 提供空间天气指数（Ap、Kp、F10.7等）的查询接口。
///
/// 关于接口设计：
/// 核心接口只包含所有空间天气数据源的公共查询方法。
/// 具体的数据加载方式（文件、网络、内嵌数据等）由子类实现，
/// 不出现在抽象接口中，以保持接口的简洁和可替换性。
/// @see SpaceWeather 基于Celestrak文件的具体实现
class AST_CORE_API SpaceWeatherProvider
{
public:
    virtual ~SpaceWeatherProvider() = default;

    /// @brief 获取指定时间的Ap日平均值
    /// @param tp 时间点
    /// @return 对应时间点的Ap值（0-400），无数据时返回0.0
    virtual double getApDaily(const TimePoint& tp) const = 0;

    /// @brief 获取指定时间的Kp日平均值
    /// @param tp 时间点
    /// @return 对应时间点的Kp值（0-9），无数据时返回0.0
    virtual double getKpDaily(const TimePoint& tp) const = 0;

    /// @brief 获取指定时间的F10.7单日观测值
    /// @param tp 时间点
    /// @return 对应时间点的F10.7观测值（10⁻²² W·m⁻²·Hz⁻¹），无数据时返回0.0
    virtual double getF10p7Daily(const TimePoint& tp) const = 0;

    /// @brief 获取指定时间的F10.7平均观测值
    /// @param tp 时间点
    /// @return 以输入时间为中心的81天平均F10.7观测值（调整到1 AU），无数据时返回0.0
    virtual double getF10p7Average(const TimePoint& tp) const = 0;

    /// @brief 获取从指定时间向前回溯的连续3小时间隔Ap值列表
    /// @param tp 参考时间点（tp所在3小时UTC块 = apList[0]）
    /// @param apList 输出缓冲区（apList[0]=当前块, apList[1]=3小时前, apList[2]=6小时前, ...）
    /// @param maxLookback 最多回溯的块数（通常最多20，即60小时）
    /// @return 实际填充的块数。返回0表示无3小时间隔数据，调用者应回退到每日Ap模式。
    ///         默认实现返回0（子类需override以提供真实数据）。
    virtual int getAp3HourlyList(const TimePoint& tp, double* apList, int maxLookback) const
    { return 0; }
};

/*! @} */

AST_NAMESPACE_END
