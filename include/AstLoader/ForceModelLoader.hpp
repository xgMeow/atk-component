/// @file      ForceModelLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class HPOPForceModel;

/// @brief 加载力模型
/// @param value 值
/// @param forceModel 输出的力模型
/// @return 错误码
errc_t aLoadForceModel(const Value& value, HPOPForceModel& forceModel);

/*! @} */

AST_NAMESPACE_END
