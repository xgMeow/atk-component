/// @file      COMUtil.hpp
/// @brief     COM 工具
/// @details   
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



/// COM 接口指针的 RAII 包装
/// @details 只负责持有一个已经带有引用的接口指针（如 QueryInterface、CoCreateInstance 的返回值），
///          在析构和 reset 时自动 Release。此类不做 AddRef，复制被禁用，转移所有权请用移动
template <typename T>
class ComScopedPtr
{
public:
    ComScopedPtr() = default;
    ComScopedPtr(const ComScopedPtr&) = delete;
    ComScopedPtr& operator=(const ComScopedPtr&) = delete;
    ComScopedPtr(ComScopedPtr&& other) noexcept : p_(other.p_) { other.p_ = nullptr; }
    ComScopedPtr& operator=(ComScopedPtr&& other) noexcept{std::swap(p_, other.p_); return *this;}
    ~ComScopedPtr() { reset(); }

    /// @brief 获取裸指针
    T* get() const { return p_; }
    T* operator->() const { return p_; }
    T& operator*() const { return *p_; }

    /// @brief 获取用于接收输出参数的地址，配合 IID_PPV_ARGS 使用
    /// @warning 要求当前未持有对象，否则原对象不会被 Release，造成引用泄漏
    T** operator&() { return &p_; }

    /// @brief 释放当前持有的对象
    void reset() { if (p_) p_->Release(); p_ = nullptr; }

    operator bool() const { return p_ != nullptr; }
private:
    T* p_{nullptr};
};

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
