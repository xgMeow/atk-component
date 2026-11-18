/// @file      DataGroupEclipseSummary.hpp
/// @brief     日食摘要数据组
/// @details   提供 "Eclipse Summary" 报表所需的数据
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-17

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupInterval.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/EclipseEventFinder.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstCore/TimeInterval.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/Frame.hpp"

#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup AstReport
    @{
*/

/// @brief 日食摘要数据组
/// @details 遍历航天器在给定区间内的日食事件，为每个日食事件产出一行汇总数据。
class AST_REPORT_API DataGroupEclipseSummary : public DataGroupInterval
{
public:
    /// @brief 行类型：直接复用 EclipseEvent（其 getter 即各报表列）
    using Data = EclipseEvent;

    static DataElements Elements();

    DataGroupEclipseSummary() = default;
    ~DataGroupEclipseSummary() = default;

    errc_t calculate(const TimeInterval& interval, VariantVector& result) const override;
    errc_t calculate(const TimeInterval& interval, std::vector<Data>& result) const;
    const DataElements& getElements() const override;

    /// @name 配置
    /// @{
    Point* getPoint() const { return point_.get(); }
    void   setPoint(Point* p) { point_ = p; }
    void   setLightSource(CelestialBody* b) { lightSource_ = b; }
    CelestialBody* getLightSource() const { return lightSource_.get(); }
    void   setOccultingBodies(const std::vector<HCelestialBody>& bodies) { occultingBodies_ = bodies; }
    void   setStepSize(double s) { stepSize_ = s; }
    /// @}

private:
    WeakPtr<Point>                 point_{nullptr};
    WeakPtr<CelestialBody>         lightSource_{nullptr};
    std::vector<HCelestialBody>    occultingBodies_{};
    double                         stepSize_{5.0};
};

/*! @} */

AST_NAMESPACE_END
