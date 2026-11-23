/// @file      ObjectComponent.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "AstUtil/RTTIAPI.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ObjectAccessConstraints;


/// @tparam ComponentType 组件类型
/// @param object 对象
/// @return 对象的组件
template<typename ComponentType>
ComponentType& aObject_EnsureComponent(Object& object)
{
    ComponentType* component = aFindChild<ComponentType*>(&object);
    if(component == nullptr)
        component = aNewObject<ComponentType>(&object);
    return *component;
}


/// @param object 对象
/// @return 对象的访问约束组件
AST_SIM_CAPI ObjectAccessConstraints& aObject_EnsureAccessConstraints(Object& object);



/*! @} */

AST_NAMESPACE_END
