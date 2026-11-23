/// @file      MotionHPOP.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstSim/MotionOrbitDynamics.hpp"
#include "AstCore/HPOPForceModel.hpp"
#include "AstCore/SpacecraftParam.hpp"
#include "AstMath/ODEIntegrator.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionHPOP;
class ODEIntegrator;
using PMotionHPOP = MotionHPOP*;
using HMotionHPOP = SharedPtr<MotionHPOP>;

class AST_SIM_API MotionHPOP: public MotionBasic
{
public:
    AST_OBJECT(MotionHPOP)
    static PMotionHPOP New();
    MotionHPOP();
    ~MotionHPOP() override;
public:
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;
public:
    /// @brief 设置力模型
    /// @param forceModel 力模型
    void setForceModel(HPOPForceModel&& forceModel){forceModel_ = std::move(forceModel);}
    void setForceModel(const HPOPForceModel& forceModel){forceModel_ = forceModel;}

    /// @brief 获取力模型
    /// @return 力模型
    const HPOPForceModel& getForceModel() const{return forceModel_;}

    /// @brief 设置航天器参数
    void setSpacecraftParam(const SpacecraftParam& spacecraftParam){spacecraftParam_= spacecraftParam;}

    /// @brief 获取航天器参数
    const SpacecraftParam& getSpacecraftParam() const{return spacecraftParam_;}

    /// @brief 设置积分器
    /// @param integrator 积分器
    void setIntegrator(ODEIntegrator* integrator);

    /// @brief 获取积分器
    /// @return 积分器
    ODEIntegrator* getIntegrator() const;
private:
    HPOPForceModel forceModel_{};            ///< 力模型
    SpacecraftParam spacecraftParam_{};      ///< 航天器参数
    SharedPtr<ODEIntegrator> integrator_{};  ///< 积分器
};

/*! @} */

AST_NAMESPACE_END