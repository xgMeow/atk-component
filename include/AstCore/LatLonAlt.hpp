/// @file      LatLonAlt.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-12

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


/// @brief 纬度、经度、高度坐标
class LatLonAlt
{
public:
    /// @brief 获取纬度
    double latitude() const { return lat_; }
    /// @brief 获取经度
    double longitude() const { return lon_; }
    /// @brief 获取高度
    double altitude() const { return alt_; }
    /// @brief 设置纬度
    double& latitude() { return lat_; }
    /// @brief 设置经度
    double& longitude() { return lon_; }
    /// @brief 设置高度
    double& altitude() { return alt_; }
    /// @brief 设置纬度
    void setLatitude(double lat) { lat_ = lat; }
    /// @brief 设置经度
    void setLongitude(double lon) { lon_ = lon; }
    /// @brief 设置高度
    void setAltitude(double alt) { alt_ = alt; }

PROPERTIES:
    angle_d  lat_;  ///< 纬度
    angle_d  lon_;  ///< 经度
    length_d alt_;  ///< 高度
};

using LatLngAlt = LatLonAlt;
using LLA = LatLonAlt;

AST_NAMESPACE_END
