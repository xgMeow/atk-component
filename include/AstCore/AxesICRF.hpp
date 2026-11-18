/// @file      AxesICRF.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-04

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

/// @brief  ICRF 轴系
class AST_CORE_API AxesICRF: public Axes
{
public:
    AxesICRF() = default;
    ~AxesICRF() override = default;
    static AxesICRF* Instance();
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};

A_ALWAYS_INLINE Axes* aAxesICRF()
{
    return AxesICRF::Instance();
}



/*! @} */

AST_NAMESPACE_END
