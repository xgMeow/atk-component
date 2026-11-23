/// @file      SpatialCalcScalarAtLocation.hpp
/// @brief     位置标量委托计算
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "SpatialCalculation.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

/// @brief 位置标量委托计算
/// @details 委托给另一个（非空间）标量计算，将父对象放置到网格位置后评估
/// @ingroup Spatial
class AST_CORE_API SpatialCalcScalarAtLocation final : public SpatialCalculation
{
public:
    SpatialCalcScalarAtLocation() = default;
    ~SpatialCalcScalarAtLocation() override = default;

    void accept(SpatialCalculationVisitor& visitor) override { visitor.visit(*this); }
    errc_t evaluate(const TimePoint& time, const Vector3d& position, double& result) const override;

    /// @name 被引用的计算
    /// @{
    void setReferencedCalculation(SpatialCalculation* calc);
    SpatialCalculation* getReferencedCalculation() const { return refCalc_.get(); }
    /// @}

private:
    WeakPtr<SpatialCalculation> refCalc_;  ///< 被引用的（非空间）标量计算
};

AST_NAMESPACE_END
