/// @file      DataGroupSolarIntensity.hpp
/// @brief     太阳光照强度数据组
/// @details   提供 "Solar Intensity" 报表所需的数据（时间变量型）。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-18

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstUtil/Span.hpp"

#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup AstReport
    @{
*/

/// @brief 太阳光照强度数据组
/// @details 时间变量型数据组，每个时间网格点一行。光照强度取所有遮挡天体
///          双锥模型光照比例的最小值（0=本影，1=全光照，(0,1)=半影）。
class AST_REPORT_API DataGroupSolarIntensity : public DataGroupTimeVar
{
public:
    /// @brief 单行数据
    struct Data
    {
        TimePoint   time_{};
        double      intensity_{1.0};     ///< 光照强度 [0,1]
        std::string currentCondition_{}; ///< 当前光照条件：Sunlight/Penumbra/Umbra
        std::string obstruction_{};      ///< 遮挡体名称（全光照时为空）

        const TimePoint&   getTime()             const { return time_; }
        double             getIntensity()        const { return intensity_; }
        double             getShadowRatio()      const { return 1.0 - intensity_; }
        const std::string& getCurrentCondition() const { return currentCondition_; }
        const std::string& getObstruction()      const { return obstruction_; }
    };

    static DataElements Elements();

    DataGroupSolarIntensity() = default;
    ~DataGroupSolarIntensity() = default;

    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
    const DataElements& getElements() const override;

    /// @name 配置
    /// @{
    Point* getPoint() const { return point_.get(); }
    void   setPoint(Point* p) { point_ = p; }
    void   setLightSource(CelestialBody* b) { lightSource_ = b; }
    CelestialBody* getLightSource() const { return lightSource_.get(); }
    void   setOccultingBodies(const std::vector<HCelestialBody>& bodies) { occultingBodies_ = bodies; }
    /// @}

private:
    WeakPtr<Point>              point_{nullptr};
    WeakPtr<CelestialBody>      lightSource_{nullptr};
    std::vector<HCelestialBody> occultingBodies_{};
};

/*! @} */

AST_NAMESPACE_END
