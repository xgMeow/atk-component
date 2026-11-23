/// @file      EventDetector.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-27

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEEventDetector.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstUtil/Dimension.hpp"

AST_NAMESPACE_BEGIN


class SpacecraftState;
class ODEEventDetector;
class StateMapper;

/// @brief 事件检测基类
/// 事件检测基类，用于检测事件是否发生。
/// 参考orekit的EventDetector类
class AST_CORE_API EventDetector: public ObjectNamed
{
public:
    using EDirection = ODEEventDetector::EDirection;
    AST_OBJECT(EventDetector)
    AST_PROPERT(active)
    AST_PROPERT(repeatCount)
    AST_PROPERT(threshold)
    AST_PROPERT(goal)
    EventDetector() = default;
    virtual ~EventDetector() = default;

    /// @brief 获取事件检测开关函数与目标值的差值
    /// @param state 航天器状态
    /// @param t 时间（相对于预报器参考时间的秒数）
    /// @return 事件检测开关函数与目标值的差值
    virtual double getDifference(const SpacecraftState& state, double t) const{return getValue(state, t) - goal_;}

    /// @brief 获取事件检测开关函数的值
    /// @param state 航天器状态
    /// @param t 时间（相对于预报器参考时间的秒数）
    /// @return 事件检测开关函数的值
    virtual double getValue(const SpacecraftState& state, double t) const = 0;

    /// @brief 获取事件检测开关函数的量纲
    /// @return 事件检测开关函数的量纲
    virtual Dimension getDimension() const {return EDimension::eUnit;}

    /// @brief 是否为角度事件检测器
    /// @return 是否为角度事件检测器
    bool isAngle() const {return getDimension() == EDimension::eAngle;}
public:

    /// @brief 创建ODE事件检测器实例
    /// @param stateMapper 状态映射器
    /// @return ODE事件检测器实例指针
    /// @note ODE事件检测器实例的生命周期由调用方负责管理，调用方需要在使用完成后调用析构函数释放资源
    ODEEventDetector* newODEEventDetector(StateMapper* stateMapper) const;

public: // rtti 暂时不支持枚举类型

    EDirection direction() const {return direction_;}
    void setDirection(EDirection dir) {direction_ = dir;}

PROPERTIES:

    bool active() const {return active_;}
    void setActive(bool active) {active_ = active;}

    int repeatCount() const {return repeatCount_;}
    void setRepeatCount(int count) {repeatCount_ = count;}


    double threshold() const {return threshold_;}
    void setThreshold(double threshold) {threshold_ = threshold;}

    double goal() const {return goal_;}
    void setGoal(double goal) {goal_ = goal;}

private:
    bool        active_{true};                  ///< 是否激活
    int         repeatCount_{1};                ///< 事件触发后的重复次数
    EDirection  direction_{EDirection::eBoth};  ///< 事件检测开关函数的方向
    double      threshold_{1e-10};              ///< 事件检测开关函数的阈值
    double      goal_{0.0};                     ///< 事件检测的目标值
};


/// @brief 泛型事件检测器
/// @details 
template<typename Func>
class EventDetectorGeneric: public EventDetector
{
public:
    explicit EventDetectorGeneric(Func func) 
        : func_(std::move(func)) 
    {}

    double getValue(const SpacecraftState& state, double t) const override {
        return func_(state, t);
    }

private:
    Func func_;
};


AST_NAMESPACE_END
