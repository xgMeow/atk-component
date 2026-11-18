/// @file      Propagate.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "MissionCommand.hpp"
#include "Segment.hpp"
#include "AstCore/HPOP.hpp"
#include "AstCore/EventDetector.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 预报段，用于建模任务序列(MissionCommand)中的轨道预报
class AST_CORE_API Propagate: public Segment
{
public:
    AST_OBJECT(Propagate)
    AST_PROPERT(minPropTime)
    AST_PROPERT(maxPropTime)
    AST_PROPERT(useMaxPropTime)
    AST_PROPERT(useMaxPropTimeWarn)
    AST_PROPERT(overrideMaxPropTime)
    Propagate();
    ~Propagate() = default;

    /// @brief 预报方向
    enum EDirection
    {
        eBackward = -1,     ///< 逆向预报
        eAuto = 0,          ///< 自动
        eForward = 1,       ///< 正向预报
    };
public:
    errc_t execute() override;
public:
    HPOP* propagator() const { return propagator_.get(); }
    void setPropagator(HPOP* propagator) { propagator_ = propagator; }
    void addEventDetector(EventDetector* eventDetector) { eventDetectors_.push_back(eventDetector); }
    EventDetector* getEventDetector(StringView name) const;
    const std::vector<SharedPtr<EventDetector>>& eventDetectors() const { return eventDetectors_; }
    void setEventDetectors(const std::vector<SharedPtr<EventDetector>>& eventDetectors) { eventDetectors_ = eventDetectors; }

    EDirection direction() const { return direction_; }
    void setDirection(EDirection direction) { direction_ = direction; }
PROPERTIES:
    double minPropTime() const { return minPropTime_; }
    void setMinPropTime(double minPropTime) { minPropTime_ = minPropTime; }

    double maxPropTime() const { return maxPropTime_; }
    void setMaxPropTime(double maxPropTime) { maxPropTime_ = maxPropTime; }

    bool useMaxPropTime() const { return useMaxPropTime_; }
    void setUseMaxPropTime(bool useMaxPropTime) { useMaxPropTime_ = useMaxPropTime; }

    bool useMaxPropTimeWarn() const { return useMaxPropTimeWarn_; }
    void setUseMaxPropTimeWarn(bool useMaxPropTimeWarn) { useMaxPropTimeWarn_ = useMaxPropTimeWarn; }

    bool overrideMaxPropTime() const { return overrideMaxPropTime_; }
    void setOverrideMaxPropTime(bool overrideMaxPropTime) { overrideMaxPropTime_ = overrideMaxPropTime; }
private:
    WeakPtr<HPOP> propagator_{};                                    ///< 轨道预报器
    std::vector<SharedPtr<EventDetector>> eventDetectors_{};        ///< 事件检测器
    double minPropTime_{0};                                       ///< 最小预报时间??
    double maxPropTime_{8640000};                                 ///< 最大预报时间
    bool useMaxPropTime_{true};                                   ///< 是否使用最大预报时间
    bool useMaxPropTimeWarn_{true};                               ///< 是否警告最大预报时间超过最大预报时间
    bool overrideMaxPropTime_{true};                              ///< ???
    EDirection direction_{eAuto};                                 ///< 预报方向
};




/*! @} */

AST_NAMESPACE_END
