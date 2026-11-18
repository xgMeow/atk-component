/// @file      SpatialConditionVisitor.hpp
/// @brief     空间条件访问者接口
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class SpatialCondition;
class SpatialCondAccessToObjects;
class SpatialCondCombined;
class SpatialCondConditionAtLocation;
class SpatialCondGridBoundingVolume;
class SpatialCondLighting;
class SpatialCondOverTime;
class SpatialCondCalculationBounds;
class SpatialCondValidTimeAtLocation;

/// @brief 空间条件访问者接口
/// @ingroup Spatial
class SpatialConditionVisitor
{
public:
    virtual ~SpatialConditionVisitor() = default;

    virtual void visit(SpatialCondition& cond) = 0;
    virtual void visit(SpatialCondAccessToObjects& cond) = 0;
    virtual void visit(SpatialCondCombined& cond) = 0;
    virtual void visit(SpatialCondConditionAtLocation& cond) = 0;
    virtual void visit(SpatialCondGridBoundingVolume& cond) = 0;
    virtual void visit(SpatialCondLighting& cond) = 0;
    virtual void visit(SpatialCondOverTime& cond) = 0;
    virtual void visit(SpatialCondCalculationBounds& cond) = 0;
    virtual void visit(SpatialCondValidTimeAtLocation& cond) = 0;
};

AST_NAMESPACE_END
