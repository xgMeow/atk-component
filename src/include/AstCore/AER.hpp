/// @file      AER.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-01

#pragma once

#include "AstGlobal.h"
#include "AstMath/Vector.hpp"
#include "TrackingCoordinates.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 通过NED坐标计算AER
AST_CORE_CAPI void aNEDToAER(const Vector3d& ned, AER& aer);

/// @brief 通过AER坐标计算NED坐标
AST_CORE_CAPI void aAERToNED(const AER& aer, Vector3d& ned);

/// @brief 通过ENU坐标计算AER
AST_CORE_CAPI void aENUToAER(const Vector3d& enu, AER& aer);

/// @brief 通过AER坐标计算ENU坐标
AST_CORE_CAPI void aAERToENU(const AER& aer, Vector3d& enu);


/// @brief 将天体固连系下的位置转换为局部球面坐标(AER)
/// @param  posInBodyFixed - 天体固连系下的位置
/// @param  origin         - 局部坐标系的原点
/// @param  aer            - 在局部坐标系下的AER坐标
/// @param  bodyShape      - 天体形状
AST_CORE_CAPI void aGeodeticToAER(const Vector3d& posInBodyFixed, const GeodeticPoint& origin, AER& aer, BodyShape* bodyShape);

// --------------------------------
// MATLAB Mapping Toolbox 同名函数
// ---------------------------------


A_ALWAYS_INLINE AER ned2aer(const Vector3d& ned)
{
    AER aer;
    aNEDToAER(ned, aer);
    return aer;
}

A_ALWAYS_INLINE Vector3d aer2ned(const AER& aer)
{
    Vector3d ned;
    aAERToNED(aer, ned);
    return ned;
}


A_ALWAYS_INLINE AER enu2aer(const Vector3d& enu)
{
    AER aer;
    aENUToAER(enu, aer);
    return aer;
}


A_ALWAYS_INLINE Vector3d aer2enu(const AER& aer)
{
    Vector3d enu;
    aAERToENU(aer, enu);
    return enu;
}

/*! @} */

AST_NAMESPACE_END


