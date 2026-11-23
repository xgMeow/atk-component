/// @file      DataGroupLLRState.hpp
/// @brief     LLR 球坐标状态数据组
/// @details   惯性系下的球坐标(纬度、经度、地心距)及变化率
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




/// @brief LLR 球坐标状态数据组 — 纬度、经度、地心距及变化率
class DataGroupLLRState : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint time_;
        double    lat_;
        double    lon_;
        double    rad_;
        double    latRate_;
        double    lonRate_;
        double    radRate_;

        const TimePoint& getTime()    const { return time_; }
        double           getLat()     const { return lat_; }
        double           getLon()     const { return lon_; }
        double           getRad()     const { return rad_; }
        double           getLatRate() const { return latRate_; }
        double           getLonRate() const { return lonRate_; }
        double           getRadRate() const { return radRate_; }
    };
    static DataElements Elements();

    DataGroupLLRState() = default;
    ~DataGroupLLRState() = default;
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
