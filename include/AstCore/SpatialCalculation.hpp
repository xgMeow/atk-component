/// @file      SpatialCalculation.hpp
/// @brief     空间计算基类
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "AstMath/Vector.hpp"
#include "SpatialCalculationVisitor.hpp"

#include "DifferentiationSettings.hpp"

AST_NAMESPACE_BEGIN

/// @brief 空间计算基类
/// @details 空间计算是一个依赖于时间和位置的标量函数
/// @ingroup Spatial
class AST_CORE_API SpatialCalculation : public ObjectNamed
{
public:
    SpatialCalculation();
    ~SpatialCalculation() override = default;

    /// @brief 接受访问者
    virtual void accept(SpatialCalculationVisitor& visitor) = 0;

    /// @brief 在指定时间和位置评估计算
    /// @param time 评估时间
    /// @param position 评估位置
    /// @param[out] result 计算结果值
    /// @return eNoError 成功，其他值表示错误
    virtual errc_t evaluate(const TimePoint& time, const Vector3d& position, double& result) const = 0;

    /// @name 导数设置
    /// @{
    void setDifferentiation(const DifferentiationSettings& ds) { diffSettings_ = ds; }
    const DifferentiationSettings& getDifferentiation() const { return diffSettings_; }
    /// @}

protected:
    DifferentiationSettings diffSettings_{};  ///< 导数/时间差分设置
};

AST_NAMESPACE_END
