/// @file      DetectorCartesian.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"

AST_NAMESPACE_BEGIN

class AST_CORE_API DetectorCartesian : public EventDetector
{
public:
    AST_OBJECT(DetectorCartesian)
    DetectorCartesian() = default;
    double getValue(const SpacecraftState& state, double t) const override;
};

AST_NAMESPACE_END
