/// @file      BuiltinAxes.hpp
/// @brief     内置轴系
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-05

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"
#include "AstCore/AxesRoot.hpp"
#include "AstCore/AxesICRF.hpp"
#include "AstCore/AxesMacro.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/


_AST_DECL_AXES(ECF)
_AST_DECL_AXES(J2000)
_AST_DECL_AXES(MOD)
_AST_DECL_AXES(TOD)
_AST_DECL_AXES(GTOD)
_AST_DECL_AXES(TEME)

_AST_DECL_AXES(B1950Vallado)
_AST_DECL_AXES(B1950Spice)
_AST_DECL_AXES(FK4)
_AST_DECL_AXES(DE118)
_AST_DECL_AXES(DE96)
_AST_DECL_AXES(DE102)
_AST_DECL_AXES(DE108)
_AST_DECL_AXES(DE111)
_AST_DECL_AXES(DE114)
_AST_DECL_AXES(DE122)
_AST_DECL_AXES(DE125)
_AST_DECL_AXES(DE130)
_AST_DECL_AXES(Galactic)
_AST_DECL_AXES(DE200)
_AST_DECL_AXES(DE202)
_AST_DECL_AXES(MarsIAU)
_AST_DECL_AXES(EclipJ2000)
_AST_DECL_AXES(EclipB1950)
_AST_DECL_AXES(DE140)
_AST_DECL_AXES(DE142)
_AST_DECL_AXES(DE143)
_AST_DECL_AXES(MeanEarth)
_AST_DECL_AXES(PA)
_AST_DECL_AXES(PA403)
_AST_DECL_AXES(PA418)
_AST_DECL_AXES(PA421)
_AST_DECL_AXES(PA430)

A_ALWAYS_INLINE Axes* aAxesECI()
{
    return aAxesICRF();
}

/// @brief      获取轴系
/// @param      name 轴系名称
/// @return     轴系指针
AST_CORE_CAPI Axes* aGetAxes(StringView name);

/*! @} */

AST_NAMESPACE_END
