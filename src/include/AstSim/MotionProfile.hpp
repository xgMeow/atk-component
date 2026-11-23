/// @file      MotionProfile.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"
#include "AstUtil/ScopedPtr.hpp"
#include "AstCore/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionProfile;
using PMotionProfile = MotionProfile*;
// using HMotionProfile = ScopedPtr<MotionProfile>;

class MotionTwoBody;
class MotionHPOP;
class MotionSPICE;
class MotionBallistic;
class MotionSimpleAscent;
class MotionProfileVisitor;
class MotionMissionCommand;
class MotionSGP4;

/// @brief 运动定义接口
class AST_SIM_API MotionProfile: public ObjectNamed
{
public:
    AST_OBJECT(MotionProfile)
    MotionProfile() = default;
    virtual ~MotionProfile() = default;
public:
    MotionHPOP* toHPOP() const;
    MotionTwoBody* toTwoBody() const;
    MotionSPICE* toSPICE() const;
    MotionBallistic* toBallistic() const;
    MotionSimpleAscent* toSimpleAscent() const;
public:
    /// @brief 生成特定星历
    /// @param eph 星历指针
    /// @return 错误码
    virtual errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const = 0;

    /// @brief 生成简单星历
    /// @param eph 星历指针
    /// @return 错误码
    virtual errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const = 0;

    /// @brief 接受访问者
    /// @param visitor 访问者
    virtual void accept(MotionProfileVisitor& visitor) = 0;
public:
    Ephemeris* createEphemeris() const;
    errc_t createEphemeris(SharedPtr<Ephemeris>& eph) const;
    errc_t createEphemeris(ScopedPtr<Ephemeris>& eph) const;
};

/*! @} */

AST_NAMESPACE_END