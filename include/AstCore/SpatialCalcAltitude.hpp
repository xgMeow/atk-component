/// @file      SpatialCalcAltitude.hpp
/// @brief     位置海拔空间计算
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "SpatialCalculation.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

class CelestialBody;
class BodyShape;

/// @brief 位置海拔空间计算
/// @details 评估指定位置相对于中心天体参考形状的高度
/// @ingroup Spatial
class AST_CORE_API SpatialCalcAltitude final : public SpatialCalculation
{
public:
    SpatialCalcAltitude() = default;
    ~SpatialCalcAltitude() override = default;

    void accept(SpatialCalculationVisitor& visitor) override { visitor.visit(*this); }
    errc_t evaluate(const TimePoint& time, const Vector3d& position, double& result) const override;

    /// @name 天体
    /// @{
    void setCentralBody(CelestialBody* body);
    CelestialBody* getCentralBody() const { return body_.get(); }
    /// @}

    /// @name 形状模型
    void setShapeModel(BodyShape* shape);
    BodyShape* getShapeModel() const { return shape_.get(); }
    /// @}

private:
    WeakPtr<CelestialBody> body_;    ///< 天体
    WeakPtr<BodyShape>      shape_;  ///< 参考形状模型
};

AST_NAMESPACE_END
