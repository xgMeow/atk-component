/// @file      FrameXXXXXX.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/Frame.hpp"
#include "AstCore/EventTime.hpp"
#include "AstCore/AxesFrozenAtEventTime.hpp"
#include "AstCore/Axes.hpp"
#include "AstCore/Point.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class FrameWithEpoch;
using PFrameWithEpoch = FrameWithEpoch*;
using HFrameWithEpoch = SharedPtr<FrameWithEpoch>;

/// @brief 带轴系历元的坐标系
class AST_CORE_API FrameWithEpoch: public Frame
{
public:
    static PFrameWithEpoch New(Point* origin, Axes* axes);
    static PFrameWithEpoch New(Point* origin, Axes* axes, EventTime* epoch);
    static HFrameWithEpoch MakeShared(Point* origin, Axes* axes);
    static HFrameWithEpoch MakeShared(Point* origin, Axes* axes, EventTime* epoch);

    FrameWithEpoch();
    FrameWithEpoch(Point* origin, Axes* axes);
    FrameWithEpoch(Point* origin, Axes* axes, EventTime* epoch);
    ~FrameWithEpoch() = default;
public:
    Axes* getAxes() const override;
    Point* getOrigin() const override;
public:
    bool getUseEpoch() const{ return useEpoch_; }
    void setUseEpoch(bool useEpoch){ useEpoch_ = useEpoch; }
    SharedPtr<EventTime>& getEpochHandle();
    EventTime* getEpoch() const;
    errc_t getEpoch(TimePoint& epoch) const;
    void setEpoch(EventTime* epoch);
    void setSourceAxes(Axes* axes);
    Axes* getSourceAxes() const;
    Axes* getReferenceAxes() const;
    void setReferenceAxes(Axes* axes);
protected:
    SharedPtr<Point>                      origin_;               ///< 原点
    SharedPtr<AxesFrozenAtEventTime>      frozenAxes_;           ///< 冻结轴系
    SharedPtr<Axes>                       sourceAxes_;           ///< 轴系
    bool                                  useEpoch_{false};      ///< 是否使用轴系历元
};

/*! @} */

AST_NAMESPACE_END