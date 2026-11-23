/// @file      LandingSiteCalculation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-02

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectCalculation.hpp"
#include "AstCore/SegmentCalculation.hpp"
#include "AstCore/LandingSite.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 着陆点计算量接口，定义计算与着陆点相关量的抽象接口
class AST_CORE_API LandingSiteCalculation: public SegmentCalculation
{
public:
    AST_OBJECT(LandingSiteCalculation)
    Class* getExpectedType() const override {return LandingSite::StaticType();};
    virtual errc_t calculate(const Segment& segment, double& result) override = 0;
};


/*! @} */

AST_NAMESPACE_END
