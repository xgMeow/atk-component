/// @file      SpatialCalculationVisitor.hpp
/// @brief     空间计算访问者接口
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class SpatialCalculation;
class SpatialCalcAltitude;
class SpatialCalcAngleToLocation;
class SpatialCalcAtmosphericDensity;
class SpatialCalcDistance;
class SpatialCalcFile;
class SpatialCalcPropagationDelay;
class SpatialCalcSEET0;
class SpatialCalcSEET1;
class SpatialCalcSEET2;
class SpatialCalcSEET3;
class SpatialCalcScalarAtLocation;
class SpatialCalcSatisfactionMetrics;
class SpatialCalcSolarIntensity;

/// @brief 空间计算访问者接口
/// @ingroup Spatial
class SpatialCalculationVisitor
{
public:
    virtual ~SpatialCalculationVisitor() = default;

    virtual void visit(SpatialCalculation& calc) = 0;
    virtual void visit(SpatialCalcAltitude& calc) = 0;
    virtual void visit(SpatialCalcAngleToLocation& calc) = 0;
    virtual void visit(SpatialCalcAtmosphericDensity& calc) = 0;
    virtual void visit(SpatialCalcDistance& calc) = 0;
    virtual void visit(SpatialCalcFile& calc) = 0;
    virtual void visit(SpatialCalcPropagationDelay& calc) = 0;
    virtual void visit(SpatialCalcSEET0& calc) = 0;
    virtual void visit(SpatialCalcSEET1& calc) = 0;
    virtual void visit(SpatialCalcSEET2& calc) = 0;
    virtual void visit(SpatialCalcSEET3& calc) = 0;
    virtual void visit(SpatialCalcScalarAtLocation& calc) = 0;
    virtual void visit(SpatialCalcSatisfactionMetrics& calc) = 0;
    virtual void visit(SpatialCalcSolarIntensity& calc) = 0;
};

AST_NAMESPACE_END
