/// @file      Angle.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-09

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/

/// @brief 角度抽象基类
/// @details 角度是一种几何元素，表示一个随时间变化的角度量。
///          所有具体角度类型（如常量角度、计算角度等）均派生自此类。
///          角度值以弧度为单位。
class AST_CORE_API Angle : public ObjectNamed
{
public:
    AST_OBJECT(Angle)

    Angle() = default;
    ~Angle() override = default;

    /// @brief 获取指定时间点的角度值
    /// @param tp 时间点
    /// @param value 输出参数，角度值（弧度）
    /// @return 错误码
    virtual errc_t getAngle(const TimePoint& tp, double& value) const = 0;

    /// @brief 获取指定时间点的角度值和角速度
    /// @param tp 时间点
    /// @param value 输出参数，角度值（弧度）
    /// @param angVel 输出参数，角速度（弧度/秒）
    /// @return 错误码
    virtual errc_t getAngle(const TimePoint& tp, double& value, double& angVel) const = 0;

    /// @brief 获取指定时间点的角度值
    /// @param tp 时间点
    /// @return 角度值（弧度），出错时返回 0.0
    double getAngle(const TimePoint& tp) const;
};

using PAngle = Angle*;                ///< 角度指针(pointer to angle)
using HAngle = SharedPtr<Angle>;      ///< 角度句柄(handle to angle)

/*! @} */

AST_NAMESPACE_END
