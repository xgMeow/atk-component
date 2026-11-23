/// @file      GeodeticPoint.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-12

#pragma once

#include "AstGlobal.h"
#include "GeoCoordinate.hpp"

AST_NAMESPACE_BEGIN


/// @brief 大地坐标
/// @details 大地坐标是指以天体表面为参考椭球，以大地纬度、经度、高度为坐标的坐标系统。
/// 大地坐标的纬度是地表某点的法线（垂直于地球表面）与赤道平面的夹角
class GeodeticPoint: public GeoCoordinate
{
public:
    using GeoCoordinate::GeoCoordinate;

};

AST_NAMESPACE_END
