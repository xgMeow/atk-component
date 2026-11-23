/// @file      Mover.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

#pragma once

#include "AstGlobal.h"
#include "AstCore/Object.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/AttitudeProfile.hpp"
#include "AstCore/Ephemeris.hpp"
#include "AstSim/MotionProfile.hpp"
#include "AstSim/Platform.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 运动对象
class AST_SIM_API Mover: public Platform
{
public:
    AST_OBJECT(Mover)
    AST_PROPERT(MotionProfile)
    AST_PROPERT(AttitudeProfile)
    AST_PROPERT(Ephemeris)
    Mover() = default;
    ~Mover() override = default;

public:
    /// @brief 生成星历
    /// @return 错误码
    errc_t generateEphemeris();

    errc_t generateEphemerisSimple();

    errc_t generateEphemerisSpec();

    /// @brief 尝试获取对象的中心天体
    /// @note 该函数目前效率不高，建议在只必要时使用，不要频繁调用
    Body* getBody() const;

public: // 从Point继承重写的函数
    Frame* getFrame() const final;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const final;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const final;
PROPERTIES:
    /// @brief 获取运动定义
    /// @return 运动定义指针
    MotionProfile* getMotionProfile() const { return motionProfile_.get(); }
    /// @brief 设置运动定义
    /// @param profile 运动定义指针
    void setMotionProfile(MotionProfile* profile);
    /// @brief 获取姿态定义
    /// @details 内部存储的是 Axes 抽象类型，此处向下转换为 AttitudeProfile；
    ///          若姿态属性被设置成了非姿态剖面的轴系(例如 AxesFrozen)，则返回 nullptr。
    /// @return 姿态定义指针
    AttitudeProfile* getAttitudeProfile() const;
    /// @brief 设置姿态定义
    /// @param profile 姿态定义指针
    void setAttitudeProfile(AttitudeProfile* profile) { setOrientation(profile); }
    /// @brief 获取星历
    /// @return 星历指针
    Ephemeris* getEphemeris() const { return location(); }
    /// @brief 设置星历
    /// @param ephemeris 星历指针
    void setEphemeris(Ephemeris* ephemeris) { setLocation(ephemeris); }
public:

    /// @brief 获取初始状态
    /// @warning 如果运动定义不是轨道动力学模型，则返回空指针
    /// @return 初始状态指针
    State* getInitialState() const;

private:
    WeakPtr<MotionProfile>      motionProfile_{};        ///< 运动定义
};

/*! @} */

AST_NAMESPACE_END