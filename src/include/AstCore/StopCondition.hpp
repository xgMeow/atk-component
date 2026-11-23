/// @file      StopCondition.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-27

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"

AST_NAMESPACE_BEGIN

/*
GMAT的StopCondition 和 orekit的EventDetector有什么区别？
*/

/// @brief 停止条件检测基类
/// 参考GMAT的StopCondition类
class AST_CORE_API StopCondition : public EventDetector
{
public:
    StopCondition() = default;
    virtual ~StopCondition() = default;
};



AST_NAMESPACE_END
