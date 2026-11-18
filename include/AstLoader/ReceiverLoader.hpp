/// @file      ReceiverLoader.hpp
/// @brief     接收器加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Receiver;

/// @brief 加载接收器对象
/// @details 从文件加载接收器对象
/// @param filepath 文件路径
/// @param receiver 接收器对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadReceiver(StringView filepath, Receiver& receiver);

/*! @} */

AST_NAMESPACE_END