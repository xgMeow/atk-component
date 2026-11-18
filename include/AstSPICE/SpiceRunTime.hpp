/// @file      SpiceRunTime.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-05

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Spice
    @{
*/
class Axes;
class CelestialBody;
class TimePoint;

/// @brief 查找指定名称的参考系统轴
/// @param name 参考系统名称
/// @return 指向 Axes 实例的指针，如果未找到则为 nullptr
AST_SPICE_CAPI Axes* aSpiceFindAxes(StringView name);

/// @brief 查找指定名称的天体
/// @param name 天体名称
/// @return 指向 CelestialBody 实例的指针，如果未找到则为 nullptr
AST_SPICE_API CelestialBody* aSpiceFindBody(StringView name);

/// @brief 查找指定 ID 的天体
/// @param id 天体 ID
/// @return 指向 CelestialBody 实例的指针，如果未找到则为 nullptr
AST_SPICE_API CelestialBody* aSpiceFindBody(int id);



/*! @} */

AST_NAMESPACE_END
