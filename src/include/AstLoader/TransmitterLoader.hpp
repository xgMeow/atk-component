/// @file      TransmitterLoader.hpp
/// @brief     发射机加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

class Transmitter;

/// @brief 加载发射机对象
/// @param filepath 文件路径
/// @param transmitter 发射机对象引用
/// @return 错误码
errc_t aLoadTransmitter(StringView filepath, Transmitter& transmitter);

AST_NAMESPACE_END