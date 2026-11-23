/// @file      TargeterSequenceLoader.hpp
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

class TargeterSequence;
class Value;

/// @brief 从值加载序列
/// @param value 值
/// @param sequence 序列对象
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadTargeterSequence(const Value& value, TargeterSequence& sequence);


/// @brief 从文件加载序列
/// @param filepath 文件路径
/// @param sequence 序列对象
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadTargeterSequence(StringView filepath, TargeterSequence& sequence);


/*! @} */

AST_NAMESPACE_END
