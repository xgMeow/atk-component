/// @file      Eclipse.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 光照类型
enum class ELightingType
{
    eSunlight,  ///< 全光照
    ePenumbra,  ///< 半影
    eUmbra      ///< 本影（全食）
};



/// @brief 计算圆柱阴影模型下的光照比例
/// @details 圆柱模型假定光源为平行光（光源位于无穷远），遮挡体在光源反方向投射出
///          一个半径等于遮挡体半径的圆柱形阴影。观测者位于阴影圆柱内则全阴影（0），
///          否则全光照（1）。该模型无半影区，结果为二值。
/// @param position 观测者相对于遮挡体中心的位置向量
/// @param lightingSourcePos 光源相对于遮挡体中心的位置向量
/// @param occultingBodyRadius 遮挡体半径
/// @return 光照强度, 0: 全阴影, 1: 全光照
AST_CORE_API int aLightingRatio_CylindricalModel(const Vector3d& position, const Vector3d& lightingSourcePos, double occultingBodyRadius);


/// @brief 计算圆柱阴影模型下的光照比例（几何元素版本，位置向量输入）
/// @param tp 时间点
/// @param position 观测者位置
/// @param frame 观测者坐标系
/// @param lightSource 光源
/// @param occultingBody 遮挡体
/// @return 光照强度, 0: 全阴影, 1: 全光照
AST_CORE_API int aLightingRatio_CylindricalModel(const TimePoint& tp, const Vector3d& position, Frame* frame, CelestialBody* lightSource, CelestialBody* occultingBody);


/// @brief 计算圆柱阴影模型下的光照比例（几何元素版本）
/// @param tp 时间点
/// @param point 观测者位置
/// @param lightSource 光源
/// @param occultingBody 遮挡体
/// @return 光照强度, 0: 全阴影, 1: 全光照
AST_CORE_API int aLightingRatio_CylindricalModel(const TimePoint& tp, Point* point, CelestialBody* lightSource, CelestialBody* occultingBody);


/// @brief 计算双锥阴影模型下的光照比例
/// @details 双锥模型考虑光源的视张角（有限远光源），将光源和遮挡体分别视为以观测者
///          为顶点的圆锥。当两圆锥交叠时，按被遮挡立体角占光源总立体角的比例计算
///          半影光照强度。基于 "Solid Angle of Conical Surfaces, Polyhedral Cones,
///          and Intersecting Spherical Caps" 公式45。
/// @param position 观测者相对于遮挡体中心的位置向量
/// @param lightingSourcePos 光源相对于遮挡体中心的位置向量
/// @param lightingSourceRadius 光源半径
/// @param occultingBodyRadius 遮挡体半径
/// @return 光照强度, 0: 全阴影, 1: 全光照，0-1: 部分遮挡/光照（半影）
AST_CORE_API double aLightingRatio_DualConeModel(const Vector3d& position, const Vector3d& lightingSourcePos, double lightingSourceRadius, double occultingBodyRadius);


/// @brief 计算双锥阴影模型下的光照比例（几何元素版本，位置向量输入）
/// @param tp 时间点
/// @param position 观测者位置
/// @param frame 观测者坐标系
/// @param lightSource 光源
/// @param occultingBody 遮挡体
/// @return 光照强度, 0: 全阴影, 1: 全光照，0-1: 部分遮挡/光照（半影）
AST_CORE_API double aLightingRatio_DualConeModel(const TimePoint& tp, const Vector3d& position, Frame* frame, CelestialBody* lightSource, CelestialBody* occultingBody);


/// @brief 计算双锥阴影模型下的光照比例（几何元素版本）
/// @param tp 时间点
/// @param point 观测者位置
/// @param lightSource 光源
/// @param occultingBody 遮挡体
/// @return 光照强度, 0: 全阴影, 1: 全光照，0-1: 部分遮挡/光照（半影）
AST_CORE_API double aLightingRatio_DualConeModel(const TimePoint& tp, Point* point, CelestialBody* lightSource, CelestialBody* occultingBody);


/*! @} */

AST_NAMESPACE_END

