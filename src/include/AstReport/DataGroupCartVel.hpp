/// @file      DataGroupCartVel.hpp
/// @brief     笛卡尔速度数据组
/// @details   对应 CartVel 服务，输出 ICRF 坐标系下的笛卡尔速度分量、速率、径向速度和迹向速度
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-08

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/Frame.hpp"
#include "AstMath/Vector.hpp"
#include "AstUtil/Span.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief 笛卡尔速度数据组 — ICRF 坐标系下的 vx, vy, vz, speed, vr, vi 速度分量
class DataGroupCartVel : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint time_;
        Vector3d  pos_;    ///< 位置（用于计算径向/迹向速度分量）
        Vector3d  vel_;

        const TimePoint& getTime() const { return time_; }
        double getVX() const { return vel_.x(); }
        double getVY() const { return vel_.y(); }
        double getVZ() const { return vel_.z(); }

        /// @brief 速率 — 速度矢量的模 |vel|
        double getSpeed() const { return vel_.norm(); }

        /// @brief 径向速度 — 速度在位置方向上的投影 vr = vel·pos / |pos|
        double getRadialVel() const
        {
            double r = pos_.norm();
            return (r < 1e-12) ? 0.0 : vel_.dot(pos_) / r;
        }

        /// @brief 迹向速度 — 速度在垂直于径向方向上的分量 vi = |pos × vel| / |pos|
        double getInTrackVel() const
        {
            double r = pos_.norm();
            return (r < 1e-12) ? 0.0 : pos_.cross(vel_).norm() / r;
        }
    };
    static DataElements Elements();
    DataGroupCartVel() = default;
    ~DataGroupCartVel() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Point* getPoint() const { return point_.get(); }
    Frame* getFrame() const { return frame_.get(); }
    void setPoint(Point* p) { point_ = p; }
    void setFrame(Frame* f) { frame_ = f; }
private:
    WeakPtr<Point> point_{};
    WeakPtr<Frame> frame_{};
};


/*! @} */

AST_NAMESPACE_END
