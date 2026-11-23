/// @file      Propagate.hpp
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

class Propagate;
class Value;
class LoaderContext;

/// @brief 从值加载 propagate 任务
/// @param value 值
/// @param propagate 输出的 propagate 对象
/// @param context 加载上下文
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadPropagate(const Value& value, Propagate& propagate, const LoaderContext* context = nullptr);


/// @brief 加载 propagate 任务
/// @param filepath propagate 文件名
/// @param propagate 输出的 propagate 对象
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadPropagate(StringView filepath, Propagate& propagate);


/*! @} */

AST_NAMESPACE_END
