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

class AxesFrozen;
using PAxesFrozen = AxesFrozen*;
using HAxesFrozen = SharedPtr<AxesFrozen>;

/// @brief 冻结轴系
class AST_CORE_API AxesFrozen: public Axes
{
public:
    static PAxesFrozen New(Axes* axes, const TimePoint& epoch, Axes* referenceAxes);
    static HAxesFrozen MakeShared(Axes* axes, const TimePoint& epoch, Axes* referenceAxes);

    AxesFrozen() = default;
    AxesFrozen(Axes* axes, const TimePoint& epoch, Axes* referenceAxes);
    ~AxesFrozen() = default;
public:
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
PROPERTIES:
    const TimePoint& getEpoch() const { return epoch_; }
    void setEpoch(const TimePoint& epoch) { epoch_ = epoch; }
    Axes* getAxes() const { return axes_; }
    void setAxes(Axes* axes) { axes_ = axes; }
    Axes* getReferenceAxes() const { return referenceAxes_; }
    void setReferenceAxes(Axes* referenceAxes) { referenceAxes_ = referenceAxes; }
protected:
    SharedPtr<Axes> referenceAxes_;     ///< 参考轴系
    SharedPtr<Axes> axes_;              ///< 冻结轴系
    TimePoint       epoch_;             ///< 冻结时间
};

/*! @} */

AST_NAMESPACE_END
