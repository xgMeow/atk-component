/// @file      Return.hpp
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


/// @brief 返回段，用于停止当前任务序列Sequence的执行，并返回到上一级的Sequence
/// @details 仅仅是标识返回，不执行任何操作
class AST_CORE_API Return : public MissionCommand
{
public:
    AST_OBJECT(Return)
    AST_PROPERT(enabled)
    Return() = default;
    ~Return() = default;
public:
    errc_t execute() override;
PROPERTIES:
    bool enabled() const {return enabled_;}
    void setEnabled(bool enabled){enabled_ = enabled;}
private:
    bool enabled_{true};        ///< 是否启用
};


/*! @} */

AST_NAMESPACE_END
