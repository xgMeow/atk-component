/// @file      Segment.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-19

#pragma once

#include "AstGlobal.h"
#include "MissionCommand.hpp"
#include "AstCore/SpacecraftState.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

// class ControlFlowEscape {};
// class ReturnEscape : public ControlFlowEscape{};

class Sequence;

/// @brief 轨道段（虚基类），用于描述任务序列中的轨道段，例如初始状态段、轨道机动段、轨道预报段等
/// @details 轨道段描述任务序列中的轨道任务段
/// 参考了GMAT-Architectural-Specification.pdf第26章的Mission Control Sequence Commands
/// 参考了STK的轨道段MCSSegment
class AST_CORE_API Segment: public MissionCommand
{
public:
    AST_OBJECT(Segment)
    AST_PROPERT(InputState)
    AST_PROPERT(OutputState)
    Segment();
    ~Segment() override = default;
public:
    /// @brief 执行任务
    /// @return 错误码
    virtual errc_t execute() override = 0;

PROPERTIES:
    /// @brief 设置输入状态
    /// @param inputState 输入状态
    void setInputState(SpacecraftState* inputState){inputState_ = inputState;}

    /// @brief 获取输入状态
    /// @return 输入状态
    SpacecraftState* getInputState() const{return inputState_.get();}

    /// @brief 获取输出状态
    /// @return 输出状态
    SpacecraftState* getOutputState() const{return outputState_.get();}


private:
    WeakPtr<SpacecraftState> inputState_;          ///< 输入状态
    SharedPtr<SpacecraftState> outputState_;       ///< 输出状态
};




/*! @} */

AST_NAMESPACE_END
