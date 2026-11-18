/// @file      PosixExt.hpp
/// @brief     扩展Posix接口
/// @details   本文件包含了一些扩展Posix接口的函数，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-19

#pragma once

#include "AstGlobal.h"
#include "Posix.hpp"
#include <string>
#include <limits>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Platform
    @{
*/

namespace posix
{
#if defined(PATH_MAX)
constexpr size_t kMaxPath = PATH_MAX;
#elif defined (MAX_PATH)
constexpr size_t kMaxPath = MAX_PATH;
#elif defined(_MAX_PATH)
constexpr size_t kMaxPath = _MAX_PATH;
#elif defined(_POSIX_PATH_MAX)
constexpr size_t kMaxPath = _POSIX_PATH_MAX;
#else
constexpr size_t kMaxPath = 255; // default max path length
#endif

    /// @brief 获取当前工作目录
    /// @return 当前工作目录的路径
    A_ALWAYS_INLINE std::string getcwd()
    {
        char buffer[kMaxPath];
        if (posix::getcwd(buffer, sizeof(buffer)) != nullptr) {
            return buffer;
        }
        return std::string();
    }
#if defined(_WIN32) || defined(AST_PARSED_BY_DOXYGEN)
    /// @brief 检查文件状态是否为目录
    /// @param st 文件状态结构体
    /// @return 如果是目录则返回true，否则返回false
    A_ALWAYS_INLINE
    bool isdir(const stat& st)
    {
        return (_S_IFDIR & st.st_mode) != 0;
    }
#else
    A_ALWAYS_INLINE
    bool isdir(const struct stat& st)
    {
        return S_ISDIR(st.st_mode);
    }
#endif
}

/*! @} */

AST_NAMESPACE_END
