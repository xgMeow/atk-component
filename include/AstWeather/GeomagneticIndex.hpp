/// @file      GeomagneticIndex.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-09

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 地磁指数Kp转换为Ap
AST_WEATHER_CAPI double aKpToAp(double kp);

/// @brief 地磁指数Ap转换为Kp
AST_WEATHER_CAPI double aApToKp(double ap);


/*! @} */

AST_NAMESPACE_END
