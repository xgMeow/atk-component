/// @file      Vector.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-14

#pragma once

#include "AstGlobal.h"
#include "AstMath/Vector.hpp"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/

/// @brief 向量抽象基类
/// @details 向量是一种几何元素，表示三维空间中具有大小和方向的量。
///          所有具体向量类型（计算向量、常量向量等）均派生自此类。
class AST_CORE_API Vector : public ObjectNamed
{
public:
    AST_OBJECT(Vector)

    Vector() = default;
    ~Vector() override = default;

    /// @brief 获取向量所在的参考坐标系
    /// @return 向量所在的参考坐标系指针
    virtual Axes *getAxes() const = 0;

    /// @brief 获取向量在指定时间点的值，相对于向量的参考坐标系
    /// @param tp 时间点
    /// @param vec 输出参数，向量的值
    /// @return 错误码
    virtual errc_t getVector(const TimePoint &tp, Vector3d &vec) const = 0;

    /// @brief 获取向量在指定时间点的位置和速度，相对于向量的参考坐标系
    /// @param tp 时间点
    /// @param vec 输出参数，向量的值
    /// @param vel 输出参数，向量的速度向量
    /// @return 错误码
    virtual errc_t getVector(const TimePoint &tp, Vector3d &vec, Vector3d &vel) const = 0;

    /// @brief 获取向量在指定时间点的位置、速度和加速度，相对于向量的参考坐标系
    /// @details 默认实现由速度的中心差分给出加速度；有解析加速度的点应当重写本函数。
    /// @param tp 时间点
    /// @param vec 输出参数，向量的值
    /// @param vel 输出参数，向量的速度向量
    /// @param acc 输出参数，向量的加速度向量
    /// @return 错误码
    virtual errc_t getVector(const TimePoint &tp, Vector3d &vec, Vector3d &vel, Vector3d &acc) const;

    /// @brief 获取向量在指定轴系下的值
    /// @param targetAxes 目标轴系指针
    /// @param tp 时间点
    /// @param vec 输出参数，向量在目标轴系下的值
    /// @return 错误码
    errc_t getVectorIn(Axes *targetAxes, const TimePoint &tp, Vector3d &vec) const;
    errc_t getVectorIn(Axes& targetAxes, const TimePoint &tp, Vector3d &vec) const;

    /// @brief 获取向量在指定轴系下的值和速度
    /// @param targetAxes 目标轴系指针
    /// @param tp 时间点
    /// @param vec 输出参数，向量在目标轴系下的值
    /// @param vel 输出参数，向量在目标轴系下的速度
    /// @return 错误码
    errc_t getVectorIn(Axes *targetAxes, const TimePoint &tp, Vector3d &vec, Vector3d &vel) const;
    errc_t getVectorIn(Axes& targetAxes, const TimePoint &tp, Vector3d &vec, Vector3d &vel) const;

    /// @brief 获取向量在指定轴系下的值、速度和加速度
    /// @param targetAxes 目标轴系指针
    /// @param tp 时间点
    /// @param vec 输出参数，向量在目标轴系下的值
    /// @param vel 输出参数，向量在目标轴系下的速度
    /// @param acc 输出参数，向量在目标轴系下的加速度
    /// @return 错误码
    errc_t getVectorIn(Axes *targetAxes, const TimePoint &tp, Vector3d &vec, Vector3d &vel, Vector3d &acc) const;
    errc_t getVectorIn(Axes& targetAxes, const TimePoint &tp, Vector3d &vec, Vector3d &vel, Vector3d &acc) const;

    /// @brief 获取向量在指定坐标系下的值（仅使用坐标系的轴系部分，忽略原点平移）
    /// @param targetFrame 目标坐标系指针
    /// @param tp 时间点
    /// @param vec 输出参数，向量在目标坐标系下的值
    /// @return 错误码
    errc_t getVectorIn(Frame *targetFrame, const TimePoint &tp, Vector3d &vec) const;
    errc_t getVectorIn(Frame& targetFrame, const TimePoint &tp, Vector3d &vec) const;

    /// @brief 获取向量在指定坐标系下的值和速度（仅使用坐标系的轴系部分，忽略原点平移）
    /// @param targetFrame 目标坐标系指针
    /// @param tp 时间点
    /// @param vec 输出参数，向量在目标坐标系下的值
    /// @param vel 输出参数，向量在目标坐标系下的速度
    /// @return 错误码
    errc_t getVectorIn(Frame *targetFrame, const TimePoint &tp, Vector3d &vec, Vector3d &vel) const;
    errc_t getVectorIn(Frame& targetFrame, const TimePoint &tp, Vector3d &vec, Vector3d &vel) const;

    /// @brief 获取向量在指定坐标系下的值、速度和加速度（仅使用坐标系的轴系部分，忽略原点平移）
    /// @param targetFrame 目标坐标系指针
    /// @param tp 时间点
    /// @param vec 输出参数，向量在目标坐标系下的值
    /// @param vel 输出参数，向量在目标坐标系下的速度
    /// @param acc 输出参数，向量在目标坐标系下的加速度
    /// @return 错误码
    errc_t getVectorIn(Frame *targetFrame, const TimePoint &tp, Vector3d &vec, Vector3d &vel, Vector3d &acc) const;
    errc_t getVectorIn(Frame& targetFrame, const TimePoint &tp, Vector3d &vec, Vector3d &vel, Vector3d &acc) const;
};


using PVector = Vector*;                ///< 向量指针(pointer to vector)
using HVector = SharedPtr<Vector>;      ///< 向量句柄(handle to vector)

/*! @} */

AST_NAMESPACE_END
