///
/// @file      ScopedPtr.hpp
/// @brief     作用域指针
/// @details   指针的生命周期限制在一个作用域内，作用域结束指针析构
/// @author    金柯<jinke18@foxmail.com>
/// @date      19.11.2025

#pragma once
 
#include "AstGlobal.h"
#include <type_traits>    // for std::enable_if
#include <cstdio>

AST_NAMESPACE_BEGIN


template<typename T, typename = void>
struct ScopedPtrDeleter
{
    static void cleanup(T* ptr) noexcept
    {
        delete ptr;
    }
};



template<>
struct ScopedPtrDeleter<std::FILE>
{
    static void cleanup(std::FILE* ptr) noexcept
    {
        fclose(ptr);
    }
};

/// @brief 作用域指针类
/// @details 作用域指针类，用于管理指针的生命周期
/// @tparam T 指针指向的对象类型
/// @warning 作用域指针类的生命周期限制在一个作用域内，作用域结束指针析构
/// @warning 作用域指针类不支持复制构造函数和赋值运算符
/// @ingroup RTTI
template<typename T>
class ScopedPtr
{
public:
    ScopedPtr(T* ptr)
        :pointer_{ ptr }
    { }
    ScopedPtr()
        :pointer_{ nullptr }
    {}
    ScopedPtr(std::nullptr_t)
        :pointer_{ nullptr }
    {
    }
    /// @brief 移动构造函数
    ScopedPtr(ScopedPtr&& other)
        :pointer_{ other.pointer_ }
    {
        other.pointer_ = nullptr;
    }
    /// @brief 移动赋值运算符
    ScopedPtr& operator=(ScopedPtr&& other)
    {
        std::swap(pointer_, other.pointer_);
        return *this;
    }
    ScopedPtr& operator=(T* ptr)
    {
        this->reset(ptr);
        return *this;
    }
    ~ScopedPtr() noexcept
    {
        this->_delete();
    }
    void reset(T* ptr) noexcept
    {
        auto oldPtr = pointer_;
        pointer_ = ptr;
        this->_delete(oldPtr);
    }
    /// @brief 释放所接管对象所有权并置空指针
    void reset() noexcept
    {
        this->reset(nullptr);
    }
    T* get() const noexcept
    {
        return pointer_;
    }
    T* operator->() const noexcept{return pointer_;}
    operator T*() const noexcept{return pointer_;}

    /// @brief 释放绑定：取消对本指针所接管对象的所有权
    /// @details 清空 pointer_ 并返回原始指针，将所有权转移给调用者；并不会销毁对象
    T* release() noexcept
    {
        T* ptr = pointer_;
        pointer_ = nullptr;
        return ptr;
    }
private:
    ScopedPtr(const ScopedPtr&) = delete;
    ScopedPtr& operator =(const ScopedPtr&) = delete;
    void _delete() noexcept
    {
        this->_delete(pointer_);
    }
    void _delete(T* ptr) noexcept
    {
        if(ptr)
            ScopedPtrDeleter<T>::cleanup(ptr);
    }
protected:
    T* pointer_{nullptr};
};
 
AST_NAMESPACE_END
 
