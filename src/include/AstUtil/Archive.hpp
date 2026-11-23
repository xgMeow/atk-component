/// @file      Archive.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-31

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Attribute.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 名值对
/// @tparam T 值类型
template<typename T>
class NameValuePair
{
public:
    const char* name() const { return name_; }
    T& value() const { return value_; }

    const char* name_;
    T& value_;
};

/// @brief 创建名值对
/// @param name 名称
/// @param val 值
/// @return NameValuePair<T> 名值对
template<typename T>
NameValuePair<T> make_nvp(const char* name, T& val)
{
    return NameValuePair<T>{name, val};
}


/// @brief 归档基类，实现对象的序列化和反序列化等操作
class AST_UTIL_API Archive
{
public:
    Archive() = default;
    virtual ~Archive() = default;
    virtual Archive& operator()(bool& val, const char* name=nullptr) = 0;
    virtual Archive& operator()(int& val, const char* name=nullptr) = 0;
    virtual Archive& operator()(double& val, const char* name=nullptr) = 0;
    virtual Archive& operator()(std::string& val, const char* name=nullptr) = 0;
    virtual Archive& operator()(Attribute& attr) {return *this;};
public:
    A_ALWAYS_INLINE Archive& operator&(bool& val) { return operator()(val); }
    A_ALWAYS_INLINE Archive& operator&(int& val) { return operator()(val); }
    A_ALWAYS_INLINE Archive& operator&(double& val) { return operator()(val); }
    A_ALWAYS_INLINE Archive& operator&(std::string& val) { return operator()(val); }
    A_ALWAYS_INLINE Archive& operator&(Attribute& attr) { return operator()(attr); }

    A_ALWAYS_INLINE Archive& operator&(const NameValuePair<bool>& nvp) { return operator()(nvp.value(), nvp.name()); }
    A_ALWAYS_INLINE Archive& operator&(const NameValuePair<int>& nvp) { return operator()(nvp.value(), nvp.name()); }
    A_ALWAYS_INLINE Archive& operator&(const NameValuePair<double>& nvp) { return operator()(nvp.value(), nvp.name()); }
    A_ALWAYS_INLINE Archive& operator&(const NameValuePair<std::string>& nvp) { return operator()(nvp.value(), nvp.name()); }
};

/*! @} */

AST_NAMESPACE_END
