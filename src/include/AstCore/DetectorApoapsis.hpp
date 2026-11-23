/// @file      DetectorApoapsis.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "DetectorBodyRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 远拱点事件检测器
class AST_CORE_API DetectorApoapsis : public DetectorBodyRelated
{
public:
    AST_OBJECT(DetectorApoapsis)

    static DetectorApoapsis* New();

    DetectorApoapsis();

    double getValue(const SpacecraftState& state, double t) const override;
private:  // 屏蔽基类函数
    using DetectorBodyRelated::setDirection;
    using DetectorBodyRelated::setGoal;
};


/*! @} */

AST_NAMESPACE_END

