/// @file      DataGroupLLAState.hpp
/// @brief     LLA 状态数据组
/// @details   天体固连系下的大地坐标(经纬高)、地心坐标及变化率
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-08

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/GeodeticPoint.hpp"
#include "AstMath/Vector.hpp"
#include "AstUtil/Span.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/




/// @brief LLA 状态数据组 — 大地坐标(经纬高)、地心经纬度及变化率
class DataGroupLLAState : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint     time_{};
        GeodeticPoint detic_{};
        double        centricLat_{};
        double        centricLon_{};
        double        latRate_{};
        double        lonRate_{};
        double        altRate_{};

        const TimePoint& getTime()       const { return time_; }
        double           getLat()        const { return detic_.latitude(); }
        double           getLon()        const { return detic_.longitude(); }
        double           getAlt()        const { return detic_.altitude(); }
        double           getLatRate()    const { return latRate_; }
        double           getLonRate()    const { return lonRate_; }
        double           getAltRate()    const { return altRate_; }
        double           getCentricLat() const { return centricLat_; }
        double           getCentricLon() const { return centricLon_; }

        // 以下元素需要额外基础设施支持，暂未实现：
        // double getAltAGL()      const; // 需要地形高程数据
        // double getTerrainAlt()  const; // 需要地形高程数据
        // double getAltMSL()      const; // 需要大地水准面模型
        // int    getUTMZone()     const; // 需要 UTM 投影转换
        // double getUTMEasting()  const; // 需要 UTM 投影转换
        // double getUTMNorthing() const; // 需要 UTM 投影转换
        // const std::string& getMGRSCell() const; // 需要 MGRS 转换
    };
    static DataElements Elements();

    DataGroupLLAState() = default;
    ~DataGroupLLAState() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Point* getPoint() const { return point_.get(); }
    Body*  getBody()    const { return body_.get(); }
    void setPoint(Point* p) { point_ = p; }
    void setBody(Body* b)     { body_ = b; }
private:
    WeakPtr<Point> point_{};
    WeakPtr<Body>  body_{};
};


/*! @} */

AST_NAMESPACE_END
