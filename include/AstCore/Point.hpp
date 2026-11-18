/// @file      Point.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-09

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Geometry
    @{
*/

class Frame;
class CelestialBody;

/// @brief 点抽象基类
/// @details 点是一种几何元素，表示三维空间中的一个位置。
///          所有具体点类型（天体中心点、行星历表点等）均派生自此类。
class AST_CORE_API Point: public ObjectNamed
{
public:
    AST_OBJECT(Point)

    Point() = default;
    ~Point() override = default;

    /// @brief 将点转换为天体
    /// @return 天体指针
    CelestialBody* toBody() const;

    /// @brief 获取点所在的参考坐标系
    /// @return 点所在的参考坐标系指针
    virtual Frame* getFrame() const = 0;

    /// @brief 获取点在指定时间点的位置，相对于点的参考坐标系
    /// @param tp 时间点
    /// @param pos 输出参数，点的位置向量
    /// @return 错误码
    virtual errc_t getPos(const TimePoint& tp, Vector3d& pos) const = 0;

    /// @brief 获取点在指定时间点的位置和速度，相对于点的参考坐标系
    /// @param tp 时间点
    /// @param pos 输出参数，点的位置向量
    /// @param vel 输出参数，点的速度向量
    /// @return 错误码
    virtual errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const = 0;

    /// @brief 获取点在指定时间点的位置、速度和加速度，相对于点的参考坐标系
    /// @details 默认实现由速度的中心差分给出加速度；有解析加速度的点应当重写本函数。
    /// @param tp 时间点
    /// @param pos 输出参数，点的位置向量
    /// @param vel 输出参数，点的速度向量
    /// @param acc 输出参数，点的加速度向量
    /// @return 错误码
    virtual errc_t getPosVelAcc(const TimePoint& tp, Vector3d& pos, Vector3d& vel, Vector3d& acc) const;

    /// @brief 获取点的时段，表示点在空间中的存在时间范围
    /// @details 默认实现返回全时间段
    /// @param interval 输出参数，点的时段
    virtual errc_t getInterval(TimeInterval& interval) const;

    /// @brief 获取点在指定时间点的位置，相对于指定参考坐标系
    /// @param frame 参考坐标系指针
    /// @param tp 时间点
    /// @param pos 输出参数，点的位置向量
    /// @return 错误码
    errc_t getPosIn(Frame* frame, const TimePoint& tp, Vector3d& pos) const;
    errc_t getPosIn(Frame& frame, const TimePoint& tp, Vector3d& pos) const;

    /// @brief 获取点在指定时间点的位置和速度，相对于指定参考坐标系
    /// @param frame 参考坐标系指针
    /// @param tp 时间点
    /// @param pos 输出参数，点的位置向量
    /// @param vel 输出参数，点的速度向量
    /// @return 错误码
    errc_t getPosVelIn(Frame* frame, const TimePoint& tp, Vector3d& pos, Vector3d& vel) const;
    errc_t getPosVelIn(Frame& frame, const TimePoint& tp, Vector3d& pos, Vector3d& vel) const;

    /// @brief 获取点在指定时间点的位置、速度和加速度，相对于指定参考坐标系
    /// @param frame 参考坐标系指针
    /// @param tp 时间点
    /// @param pos 输出参数，点的位置向量
    /// @param vel 输出参数，点的速度向量
    /// @param acc 输出参数，点的加速度向量
    /// @return 错误码
    errc_t getPosVelAccIn(Frame* frame, const TimePoint& tp, Vector3d& pos, Vector3d& vel, Vector3d& acc) const;
    errc_t getPosVelAccIn(Frame& frame, const TimePoint& tp, Vector3d& pos, Vector3d& vel, Vector3d& acc) const;

    /// @brief 获取点在指定时间段内的位置列表，相对于指定参考坐标系
    /// @param frame 坐标系
    /// @param range 时间点范围
    /// @param posList 输出参数，点的位置向量列表
    /// @return 错误码
    errc_t getPosIn(Frame* frame, const TimePointRange& range, std::vector<Vector3d>& posList) const;

    /// @brief 获取点在指定时间段内的位置列表和速度列表，相对于指定参考坐标系
    /// @param frame 坐标系
    /// @param range 时间点范围
    /// @param posList 输出参数，点的位置向量列表
    /// @param velList 输出参数，点的速度向量列表
    /// @return 错误码
    errc_t getPosVelIn(Frame* frame, const TimePointRange& range, std::vector<Vector3d>& posList, std::vector<Vector3d>& velList) const;

};

using PPoint = Point*;                ///< 点指针(pointer to point)
using HPoint = SharedPtr<Point>;      ///< 点句柄(handle to point)

/*! @} */

AST_NAMESPACE_END
