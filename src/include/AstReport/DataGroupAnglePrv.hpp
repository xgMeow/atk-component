/// @file      DataGroupAnglePrv.hpp
/// @brief     角度数据组
/// @details   角度及其变化率
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-08

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Angle.hpp"
#include "AstUtil/Span.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief 角度数据组 — 角度及角速率
class DataGroupAnglePrv : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint time_;
        double    angle_;
        double    angleRate_;

        const TimePoint& getTime()      const { return time_; }
        double           getAngle()     const { return angle_; }
        double           getAngleRate() const { return angleRate_; }
    };
    static DataElements Elements();

    DataGroupAnglePrv() = default;
    ~DataGroupAnglePrv() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Angle* getAngle() const { return angle_.get(); }
private:
    WeakPtr<Angle> angle_{};
};


/*! @} */

AST_NAMESPACE_END
