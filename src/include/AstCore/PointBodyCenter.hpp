/// @file      PointBodyCenter.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-12

#pragma once

#include "AstGlobal.h"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

class CelestialBody;

/// @brief 天体的中心点
class AST_CORE_API PointBodyCenter final: public Point
{
public:
    PointBodyCenter() = default;

    PointBodyCenter(const PointBodyCenter&) = delete;
    PointBodyCenter& operator=(const PointBodyCenter&) = delete;

    explicit PointBodyCenter(CelestialBody* body);
    ~PointBodyCenter() = default;
    CelestialBody* getBody() const{ return body_; }
    void setBody(CelestialBody* body){ body_ = body; }
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
protected:
    CelestialBody* body_{nullptr};
};


/*! @} */

AST_NAMESPACE_END
