/// @file      TrackingCoordinates.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-01

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 测量/跟踪坐标，包含方位角、仰角和距离
class TrackingCoordinates 
{
public:
    /// @brief 获取方位角
    double azimuth() const { return azimuth_; }
    double& azimuth() { return azimuth_; }
    /// @brief 获取仰角
    double elevation() const { return elevation_; }
    double& elevation() { return elevation_; }
    /// @brief 获取距离
    double range() const { return range_; }
    double& range() { return range_; }
    /// @brief 设置方位角
    void setAzimuth(double az) { azimuth_ = az; }
    /// @brief 设置仰角
    void setElevation(double el) { elevation_ = el; }
    /// @brief 设置距离
    void setRange(double r) { range_ = r; }
public:
    double azimuth_;            ///< 方位角
    double elevation_;          ///< 仰角
    double range_;              ///< 距离
};

using AER = TrackingCoordinates; ///< 别名: AER坐标

/*! @} */

AST_NAMESPACE_END

