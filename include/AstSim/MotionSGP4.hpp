/// @file      MotionSGP4.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-14

#pragma once

#include "AstGlobal.h"
#include "AstSim/MotionProfile.hpp"
#include "AstSim/MotionWithIntervalStep.hpp"
#include "AstCore/SGP4.hpp"
#include "AstCore/TLELines.hpp"
#include "AstCore/TLE.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/



/// @brief SGP4 运动模型
/// @details   
class AST_SIM_API MotionSGP4 : public MotionWithIntervalStep
{
public:
    MotionSGP4() = default;
    ~MotionSGP4() = default;
public:
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;
public:
    std::string SSCNumber_{};                ///< SSC 编号字符串
    std::string intlDesignator_{};           ///<
    std::string commonName_{};               ///< 通用名称
    std::vector<TLE> elements_{}; ///< TLE 列表
};

/*! @} */

AST_NAMESPACE_END