/// @file      ReflectAPI.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-29

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ReflectAPI.hpp"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 创建一个时间点属性
/// @warning 本函数为内部函数，不建议直接调用。
/// @param getter 获取属性值的函数指针
/// @param setter 设置属性值的函数指针
/// @return Property* 属性指针
AST_CORE_CAPI Property* _aNewPropertyTimePoint(FPropertyGet getter, FPropertySet setter);


#ifndef SWIG

/// @brief 创建一个时间点属性
/// @warning 本函数为内部函数，不建议直接调用。
/// @param getter 获取属性值的函数指针
/// @param setter 设置属性值的函数指针
/// @return Property* 属性指针
template<>
A_ALWAYS_INLINE Property* _aNewProperty<TimePoint>(FPropertyGet getter, FPropertySet setter)
{
    return _aNewPropertyTimePoint(getter, setter);
}




template<typename T, TimePoint T::* Member>
A_ALWAYS_INLINE Property* aNewPropertyTimePointMem()
{
    return _aNewPropertyTimePoint(
        [](const void* obj, void* value) -> errc_t
        {
            *((TimePoint*)value) = ((T*)obj)->*Member;
            return 0;
        },
        [](void* obj, const void* value) -> errc_t
        {
            ((T*)obj)->*Member = *((TimePoint*)value);
            return 0;
        }
    );
}


template<typename T, TimePoint T::* Member>
A_ALWAYS_INLINE Property* aNewPropertyTimePoint()
{
    return aNewPropertyTimePointMem<T, Member>();
}



/// @brief 创建一个时间点属性
/// @details 本函数创建一个时间点属性，属性值通过调用对象的成员函数获取。
/// @tparam T 类类型
/// @tparam Getter 时间点属性获取函数指针
/// @return Property* 属性指针
template<typename T, TimePoint(T::*Getter)() const>
A_ALWAYS_INLINE Property* aNewPropertyTimePoint()
{
    return _aNewPropertyTimePoint(
        [](const void* obj, void* value) -> errc_t
        {
            *((TimePoint*)value) = (((T*)obj)->*Getter)();
            return 0;
        },
        nullptr
    );
}


/// @brief 创建一个时间点属性
/// @details 本函数创建一个时间点属性，属性值通过调用对象的成员函数获取和设置。
/// @tparam T 类类型
/// @tparam Getter 时间点属性获取函数指针
/// @tparam Setter 时间点属性设置函数指针
/// @return Property* 属性指针
template<typename T, TimePoint(T::*Getter)() const, void (T::*Setter)(TimePoint)>
A_ALWAYS_INLINE Property* aNewPropertyTimePoint()
{
    A_STATIC_ASSERT_CXX14(Getter!=nullptr, "invalid getter");
    A_STATIC_ASSERT_CXX14(Setter!=nullptr, "invalid setter");

    return _aNewPropertyTimePoint(
        [](const void* obj, void* value) -> errc_t
        {
            *((TimePoint*)value) = (((T*)obj)->*Getter)();
            return 0;
        },
        [](void* obj, const void* value) -> errc_t
        {
            (((T*)obj)->*Setter)(*((TimePoint*)value));
            return 0;
        }
    );
}


/// @brief 创建一个时间点属性
/// @details 本函数创建一个时间点属性，属性值通过调用对象的成员函数获取和设置，支持错误返回值。
/// @tparam T 类类型
/// @tparam Getter 时间点属性获取函数指针
/// @tparam Setter 时间点属性设置函数指针（带错误返回值）
/// @return Property* 属性指针
template<typename T, TimePoint(T::*Getter)() const, errc_t (T::*Setter)(TimePoint)>
A_ALWAYS_INLINE Property* aNewPropertyTimePoint()
{
    A_STATIC_ASSERT_CXX14(Getter!=nullptr, "invalid getter");
    A_STATIC_ASSERT_CXX14(Setter!=nullptr, "invalid setter");

    return _aNewPropertyTimePoint(
        [](const void* obj, void* value) -> errc_t
        {
            *((TimePoint*)value) = (((T*)obj)->*Getter)();
            return 0;
        },
        [](void* obj, const void* value) -> errc_t
        {
            return (((T*)obj)->*Setter)(*((TimePoint*)value));
        }
    );
}


/// @brief 创建一个时间点属性
/// @details 本函数创建一个时间点属性，属性值通过调用对象的成员函数获取和设置，支持引用参数的 getter。
/// @tparam T 类类型
/// @tparam Getter 时间点属性获取函数指针（接受引用参数）
/// @tparam Setter 时间点属性设置函数指针
/// @return Property* 属性指针
template<typename T, errc_t (T::*Getter)(TimePoint&) const, void (T::*Setter)(const TimePoint&)>
A_ALWAYS_INLINE Property* aNewPropertyTimePoint()
{
    A_STATIC_ASSERT_CXX14(Getter!=nullptr, "invalid getter");
    A_STATIC_ASSERT_CXX14(Setter!=nullptr, "invalid setter");

    return _aNewPropertyTimePoint(
        [](const void* obj, void* value) -> errc_t
        {
            TimePoint time;
            errc_t result = (static_cast<const T*>(obj)->*Getter)(time);
            if (result == 0) {
                *static_cast<TimePoint*>(value) = time;
            }
            return result;
        },
        [](void* obj, const void* value) -> errc_t
        {
            (static_cast<T*>(obj)->*Setter)(*static_cast<const TimePoint*>(value));
            return 0;
        }
    );
}


template<typename T, const TimePoint& (T::* Getter) () const, void (T::* Setter)(const TimePoint&)>
A_ALWAYS_INLINE Property* aNewPropertyTimePoint()
{
    A_STATIC_ASSERT_CXX14(Getter!=nullptr, "invalid getter");
    A_STATIC_ASSERT_CXX14(Setter!=nullptr, "invalid setter");

    return _aNewPropertyTimePoint(
        [](const void* obj, void* value) -> errc_t
    {
        *((TimePoint*)value) = (((T*)obj)->*Getter)();
        return 0;
    },
        [](void* obj, const void* value) -> errc_t
    {
        (((T*)obj)->*Setter)(*((TimePoint*)value));
        return 0;
    }
    );
}


template<typename T, const TimePoint& (T::* Getter) () const, errc_t (T::* Setter)(const TimePoint& value)>
A_ALWAYS_INLINE Property* aNewPropertyTimePoint()
{
    A_STATIC_ASSERT_CXX14(Getter!=nullptr, "invalid getter");
    A_STATIC_ASSERT_CXX14(Setter!=nullptr, "invalid setter");

    return _aNewPropertyTimePoint(
        [](const void* obj, void* value) -> errc_t
    {
        *((TimePoint*)value) = (((T*)obj)->*Getter)();
        return 0;
    },
        [](void* obj, const void* value) -> errc_t
    {
        return (((T*)obj)->*Setter)(*((TimePoint*)value));
    }
    );
}

#endif

/*! @} */

AST_NAMESPACE_END