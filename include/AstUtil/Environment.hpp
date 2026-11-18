/// @file      Environment.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-20

#pragma once

#include "AstGlobal.h"
#include "Terminal.hpp"
#include "GUI.hpp"
#include <cstdio>

AST_NAMESPACE_BEGIN


/*!
    @addtogroup Platform
    @{
*/

/// @brief 检查是否在持续集成环境中运行
/// @return 如果在CI环境中运行，返回true；否则返回false
AST_UTIL_CAPI bool aIsCI();


/// @brief 检查是否在Github action CI环境中运行
/// @return 如果在Github action CI环境中运行，返回true；否则返回false
AST_UTIL_CAPI bool aIsGithubCI();


/// @brief 检查是否在Gitlab runner CI环境中运行
/// @return 如果在Gitlab runner CI环境中运行，返回true；否则返回false
AST_UTIL_API bool aIsGitlabCI();


/// @brief 检查终端是否支持颜色
/// @return 如果终端支持颜色，返回true；否则返回false
AST_UTIL_API bool aTerminalSupportColor();


/// @brief 获取终端窗口宽度（列数）
/// @return 终端宽度（列），若无法获取则返回默认值 80
AST_UTIL_API int aTerminalWidth();


/// @brief 获取当前项目的名称
/// @return 项目的名称
AST_UTIL_API StringView aProjectName();


/// @brief 检查文件是否为终端
/// @param file 文件指针
/// @return 如果文件为终端，返回true；否则返回false
AST_UTIL_CAPI bool aIsTerminal(FILE* file);


/// @brief 检查文件是否为普通文件
/// @param file 文件指针
/// @return 如果文件为普通文件，返回true；否则返回false
AST_UTIL_CAPI bool aIsFile(FILE* file);


/// @brief 检查标准输入是否为终端
/// @return 如果标准输入为终端，返回true；否则返回false
AST_UTIL_CAPI bool aStdInIsTerminal();


/// @brief 检查标准输入是否为文件
/// @return 如果标准输入为文件，返回true；否则返回false
AST_UTIL_CAPI bool aStdInIsFile();


/// @brief 检查标准输出是否为终端
/// @return 如果标准输出为终端，返回true；否则返回false
AST_UTIL_CAPI bool aStdOutIsTerminal();


/// @brief 检查标准输出是否为文件
/// @return 如果标准输出为文件，返回true；否则返回false
AST_UTIL_CAPI bool aStdOutIsFile();

/// @brief 检查标准错误是否为终端
/// @return 如果标准错误为终端，返回true；否则返回false
AST_UTIL_CAPI bool aStdErrIsTerminal();

/// @brief 检查标准错误是否为文件
/// @return 如果标准错误为文件，返回true；否则返回false
AST_UTIL_CAPI bool aStdErrIsFile();


/*! @} */


AST_NAMESPACE_END
