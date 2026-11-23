/// @file      MotionHPOPSax.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-19

#pragma once

#include "AstGlobal.h"
#include "MotionOrbitDynamicsSax.hpp"
#include "AstCore/StateCartesian.hpp"
#include "AstSim/MotionHPOP.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionHPOPSax : public MotionOrbitDynamicsSax
{
public:
    struct PhysicalParam{
        double mass_{1000};
        double dragCoefficient_{0.0};
        double dragAreaMassRatio_{0.0};
        double srpCoefficient_{0.0};
        double srpArea_{0.0};
    };
    using MotionOrbitDynamicsSax::MotionOrbitDynamicsSax;
    ~MotionHPOPSax() override = default;
public:
    errc_t begin(StringView name) override;
    errc_t keyValue(StringView key, const ValueView& value) override;
    errc_t getMotion(ScopedPtr<MotionProfile>& motion) override;
public:
protected:
    double getMass() const {return spacecraftParam_.mass_;}
private:
    CartState cartState_{};                ///< 直角坐标
    HPOPForceModel forceModel_{};          ///< 力模型
    PhysicalParam spacecraftParam_{}; 
    struct {
        std::string method_{};              ///< 积分器方法 (IntegMethod)
        std::string stepControlMethod_{};   ///< 步长控制方法 (StepControlMethod)
        double errorTolerance_ = 1e-13;    ///< 误差容限 (ErrorTolerance)
        double timeStep_ = 60.0;           ///< 时间步长 (TimeStep)
        double minStepSize_ = 1.0;         ///< 最小步长 (MinStepSize)
        double maxStepSize_ = 86400.0;     ///< 最大步长 (MaxStepSize)
        bool reportOnFixedStep_ = true;    ///< 按固定步长报告 (ReportOnFixedStep)
        int interpolationSamplesM1_ = 7;   ///< 插值采样数-1 (InterpolationSamplesM1)
        std::string interpolationMethod_{}; ///< 插值方法 (InterpolationMethod)
        double altitudeCutOff_ = 10000.0;  ///< 高度截止 (AltitudeCutOff)
    } integrator_{};                      ///< 积分器配置参数
};

/*! @} */

AST_NAMESPACE_END
