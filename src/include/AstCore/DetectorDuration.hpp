/// @file      DetectorDuration.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API DetectorDuration: public EventDetector
{
public:
    AST_OBJECT(DetectorDuration)
    AST_PROPERT(duration)
    static DetectorDuration* New();

    DetectorDuration() = default;
    virtual ~DetectorDuration() = default;

public:
    double getValue(const SpacecraftState& state, double t) const override;

PROPERTIES:
    double duration() const {return duration_;}
    void setDuration(double duration) {duration_ = duration;}
private:
    double duration_{0.0};
};

/*! @} */

AST_NAMESPACE_END
