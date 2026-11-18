/// @file      SegmentGraph.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-19

#pragma once

#include "AstGlobal.h"
#include "Segment.hpp"
#include "Sequence.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 轨道段框图，用类似simulink的框图描述复杂、多航天的航天任务中的轨道任务段
class AST_CORE_API SegmentGraph: public Segment
{
public:
    AST_OBJECT(SegmentGraph)

    SegmentGraph() = default;
    ~SegmentGraph() override = default;
public:
    errc_t execute() override;
public:
    std::vector<HMissionCommand> commands_{};     ///< 任务命令序列
};


/*! @} */

AST_NAMESPACE_END
