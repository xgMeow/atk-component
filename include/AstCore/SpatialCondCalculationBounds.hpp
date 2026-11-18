/// @file      SpatialCondCalculationBounds.hpp
/// @brief     计算边界空间条件
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "SpatialCondition.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

class SpatialCalculation;

/// @brief 边界类型
enum class EBoundType
{
    eAboveMinimum,                ///< 高于最小值
    eBelowMaximum,                ///< 低于最大值
    eBetweenMinimumAndMaximum,    ///< 介于最小值和最大值之间
    eOutsideMinimumAndMaximum     ///< 在最小值和最大值之外
};

/// @brief 计算边界空间条件
/// @details 对空间计算的值施加数值边界，值在边界内时条件满足
/// @ingroup Spatial
class AST_CORE_API SpatialCondCalculationBounds final : public SpatialCondition
{
public:
    SpatialCondCalculationBounds() = default;
    ~SpatialCondCalculationBounds() override = default;

    void accept(SpatialConditionVisitor& visitor) override { visitor.visit(*this); }
    errc_t evaluate(const TimePoint& time, const Vector3d& position, bool& result) const override;

    /// @name 引用的空间计算
    /// @{
    void setCalculation(SpatialCalculation* calc);
    SpatialCalculation* getCalculation() const { return calc_.get(); }
    /// @}

    /// @name 边界类型
    /// @{
    void setBoundType(EBoundType type) { boundType_ = type; }
    EBoundType getBoundType() const { return boundType_; }
    /// @}

    /// @name 边界值
    /// @{
    void setLowerBound(double bound) { lowerBound_ = bound; }
    double getLowerBound() const { return lowerBound_; }
    void setUpperBound(double bound) { upperBound_ = bound; }
    double getUpperBound() const { return upperBound_; }
    /// @}

private:
    WeakPtr<SpatialCalculation> calc_;                                     ///< 被引用的空间计算
    EBoundType                   boundType_{EBoundType::eAboveMinimum};     ///< 边界类型
    double                       lowerBound_{0.0};                          ///< 下界
    double                       upperBound_{0.0};                          ///< 上界
};

AST_NAMESPACE_END
