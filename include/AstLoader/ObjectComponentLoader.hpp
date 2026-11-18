/// @file      ObjectComponentLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 加载对象的扩展组件
/// @param parser 键值对解析器
/// @param object 对象
/// @return 错误码
errc_t aLoadObjectExtensions(BKVParser& parser, Object& object);



/*! @} */

AST_NAMESPACE_END
