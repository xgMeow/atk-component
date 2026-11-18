/// @file      DataGroupBetaAngle.hpp
/// @brief     贝塔角数据组
/// @details   太阳贝塔角及月球贝塔角 — 天体方向矢量与轨道面的夹角
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




/// @brief 贝塔角数据组 — 太阳贝塔角及月球贝塔角
/// @details beta = arcsin(r_third · (r × v)/|r × v|)
class DataGroupBetaAngle : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint time_;
        double    betaAngle_;
        double    lunarBetaAngle_;

        const TimePoint& getTime()           const { return time_; }
        double           getBetaAngle()      const { return betaAngle_; }
        double           getLunarBetaAngle() const { return lunarBetaAngle_; }
    };
    static DataElements Elements();

    DataGroupBetaAngle() = default;
    ~DataGroupBetaAngle() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Point* getPoint()   const { return point_.get(); }
    Frame* getFrame()     const { return frame_.get(); }
    Point* getSunPoint()  const { return sunPoint_.get(); }
    Point* getMoonPoint() const { return moonPoint_.get(); }
    void setPoint(Point* p)   { point_ = p; }
    void setFrame(Frame* f)     { frame_ = f; }
    void setSunPoint(Point* p)  { sunPoint_ = p; }
    void setMoonPoint(Point* p) { moonPoint_ = p; }
private:
    WeakPtr<Point> point_{};
    WeakPtr<Frame> frame_{};
    WeakPtr<Point> sunPoint_{};
    WeakPtr<Point> moonPoint_{};
};


/*! @} */

AST_NAMESPACE_END
