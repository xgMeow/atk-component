/// @file      InitialStateLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class InitialState;


/// @brief 从值加载初始状态任务
/// @param value 值
/// @param initialState 初始状态任务
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadInitialState(const Value& value, InitialState& initialState);


/// @brief 加载初始状态任务
/// @details filepath 初始状态任务的文件路径
/// @param initialState 初始状态任务
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadInitialState(StringView filepath, InitialState& initialState);


/*! @} */

AST_NAMESPACE_END
