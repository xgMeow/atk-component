/// @file      Atmosphere.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-08

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/




/// @brief 大气模型基类
/// @details 大气模型基类，定义了大气模型的基本接口，参考了orekit的Atmosphere接口
/// 关于 Atmosphere 接口的抽象设计：
/// 1. 核心抽象接口只包含所有大气模型接口的交集。
///    例如，有些大气模型需要太阳位置、F10.7 指数等参数，而有些则不需要。
///    这类“非必需”参数不出现在核心抽象接口中，以避免接口臃肿。
///    但它们可以作为子类模型的配置参数，或通过依赖注入（如注入抽象的 Provider、Frame、Shape 等接口）来提供。
/// 
/// 2. 考虑到接口的可重入性（即同一实例可在多线程中安全并发调用，且不依赖内部可变状态），
///    应将仿真中随时间变化的动态参数（如时间点、位置）直接作为方法的输入参数。
///    其他动态数据（如太阳活动指数）可通过依赖注入的方式由实现类自行获取；
///    纬度、经度、高度等几何量可从输入位置直接计算得到。
class AST_CORE_API Atmosphere
{
public:
    virtual ~Atmosphere() = default;

    /// @brief 获取大气密度
    /// @param tp 当前时间
    /// @param posInBodyFixed 当前位置(相对于getFrame()返回的坐标系)
    /// @return 大气密度（单位：kg/m³）
    virtual double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const = 0;

    /// @brief 获取大气模型的参考坐标系
    virtual Frame* getFrame() const = 0;

    /// @brief 获取大气模型对应的天体形状
    virtual BodyShape* getShape() const;

protected:
    double getAltitude(const Vector3d& posInBodyFixed) const;
};

/*! @} */

AST_NAMESPACE_END
