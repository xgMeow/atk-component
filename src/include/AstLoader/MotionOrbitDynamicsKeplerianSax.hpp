/// @file      TwoBodySAX.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-19

#pragma once

#include "AstGlobal.h"
#include "MotionOrbitDynamicsSax.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_LOADER_API MotionOrbitDynamicsKeplerianSax: public MotionOrbitDynamicsSax
{
public:
    using MotionOrbitDynamicsSax::MotionOrbitDynamicsSax;
    ~MotionOrbitDynamicsKeplerianSax() override = default;
public:
    errc_t keyValue(StringView key, const ValueView& value) override;
    errc_t getMotion(ScopedPtr<MotionProfile>& motion) override;
    virtual MotionOrbitDynamics* newMotionOrbitDynamics() = 0;
protected:
    double radiusOfPerigee_ = 0.0;
    double inclination_ = 0.0;
    double eccentricity_ = 0.0;
    double argOfPerigee_ = 0.0;
    double rightAscension_ = 0.0;
    double trueAnomaly_ = 0.0;
    double timeStep_ = 0.0;
    std::string orbElemCoordSys_{};
    SharedPtr<Axes> orbElemCoordAxes_{};
    std::string propagationCoordSys_{};
    SharedPtr<Axes> propagationCoordAxes_{};
    int displayCoordType_ = 0;
    std::string displayCoordSys_{};
    SharedPtr<Axes> displayCoordAxes_{};
};


/*! @} */

AST_NAMESPACE_END
