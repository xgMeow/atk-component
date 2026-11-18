/// @file      MotionJ4Analytical.hpp
/// @brief     J4解析轨道动力学
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

class MotionJ4Analytical;
using PMotionJ4Analytical = MotionJ4Analytical*;

/// @brief J4解析轨道动力学模型
/// @details
/// @see MotionOrbitDynamics
class AST_SIM_API MotionJ4Analytical final: public MotionOrbitDynamics
{
public:
    AST_OBJECT(MotionJ4Analytical)
    static MotionJ4Analytical* New();
    MotionJ4Analytical() = default;
    ~MotionJ4Analytical() override = default;
public:
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;
};

/*! @} */

AST_NAMESPACE_END