/// @file      DetectorPointRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_CORE_API DetectorPointRelated : public EventDetector
{
public:
    AST_OBJECT(DetectorPointRelated)

    DetectorPointRelated() = default;
    ~DetectorPointRelated() = default;
public:
    void setPointByName(StringView pointName);
public:
    Point* point() const { return point_.get(); }
    void setPoint(Point* point) { point_ = point; }
private:
    WeakPtr<Point> point_{};
};

/*! @} */

AST_NAMESPACE_END
