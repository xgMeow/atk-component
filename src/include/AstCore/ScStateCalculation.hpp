/// @file      ScStateCalculation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-19

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectCalculation.hpp"
#include "AstUtil/Dimension.hpp"
#include "AstCore/SpacecraftState.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ScStateCalculation;

using HScStateCalculation = SharedPtr<ScStateCalculation>;

class AST_CORE_API ScStateCalculation: public ObjectCalculation
{
public:
    AST_OBJECT(ScStateCalculation)
    Class* getExpectedType() const override {return SpacecraftState::StaticType();};
    errc_t calculateNoCheckType(const Object* obj, double& result) override;
    virtual errc_t calculate(const SpacecraftState& scState, double& result) = 0;
};

/*! @} */

AST_NAMESPACE_END
