/// @file      FrameAssembly.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-11

#pragma once

#include "AstGlobal.h"
#include "AstCore/Frame.hpp"
#include "AstCore/Axes.hpp"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

class FrameAssembly;
using HFrameAssembly = SharedPtr<FrameAssembly>;
using PFrameAssembly = FrameAssembly*;

/// @brief 组装坐标系
/// @details 组装坐标系由轴系和原点组成
/// 可以通过轴系和原点的灵活组合定义坐标系
class AST_CORE_API FrameAssembly: public Frame
{
public:
    AST_OBJECT(FrameAssembly)
    AST_PROPERT(Origin)
    AST_PROPERT(Axes)
    /// @brief 创建组装坐标系
    /// @param origin 原点
    /// @param axes 轴系
    /// @warning 返回的指针为裸指针，需要手动管理内存，避免内存泄漏
    /// @return 组装坐标系指针
    static PFrameAssembly New(Point* origin, Axes* axes);

    /// @brief 创建组装坐标系
    /// @param origin 原点
    /// @param axes 轴系
    /// @note 返回的智能指针会自动管理内存
    /// @return 组装坐标系智能指针
    static HFrameAssembly MakeShared(Point* origin, Axes* axes);

    FrameAssembly() = default;
    FrameAssembly(Point* origin, Axes* axes);
    ~FrameAssembly() = default;

    Frame* getParent() const final;
    /// @note 本类重载了 getTransform 的部分版本，会遮蔽基类的其它版本，需显式引入基类的重载集合
    using Frame::getTransform;
    errc_t getTransform(const TimePoint&tp, Transform& transform) const override;
    errc_t getTransform(const TimePoint&tp, KinematicTransform& transform) const override;
PROPERTIES:
    Point* getOrigin() const final { return origin_.get(); }
    void setOrigin(Point* origin) { origin_ = origin; }
    Axes* getAxes() const final { return axes_.get(); }
    void setAxes(Axes* axes) { axes_ = axes; }
protected:
    SharedPtr<Point> origin_{};   ///< 原点
    SharedPtr<Axes>  axes_{};     ///< 轴系统
};

/*! @} */

AST_NAMESPACE_END
