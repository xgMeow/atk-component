/// @file      DataGroupEclipse.hpp
/// @brief     日食时刻数据组
/// @details   提供 "Eclipse Times" 报表所需的数据
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-15

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupInterval.hpp"
#include "AstCore/CelestialBody.hpp"
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

/// @brief 日食时刻数据组
/// @details 遍历航天器在给定区间内的日食事件，为每个本影/半影段产出一行。
class AST_REPORT_API DataGroupEclipse : public DataGroupInterval
{
public:
    /// @brief 单行数据
    struct Data
    {
        TimePoint   startTime_{};
        TimePoint   stopTime_{};
        double      duration_{0.0};
        std::string obstruction_{};
        std::string currentCondition_{};
        std::string worstCondition_{};
        double      totalDuration_{0.0};

        const TimePoint&   getStartTime()       const { return startTime_; }
        const TimePoint&   getStopTime()        const { return stopTime_; }
        double             getDuration()        const { return duration_; }
        const std::string& getObstruction()     const { return obstruction_; }
        const std::string& getCurrentCondition() const { return currentCondition_; }
        const std::string& getWorstCondition()  const { return worstCondition_; }
        double             getTotalDuration()   const { return totalDuration_; }
    };

    static DataElements Elements();

    DataGroupEclipse() = default;
    ~DataGroupEclipse() = default;

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
