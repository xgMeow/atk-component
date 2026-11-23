/// @file      ShooterResultLoader.hpp
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

class ShooterResult;

/// @brief 加载结果
/// @param value 值
/// @param result 输出的结果
/// @return 错误码
errc_t aLoadShooterResult(const Value& value, ShooterResult& result);


/*! @} */

AST_NAMESPACE_END
