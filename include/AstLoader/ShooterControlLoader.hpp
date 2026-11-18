/// @file      ShooterControlLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ShooterControl;

/// @brief 加载控制变量
/// @param value 值
/// @param control 输出的控制变量
/// @return 错误码
errc_t aLoadShooterControl(const Value& value, ShooterControl& control);

/*! @} */

AST_NAMESPACE_END
