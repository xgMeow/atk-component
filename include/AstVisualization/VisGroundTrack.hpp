/// @file      VisGroundTrack.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "VisObject.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/Frame.hpp"
#include "AstCore/TimeInterval.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

/// @brief 地面轨迹可视化对象
/// @details 用于可视化一个点在天体上的投影轨迹。
class AST_VISUALIZATION_API VisGroundTrack : public VisObject
{
public:
    VisGroundTrack() = default;
    ~VisGroundTrack() = default;
    A_DISABLE_COPY(VisGroundTrack)
public:
    /// @brief 访问者分派
    void accept(VisVisitor& visitor) override;
public:
    Body* body() const { return body_.get(); }
    void setBody(Body* body) { body_ = body; }
    Point* point() const { return point_.get(); }
    void setPoint(Point* point) { point_ = point; }
    const TimeInterval& interval() const { return interval_; }
    void setInterval(const TimeInterval& interval) { interval_ = interval; }
    double step() const { return step_; }
    void setStep(double step) { step_ = step; }
private:
    WeakPtr<Body> body_{};
    WeakPtr<Point> point_{};
    TimeInterval interval_{};
    double step_{6};
};



/*! @} */

AST_NAMESPACE_END
