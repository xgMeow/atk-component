/// @file      SunSynchronousOrbitDesigner.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"
#include "BaseOrbitDesigner.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Orbit
    @{
*/


/// @brief 太阳同步轨道设计器
class AST_CORE_API SunSynchronousOrbitDesigner final: public BaseOrbitDesigner
{
public:
    enum EGeometryDefinition
    {
        eAltitude = 0,
        eInclination = 1,
    };
    enum ENodeDefinition
    {
        eAscendingNode = 0,
        eDescendingNode = 1,
    };
    SunSynchronousOrbitDesigner();
    explicit SunSynchronousOrbitDesigner(CelestialBody *body);
    ~SunSynchronousOrbitDesigner() = default;
    errc_t getOrbitState(ModOrbElem &orbElem) const override;

    /// @brief 获取几何定义方式
    EGeometryDefinition getGeometryDefinition() const { return geometryDefinition_; }
    /// @brief 设置几何定义方式
    void setGeometryDefinition(EGeometryDefinition def) { geometryDefinition_ = def; }
    /// @brief 获取升交点定义方式
    ENodeDefinition getNodeDefinition() const { return nodeDefinition_; }
    /// @brief 设置升交点定义方式
    void setNodeDefinition(ENodeDefinition def) { nodeDefinition_ = def; }

    /// @brief 计算轨道倾角
    double calcInclination(double alt) const;
    /// @brief 计算轨道倾角
    double calcInclination() const;
    /// @brief 计算轨道高度
    double calcAltitude(double inc) const;
    /// @brief 计算轨道高度
    double calcAltitude() const;

    /// @brief 获取轨道倾角
    double getInclination() const;

    /// @brief 设置轨道倾角
    void setInclination(double inc);

    /// @brief 获取轨道高度
    double getAltitude() const;

    /// @brief 设置轨道高度
    void setAltitude(double alt);

    double getLocalTimeOfAscendingNode() const { return localTimeOfAscendingNode_; }
    void setLocalTimeOfAscendingNode(double t) { localTimeOfAscendingNode_ = t; }
private:
    EGeometryDefinition geometryDefinition_{eAltitude};
    ENodeDefinition     nodeDefinition_{eAscendingNode};
    double              inclination_{0};
    double              altitude_{0};
    double              localTimeOfAscendingNode_{0};
    double              localTimeOfDescendingNode_{0};
};


/*! @} */

AST_NAMESPACE_END
