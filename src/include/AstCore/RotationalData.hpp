/// @file      RotationalData.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-20

#pragma once

#include "AstGlobal.h"
#include "RotationElement.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstMath/Transform.hpp"
#include "AstMath/Rotation.hpp"
#include "BodyOrientation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/


/// @brief 行星旋转数据
/// @details 描述行星旋转状态的系数
class AST_CORE_API RotationalData final: public BodyOrientation
{
public:
    AST_OBJECT(RotationalData)
    RotationalData() = default;
    ~RotationalData() = default;
    errc_t load(StringView filepath);


    /// @brief 获取ICRF到天体固连系的旋转
    /// @param tp 时间点
    /// @param rot 旋转
    void getICRFToFixedTransform(const TimePoint& tp, Rotation &rot) const override;


    /// @brief 获取ICRF到天体固连系的旋转变换
    /// @param tp 时间点
    /// @param rotation 旋转变换
    void getICRFToFixedTransform(const TimePoint& tp, KinematicRotation &rotation) const override;


    /// @brief 获取ICRF到天体惯性系的旋转
    /// @param tp 时间点
    /// @param rot 旋转
    void getICRFToInertialTransform(const TimePoint& tp, Rotation &rot) const override;


    Axes* getMODParent() const override;
    void getMODTransform(const TimePoint& tp, Rotation &rot) const override;
    Axes* getTODParent() const override;
    void getTODTransform(const TimePoint& tp, Rotation &rot) const override;

    /// @brief 获取天体惯性系到天体固连系的旋转
    /// @param tp 时间点
    /// @param rot 旋转
    void getInertialToFixedTransform(const TimePoint& tp, Rotation &rot) const;

    /// @brief 获取ICRF到MOD系的旋转    
    /// @param tp 时间点
    /// @param rot 旋转
    void getICRFToMODTransform(const TimePoint& tp, Rotation &rot) const;

    /// @brief 获取ICRF到TOD系的旋转
    /// @param tp 时间点
    /// @param rot 旋转
    void getICRFToTODTransform(const TimePoint& tp, Rotation &rot) const;


    /// @brief 获取ICRF到天体固连系的旋转矩阵
    /// @param tp 时间点
    /// @param matrix 矩阵
    void getICRFToFixedMatrix(const TimePoint& tp, Matrix3d &matrix) const;


    /// @brief 获取ICRF到天体惯性系的旋转矩阵
    /// @param tp 时间点
    /// @param matrix 矩阵
    void getICRFToInertialMatrix(const TimePoint& tp, Matrix3d &matrix) const;


    /// @brief 获取ICRF到MOD系的旋转矩阵
    /// @param tp 时间点
    /// @param matrix 矩阵
    void getICRFToMODMatrix(const TimePoint& tp, Matrix3d &matrix) const;


    /// @brief 获取ICRF到TOD系的旋转矩阵
    /// @param tp 时间点
    /// @param matrix 矩阵
    void getICRFToTODMatrix(const TimePoint& tp, Matrix3d &matrix) const;



protected:
    TimePoint rotationEpoch_{};          ///< 旋转历元
    RotationElement rightAscension_{};
    RotationElement declination_{};
    RotationElement rotation_{};
};

/*! @} */

AST_NAMESPACE_END
