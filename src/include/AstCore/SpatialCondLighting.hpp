/// @file      SpatialCondLighting.hpp
/// @brief     光照空间条件
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "SpatialCondition.hpp"
#include "AstCore/SharedPtr.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/Eclipse.hpp"      // for ELightingType

#include <vector>

AST_NAMESPACE_BEGIN

/// @brief 光照空间条件
/// @details 评估指定位置的光照状态（考虑遮挡天体）
/// @ingroup Spatial
class AST_CORE_API SpatialCondLighting final : public SpatialCondition
{
public:
    SpatialCondLighting() = default;
    ~SpatialCondLighting() override = default;

    void accept(SpatialConditionVisitor& visitor) override { visitor.visit(*this); }
    errc_t evaluate(const TimePoint& time, const Vector3d& position, bool& result) const override;

    /// @name 光照类型
    /// @{
    void setLightingType(ELightingType type) { lightingType_ = type; }
    ELightingType getLightingType() const { return lightingType_; }
    /// @}

    /// @name 遮挡天体
    /// @{
    void addEclipsingBody(const SharedPtr<CelestialBody>& body) { eclipsingBodies_.push_back(body); }
    size_t getEclipsingBodyCount() const { return eclipsingBodies_.size(); }
    const std::vector<SharedPtr<CelestialBody>>& getEclipsingBodies() const { return eclipsingBodies_; }
    /// @}

private:
    ELightingType                           lightingType_{ELightingType::eSunlight};  ///< 光照类型
    std::vector<SharedPtr<CelestialBody>>   eclipsingBodies_;                         ///< 遮挡天体列表
};

AST_NAMESPACE_END
