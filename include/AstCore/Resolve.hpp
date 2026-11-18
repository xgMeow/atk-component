/// @file      Resolve.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-17

#pragma once

#include "AstGlobal.h"
#include "AstUtil/RTTIAPI.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 获取对象的坐标系
/// @param obj 对象指针
/// @param frameName 坐标系名称
/// @return 坐标系指针
/// @note 如果坐标系不存在，返回 nullptr
AST_CORE_API Frame* aObject_GetFrame(Object* obj, StringView frameName);

#if 0 // 移动到 AstUtil 工程

/// @brief 解析对象
/// @param value 对象路径/名称/表达式
/// @param type 对象类型，默认 nullptr 表示不指定类型
/// @return 对象指针
/// @note 如果对象不存在，返回 nullptr
AST_CORE_API Object* aResolveObject(StringView value, Class* type=nullptr);

#endif

/// @brief 解析天体
/// @param name 天体名称
/// @return 天体指针
/// @note 如果天体不存在，返回 nullptr
AST_CORE_API Body* aResolveBody(StringView name);


/// @brief 解析坐标系
/// @param name 坐标系名称
/// @return 坐标系指针
/// @note 如果坐标系不存在，返回 nullptr
AST_CORE_API Frame* aResolveFrame(StringView name);


/// @brief 解析坐标轴
/// @param name 坐标轴名称
/// @return 坐标轴指针
/// @note 如果坐标轴不存在，返回 nullptr
AST_CORE_API Axes* aResolveAxes(StringView name);


/// @brief 解析点
/// @param name 点名称
/// @return 点指针
/// @note 如果点不存在，返回 nullptr
AST_CORE_API Point* aResolvePoint(StringView name);

#ifndef SWIG

inline Point* operator ""_point(const char* str, size_t len)
{
    return aResolvePoint(StringView(str, len));
}

inline Body* operator ""_body(const char* str, size_t len)
{
    return aResolveBody(StringView(str, len));
}


inline Frame* operator ""_frame(const char* str, size_t len)
{
    return aResolveFrame(StringView(str, len));
}

inline Axes* operator ""_axes(const char* str, size_t len)
{
    return aResolveAxes(StringView(str, len));
}

inline Object* operator ""_object(const char* str, size_t len)
{
    return aResolveObject(StringView(str, len));
}
#endif


/*! @} */

AST_NAMESPACE_END
