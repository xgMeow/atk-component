/// @file      SpatialCondition.hpp
/// @brief     空间条件基类
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "AstMath/Vector.hpp"
#include "SpatialConditionVisitor.hpp"

AST_NAMESPACE_BEGIN

/// @brief 空间条件基类
/// @details 空间条件是一个依赖于时间和位置的布尔函数
/// @ingroup Spatial
class AST_CORE_API SpatialCondition : public ObjectNamed
{
public:
    SpatialCondition();
    ~SpatialCondition() override = default;

    /// @brief 接受访问者
    virtual void accept(SpatialConditionVisitor& visitor) = 0;

    /// @brief 在指定时间和位置评估条件
    /// @param time 评估时间
    /// @param position 评估位置
    /// @param[out] result 条件是否满足
    /// @return eNoError 成功，其他值表示错误
    virtual errc_t evaluate(const TimePoint& time, const Vector3d& position, bool& result) const = 0;
};

AST_NAMESPACE_END
