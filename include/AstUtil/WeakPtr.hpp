///
/// @file      WeakPtr.hpp
/// @brief     弱引用指针
/// @details   与std::weak_ptr功能类型
/// @author    金柯<jinke18@foxmail.com>
/// @date      19.11.2025

#pragma once
 
#include "AstGlobal.h"
#include "AstUtil/Object.hpp"

AST_NAMESPACE_BEGIN
 

/// @brief 弱引用指针
/// @tparam _Object 指向的对象类型
/// @details   与std::weak_ptr功能类型
/// @ingroup RTTI
template<typename _Object>
class WeakPtr
{
public:
    WeakPtr() noexcept
        :object_{ nullptr }
    {
    }
    WeakPtr(std::nullptr_t) noexcept
        :object_{ nullptr }
    {
    }
    WeakPtr(_Object* obj) noexcept
        :object_{ obj }
    {
        _incWeakRef();
    }
    WeakPtr(const WeakPtr& ptr) noexcept
        :WeakPtr{ ptr.object_ }
    {
    }
    ~WeakPtr() noexcept
    {
        _decWeakRef();
    }
    WeakPtr& operator=(_Object* obj) noexcept
    {
        if (obj != object_) {
            _decWeakRef();
            object_ = obj;
            _incWeakRef();
        }
        return *this;
    }
    WeakPtr& operator=(std::nullptr_t) noexcept
    {
        reset();
        return *this;
    }
    WeakPtr& operator=(const WeakPtr& ptr) noexcept
    {
        if (this != &ptr) {
            this->operator=(ptr.object_);
        }
        return *this;
    }
    _Object* lock() const noexcept
    {
        return get();
    }
    _Object* get() const noexcept
    {
        if (expired()) {
            return nullptr;
        }
        return object_;
    }
    bool expired() const noexcept
    {
        return !object_ || aObject_IsDestructed(object_);
    }
    void reset() noexcept
    {
        _decWeakRef();
        object_ = nullptr;
    }
    _Object* operator->() const noexcept
    {
        return object_;
    }
    // operator _Object*() const
    // {
    //     return get();
    // }
    explicit operator bool() const noexcept
    {
        return !expired();
    }
    bool operator==(const WeakPtr& other) const noexcept
    {
        return object_ == other.object_;
    }
    bool operator!=(const WeakPtr& other) const noexcept
    {
        return object_ != other.object_;
    }
    bool operator<(const WeakPtr& other) const noexcept
    {
        return object_ < other.object_;
    }
private:
    void _incWeakRef() noexcept
    {
        if(object_)
            aObject_IncWeakRef(object_);
    }
    void _decWeakRef() noexcept
    {
        if(object_)
            aObject_DecWeakRef(object_);
    }
protected:
    _Object* object_{nullptr};
};


 
AST_NAMESPACE_END

namespace std
{
    template<typename _Object>
    struct hash<_AST WeakPtr<_Object>>
    {
        size_t operator()(const _AST WeakPtr<_Object>& ptr) const
        {
            return hash<_Object*>()(ptr.get());
        }
    };
}
