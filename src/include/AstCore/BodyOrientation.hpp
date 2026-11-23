/// @file      PlanetOrientation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/

class Rotation;
class KinematicRotation;

/// @brief 天体姿态/指向
class AST_CORE_API BodyOrientation: public ObjectNamed
{
public:
    AST_OBJECT(BodyOrientation)
    BodyOrientation() = default;


    virtual ~BodyOrientation() = default;


    /// @brief 获取ICRF到天体固连系的旋转变换
    /// @param tp 时间点
    /// @param rotation 旋转变换
    virtual void getICRFToFixedTransform(const TimePoint& tp, Rotation &rotation) const = 0;


    /// @brief 获取ICRF到天体固连系的旋转变换
    /// @param tp 时间点
    /// @param rotation 旋转变换
    virtual void getICRFToFixedTransform(const TimePoint& tp, KinematicRotation &rotation) const = 0;


    /// @brief 获取ICRF到天体惯性系的旋转变换
    /// @param tp 时间点
    /// @param rotation 旋转变换
    virtual void getICRFToInertialTransform(const TimePoint& tp, Rotation &rotation) const = 0;


    /// @brief 获取MOD系的父系
    /// @return Axes* 内置轴系
    virtual Axes* getMODParent() const = 0;


    /// @brief 获取MOD系的旋转变换
    /// @param tp 时间点
    /// @param rot 旋转变换
    virtual void getMODTransform(const TimePoint& tp, Rotation &rot) const = 0;


    /// @brief 获取TOD系的父系
    /// @return Axes* 内置轴系
    virtual Axes* getTODParent() const = 0;


    /// @brief 获取TOD系的旋转变换
    /// @param tp 时间点
    /// @param rot 旋转变换
    virtual void getTODTransform(const TimePoint& tp, Rotation &rot) const = 0;

};

/*! @} */

AST_NAMESPACE_END
