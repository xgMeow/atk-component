/// @file      MotionBasic.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstSim/MotionProfile.hpp"
#include "AstSim/MotionWithIntervalStep.hpp"
#include "AstCore/State.hpp"
#include "AstCore/EventInterval.hpp"
#include "AstCore/OrbitElement.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionOrbitDynamics;
using PMotionOrbitDynamics = MotionOrbitDynamics*;
// using HMotionOrbitDynamics = SharedPtr<MotionOrbitDynamics>;
using MotionBasic = MotionOrbitDynamics; // 兼容处理

/// @brief 轨道动力学基础运动模型数据结构
class AST_SIM_API MotionOrbitDynamics: public MotionWithIntervalStep
{
public:
    AST_OBJECT(MotionOrbitDynamics)
    AST_PROPERT(InitialState)
    AST_PROPERT(PropagationFrame)
    MotionOrbitDynamics() = default;
    ~MotionOrbitDynamics() = default;


    /// @brief 获取状态类型
    /// @return 状态类型
    EStateType getStateType() const;

    /// @brief 设置状态类型
    /// @param type 状态类型
    void setStateType(EStateType type);
protected:
    struct PropagationParams
    {
        TimePoint    epoch_;                      ///< 预报时间点
        CartState    stateInPropagationFrame_;    ///< 预报坐标系下的初始状态
        Frame*       propagationFrame_;           ///< 预报坐标系指针
    };

    errc_t getPropagationParams(PropagationParams& params) const;

    errc_t discretizeInterval(const TimePoint& epoch, double stepSize, std::vector<double>& times) const;
PROPERTIES:
    State* getInitialState() const { return initialState_.get(); }
    void setInitialState(State* state) { initialState_ = state; }
    Frame* getPropagationFrame() const { return propagationFrame_.get(); }
    void setPropagationFrame(Frame* frame) { propagationFrame_ = frame; }
protected:
    SharedPtr<State>            initialState_{};         ///< 初始状态
    SharedPtr<Frame>            propagationFrame_{};     ///< 预报坐标系
};

/*! @} */

AST_NAMESPACE_END
