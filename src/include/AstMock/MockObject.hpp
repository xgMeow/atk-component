/// @file      MockObject.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-29

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_MOCK_API MockObject: public Object
{
public:
    AST_OBJECT(MockObject)
    AST_PROPERT(x)
    AST_PROPERT(duration)
    AST_PROPERT(factor)
    MockObject() = default;
    ~MockObject() = default;
PROPERTIES:
    length_d x() const { return x_; }
    void setX(length_d x) { x_ = x; }
    time_d duration() const { return duration_; }
    void setDuration(time_d duration) { duration_ = duration; }
    double factor() const { return factor_; }
    void setFactor(double factor) { factor_ = factor; }
private:
    length_d x_{0.0};
    time_d duration_{0.0};
    double factor_{1.0};
};

/*! @} */

AST_NAMESPACE_END
