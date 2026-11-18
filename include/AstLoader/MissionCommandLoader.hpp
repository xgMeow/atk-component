/// @file      MissionCommandLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "InitialStateLoader.hpp"
#include "ManeuverLoader.hpp"
#include "PropagateLoader.hpp"
#include "SequenceLoader.hpp"
#include "TargeterSequenceLoader.hpp"
#include "ReturnLoader.hpp"
#include "AstUtil/SharedPtr.hpp"
#include "AstCore/MissionCommand.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class LoaderContext;

/// @brief 从值加载任务命令
/// @param value 值
/// @param missionCommand 任务命令对象
AST_LOADER_API errc_t aLoadMissionCommand(const Value& value, SharedPtr<MissionCommand>& missionCommand, const LoaderContext* context = nullptr);

/// @brief 从文件加载任务命令
/// @param filepath 文件路径
/// @param missionCommand 任务命令对象
AST_LOADER_API errc_t aLoadMissionCommand(StringView filepath, SharedPtr<MissionCommand>& missionCommand);

/*! @} */

AST_NAMESPACE_END
