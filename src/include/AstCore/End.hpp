/// @file      End.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-18

#pragma once

#include "AstGlobal.h"
#include "MissionCommand.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 结束段，仅用于标识任务序列Sequence的结束
/// @details 仅仅是标识结束，不执行任何操作
class AST_CORE_API End : public MissionCommand
{
public:
    AST_OBJECT(End)
    End() = default;
    ~End() = default;
public:
    errc_t execute() override{return eNoError;}
};

/*! @} */

AST_NAMESPACE_END
