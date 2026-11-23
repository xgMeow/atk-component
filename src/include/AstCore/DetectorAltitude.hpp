/// @file      DetectorAltitude.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"
#include "DetectorBodyRelated.hpp"

AST_NAMESPACE_BEGIN

class AST_CORE_API DetectorAltitude : public DetectorBodyRelated
{
public:
    AST_OBJECT(DetectorAltitude)
    DetectorAltitude() = default;
    double getValue(const SpacecraftState& state, double t) const override;
};

AST_NAMESPACE_END
