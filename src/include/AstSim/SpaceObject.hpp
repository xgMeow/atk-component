/// @file      SpaceObject.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-26

#pragma once

#include "AstGlobal.h"
#include "AstSim/Mover.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_SIM_API SpaceObject: public Mover
{
public:
    AST_OBJECT(SpaceObject)
    SpaceObject() = default;
    ~SpaceObject() override = default;
};

class ObjectLinkTo;

/// @brief 获取参考航天器链接
AST_SIM_API ObjectLinkTo* aSpaceObject_GetReferenceVehicleLink(SpaceObject* spaceObject);

/// @brief 获取参考航天器
AST_SIM_API SpaceObject* aSpaceObject_GetReferenceVehicle(SpaceObject* spaceObject);

/// @brief 设置参考航天器
AST_SIM_API void aSpaceObject_SetReferenceVehicle(SpaceObject* spaceObject, SpaceObject* referenceVehicle);

/// @brief 设置参考航天器(通过路径)
AST_SIM_API void aSpaceObject_SetReferenceVehicle(SpaceObject* spaceObject, StringView referenceVehiclePath);


/*! @} */

AST_NAMESPACE_END