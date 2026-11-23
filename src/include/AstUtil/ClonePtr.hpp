/// @file      ClonePtr.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-22

#pragma once

#include "AstGlobal.h"
#include "ScopedPtr.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup RTTI
    @{
*/

/// @brief 克隆指针类
/// @details 克隆指针类，用于管理可克隆对象的指针
/// @tparam T 可克隆对象的类型
template<typename T>
class ClonePtr: public ScopedPtr<T>
{
public:
    ClonePtr() = default;
    ClonePtr(const ClonePtr& other)
    {
        if(other.get())
            this->pointer_ = other.get()->clone();
    }
    ClonePtr(ClonePtr&& other)
    {
        this->pointer_ = other.pointer_;
        other.pointer_ = nullptr;
    }
    ClonePtr& operator=(const ClonePtr& other)
    {
        if(other.get())
            this->reset(other.get()->clone());
        else
            this->reset(nullptr);
        return *this;
    }
    ClonePtr& operator=(ClonePtr&& other)
    {
        std::swap(this->pointer_, other.pointer_);
        return *this;
    }
    ClonePtr& operator=(T* ptr)
    {
        this->reset(ptr);
        return *this;
    }
};

/*! @} */

AST_NAMESPACE_END
