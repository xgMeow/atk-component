/// @file      ScStateCalcPointRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_CORE_API ScStateCalcPointRelated : public ScStateCalculation
{
public:
    AST_OBJECT(ScStateCalcPointRelated)
    AST_PROPERT(point)
PROPERTIES:
    Point* point() const { return point_.get(); }
    void setPoint(Point* point) { point_ = point; }
private:
    WeakPtr<Point> point_{};      ///< 点
};

/*! @} */

AST_NAMESPACE_END
