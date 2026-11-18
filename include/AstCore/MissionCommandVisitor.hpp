/// @file      MissianCommandVisitor.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "MissionCommand.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class InitialState;
class Propagate;
class Maneuver;
class Sequence;


/// @brief 任务命令访问者接口
class MissionCommandVisitor
{
public:
    virtual ~MissionCommandVisitor() = default;
    virtual void visit(MissionCommand&) = 0;
    virtual void visit(InitialState&) = 0;
    virtual void visit(Propagate&) = 0;
    virtual void visit(Maneuver&) = 0;
    virtual void visit(Sequence&) = 0;
};



/*! @} */

AST_NAMESPACE_END
