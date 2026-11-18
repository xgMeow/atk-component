/// @file      NoopShape.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-01

#pragma once

#include "AstGlobal.h"
#include "BodyShape.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

#ifndef SWIG

/// @brief 无操作形状，用于默认占位
class NoopShape final : public BodyShape
{
public:
    double majorAxis() const override{return 0;}

    void transform(const Vector3d& cartesian, GeodeticPoint& detic) const override;

    void transform(const GeodeticPoint& detic, Vector3d& cartesian) const override;
};

#endif

/*! @} */

AST_NAMESPACE_END
