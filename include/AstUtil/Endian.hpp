/// @file      Endian.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Platform
    @{
*/

enum EEndian{
    eLittleEndian,      ///< 小端字节序
    eBigEndian,         ///< 大端字节序
};


/// @brief 获取当前系统的字节序
/// @return EEndian 当前系统的字节序
AST_UTIL_CAPI EEndian aGetEndian();


/*! @} */

AST_NAMESPACE_END
