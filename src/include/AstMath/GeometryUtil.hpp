/// @file      GeometryUtil.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-03

#pragma once

#include "AstGlobal.h"
#include "AstMath/Vector.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/


/// @brief     计算两个向量的叉积及其时间导数
/// @details   对两个随时间变化的向量求叉积，并按乘积法则同时给出叉积的时间导数：
///            `result = vector1 × vector2`
///            `resultVelocity = velocity1 × vector2 + vector1 × velocity2`
///            其中 velocity1、velocity2 分别为 vector1、vector2 的时间导数。
/// @param     vector1        第一个向量
/// @param     velocity1      第一个向量的时间导数
/// @param     vector2        第二个向量
/// @param     velocity2      第二个向量的时间导数
/// @param     result         输出：两个向量的叉积 `vector1 × vector2`
/// @param     resultVelocity 输出：叉积的时间导数 `velocity1 × vector2 + vector1 × velocity2`
/// @note      两个速度可传零向量，此时退化为只求叉积
AST_MATH_API void aVectorCross(
    const Vector3d& vector1, const Vector3d& velocity1,
    const Vector3d& vector2, const Vector3d& velocity2,
    Vector3d& result, Vector3d& resultVelocity
);


/*! @} */

AST_NAMESPACE_END
