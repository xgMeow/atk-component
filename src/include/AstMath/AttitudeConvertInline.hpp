/// @file      AttitudeConvertInline.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-05

#pragma once

#include "AstGlobal.h"
#include "AttitudeConvertProto.hpp"
#include "AstMath/Quaternion.hpp"
#include "AstMath/Matrix.hpp"
#include "AstMath/Euler.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/


/// @brief 矩阵转四元数
/// @param mtx 旋转矩阵
/// @return 四元数
A_ALWAYS_INLINE	Quaternion aMatrixToQuat(const Matrix3d& mtx)
{
	Quaternion q;
	aMatrixToQuat(mtx, q);
	return q;
}


A_ALWAYS_INLINE	Matrix3d aEuler323ToMatrix(const Euler& euler)
{
	Matrix3d mtx;
	aEuler323ToMatrix(euler, mtx);
	return mtx;
}


A_ALWAYS_INLINE	Matrix3d aEuler313ToMatrix(const Euler& euler)
{
	Matrix3d mtx;
	aEuler313ToMatrix(euler, mtx);
	return mtx;
}

A_ALWAYS_INLINE	Matrix3d aRotationZMatrix(double angle)
{
	Matrix3d mtx;
	aRotationZMatrix(angle, mtx);
	return mtx;
}

A_ALWAYS_INLINE	Matrix3d aRotationXMatrix(double angle)
{
	Matrix3d mtx;
	aRotationXMatrix(angle, mtx);
	return mtx;
}


/*! @} */

AST_NAMESPACE_END
