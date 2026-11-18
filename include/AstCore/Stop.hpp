/// @file      Stop.hpp
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

/// @brief 停止段，用于停止任务序列的执行
class AST_CORE_API Stop : public MissionCommand
{
public:
    AST_OBJECT(Stop)
    AST_PROPERT(enabled)
    Stop() = default;
    ~Stop() = default;
PROPERTIES:
    bool enabled() const { return enabled_; }
    void setEnabled(bool enabled) { enabled_ = enabled; }
public:
    errc_t execute() override;
private:
    bool enabled_{true};        ///< 是否启用
};

/*! @} */

AST_NAMESPACE_END
