/// @file      SequenceLoader.hpp
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

class Sequence;
class Value;
class LoaderContext;


/// @brief 从值加载序列
/// @param value 值
/// @param sequence 序列对象
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadSequence(const Value& value, Sequence& sequence, const LoaderContext* context = nullptr);

/// @brief 从文件加载序列
/// @param filepath 文件路径
/// @param sequence 序列对象
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadSequence(StringView filepath, Sequence& sequence);


/*! @} */

AST_NAMESPACE_END
