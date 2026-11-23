/// @file      DetectorBodyRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"
#include "AstCore/CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_CORE_API DetectorBodyRelated : public EventDetector
{
public:
    AST_OBJECT(DetectorBodyRelated)
    AST_PROPERT(body)
public:
    void setBodyByName(StringView bodyName);
    void setBody(StringView bodyName);
PROPERTIES:
    Body* body() const {return body_.get();}
    void setBody(Body* body) {body_ = body;}
private:
    WeakPtr<Body> body_{};
};


/*! @} */

AST_NAMESPACE_END
