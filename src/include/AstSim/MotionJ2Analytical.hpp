/// @file      MotionJ2Analytical.hpp
/// @brief     J2解析轨道动力学
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-14

#pragma once

#include "AstGlobal.h"
#include "AstSim/MotionOrbitDynamics.hpp"
#include "AstSim/MotionProfile.hpp"
#include "AstCore/State.hpp"
#include "AstCore/EventInterval.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionJ2Analytical;
using PMotionJ2Analytical = MotionJ2Analytical*;

/// @brief J2解析轨道动力学
/// @details
/// @see MotionOrbitDynamics
class AST_SIM_API MotionJ2Analytical final: public MotionOrbitDynamics
{
public:
    AST_OBJECT(MotionJ2Analytical)
    static MotionJ2Analytical* New();
    MotionJ2Analytical() = default;
    ~MotionJ2Analytical() override = default;
public:
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;
};

/*! @} */

AST_NAMESPACE_END