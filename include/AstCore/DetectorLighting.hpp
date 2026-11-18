/// @file      DetectorLighting.hpp
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

class AST_CORE_API DetectorLighting : public EventDetector
{
public:
    AST_OBJECT(DetectorLighting)
    DetectorLighting() = default;
    ~DetectorLighting() = default;

    double getValue(const SpacecraftState& state, double t) const override;
};

/*! @} */

AST_NAMESPACE_END

