/// @file      AxesProxy.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 轴系代理类
/// @details 将轴系接口原样转发给被代理的轴对象，自身不产生任何计算。
class AST_CORE_API AxesProxy final: public Axes
{
public:
    AxesProxy() = default;
    explicit AxesProxy(Axes* axes):impl_(axes){}
    ~AxesProxy() override = default;

public:
    void setImpl(Axes* impl){impl_ = impl;}
    Axes* impl() const {return impl_.get();}
public:
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, AccelerationRotation& rotation) const override;
private:
    WeakPtr<Axes> impl_{};
};




/*! @} */

AST_NAMESPACE_END
