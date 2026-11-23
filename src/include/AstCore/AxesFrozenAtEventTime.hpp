/// @file      AxesFrozen.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-15

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"
#include "AstCore/EventTime.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AxesFrozenAtEventTime;
using PAxesFrozenAtEventTime = AxesFrozenAtEventTime*;
using HAxesFrozenAtEventTime = SharedPtr<AxesFrozenAtEventTime>;

/// @brief 事件时间冻结轴系
class AST_CORE_API AxesFrozenAtEventTime: public Axes
{
public:
    static PAxesFrozenAtEventTime New(Axes* axes, EventTime* epoch, Axes* referenceAxes);
    static HAxesFrozenAtEventTime MakeShared(Axes* axes, EventTime* epoch, Axes* referenceAxes);

    AxesFrozenAtEventTime() = default;
    AxesFrozenAtEventTime(Axes* axes, EventTime* epoch, Axes* referenceAxes);
    ~AxesFrozenAtEventTime() = default;
public:
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
PROPERTIES:
    /// @brief 获取冻结时间
    EventTime* getEpoch() const { return epoch_.get(); }

    /// @brief 获取冻结时间句柄
    SharedPtr<EventTime>& getEpochHandle() { return epoch_; }

    /// @brief 设置冻结时间
    void setEpoch(EventTime* epoch) { epoch_ = epoch; }

    /// @brief 获取参考轴系
    Axes* getReferenceAxes() const { return referenceAxes_.get(); }

    /// @brief 设置参考轴系
    void setReferenceAxes(Axes* referenceAxes) { referenceAxes_ = referenceAxes; }

    /// @brief 获取冻结轴系
    Axes* getAxes() const { return axes_.get(); }

    /// @brief 设置冻结轴系
    void setAxes(Axes* axes) { axes_ = axes; }
public:
    /// @brief 获取冻结时间点
    errc_t getEpoch(TimePoint& epoch) const;

    /// @brief 设置冻结时间点
    void setEpoch(const TimePoint& epoch);
protected:
    SharedPtr<Axes>         referenceAxes_{};    ///< 参考轴系
    SharedPtr<Axes>         axes_{};             ///< 冻结轴系
    SharedPtr<EventTime>    epoch_{};            ///< 冻结时间
};

/*! @} */

AST_NAMESPACE_END
