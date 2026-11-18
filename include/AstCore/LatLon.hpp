/// @file      LatLon.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-28

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 纬度经度坐标
class LatLon
{
public:
    LatLon() = default;
    LatLon(double lat, double lon) : lat_(lat), lon_(lon) {}

    double latitude() const { return lat_; }
    double longitude() const { return lon_; }
    double& latitude() { return lat_; }
    double& longitude() { return lon_; }
    void setLatitude(double lat) { lat_ = lat; }
    void setLongitude(double lon) { lon_ = lon; }
PROPERTIES:
    angle_d  lat_;  ///< 纬度
    angle_d  lon_;  ///< 经度
};

using LatLng = LatLon;

/*! @} */

AST_NAMESPACE_END
