/// @file      MoverLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Mover;

/// @brief 加载移动对象
/// @details 从文件加载移动对象
/// @param filepath 文件路径
/// @param mover 移动对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadMover(StringView filepath, Mover& mover);

/*! @} */

AST_NAMESPACE_END
