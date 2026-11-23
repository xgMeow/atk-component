/// @file      AccessConstraint.hpp
/// @brief     访问约束抽象基类
/// @details   定义可见性/访问约束的统一接口。约束返回有符号双精度特征值，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-21

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

class Point;

/// @brief 访问约束抽象基类
/// @details 约束评估返回有符号特征值 double：
///          - value >= 0 → 约束满足（可见/可访问）
///          - value < 0 → 约束违反（不可见/不可访问）
///          - value == 0 → 恰好处于边界
///
///          该设计与 EventDetector::getValue() 一致，
///          允许 Brent/Dekker/二分法等算法精确定位约束切换时刻。
class AST_CORE_API AccessConstraint : public ObjectNamed
{
public:
    AST_OBJECT(AccessConstraint)

    AccessConstraint() = default;
    virtual ~AccessConstraint() = default;

    /// @brief 评估约束的特征值
    /// @param time 评估时刻
    /// @return 特征值：>0 满足，<0 违反，==0 恰好边界
    virtual double evaluate(const TimePoint& time) const = 0;

    /// @brief 便捷方法：约束是否满足
    /// @param time 评估时刻
    /// @return true = 约束满足
    bool isSatisfied(const TimePoint& time) const
    {
        return evaluate(time) >= 0.0;
    }

};

AST_NAMESPACE_END
