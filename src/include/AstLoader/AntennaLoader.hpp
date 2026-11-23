/// @file      AntennaLoader.hpp
/// @brief     天线加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Antenna;

/// @brief 加载天线对象
/// @details 从文件加载天线对象
/// @param filepath 文件路径
/// @param antenna 天线对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadAntenna(StringView filepath, Antenna& antenna);

/*! @} */

AST_NAMESPACE_END