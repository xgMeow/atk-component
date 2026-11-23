/// @file      LandingSiteCalcSunAzimuth.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-03

#pragma once

#include "AstGlobal.h"
#include "AstCore/SegmentCalculation.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API LandingSiteCalcSunAzimuth: public SegmentCalculation
{
public:
    AST_OBJECT(LandingSiteCalcSunAzimuth)

    errc_t calculate(const Segment& segment, double& result) override;
    Dimension getDimension() const override{return EDimension::eAngle;}
};


/*! @} */

AST_NAMESPACE_END




