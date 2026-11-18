/// @file      AccessEvaluator.hpp
/// @brief     访问评估器
/// @details   基于步进策略采样约束，发现符号翻转后用 Brent 求根精化边界，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-22

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstCore/TimeInterval.hpp"
#include "AstCore/TimeIntervalList.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

class AccessConstraint;
class AccessStepper;



/// @brief 评估访问约束的时间段
/// @param constraint 访问约束
/// @param stepper 步进策略
/// @param interval 搜索时间区间
/// @param result 满足约束的时间段列表
/// @return 错误码
AST_CORE_API errc_t aEvaluateAccess(
    const AccessConstraint* constraint,
    AccessStepper* stepper,
    const TimeInterval& interval,
    TimeIntervalList& result
);


/// @brief 评估访问约束的时间段
/// @param constraint 访问约束
/// @param stepper 步进策略
/// @param intervalList 搜索时间区间列表
/// @param result 满足约束的时间段列表
/// @return 错误码
AST_CORE_API errc_t aEvaluateAccess(
    const AccessConstraint* constraint,
    AccessStepper* stepper,
    const TimeIntervalList& intervalList,
    TimeIntervalList& result
);


/// @brief 评估访问约束的时间段
/// @param constraints 访问约束列表
/// @param stepper 步进策略
/// @param interval 搜索时间区间
/// @param result 满足约束的时间段列表
/// @return 错误码
AST_CORE_API errc_t aEvaluateAccess(
    const std::vector<AccessConstraint*>& constraints,
    AccessStepper* stepper,
    const TimeInterval& interval,
    TimeIntervalList& result
);



/// @brief 访问评估器
/// @details 在指定时间范围内，按步进策略采样单条约束，搜索满足区间并精化边界。
class AST_CORE_API AccessEvaluator : public ObjectNamed
{
public:
    AST_OBJECT(AccessEvaluator)

    AccessEvaluator();
    virtual ~AccessEvaluator();
    A_DISABLE_COPY(AccessEvaluator)

    /// @brief 设置约束
    void setConstraint(AccessConstraint* constraint) { constraint_ = constraint; }
    AccessConstraint* constraint() const { return constraint_; }

    /// @brief 设置步进策略
    void setStepper(AccessStepper* stepper) { stepper_ = stepper; }
    AccessStepper* stepper() const { return stepper_; }

    /// @brief 计算访问时间段
    /// @param interval 搜索时间区间
    /// @param result 满足约束的时间段列表
    /// @return 错误码
    errc_t evaluate(const TimeInterval& interval, TimeIntervalList& result);

    /// @brief 单点判断是否可访问
    bool check(const TimePoint& time) const;

private:
    AccessConstraint*  constraint_{};
    AccessStepper*     stepper_{};
};

AST_NAMESPACE_END
