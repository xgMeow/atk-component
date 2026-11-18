/// @file      MathDegree.hpp
/// @brief     角度量相关函数
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-27

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Constants.hpp"
#include <cmath>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Util
    @{
*/

/// @brief 将弧度转换为角度
/// @param x 输入弧度
/// @return 转换后的角度值
A_ALWAYS_INLINE double rad2deg(double x)
{
    return x * kRadToDeg;
}

/// @brief 将角度转换为弧度
/// @param x 输入角度
/// @return 转换后的弧度值
A_ALWAYS_INLINE double deg2rad(double x)
{
    return x * kDegToRad;
}


/// @brief 计算正弦值(以度为单位)
/// @param x 角度(以度为单位)
/// @return 正弦值
A_ALWAYS_INLINE double sind(double x)
{
    return sin(deg2rad(x));
}

/// @brief 计算余弦值(以度为单位)
/// @param x 角度(以度为单位)
/// @return 余弦值
A_ALWAYS_INLINE double cosd(double x)
{
    return cos(deg2rad(x));
}

/// @brief 计算正切值(以度为单位)
/// @param x 角度(以度为单位)
/// @return 正切值
A_ALWAYS_INLINE double tand(double x)
{
    return tan(deg2rad(x));
}


/// @brief 计算反正弦(以度为单位)
/// @param x 正弦值(范围[-1, 1])
/// @return 角度(以度为单位)
A_ALWAYS_INLINE double asind(double x)
{
    return rad2deg(asin(x));
}


/// @brief 计算反余弦(以度为单位)
/// @param x 余弦值(范围[-1, 1])
/// @return 角度(以度为单位)
A_ALWAYS_INLINE double acosd(double x)
{
    return rad2deg(acos(x));
}


/// @brief 计算反正切(以度为单位)
/// @param x 正切值
/// @return 角度(以度为单位)
A_ALWAYS_INLINE double atand(double x)
{
    return rad2deg(atan(x));
}


/// @brief 计算四象限反正切(以度为单位)
/// @param y 垂直坐标
/// @param x 水平坐标
/// @return 角度(以度为单位)
A_ALWAYS_INLINE double atan2d(double y, double x)
{
    return rad2deg(atan2(y, x));
}



/*! @} */

AST_NAMESPACE_END
