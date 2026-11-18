/// @file      SegmentCalculation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-19

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectCalculation.hpp"
#include "AstCore/Segment.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API SegmentCalculation: public ObjectCalculation
{
public:
    AST_OBJECT(SegmentCalculation)
    Class* getExpectedType() const override {return Segment::StaticType();};
    errc_t calculateNoCheckType(const Object* obj, double& result) override;
    virtual errc_t calculate(const Segment& segment, double& result) = 0;
};

/*! @} */

AST_NAMESPACE_END
