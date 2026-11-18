/// @file      StateVector.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-08

#pragma once

#include "AstGlobal.h"
#include "Calculation.hpp"

AST_NAMESPACE_BEGIN


class AST_CALC_API StateVector : public Calculation
{
public:
    StateVector() = default;
    ~StateVector() = default;
    errc_t evaluate(const TimePoint& tp, double& result) const override;
};

AST_NAMESPACE_END
