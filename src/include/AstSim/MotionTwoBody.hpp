/// @file      MotionTwoBody.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

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

class MotionTwoBody;
using PMotionTwoBody = MotionTwoBody*;

/// @brief 二体问题轨道动力学模型
/// @details
/// 该类封装了一个二体问题的轨道动力学模型，用于计算二体问题的轨道状态。
/// @see MotionOrbitDynamics
class AST_SIM_API MotionTwoBody final: public MotionOrbitDynamics
{
public:
    AST_OBJECT(MotionTwoBody)
    static MotionTwoBody* New();
    MotionTwoBody() = default;
    ~MotionTwoBody() override = default;
public:
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;
};

/*! @} */

AST_NAMESPACE_END