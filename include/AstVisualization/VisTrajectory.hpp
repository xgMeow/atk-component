/// @file      VisTrajectory.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "VisObject.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/Frame.hpp"
#include "AstCore/TimeInterval.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 轨迹可视化对象
/// @details 用于可视化空间中的轨迹，可以配置点、坐标系、时间间隔和步长。
class AST_VISUALIZATION_API VisTrajectory final: public VisObject
{
public:
    VisTrajectory() = default;
    ~VisTrajectory() = default;
    A_DISABLE_COPY(VisTrajectory)
public:
    /// @brief 访问者分派
    void accept(VisVisitor& visitor) override;
public:
    Frame* frame() const { return frame_.get(); }
    void setFrame(Frame* frame) { frame_ = frame; }
    Point* point() const { return point_.get(); }
    void setPoint(Point* point) { point_ = point; }
    const TimeInterval& interval() const { return interval_; }
    void setInterval(const TimeInterval& interval) { interval_ = interval; }
    double step() const { return step_; }
    void setStep(double step) { step_ = step; }
public:
    /// @brief 采样整条轨迹
    /// @param positions 输出采样位置（SI，米）
    void getPositions(std::vector<Vector3d>& positions) const;
private:
    WeakPtr<Frame> frame_{};
    WeakPtr<Point> point_{};
    TimeInterval interval_{};
    double step_{6};
};


/*! @} */

AST_NAMESPACE_END
