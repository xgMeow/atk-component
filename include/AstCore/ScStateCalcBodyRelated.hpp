/// @file      ScStateCalcBodyRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"
#include "AstCore/CelestialBody.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API ScStateCalcBodyRelated: public ScStateCalculation
{
public:
    AST_OBJECT(ScStateCalcBodyRelated)
    AST_PROPERT(body)
    ScStateCalcBodyRelated() = default;
    ~ScStateCalcBodyRelated() = default;
PROPERTIES:
    Body* body() const { return body_.get(); }
    void setBody(Body* body) { body_ = body; }
private:
    WeakPtr<CelestialBody> body_{};
};

/*! @} */

AST_NAMESPACE_END
