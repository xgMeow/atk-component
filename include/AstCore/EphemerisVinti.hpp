/// @file      EphemerisVinti.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-05

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstCore/BuiltinFrame.hpp"
#include "AstCore/OrbitElement.hpp"
#include "AstMath/Vector.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief Vinti 解析解星历（含 J2 / J3 扁率项）
/// @details 内部调用 aVinti() 进行闭式轨道预报，
///          需要引力常数 gm、J2/J3 系数与天体赤道半径 re。
class AST_CORE_API EphemerisVinti final: public Ephemeris
{
public:
    static EphemerisVinti* New(Frame* frame, const TimePoint& epoch, const CartState& initstate);
    static EphemerisVinti* New(Frame* frame, double gm, double j2, double j3, double re, const TimePoint& epoch, const CartState& initstate);

    EphemerisVinti();
    EphemerisVinti(Frame* frame, double gm, double j2, double j3, double re, const TimePoint& epoch, const CartState& initstate);
    ~EphemerisVinti() override = default;
    void setFrame(Frame* frame){ frame_ = frame; }
    void setGM(double gm){ gm_ = gm; }
    void setJ2(double j2){ j2_ = j2; }
    void setJ3(double j3){ j3_ = j3; }
    void setRe(double re){ re_ = re; }
    double getGM() const{ return gm_; }
    double getJ2() const{ return j2_; }
    double getJ3() const{ return j3_; }
    double getRe() const{ return re_; }
    void setEpoch(const TimePoint& epoch){ epoch_ = epoch; }
    const TimePoint& getEpoch() const{ return epoch_; }
    void setInitialState(const CartState& initstate){ initstate_ = initstate; }
    void getInitialState(CartState& initstate) const{ initstate = initstate_; }
public:
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
    errc_t getInterval(TimeInterval& interval) const override;
protected:
    SharedPtr<Frame> frame_{aFrameECI()};
    double           gm_{0.0};     ///< 引力常数 [m³/s²]
    double           j2_{0.0};     ///< J2 带谐系数
    double           j3_{0.0};     ///< J3 带谐系数
    double           re_{0.0};     ///< 天体赤道半径 [m]
    TimePoint        epoch_{};
    CartState        initstate_{};
};

/*! @} */

AST_NAMESPACE_END
