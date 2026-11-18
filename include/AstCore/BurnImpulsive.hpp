/// @file      BurnImpulsive.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-18

#pragma once

#include "AstGlobal.h"
#include "AstCore/Burn.hpp"
#include "AstCore/Axes.hpp"
#include "AstMath/Vector.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 脉冲点火
class AST_CORE_API BurnImpulsive: public Burn
{
public:
    AST_OBJECT(BurnImpulsive)
    AST_PROPERT(x)
    AST_PROPERT(y)
    AST_PROPERT(z)
    AST_PROPERT(axes)
    BurnImpulsive() = default;
    ~BurnImpulsive() = default;

PROPERTIES:
    double x() const {return impulse_.x();}
    void setX(double value) {impulse_.x() = value;}

    double y() const {return impulse_.y();}
    void setY(double value) {impulse_.y() = value;}

    double z() const {return impulse_.z();}
    void setZ(double value) {impulse_.z() = value;}

    Axes* axes() const {return axes_.get();}
    void setAxes(Axes* value) {axes_ = value;}
public:
    const Vector3d& impulse() const {return impulse_;}
    void setImpulse(const Vector3d& value) {impulse_ = value;}
private:
    WeakPtr<Axes> axes_{};
    Vector3d impulse_{};
};



/*! @} */

AST_NAMESPACE_END
