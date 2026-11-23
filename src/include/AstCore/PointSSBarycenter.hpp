/// @file      PointSSBarycenter.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-11

#pragma once

#include "AstGlobal.h"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

/// @brief  太阳系质心
class AST_CORE_API PointSSBarycenter: public Point
{
public:
    PointSSBarycenter() = default;
    ~PointSSBarycenter() override = default;
    static Point* Instance();

    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
};


A_ALWAYS_INLINE Point* aPointSSBarycenter()
{
    return PointSSBarycenter::Instance();
}


/*! @} */

AST_NAMESPACE_END
