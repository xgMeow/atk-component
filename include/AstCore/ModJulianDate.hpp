/// @file      ModJulianDate.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      30.11.2025

#pragma once

#include "AstGlobal.h"
#include "JulianDate.hpp"

AST_NAMESPACE_BEGIN


/*!
    @addtogroup Time
    @{
*/

/// @brief 简约儒略日
class ModJulianDate: protected JulianDate
{
public:
    using JulianDate::JulianDate;

    using JulianDate::day;
    using JulianDate::second;
    using JulianDate::setDay;
    using JulianDate::setSecond;
    using JulianDate::getDaySecond;
    using JulianDate::setDaySecond;
    using JulianDate::dayFractional;
    using JulianDate::setDayFractional;

    using JulianDate::impreciseDay;
    using JulianDate::setImpreciseDay;

    using JulianDate::operator +=;
    using JulianDate::operator -=;
    using JulianDate::operator +;
    using JulianDate::operator -;


};


/*! @} */

AST_NAMESPACE_END

