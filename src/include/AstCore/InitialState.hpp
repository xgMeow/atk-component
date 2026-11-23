/// @file      InitialState.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "MissionCommand.hpp"
#include "AstCore/SpacecraftState.hpp"
#include "Segment.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 初始轨道段，用于建模任务序列(MissionCommand)中的初始状态任务
/// @details 初始状态任务负责设置初始状态参数，确保任务序列的执行从正确的状态开始
class AST_CORE_API InitialState: public Segment
{
public:
    AST_OBJECT(InitialState)
    AST_PROPERT(InitialState)
    InitialState();
    ~InitialState() = default;
PROPERTIES:
    /// @brief 获取初始状态
    /// @details 对于初始轨道段，其初始状态就是输出状态
    /// @return 初始状态
    SpacecraftState* getInitialState() const{return getOutputState();}
public:
    errc_t execute() override;
};

/*! @} */

AST_NAMESPACE_END
