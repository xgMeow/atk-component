/// @file      StateSpherical.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/State.hpp"
#include "AstCore/OrbitElement.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/
class StateSpherical;
using PStateSpherical = StateSpherical*;
using HStateSpherical = SharedPtr<StateSpherical>;

/// @brief 球坐标状态
/// @details
/// 球坐标状态用赤经、赤纬、地心距描述位置, 用飞行航迹角、航迹方位角、速度大小描述速度。
/// 各分量均在参考坐标系的轴系下定义: 赤经自x轴逆时针量, 赤纬自赤道面量,
/// 航迹方位角自当地北向东量。具体的转换算法与奇异处理参见
/// @ref aCartToSpherical 和 @ref aSphericalToCart 
class AST_CORE_API StateSpherical final: public State
{
public:
    AST_OBJECT(StateSpherical)
    AST_PROPERT(RA)
    AST_PROPERT(Dec)
    AST_PROPERT(Radius)
    AST_PROPERT(FltPathAng)
    AST_PROPERT(FltPathAzi)
    AST_PROPERT(Vel)
    static PStateSpherical New();
    static HStateSpherical MakeShared();
    static PStateSpherical New(const SphericalElem& sphericalElem);
    static HStateSpherical MakeShared(const SphericalElem& sphericalElem);

    StateSpherical() = default;
    StateSpherical(const SphericalElem& sphericalElem);
    StateSpherical(const State& state);
    ~StateSpherical() override = default;
public:
    EStateType getStateType() const override { return EStateType::eSpherical; }
    errc_t getState(CartState& state) const override;
    errc_t getState(ModOrbElem& orbElem) const override;
    errc_t setState(const CartState& state) override;
    errc_t setState(const ModOrbElem& orbElem) override;
public:
    /// @brief 获取球坐标根数
    /// @param sphericalElem 输出球坐标根数
    void getState(SphericalElem& sphericalElem) const { sphericalElem = sphericalElem_; }

    /// @brief 设置球坐标根数
    /// @param sphericalElem 球坐标根数
    /// @return 错误码，成功返回eNoError
    errc_t setState(const SphericalElem& sphericalElem);
PROPERTIES:
    /// @brief 获取赤经
    angle_d getRA() const { return sphericalElem_.ra_; }
    /// @brief 设置赤经
    void setRA(angle_d ra) { sphericalElem_.ra_ = ra; }

    /// @brief 获取赤纬
    angle_d getDec() const { return sphericalElem_.dec_; }
    /// @brief 设置赤纬
    void setDec(angle_d dec) { sphericalElem_.dec_ = dec; }

    /// @brief 获取地心距
    length_d getRadius() const { return sphericalElem_.r_; }
    /// @brief 设置地心距
    void setRadius(length_d r) { sphericalElem_.r_ = r; }

    /// @brief 获取航迹角
    angle_d getFltPathAng() const { return sphericalElem_.fpa_; }
    /// @brief 设置航迹角
    void setFltPathAng(angle_d fpa) { sphericalElem_.fpa_ = fpa; }

    /// @brief 获取航迹方位角
    angle_d getFltPathAzi() const { return sphericalElem_.azi_; }
    /// @brief 设置航迹方位角
    void setFltPathAzi(angle_d azi) { sphericalElem_.azi_ = azi; }

    /// @brief 获取速度大小
    speed_d getVel() const { return sphericalElem_.v_; }
    /// @brief 设置速度大小
    void setVel(speed_d v) { sphericalElem_.v_ = v; }
protected:
    SphericalElem sphericalElem_{};             ///< 球坐标根数
};



/*! @} */

AST_NAMESPACE_END
