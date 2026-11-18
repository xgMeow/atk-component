/// @file      IAUXYSSeries.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-12

#pragma once

#include "AstGlobal.h"
#include "AstCore/NutationSeries.hpp"


AST_NAMESPACE_BEGIN

/// @brief IERS 2003/2010 岁差章动模型XYS系数
/// 参考 IAU 2000决议中的新岁差-章动模型
class AST_CORE_API IAUXYS
{
public:
    IAUXYS() = default;
    ~IAUXYS() = default;

    /// @brief 加载岁差章动模型XYS系数文件
    /// @param xSeriesPath X系数文件路径
    /// @param ySeriesPath Y系数文件路径
    /// @param spxy2SeriesPath S系数文件路径
    errc_t load(StringView xSeriesPath, StringView ySeriesPath, StringView spxy2SeriesPath);


    /// @brief 加载默认岁差章动模型XYS系数文件
    errc_t loadDefault();

    /// @brief 计算岁差章动模型XYS系数
    /// @param t 儒略日
    /// @param x 输出X系数
    /// @param y 输出Y系数
    /// @param s 输出S+XY/2系数
    void eval(double t, const FundamentalArguments& fundargs, array3d& xys) const;

    /// @brief 检查是否加载了系数表
    /// @return bool
    bool isLoaded() const {return isLoaded_;}

protected:
    NutationSeries xSeries_{};        ///< 岁差章动模型X系数
    NutationSeries ySeries_{};        ///< 岁差章动模型Y系数
    NutationSeries spxy2Series_{};   ///< 岁差章动模型S+XY/2
    bool isLoaded_ {false};         ///< 检查是否加载了系数表
};


AST_NAMESPACE_END
