/// @file      DetectorRMagnitude.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "DetectorPointRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API DetectorRMagnitude : public DetectorPointRelated
{
public:
    AST_OBJECT(DetectorRMagnitude)

    DetectorRMagnitude() = default;
    ~DetectorRMagnitude() = default;

    double getValue(const SpacecraftState& state, double t) const override;
};

/*! @} */

AST_NAMESPACE_END
