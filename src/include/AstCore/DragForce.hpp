/// @file      DragForce.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "ForceModel.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @ingroup Core
    @defgroup ForceModel
    @{
*/


enum class EAtmDensityModel
{
    eNone,
    e1976Standard,
    eHarrisPriester,
    eJacchia60,
    eJacchia70,
    eJacchia71,
    eJacchiaRoberts,
    eMSIS1986,
    eMSISE1990,
    eNRLMSISE2000,
    eCIRA72,
    eDTM2012,
};


enum class EGeoMagFluxSource
{
    eKp,
    eAp,
};

enum class EGeoMagFluxUpdateRate
{
    eDaily,
    e3Hourly,
    e3HourlyInterp,
    e3HourlyCubicSpline,
};

/// @brief 大气阻力模型
class AST_CORE_API DragForce : public ForceModel
{
public:
    AST_OBJECT(DragForce)
    DragForce() = default;
    ~DragForce() = default;

    /// @brief 地磁活动 ap 指数
    double ap() const;

    /// @brief 地磁活动 Kp 指数
    double kp() const;

    /// @brief 当日 F10.7 太阳射电流量
    double f10p7Daily() const;

    /// @brief 平均 F10.7 太阳射电流量
    double f10p7Average() const;
public:
    /// @name 大气密度模型配置
    /// @{
    EAtmDensityModel atmDensityModel_{EAtmDensityModel::e1976Standard};         ///< 主大气密度模型
    EAtmDensityModel lowAltAtmDensityModel_{EAtmDensityModel::eNone};           ///< 低高度辅助模型（通常 eMSISE1990 / eNRLMSISE2000）
    double atmBlendingRange_{0.0};                                              ///< 主/低高度模型混合过渡范围 [m]
    /// @}


    /// @name 空间天气数据源
    /// @{
    bool useFluxApFile_{false};                                                 ///< 是否从外部文件读取地磁/太阳通量数据

    /// @name 手动输入的太阳/地磁指数（useFluxApFile_ == false 时生效）
    /// @{
    double f10p7Average_{150.0};                                                ///< 平均 F10.7 太阳射电流量
    double f10p7Daily_{150.0};                                                  ///< 当日 F10.7 太阳射电流量
    double kp_{3.0};                                                            ///< 地磁活动 Kp 指数
    /// @}

    /// @name 文件数据配置参数（useFluxApFile_ == true 时生效）
    /// @{
    std::string fluxApFile_{};                                                  ///< 空间天气文件路径（若 useFluxApFile_ == true）
    EGeoMagFluxUpdateRate geoMagFluxUpdateRate_{EGeoMagFluxUpdateRate::eDaily}; ///< 地磁通量数据更新频率
    EGeoMagFluxSource geoMagFluxSource_{EGeoMagFluxSource::eKp};                ///< 地磁通量源类型（Kp 或 Ap）
    double geoMagFluxInterpSubSamplingRatio_{1.0};                              ///< 插值时的下采样因子
    /// @}
    /// @}


    /// @name 阻力计算方法开关
    /// @{
    bool useApproxAltForDrag_{false};                                           ///< 是否使用近似高度替代真实高度计算大气密度
    ESunPosition sunPosition_{ESunPosition::eTrue};                             ///< 太阳位置（真实/视太阳位置）
    /// @}
};

AST_CORE_API std::string toString(EAtmDensityModel model);

/*! @} */

AST_NAMESPACE_END

