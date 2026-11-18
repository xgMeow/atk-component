/// @file      MotionGreatArc.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-13

#pragma once

#include "AstGlobal.h"
#include "MotionProfile.hpp"
#include "AstCore/GeodeticPoint.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class WayPoint
{
public:
    double time() const {return time_;}
public:
    double time_;             ///< 时间
    GeodeticPoint position_;  ///< 位置
    double speed_;            ///< 速度
    double acceleration_;     ///< 加速度
    double turnRadius_;       ///< 转弯半径
};


class MotionGreatArc;
using PMotionGreatArc = MotionGreatArc*;
using HMotionGreatArc = SharedPtr<MotionGreatArc>;

class AST_SIM_API MotionGreatArc : public MotionProfile
{
public:
    static PMotionGreatArc New();
    MotionGreatArc();
    ~MotionGreatArc();
public:
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;
public:
    using WayPointVector = std::vector<WayPoint>;
    void setStartTime(const TimePoint& tp);
    errc_t getStartTime(TimePoint& tp) const;
    errc_t getStopTime(TimePoint& tp) const;
    errc_t getInterval(TimeInterval& interval) const;
    const WayPointVector& getWayPoints() const{return wayPoints_;}
    void setWayPoints(const WayPointVector& wayPoints){wayPoints_ = wayPoints;}
private:
    SharedPtr<EventTime> startTime_{};       ///< 开始时间
    WayPointVector wayPoints_{};             ///< 路径点
};

/*! @} */

AST_NAMESPACE_END
