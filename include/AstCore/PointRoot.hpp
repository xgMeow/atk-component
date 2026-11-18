/// @file      PointRoot.hpp
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


class AST_CORE_API PointRoot : public Point
{
public:
    PointRoot() = default;
    ~PointRoot() = default;
    static Point* Instance();

    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
};


A_ALWAYS_INLINE Point* aPointRoot()
{
    return PointRoot::Instance();
}

/*! @} */

AST_NAMESPACE_END
