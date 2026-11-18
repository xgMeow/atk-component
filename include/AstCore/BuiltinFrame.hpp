/// @file      BuiltinFrame.hpp
/// @brief     内置坐标系
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-11

#pragma once

#include "AstGlobal.h"
#include "AstCore/FrameICRF.hpp"
#include "AstCore/FrameRoot.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/


/*
- 这些函数并不是工厂函数，他们所返回的对象示例都是不变的单个实例，
  不会因为DataContext的更改而返回不同实例。
  但是重新加载或者修改线程DataContext的数据后，会影响这些坐标点的计算结果
  也就是说他们依赖于当前线程DataContext的相关数据
*/


/// @brief 地球惯性系
/// @note 坐标系的定义与当前线程的DataContext所加载的数据相关
AST_CORE_CAPI Frame* aFrameECI();

/// @brief 地球ICRF系
/// @note 坐标系的定义与当前线程的DataContext所加载的数据相关
AST_CORE_CAPI Frame* aFrameEarthICRF();

/// @brief 地球J2000系
/// @note 坐标系的定义与当前线程的DataContext所加载的数据相关
AST_CORE_CAPI Frame* aFrameEarthJ2000();

/// @brief 地球ECF系
/// @note 坐标系的定义与当前线程的DataContext所加载的数据相关
AST_CORE_CAPI Frame* aFrameECF();

/// @brief 地球TEME系（真赤道平春分点系）
/// @note SGP4/SDP4 预报器的输出坐标系
AST_CORE_CAPI Frame* aFrameTEME();

/*! @} */

AST_NAMESPACE_END
