/// @file      EclipseCalculator.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-10

#pragma once

#include "AstGlobal.h"
#include "AstCore/CelestialBody.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 阴影光照计算器
class AST_CORE_API EclipseCalculator
{
public:
    EclipseCalculator() = default;
    explicit EclipseCalculator(CelestialBody* lightSource)
        : lightSource_(lightSource)
    {
    }
    virtual ~EclipseCalculator() = default;

    /// @brief 计算光照强度
    /// @param time 时间点
    /// @param position 观测者位置（相对于观测者所在参考系）
    /// @param frame 观测者所在参考系
    /// @return 光照强度, 0: 全阴影, 1: 全光照，0-1: 部分遮挡/光照
    virtual double getLightingRatio(const TimePoint& time, const Vector3d& position, Frame* frame) = 0;

    /// @brief 获取光源体
    CelestialBody* lightSource() const {return lightSource_;}

    /// @brief 设置光源体
    void setLightSource(CelestialBody* lightSource) {lightSource_ = lightSource;}

    /// @brief 设置遮挡体列表
    void setOccultingBodies(const std::vector<HCelestialBody>& occultingBodies) {occultingBodies_ = occultingBodies;}

    /// @brief 添加遮挡体
    void addOccultingBody(HCelestialBody occultingBody) {occultingBodies_.push_back(occultingBody);}
protected:
    HCelestialBody lightSource_{nullptr};           ///< 光源体
    std::vector<HCelestialBody> occultingBodies_{};   ///< 阴影体列表
};



/*! @} */

AST_NAMESPACE_END
