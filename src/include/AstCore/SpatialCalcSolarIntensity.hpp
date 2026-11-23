/// @file      SpatialCalcSolarIntensity.hpp
/// @brief     太阳光照强度空间计算
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "SpatialCalculation.hpp"
#include "AstCore/SharedPtr.hpp"
#include "AstCore/CelestialBody.hpp"

#include <vector>

AST_NAMESPACE_BEGIN

/// @brief 太阳光照强度空间计算
/// @details 评估指定位置处考虑遮挡天体后的太阳辐射强度分数
/// @ingroup Spatial
class AST_CORE_API SpatialCalcSolarIntensity final : public SpatialCalculation
{
public:
    SpatialCalcSolarIntensity() = default;
    ~SpatialCalcSolarIntensity() override = default;

    void accept(SpatialCalculationVisitor& visitor) override { visitor.visit(*this); }
    errc_t evaluate(const TimePoint& time, const Vector3d& position, double& result) const override;

    /// @name 遮挡天体
    /// @{
    void setUseObjectEclipsingBodies(bool use) { useObjEclipsing_ = use; }
    bool getUseObjectEclipsingBodies() const { return useObjEclipsing_; }

    void addEclipsingBody(const SharedPtr<CelestialBody>& body) { eclipsingBodies_.push_back(body); }
    size_t getEclipsingBodyCount() const { return eclipsingBodies_.size(); }
    const std::vector<SharedPtr<CelestialBody>>& getEclipsingBodies() const { return eclipsingBodies_; }
    /// @}

private:
    bool                                    useObjEclipsing_{true};    ///< 是否使用对象自身的遮挡体设置
    std::vector<SharedPtr<CelestialBody>>   eclipsingBodies_;          ///< 遮挡天体列表
};

AST_NAMESPACE_END
