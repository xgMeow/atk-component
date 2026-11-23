/// @file      SpacecraftStateLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-30

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class SpacecraftState;

/// @brief 加载航天器状态
/// @param value 航天器状态值
/// @param spacecraftState 航天器状态
/// @return 错误码
errc_t aLoadSpacecraftState(const Value& value, SpacecraftState& spacecraftState);

/*! @} */

AST_NAMESPACE_END
