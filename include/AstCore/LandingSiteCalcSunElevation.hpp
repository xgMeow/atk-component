/// @file      LandingSiteCalcSunElevation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/LandingSiteCalculation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 计算着陆点太阳高度角
class AST_CORE_API LandingSiteCalcSunElevation: public LandingSiteCalculation
{
public:
    AST_OBJECT(LandingSiteCalcSunElevation)
    errc_t calculate(const Segment& segment, double& result) override;
    Dimension getDimension() const override{return EDimension::eAngle;}
private:

};


/*! @} */

AST_NAMESPACE_END
