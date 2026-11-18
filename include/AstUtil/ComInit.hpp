/// @file      ComInit.hpp
/// @brief     COM 初始化工具
/// @details   提供 RAII 风格的 COM 初始化和释放守卫，以及线程局部 COM 初始化函数。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstGlobal.h"

#if defined(_WIN32) && !defined(SWIG)
#include <Windows.h>
#endif

AST_NAMESPACE_BEGIN

#if defined(_WIN32) && !defined(SWIG)

/// COM 初始化和释放守卫
/// @details RAII 风格，构造时调用 CoInitializeEx，析构时调用 CoUninitialize
class CoInitializeGuard
{
public:
    explicit CoInitializeGuard(COINIT initFlags) : hr_(CoInitializeEx(nullptr, initFlags)) {}
    ~CoInitializeGuard() { if (SUCCEEDED(hr_)) CoUninitialize(); }
    CoInitializeGuard(const CoInitializeGuard&) = delete;
    CoInitializeGuard& operator=(const CoInitializeGuard&) = delete;
    HRESULT hr_{};
};

/// 确保当前线程 COM 已初始化
/// @details 使用 thread_local 静态守卫，每个线程仅初始化一次（STA 模式）
/// @return S_OK 表示成功，否则返回失败 HRESULT
AST_UTIL_API HRESULT aEnsureCoInitialized();

#else

// 非 Windows 平台：空实现
class CoInitializeGuard
{
public:
    explicit CoInitializeGuard(int) {}
    int hr_ = 0;
};

A_ALWAYS_INLINE int aEnsureCoInitialized() { return 0; }

#endif

AST_NAMESPACE_END
