/// @file      PointProxy.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/

/// @brief 点代理类
/// @details 将点接口原样转发给被代理的点对象，自身不产生任何计算。
class AST_CORE_API PointProxy final: public Point
{
public:
    PointProxy() = default;
    explicit PointProxy(Point* point):impl_(point){}
    ~PointProxy() override = default;

public:
    void setImpl(Point* impl){impl_ = impl;}
    Point* impl() const {return impl_.get();}
public:
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
    errc_t getPosVelAcc(const TimePoint& tp, Vector3d& pos, Vector3d& vel, Vector3d& acc) const override;
    errc_t getInterval(TimeInterval& interval) const override;
private:
    WeakPtr<Point> impl_{};
};




/*! @} */

AST_NAMESPACE_END
