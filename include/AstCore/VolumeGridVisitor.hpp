/// @file      VolumeGridVisitor.hpp
/// @brief     体积网格访问者接口
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class VolumeGrid;
class VolumeGridCartesian;
class VolumeGridCartographic;
class VolumeGridCylindrical;
class VolumeGridSpherical;
class VolumeGridSurfaceBearing;
class VolumeGridConstrained;

/// @brief 体积网格访问者接口
/// @ingroup Spatial
class VolumeGridVisitor
{
public:
    virtual ~VolumeGridVisitor() = default;

    virtual void visit(VolumeGrid& grid) = 0;
    virtual void visit(VolumeGridCartesian& grid) = 0;
    virtual void visit(VolumeGridCartographic& grid) = 0;
    virtual void visit(VolumeGridCylindrical& grid) = 0;
    virtual void visit(VolumeGridSpherical& grid) = 0;
    virtual void visit(VolumeGridSurfaceBearing& grid) = 0;
    virtual void visit(VolumeGridConstrained& grid) = 0;
};

AST_NAMESPACE_END
