/// @file      BodyEphemeris.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/

/// @brief 天体星历接口
/// @details 在星历接口的基础上增加对ICRF坐标系下的位置和速度的直接获取
/// @todo 但是对于行星卫星，他们的星历是相对于行星系的，例如月球
///       此时 `getPosVelICRF` 接口会产生数值截断误差，需要考虑如何处理
class AST_CORE_API BodyEphemeris: public Ephemeris
{
public:
    BodyEphemeris() = default;

    virtual ~BodyEphemeris() = default;

    /// @brief 获取天体在ICRF坐标系下的位置
    /// @param tp 时间点
    /// @param pos 输出位置
    /// @return errc_t 错误码
    virtual errc_t getPosICRF(const TimePoint& tp, Vector3d& pos) const = 0;

    /// @brief 获取天体在ICRF坐标系下的位置和速度
    /// @param tp 时间点
    /// @param pos 输出位置
    /// @param vel 输出速度
    /// @return errc_t 错误码
    virtual errc_t getPosVelICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const = 0;
public:
    virtual Frame* getFrame() const override;
    virtual errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    virtual errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
    virtual errc_t getInterval(TimeInterval& interval) const override = 0;
};


/*! @} */

AST_NAMESPACE_END
