/// @file      EphemerisTwoBody.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

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


/// @brief 二体星历
class AST_CORE_API EphemerisTwoBody final: public Ephemeris
{
public:
    static EphemerisTwoBody* New(Frame* frame, const TimePoint& epoch, const CartState& initstate);
    static EphemerisTwoBody* New(Frame* frame, double gm, const TimePoint& epoch, const CartState& initstate);

    EphemerisTwoBody();
    EphemerisTwoBody(Frame* frame, double gm, const TimePoint& epoch, const CartState& initstate);
    ~EphemerisTwoBody() override = default;
    void setFrame(Frame* frame){ frame_ = frame; }
    void setGM(double gm){ gm_ = gm; }
    double getGM() const{ return gm_; }
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
    double           gm_{0.0};
    TimePoint        epoch_{};
    CartState        initstate_{};
};

/*! @} */

AST_NAMESPACE_END
