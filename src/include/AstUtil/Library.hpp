/// @file      Library.hpp
/// @brief     动态库加载类
/// @details   提供 RAII 动态库封装，底层封装 aLoadLibrary / aFreeLibrary / aResolveProcAddress。
/// @author    金柯<jinke18@foxmail.com>
/// @date      30.07.2026

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Platform
    @{
*/

/// @brief 动态库加载类
/// @details 封装动态库的加载、符号解析和卸载，提供 RAII 生命周期管理。
///
/// 使用示例：
/// @code
///   Library lib("myLib");
///   if (lib.load() != eNoError) {
///       return;
///   }
///   auto func = (MyFunc)lib.resolve("myFunction");
///   if (func) {
///       func();
///   }
///   lib.unload();
/// @endcode
class AST_UTIL_API Library
{
public:
    /// @brief 默认构造函数
    Library();

    /// @brief 带文件名的构造函数
    explicit Library(StringView fileName);

    /// @brief 析构函数，自动卸载动态库
    ~Library();

    A_DISABLE_COPY(Library)

    /// @brief 加载动态库
    /// @return eNoError 成功，其他错误码表示失败
    errc_t load();

    /// @brief 卸载动态库
    /// @return eNoError 成功
    errc_t unload();

    /// @brief 判断动态库是否已加载
    bool isLoaded() const { return handle_ != nullptr; }

    /// @brief 解析符号地址
    /// @details 如果库尚未加载，会自动调用 load()
    /// @param symbol 符号名称
    /// @return 函数指针，失败返回 nullptr
    void* resolve(const char* symbol);

    /// @brief 获取文件名
    std::string fileName() const { return fileName_; }

    /// @brief 设置文件名
    /// @details 如果已有已加载的库，会先卸载
    void setFileName(StringView fileName);

    /// @brief 判断文件名是否为有效的库后缀
    static bool IsLibrary(StringView fileName);

    /// @brief 加载库并解析符号
    /// @details 库加载后保持到进程退出
    /// @param fileName 库文件名
    /// @param symbol 符号名称
    /// @return 函数指针，失败返回 nullptr
    static void* Resolve(StringView fileName, const char* symbol);

private:
    void*       handle_{ nullptr };
    std::string fileName_{};
};

/*! @} */

AST_NAMESPACE_END
