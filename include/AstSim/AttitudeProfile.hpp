/// @file      AttitudeProfile.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 姿态定义接口
class AttitudeProfile: public ObjectNamed
{
public:
    AttitudeProfile() = default;
    virtual ~AttitudeProfile() = default;

    
};


/*! @} */

AST_NAMESPACE_END
