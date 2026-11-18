/// @file      posix.hpp
/// @brief     posix 相关函数
/// @details   可移植操作系统接口(Portable Operating System Interface)
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-01

#pragma once

#include "AstGlobal.h"
#include "AstUtil/IO.hpp"               // for functions such as printf, fopen
#include "AstUtil/StringPosix.hpp"      // for functions such as strcasecmp, strncasecmp

#include <cstdlib>                      // for std::getenv
#include <cstdio>                       // for FILE
#include <cstring>

#ifdef _WIN32
#include <sys/types.h>          
#include <fcntl.h>              
#include <io.h>                         // for _isatty, _fileno
#include <sys/stat.h>                   // for fstat
#include <direct.h>                     // for _rmdir
#else
#include <unistd.h>                     // for isatty, fileno, rmdir
#include <sys/stat.h>                   // for fstat
#endif

AST_NAMESPACE_BEGIN


/// @brief posix 函数
/// @details  该命名空间包含了可移植操作系统接口(posix)所定义的函数，
///           并屏蔽了不同操作系统之间的差异。
/// @ingroup Platform
namespace posix
{
#if defined(_WIN32) || defined(AST_PARSED_BY_DOXYGEN)
    // typedef struct _stat stat;
    using stat = struct ::_stat;

    /// @brief 获取文件流的文件描述符
    /// @param file 文件流指针
    /// @return 文件描述符
    A_ALWAYS_INLINE
    int fileno(FILE* file)
    {
        return ::_fileno(file);
    }

    /// @brief 删除目录
    /// @param path 目录路径
    /// @return 如果成功则返回0，否则返回-1
    AST_UTIL_API
    int rmdir(const char* path);

    /// @brief 判断文件描述符是否为终端
    /// @param fd 文件描述符
    /// @return 如果是终端则返回非0值，否则返回0
    A_ALWAYS_INLINE
    int isatty(int fd)
    {
        return ::_isatty(fd);
    }

    /// @brief 获取文件状态
    /// @param fd 文件描述符
    /// @param buf 指向stat结构体的指针
    /// @return 如果成功则返回0，否则返回-1
    A_ALWAYS_INLINE
    int fstat(int fd, stat* buf)
    {
        return ::_fstat(fd, buf);
    }

    /// @brief 改变当前工作目录
    /// @param path 目录路径
    /// @return 如果成功则返回0，否则返回-1
    AST_UTIL_API
    int chdir(const char* path);

    /// @brief 获取当前工作目录
    /// @param buf 指向字符数组的指针，用于存储当前工作目录的路径
    /// @param size buf数组的大小
    /// @return 如果成功则返回buf，否则返回nullptr
    AST_UTIL_API
    char* getcwd(char* buf, size_t size);

    using ::fdopen;
    using ::read;
    using ::write;
    using ::close;
    using ::abort;
#else
    using ::stat;
    using ::fileno;
    using ::rmdir;
    using ::isatty;
    using ::fstat;
    using ::chdir;
    using ::getcwd;
    using ::fdopen;
    using ::read;
    using ::write;
    using ::close;
    using ::abort;

#endif

#if defined(__BORLANDC__) || defined(__SunOS_5_8) || defined(__SunOS_5_9)
    /// @brief 获取环境变量的值
    /// @param name 环境变量名
    /// @return 环境变量的值，如果不存在则返回nullptr
    A_ALWAYS_INLINE
    const char* getenv(const char* name){
        const char* const env = std::getenv(name);
        return (env != nullptr && env[0] != '\0') ? env : nullptr;
    }
#else
    using std::getenv;
#endif


}
AST_NAMESPACE_END
