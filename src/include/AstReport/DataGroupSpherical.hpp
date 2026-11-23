/// @file      DataGroupSpherical.hpp
/// @brief     球坐标轨道根数数据组
/// @details   赤经、赤纬、地心距、水平航迹角、惯性航迹方位角、惯性速度
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




/// @brief 球坐标轨道根数数据组 — 赤经、赤纬、地心距、水平航迹角、惯性航迹方位角、惯性速度
class DataGroupSpherical : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint time_;
        double    rightAscen_;
        double    declination_;
        double    radius_;
        double    horizFltPathAng_;
        double    inertialFltPathAzi_;
        double    inertialVel_;

        const TimePoint& getTime()                const { return time_; }
        double getRightAscen()                    const { return rightAscen_; }
        double getDeclination()                   const { return declination_; }
        double getRadius()                        const { return radius_; }
        double getHorizFltPathAng()               const { return horizFltPathAng_; }
        double getInertialFltPathAzi()            const { return inertialFltPathAzi_; }
        double getInertialVel()                   const { return inertialVel_; }
    };
    static DataElements Elements();

    DataGroupSpherical() = default;
    ~DataGroupSpherical() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Point* getPoint() const { return point_.get(); }
    Frame* getFrame()   const { return frame_.get(); }
    void setPoint(Point* p) { point_ = p; }
    void setFrame(Frame* f)   { frame_ = f; }
private:
    WeakPtr<Point> point_{};
    WeakPtr<Frame> frame_{};
};


/*! @} */

AST_NAMESPACE_END
