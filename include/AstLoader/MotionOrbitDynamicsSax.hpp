/// @file      MotionSax.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-19

#pragma once

#include "AstGlobal.h"
#include "AstUtil/BKVSax.hpp"
#include "AstCore/EventTime.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstSim/MotionWithIntervalStep.hpp"
#include "AstSim/MotionOrbitDynamics.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/
class MotionOrbitDynamics;
struct VehiclePathData;
class BKVParser;

class AST_LOADER_API MotionOrbitDynamicsSax: public BKVSax
{
public:
    MotionOrbitDynamicsSax(BKVParser& parser, const VehiclePathData& vehiclePathData)
        : parser_(parser)
        , vehiclePathData_(vehiclePathData)
    {}
    ~MotionOrbitDynamicsSax() override = default;
public:
    errc_t begin(StringView name) override;
    errc_t end(StringView name) override;
    errc_t keyValue(StringView key, const ValueView& value) override;
public:
    virtual errc_t getMotion(ScopedPtr<MotionProfile>& motion) = 0;
public:
    HEventTime makeStateEpoch() const;
    HEventInterval makeInterval() const;
protected:
    Body* getBody() const;
protected:
    BKVParser& parser_;
    const VehiclePathData& vehiclePathData_;
    SharedPtr<EventTime> ephemSmartEpoch_{};
    SharedPtr<EventInterval> ephemSmartInterval_{};
    TimePoint ephemEpoch_{};
    TimePoint startTime_{};
    TimePoint stopTime_{};
    bool useScenTime_ = false;
};

/*! @} */

AST_NAMESPACE_END
