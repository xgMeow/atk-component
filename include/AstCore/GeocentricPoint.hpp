/// @file      GeocentricPoint.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-12

#pragma once

#include "AstGlobal.h"
#include "GeoCoordinate.hpp"

AST_NAMESPACE_BEGIN


/// @brief 地心坐标
/// @details 地心坐标是指以天体中心为原点，以天体中心到空间中任意点的连线为坐标轴的坐标系统。
/// 地心坐标的纬度是从地表点到天体质心的连线与赤道平面的夹角
class GeocentricPoint: public GeoCoordinate
{
public:
    using GeoCoordinate::GeoCoordinate;
};



AST_NAMESPACE_END
