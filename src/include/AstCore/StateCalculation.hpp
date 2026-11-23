/// @file      StateCalculation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-19

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectCalculation.hpp"
#include "AstCore/State.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_CORE_API StateCalculation: public ObjectCalculation
{
public:
    Class* getExpectedType() const override {return State::StaticType();};
    errc_t calculateNoCheckType(const Object* obj, double& result) override;
    virtual errc_t calculate(const State& state, double& result) = 0;
protected:

};

/*! @} */

AST_NAMESPACE_END
