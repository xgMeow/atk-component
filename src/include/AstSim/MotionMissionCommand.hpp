/// @file      MotionMissionSequence.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "AstSim/MotionProfile.hpp"
#include "AstCore/MainSequence.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 任务命令运动模型，定义并协调一系列轨道机动任务（类似 STK Astrogator 中的任务控制序列MCS）
/// @details
/// 该类封装了一个完整的轨道机动任务序列，通过 MissionModerator 协调各任务的执行顺序与参数。
/// 每个子任务（如推力弧段、滑行段、初始段等）均包含独立的配置，并按顺序依次执行。
/// 主要功能包括：
/// - 获取底层任务序列`mainSequence()`，支持对任务列表进行动态增删改查；
/// - 生成星历（Ephemeris）对象：makeEphemerisSpec() 生成详细规格星历，makeEphemerisSimple() 生成简化星历；
/// - 支持访问者模式（accept()），便于对任务序列进行遍历、校验或导出操作。
/// 
/// 该类设计参考了 STK 的 Astrogator 模块，可用于建模轨道转移、位置保持、交会对接等复杂机动序列。
/// @note 具体任务类型由 Sequence 中存储的任务对象决定，用户需确保任务参数有效且执行顺序合理。
/// @see MotionProfile, MissionModerator, Sequence, Ephemeris
class AST_SIM_API MotionMissionCommand: public MotionProfile
{
public:
    AST_OBJECT(MotionMissionCommand)
    static MotionMissionCommand* New();

    MotionMissionCommand();
    ~MotionMissionCommand() = default;

    Sequence& getSequence() { return *mainSequence_; }
    errc_t makeEphemerisSpec(ScopedPtr<Ephemeris>& eph) const override;
    errc_t makeEphemerisSimple(ScopedPtr<Ephemeris>& eph) const override;
    void accept(MotionProfileVisitor& visitor) override;
private:
    SharedPtr<MainSequence> mainSequence_{};     ///< 任务序列协调器
};

/*! @} */

AST_NAMESPACE_END
