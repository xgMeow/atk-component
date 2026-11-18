/// @file      OutOfDateFilter.hpp
/// @brief     过期预过滤
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-19

#pragma once

#include "CloseApproachFilter.hpp"
#include "AstCore/TimeInterval.hpp"
#include "AstUtil/Literals.hpp"

AST_NAMESPACE_BEGIN

/// @brief 过期预过滤
/// @details 剔除历元不在 [窗口起点 - pad, 窗口终点 + pad] 内的 TLE。
class AST_CORE_API OutOfDateFilter final : public CloseApproachFilter
{
public:
    explicit OutOfDateFilter(const CloseApproachOptions& opts);

    bool keep(const TLE& candidate) const override;

    void setInterval(const TimeInterval& interval){interval_ = interval;}
    void setThreshold(double threshold){threshold_ = threshold;}
private:
    TimeInterval interval_{};         ///< 分析窗口
    double threshold_{30_day};        ///< 过期门限 [s]
};

AST_NAMESPACE_END
