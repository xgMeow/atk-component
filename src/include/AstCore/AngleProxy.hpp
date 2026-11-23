/// @file      AngleProxy.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "AstCore/Angle.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/

/// @brief 角度代理类
/// @details 将角度接口原样转发给被代理的角度对象，自身不产生任何计算。
class AST_CORE_API AngleProxy final: public Angle
{
public:
    AngleProxy() = default;
    explicit AngleProxy(Angle* angle):impl_(angle){}
    ~AngleProxy() override = default;

public:
    void setImpl(Angle* impl){impl_ = impl;}
    Angle* impl() const {return impl_.get();}
public:
    errc_t getAngle(const TimePoint& tp, double& value) const override;
    errc_t getAngle(const TimePoint& tp, double& value, double& angVel) const override;
private:
    WeakPtr<Angle> impl_{};
};




/*! @} */

AST_NAMESPACE_END
