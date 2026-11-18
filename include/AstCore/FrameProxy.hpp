/// @file      FrameProxy.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "AstCore/Frame.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/

/// @brief 坐标系代理类
/// @details 将坐标系接口原样转发给被代理的坐标系对象，自身不产生任何计算。
class AST_CORE_API FrameProxy final: public Frame
{
public:
    FrameProxy() = default;
    explicit FrameProxy(Frame* frame):impl_(frame){}
    ~FrameProxy() override = default;

public:
    void setImpl(Frame* impl){impl_ = impl;}
    Frame* impl() const {return impl_.get();}
public:
    std::string getRepresentation() const override;
    Frame* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Transform& transform) const override;
    errc_t getTransform(const TimePoint& tp, KinematicTransform& transform) const override;
    errc_t getTransform(const TimePoint& tp, AccelerationTransform& transform) const override;
    Axes* getAxes() const override;
    Point* getOrigin() const override;
private:
    WeakPtr<Frame> impl_{};
};




/*! @} */

AST_NAMESPACE_END
