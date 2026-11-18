/// @file      ApogeePerigeeFilter.hpp
/// @brief     近/远地点预过滤
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-19

#pragma once

#include "CloseApproachFilter.hpp"
#include "AstUtil/Constants.hpp"

AST_NAMESPACE_BEGIN

/// @brief 近/远地点预过滤
/// @details 剔除近/远地点半径区间（含 padding）与参考对象不重叠的候选对象。
class AST_CORE_API ApogeePerigeeFilter final : public CloseApproachFilter
{
public:
    ApogeePerigeeFilter(const CloseApproachOptions& opts, const CloseApproachContext& ctx);

    bool keep(const TLE& candidate) const override;

private:
    double apogeeRadius_{};
    double perigeeRadius_{};
    double gm_{kEarthGrav};
    double threshold_{};
};

AST_NAMESPACE_END
