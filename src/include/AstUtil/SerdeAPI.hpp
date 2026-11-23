/// @file      SerdeAPI.hpp
/// @brief     序列化模块的API头文件
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-30

#pragma once

#include "AstGlobal.h"
#include "Serde.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Serde
    @{
*/

/// @brief 将对象配置转换为 C++ 代码
/// @details 将对象配置转换为 C++ 代码，用于序列化和反序列化
/// @param object 对象指针
/// @param cppcode 输出的 C++ 代码
/// @return 错误码
AST_UTIL_CAPI errc_t aObjectToCppCode(Object* object, std::string& cppcode);


/// @brief 将对象配置转换为 C++ 代码文件
/// @details 将对象配置转换为 C++ 代码文件，用于序列化和反序列化
/// @param object 对象指针
/// @param cppfilepath 输出的 C++ 代码文件路径
/// @return 错误码
AST_UTIL_CAPI errc_t aObjectToCppFile(Object* object, StringView cppfilepath);


/// @brief 将对象序列化为指定格式
/// @details 将对象序列化为JSON、XML、C++、Java或Python格式
/// @param object 对象指针
/// @param format 序列化格式
/// @param output 输出字符串
/// @return 错误码
AST_UTIL_CAPI errc_t aObjectSerialize(Object* object, ESerializationFormat format, std::string& output);

/// @brief 从指定格式反序列化对象
/// @details 从JSON、XML、C++、Java或Python格式反序列化对象
/// @param input 输入字符串
/// @param format 序列化格式
/// @param object 对象指针
/// @return 错误码
AST_UTIL_CAPI errc_t aObjectDeserialize(const std::string& input, ESerializationFormat format, Object* object);

/*! @} */

AST_NAMESPACE_END