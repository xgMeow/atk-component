/// @file      RunTimeLeapSecond.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/


/// @brief 获取UTC时间的闰秒数
/// @param jdUTC 
/// @return 
AST_CORE_CAPI double aLeapSecondUTC(double jdUTC);

/// @brief 获取UTC时间的闰秒数（MJD）
/// @param mjdUTC 
/// @return 
AST_CORE_CAPI double aLeapSecondUTCMJD(double mjdUTC);


/*! @} */

AST_NAMESPACE_END

