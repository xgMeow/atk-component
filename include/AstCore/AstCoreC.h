/// @file      AstCoreC.h
/// @brief     AstCore的C语言接口，确保与C++的实现二进制兼容
/// @details   因为CAPI使用较少，该文件不会包含所有功能，只会按需增加
/// @author    金柯<jinke18@foxmail.com>
/// @date      15.11.2025

#pragma once

#include "AstGlobal.h"

#if !defined __cplusplus

typedef struct AVector3d
{
	double x_, y_, z_;
} AVector3d;

typedef struct AMatrix3d
{
	double data_[3][3];
} AMatrix3d;

#endif

#if !defined(AST_BUILD_LIB) && defined(AST_ENABLE_CAPI)  // 避免报错：conflicting C language linkage declaration

AST_CORE_CAPI int aTwoBodyProp(double dt, double gm, AVector3d* pos, AVector3d* vel);

#endif