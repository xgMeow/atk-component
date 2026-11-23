/// @file      AttitudeTrajectoryRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-30

#pragma once

#include "AstGlobal.h"
#include "AttitudeProfile.hpp"
#include "AstCore/Frame.hpp"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 与轨迹相关的姿态
/// @details 即根据航天器的轨迹参数计算出的姿态
/// 例如，根据航天器当前的位置速度计算得到的 VVLH 姿态
class AST_CORE_API AttitudeTrajectoryRelated : public AttitudeProfile
{
public:
    AST_OBJECT(AttitudeTrajectoryRelated)

    AttitudeTrajectoryRelated() = default;
    AttitudeTrajectoryRelated(Point* point, Frame* frame);
    ~AttitudeTrajectoryRelated() override = default;
public:
    Axes* getParent() const override;
public:
    void setPoint(Point* point) { point_ = point; }
    void setFrame(Frame* frame) { frame_ = frame; }
    Point* point() const { return point_.get(); }
    Frame* frame() const { return frame_.get(); }
protected:
    errc_t getPosVelAccLocal(const TimePoint& tp, Vector3d& pos, Vector3d& vel, Vector3d& acc) const;
    errc_t getPosVelLocal(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const;
    errc_t getPosLocal(const TimePoint& tp, Vector3d& pos) const;
private:
    WeakPtr<Point> point_{};    ///< 轨迹点
    WeakPtr<Frame> frame_{};    ///< 轨迹参考系
};



/*! @} */

AST_NAMESPACE_END
