/// @file      USSA1976.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-26

#pragma once

#include "AstGlobal.h"
#include "AtmosphereBase.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief USSA1976大气模型
class AST_CORE_API USSA1976: public AtmosphereBase
{
public:
    using AtmosphereBase::AtmosphereBase;
    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override;

};


/*! @} */

AST_NAMESPACE_END
