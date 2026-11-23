/// @file      SphereShape.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-12

#pragma once

#include "AstGlobal.h"
#include "BodyShape.hpp"

AST_NAMESPACE_BEGIN

/// @brief 球体形状
class AST_CORE_API SphereShape final: public BodyShape
{
public:
    AST_OBJECT(SphereShape)
    AST_PROPERT(radius)
    SphereShape() = default;
    SphereShape(double radius);

    double majorAxis() const override{return radius_;}

    void transform(const Vector3d& cartesian, GeodeticPoint& detic) const override;

    void transform(const GeodeticPoint& detic, Vector3d& cartesian) const override;

    errc_t transform(const Vector3d& pos, const Vector3d& vel,
                     GeodeticPoint& detic, LatLonAlt& rate) const override;

    errc_t transform(const GeodeticPoint& detic, const LatLonAlt& rate,
                     Vector3d& pos, Vector3d& vel) const override;

PROPERTIES:
    length_d radius_{}; ///< 半径长度
};

AST_NAMESPACE_END
