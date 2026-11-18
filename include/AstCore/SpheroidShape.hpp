/// @file      SpheroidShape.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-12

#pragma once

#include "AstGlobal.h"
#include "BodyShape.hpp"

AST_NAMESPACE_BEGIN

/// @brief 旋转椭球体/扁球体
/// @details 有两个轴长度相同，且与旋转轴垂直。
class AST_CORE_API SpheroidShape final : public BodyShape
{
public:
    AST_OBJECT(SpheroidShape)
    AST_PROPERT(majorAxis)
    AST_PROPERT(flatfactor)
    static SpheroidShape* NewFromMajorAxisFlatFactor(double majorAxis, double flatFactor);
    static SpheroidShape* NewFromMajorMinorAxis(double majorAxis, double minorAxis);

    SpheroidShape() = default;
    SpheroidShape(double majorAxis, double flatFactor);
    using BodyShape::transform;

    double majorAxis() const override{return majorAxis_;}

    void transform(const Vector3d& cartesian, GeodeticPoint& detic) const override;

    void transform(const GeodeticPoint& detic, Vector3d& cartesian) const override;

    errc_t transform(const Vector3d& pos, const Vector3d& vel,
                     GeodeticPoint& detic, LatLonAlt& rate) const override;

    errc_t transform(const GeodeticPoint& detic, const LatLonAlt& rate,
                     Vector3d& pos, Vector3d& vel) const override;
public:
    double flatFactor() const { return flatFactor_; }
PROPERTIES:
    length_d    majorAxis_{};  ///< 长轴长度
    double      flatFactor_{}; ///< 扁率因子
};

AST_NAMESPACE_END
