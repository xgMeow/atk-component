/// @file      EllipsoidShape.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-12

#pragma once

#include "AstGlobal.h"
#include "BodyShape.hpp"

AST_NAMESPACE_BEGIN

/// @brief 椭球体形状
class AST_CORE_API EllipsoidShape final : public BodyShape
{
public:
    AST_OBJECT(EllipsoidShape)
    AST_PROPERT(majorAxis)
    AST_PROPERT(middleAxis)
    AST_PROPERT(minorAxis)
    EllipsoidShape() = default;
    EllipsoidShape(double majorAxis, double middleAxis, double minorAxis);

    double majorAxis() const override{return majorAxis_;}

    void transform(const Vector3d& cartesian, GeodeticPoint& detic) const override;

    void transform(const GeodeticPoint& detic, Vector3d& cartesian) const override;

PROPERTIES:
    length_d majorAxis_{};  ///< 长轴长度
    length_d middleAxis_{}; ///< 中轴长度
    length_d minorAxis_{};  ///< 短轴长度
};

AST_NAMESPACE_END
