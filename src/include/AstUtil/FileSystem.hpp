/// @file      FileSystem.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      23.11.2025

#pragma once

#include "AstGlobal.h"
#include "FileSystemSimple.hpp"
#include <string>

// 是否允许使用 std::experimental::filesystem 的c++实验特性，如果存在的话
// #define AST_USE_STD_FILESYSTEM_EXPERIMENTAL

// 判断 c++ 标准库是否有std::filesystem
#ifdef __cpp_lib_filesystem
#   include <filesystem>
#   define _A_STD_FILESYSTEM std::filesystem
#elif defined(__cplusplus) && __cplusplus >= 201703L
#   include <filesystem>
#   define _A_STD_FILESYSTEM std::filesystem
#elif defined AST_USE_STD_FILESYSTEM_EXPERIMENTAL
#   define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#   if defined _MSC_VER
#      include <experimental/filesystem>
#      define _A_STD_FILESYSTEM std::experimental::filesystem
#   elif defined(__has_include) && __has_include(<experimental/filesystem>) && defined AST_USE_STD_FILESYSTEM_EXPERIMENTAL
#      include <experimental/filesystem>
#      define _A_STD_FILESYSTEM std::experimental::filesystem
#   endif
#else
#   undef _A_STD_FILESYSTEM
#endif


AST_NAMESPACE_BEGIN


/*!
    @addtogroup Platform
    @{
*/


// 如果 c++ 标准库没有 filesystem功能，则切换到ast项目对filesystem功能的简化实现
#if defined(_A_STD_FILESYSTEM) && defined(AST_USE_STD_FILESYSTEM)
// #pragma message("use std::filesystem")
namespace filesystem = _A_STD_FILESYSTEM;
#else
// #pragma message("use ast simple_fs")
namespace filesystem = fs_simple;
#endif

namespace fs = filesystem;


/// @brief 获取函数、变量所在模块的路径
/// @param addr 函数地址/变量地址
/// @return std::string 模块路径
AST_UTIL_API std::string aGetModulePathFromAddress(void* addr);

/// @brief 获取当前的AstUtil动态库所在目录
/// @return 
AST_UTIL_API std::string aLibDir();


/// @brief 获取当前的可执行文件所在目录
/// @return 
AST_UTIL_API std::string aExeDir();


/// @brief 获取当前的AstUtil动态库的名称
/// @return 
AST_UTIL_API std::string aLibPath();


/// @brief 获取当前的可执行文件路径
/// @return 
AST_UTIL_API std::string aExePath();



/*! @} */


AST_NAMESPACE_END

