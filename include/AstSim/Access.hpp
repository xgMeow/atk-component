/// @file      Access.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/BodyPosition.hpp"
#include "AstCore/TimeIntervalList.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

/// @brief 访问计算算法配置
struct AST_SIM_API AccessConfig
{
    bool            useLightTimeDelay_{true};                       ///< 是否应用光行时延迟
    EClockHost      clockHost_{EClockHost::eFirstObject};           ///< 时钟主机
    ETimeSense      timeSense_{ETimeSense::eTransmit};              ///< 信号传输方向
    EAberrationType aberrationType_{EAberrationType::eAnnual};      ///< 光行差类型
    double          maxTimeStep_{360.0};                            ///< 最大步长（秒）
    double          minTimeStep_{0.01};                             ///< 最小步长（秒）
    double          timeConvergence_{0.005};                        ///< 时间收敛阈值
    double          absValueConvergence_{1e-14};                    ///< 绝对值收敛阈值
    double          relValueConvergence_{1e-08};                    ///< 相对值收敛阈值
};

/// @brief 访问对象
/// @details 描述两个物体之间的可见性关系
class AST_SIM_API Access : public ObjectNamed
{
public:
    AST_OBJECT(Access)

    Access() = default;
    ~Access() override = default;

public: // 相关配置

    /// @name 主对象
    /// @{
    void setBaseObject(Object* obj) { baseObject_ = obj; }
    Object* baseObject() const { return baseObject_.get(); }
    /// @}

    /// @name 目标对象
    /// @{
    void setTargetObject(Object* obj) { targetObject_ = obj; }
    Object* targetObject() const { return targetObject_.get(); }
    /// @}

    /// @name 算法配置
    /// @{
    void setConfig(const AccessConfig& config) { config_ = config; }
    const AccessConfig& config() const { return config_; }
    /// @}

    /// @name 搜索时间区间
    /// @{
    /// @brief 设置搜索时间区间列表
    /// @details 
    /// 访问计算的搜索范围，计算只在落于其中的时段内进行
    /// 时段为空表示未指定搜索范围，默认为两对象时间段的交集
    /// @param intervals 搜索时间区间列表
    void setSearchIntervals(const TimeIntervalList& intervals) { searchIntervals_ = intervals; }
    const TimeIntervalList& searchIntervals() const { return searchIntervals_; }
    /// @}

public: // 计算结果

    /// @brief 获取访问时段计算结果
    /// @note 未计算时返回空列表。
    const TimeIntervalList& accessIntervals() const { return accessIntervals_; }

public:
    /// @brief 计算访问时段
    /// @details 根据配置和搜索时间区间，计算主对象和目标对象之间的可见性时段
    /// @return 错误码
    errc_t compute();

private:
    WeakPtr<Object> baseObject_{};                  ///< 主对象
    WeakPtr<Object> targetObject_{};                ///< 目标对象
    AccessConfig config_{};                         ///< 配置
    TimeIntervalList searchIntervals_{};            ///< 搜索时间区间列表
    TimeIntervalList accessIntervals_{};            ///< 访问时段计算结果
};

using HAccess = SharedPtr<Access>;      ///< 访问对象句柄


/// @brief 查找访问对象
/// @details 从场景中查找两个对象之间的访问对象
/// @param scenario 场景对象
/// @param object1 对象1
/// @param object2 对象2
/// @return 访问对象句柄
AST_SIM_API Access* aFindAccess(Scenario& scenario, Object& object1, Object& object2);



/*! @} */

AST_NAMESPACE_END
