/// @file      TestConfig.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-21

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StartupConfig.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 获取测试配置
/// @return 测试配置指针
AST_TEST_CAPI StartupConfig* aTestGetConfig();


/// @brief 获取测试数据目录
/// @details 解析顺序：
///          1. AST_TEST_DATA_DIR 环境变量；
///          2. 动态库所在文件夹的 test-data 目录
/// @return 测试数据目录路径
AST_TEST_API std::string aTestDataDirGet();


/// @brief 获取测试配置值
/// @param key 配置键
/// @return 配置值视图
AST_TEST_API ValueView aTestGetConfigValue(StringView key);



/// @brief 获取测试配置值向量
/// @param key 配置键
/// @return 配置值向量
AST_TEST_API std::vector<std::string> aTestGetConfigStringVector(StringView key);


/// @brief 获取测试配置值视图向量
/// @param key 配置键
/// @return 配置值视图向量
AST_TEST_API std::vector<StringView> aTestGetConfigStringViewVector(StringView key);


/*! @} */

AST_NAMESPACE_END
