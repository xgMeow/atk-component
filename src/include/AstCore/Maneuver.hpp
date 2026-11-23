/// @file      Maneuver.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "MissionCommand.hpp"
#include "AstCore/Burn.hpp"
#include "Segment.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Burn;

/// @brief 机动轨道段，用于建模任务序列(MissionCommand)中的机动任务
/// @details 机动负责执行任务序列中的机动任务
class AST_CORE_API Maneuver: public Segment
{
public:
    AST_OBJECT(Maneuver)
    AST_PROPERT(burn)
    Maneuver() = default;
    ~Maneuver() = default;
public:
    errc_t execute() override;
PROPERTIES:
    Burn* burn() const {return burn_.get();}
    void setBurn(Burn* burn);
private:
    WeakPtr<Burn> burn_{};       ///< 发动机点火
};


/*! @} */

AST_NAMESPACE_END
