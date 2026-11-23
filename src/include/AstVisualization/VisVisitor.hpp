/// @file      VisVisitor.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class VisGroup;
class VisTrajectory;
class VisCelestialBody;
class VisGroundTrack;

/// @brief 可视化对象访问者
/// @details 用于对场景图中的各可视化对象做双分派。渲染后端各自实现本接口，
///          通过 visit() 重载决定每个对象如何被渲染，对象本身只提供数据
///          （如轨迹采样、天体半径），不依赖任何具体后端。
class AST_VISUALIZATION_API VisVisitor
{
public:
    virtual ~VisVisitor() = default;

    /// @brief 访问对象分组
    virtual void visit(VisGroup& group) = 0;

    /// @brief 访问轨迹对象
    virtual void visit(VisTrajectory& trajectory) = 0;

    /// @brief 访问天体对象
    virtual void visit(VisCelestialBody& celestialBody) = 0;

    /// @brief 访问地面轨迹对象
    virtual void visit(VisGroundTrack& groundTrack) = 0;
};

/*! @} */

AST_NAMESPACE_END
