/// @file      Command.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-06

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class Command;
using PCommand = Command*;
using HCommand = SharedPtr<Command>;

/// @brief 命令（虚基类），用于定义任务序列中的命令，例如初始状态、轨道机动、轨道预报等
/// @details 命令负责执行任务序列中的任务操作
/// 参考GMAT的GmatCommand.hpp
class AST_CORE_API Command: public ObjectNamed
{
public:
    AST_OBJECT(Command)

    /// @brief 执行命令
    virtual errc_t execute() = 0;

    /// @brief 从父序列中移除
    errc_t removeFromParentSequence();
private:

};





/*! @} */

AST_NAMESPACE_END
