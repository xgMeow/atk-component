/// @file      OrbitPathFilter.hpp
/// @brief     轨道路径预过滤
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-19

#pragma once

#include "CloseApproachFilter.hpp"
#include "AstUtil/Constants.hpp"

AST_NAMESPACE_BEGIN

/// @brief 轨道路径预过滤
/// @details 计算候选对象与参考对象两条二体椭圆在惯性空间的最小路径距离，
///          大于 阈值 + padding 则剔除。不考虑时间/相位。
class AST_CORE_API OrbitPathFilter final : public CloseApproachFilter
{
public:
    OrbitPathFilter(const CloseApproachOptions& opts, const CloseApproachContext& ctx);

    bool keep(const TLE& candidate) const override;

private:
    OrbElem referenceOrbit_{};
    double threshold_{};
    double gm_{kEarthGrav};
};

AST_NAMESPACE_END
