/// @file      AstDataUpdateGlobal.hpp
/// @brief     AstDataUpdate 模块全局定义
/// @details   定义模块导出宏和基础类型
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-30

#pragma once

#include "AstGlobal.h"

#ifdef AST_BUILD_LIB_DATAUPDATE
#  define AST_DATAUPDATE_API A_DECL_EXPORT
#else
#  define AST_DATAUPDATE_API A_DECL_IMPORT
#endif

AST_NAMESPACE_BEGIN

/*!
    @defgroup DataUpdate 数据更新
    @brief 提供动态数据文件的在线更新和管理功能。
*/

/*! @} */

AST_NAMESPACE_END
