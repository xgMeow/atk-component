/// @file      MoonFrame.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-29

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

class Rotation;
class KinematicRotation;

/// @brief 计算地球ICRF坐标系到月球ICRF坐标系的转换
/// @note 该函数依赖DE星历数据
/// @param tp 时间点
/// @param posInEarthICRF 地球ICRF坐标系下的位置向量
/// @param posInMoonICRF 月球ICRF坐标系下的位置向量
/// @return errc_t 错误码
AST_CORE_API errc_t aEarthICRFToMoonICRF(
    const TimePoint& tp, 
    const Vector3d&  posInEarthICRF, 
    Vector3d&        posInMoonICRF
);


/// @brief 计算地球ICRF坐标系到月球ICRF坐标系的转换
/// @note 该函数依赖DE星历数据
/// @param tp 时间点
/// @param posInEarthICRF 地球ICRF坐标系下的位置向量
/// @param velInEarthICRF 地球ICRF坐标系下的速度向量
/// @param posInMoonICRF 月球ICRF坐标系下的位置向量
/// @param velInMoonICRF 月球ICRF坐标系下的速度向量
/// @return errc_t 错误码
AST_CORE_API errc_t aEarthICRFToMoonICRF(
    const TimePoint& tp, 
    const Vector3d&  posInEarthICRF, 
    const Vector3d&  velInEarthICRF,
    Vector3d&        posInMoonICRF,  
    Vector3d&        velInMoonICRF
);


/// @brief 计算月球ICRF坐标系到地球ICRF坐标系的转换
/// @note 该函数依赖DE星历数据
/// @param tp 时间点
/// @param posInMoonICRF 月球ICRF坐标系下的位置向量
/// @param posInEarthICRF 地球ICRF坐标系下的位置向量
/// @return errc_t 错误码
AST_CORE_API errc_t aMoonICRFToEarthICRF(
    const TimePoint& tp, 
    const Vector3d&  posInMoonICRF, 
    Vector3d&        posInEarthICRF
);


/// @brief 计算月球ICRF坐标系到地球ICRF坐标系的转换
/// @note 该函数依赖DE星历数据
/// @param tp 时间点
/// @param posInMoonICRF 月球ICRF坐标系下的位置向量
/// @param velInMoonICRF 月球ICRF坐标系下的速度向量
/// @param posInEarthICRF 地球ICRF坐标系下的位置向量
/// @param velInEarthICRF 地球ICRF坐标系下的速度向量
/// @return errc_t 错误码
AST_CORE_API errc_t aMoonICRFToEarthICRF(
    const TimePoint& tp, 
    const Vector3d&  posInMoonICRF, 
    const Vector3d&  velInMoonICRF,
    Vector3d&        posInEarthICRF,
    Vector3d&        velInEarthICRF
);


/// @brief 计算ICRF到月球主轴系(PA)的转换
/// @note 该函数依赖DE星历数据里的月球平动角
/// @param tp 时间点
/// @param rotation 旋转矩阵
/// @return errc_t 错误码
AST_CORE_API errc_t aICRFToMoonPrincipalAxesTransform(
    const TimePoint& tp, 
    Rotation&        rotation
);


/// @brief 计算ICRF到月球主轴系(PA)的转换
/// @note 该函数依赖DE星历数据里的月球平动角
/// @param tp 时间点
/// @param rotation 运动学旋转
/// @return errc_t 错误码
AST_CORE_API errc_t aICRFToMoonPrincipalAxesTransform(
    const TimePoint& tp, 
    KinematicRotation&  rotation
);

/// @brief 计算ICRF到月球主轴系(PA)的转换
/// @note 该函数依赖DE星历数据里的月球平动角
/// @todo 还未实现该函数，需要实现旋转角速度的计算
/// @param tp 时间点
/// @param rotation 旋转矩阵
/// @return errc_t 错误码
// AST_CORE_API errc_t aICRFToMoonPrincipalAxesTransform(
//     const TimePoint& tp, 
//     KinematicRotation& rotation
// );


/// @brief 计算月球主轴系(PA)到月球MeanEarth系的转换
/// @note 该函数依赖DE星历数据
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI errc_t aMoonPAToMeanEarthTransform(
    Rotation&        rotation
);


/// @brief 计算月球主轴系(PA430)到月球MeanEarth系的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonPA430ToMeanEarthTransform(
    Rotation&        rotation
);

/// @brief 计算月球MeanEarth系到月球主轴系(PA430)的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonMeanEarthToPA430Transform(
    Rotation&        rotation
);


/// @brief 计算月球主轴系(PA421)到月球MeanEarth系的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonPA421ToMeanEarthTransform(
    Rotation& rotation
);

/// @brief 计算月球MeanEarth系到月球主轴系(PA421)的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonMeanEarthToPA421Transform(
    Rotation&        rotation
);


/// @brief 计算月球主轴系(PA418)到月球MeanEarth系的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonPA418ToMeanEarthTransform(
    Rotation&        rotation
);

/// @brief 计算月球MeanEarth系到月球主轴系(PA418)的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonMeanEarthToPA418Transform(
    Rotation&        rotation
);


/// @brief 计算月球主轴系(PA403)到月球MeanEarth系的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonPA403ToMeanEarthTransform(
    Rotation& rotation
);


/// @brief 计算月球MeanEarth系到月球主轴系(PA403)的转换
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_CAPI void aMoonMeanEarthToPA403Transform(
    Rotation&        rotation
);

/// @brief 计算月球ICRF坐标系到月球MeanEarth系的转换(依赖DE星历)
/// @note 该函数依赖DE星历数据
/// @param tp 时间点
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_API errc_t aICRFToMoonMeanEarthTransform_DE(
    const TimePoint& tp, 
    Rotation&        rotation
);


/// @brief 计算月球ICRF坐标系到月球MeanEarth系的转换(依赖DE星历)
/// @note 该函数依赖DE星历数据
/// @param tp 时间点
/// @param rotation 运动学旋转
/// @return errc_t 错误码
AST_CORE_API errc_t aICRFToMoonMeanEarthTransform_DE(
    const TimePoint& tp, 
    KinematicRotation& rotation
);


/// @brief 计算月球ICRF坐标系到月球MeanEarth系的转换(依赖IAU旋转系数)
/// @todo 还未实现该函数
/// @param tp 
/// @param rotation 
/// @return 
// AST_CORE_CAPI errc_t aICRFToMoonMeanEarthTransform_IAU(
//     const TimePoint& tp, 
//     Rotation&        rotation
// );

/// @brief 计算月球ICRF坐标系到月球MeanEarth系的转换(默认为DE实现)
/// @param tp 时间点
/// @param rotation 旋转
/// @return errc_t 错误码
AST_CORE_API errc_t aICRFToMoonMeanEarthTransform(
    const TimePoint& tp, 
    Rotation&        rotation
);


/// @brief 计算月球ICRF坐标系到月球MeanEarth系的转换(默认为DE实现)
/// @param tp 时间点
/// @param rotation 运动学旋转
/// @return errc_t 错误码
AST_CORE_API errc_t aICRFToMoonMeanEarthTransform(
    const TimePoint& tp, 
    KinematicRotation& rotation
);

/*! @} */


AST_NAMESPACE_END
