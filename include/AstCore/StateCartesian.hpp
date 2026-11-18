/// @file      StateCartesian.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/State.hpp"
#include "AstMath/Vector.hpp"
#include "AstCore/OrbitElement.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/
class StateCartesian;
using PStateCartesian = StateCartesian*;
using HStateCartesian = SharedPtr<StateCartesian>;

/// @brief 笛卡尔状态(直角坐标)
class AST_CORE_API StateCartesian final: public State
{
public:
    AST_OBJECT(StateCartesian)
    AST_PROPERT(x)
    AST_PROPERT(y)
    AST_PROPERT(z)
    AST_PROPERT(vx)
    AST_PROPERT(vy)
    AST_PROPERT(vz)
    static PStateCartesian New();
    static HStateCartesian MakeShared();
    static PStateCartesian New(const CartState& state);
    static HStateCartesian MakeShared(const CartState& state);

    StateCartesian() = default;
    StateCartesian(const CartState& state);
    StateCartesian(const State& state);
    ~StateCartesian() override = default;
public:
    EStateType getStateType() const override { return EStateType::eCartesian; }
    errc_t getState(CartState& state) const override;
    errc_t getState(ModOrbElem& orbElem) const override;
    errc_t setState(const CartState& state) override;
    errc_t setState(const ModOrbElem& orbElem) override;
PROPERTIES:
    length_d x() const { return cartState_.x(); }
    length_d y() const { return cartState_.y(); }
    length_d z() const { return cartState_.z(); }
    speed_d vx() const { return cartState_.vx(); }
    speed_d vy() const { return cartState_.vy(); }
    speed_d vz() const { return cartState_.vz(); }
    void setX(length_d x){ cartState_.x() = x; }
    void setY(length_d y){ cartState_.y() = y; }
    void setZ(length_d z){ cartState_.z() = z; }
    void setVx(speed_d vx){ cartState_.vx() = vx; }
    void setVy(speed_d vy){ cartState_.vy() = vy; }
    void setVz(speed_d vz){ cartState_.vz() = vz; }
protected:
    CartState cartState_{};
};



/*! @} */

AST_NAMESPACE_END