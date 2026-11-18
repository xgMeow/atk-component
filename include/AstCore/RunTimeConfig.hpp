/// @file      RunTimeConfig.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-21

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ValueView.hpp"
#include <vector>
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/

/// @brief 获取当前线程的数据上下文的配置值
/// @param key 配置键
/// @return 配置值
AST_CORE_API ValueView aGetConfigValue(StringView key);

/// @brief 获取当前线程的数据上下文的配置字符串向量
/// @param key 配置键
/// @return 配置字符串向量
AST_CORE_API std::vector<std::string> aGetConfigStringVector(StringView key);


/// @brief 获取当前线程的数据上下文的配置字符串视图向量
/// @param key 配置键
/// @return 配置字符串视图向量
AST_CORE_API std::vector<StringView> aGetConfigStringViewVector(StringView key);



/*! @} */

AST_NAMESPACE_END
