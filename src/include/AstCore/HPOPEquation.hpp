/// @file      HPOPEquation.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstMath/OrdinaryDifferentialEquation.hpp"
#include "AstCore/BlockDynamicSystem.hpp"
#include "AstCore/SimTime.hpp"
#include "AstCore/HPOPForceModel.hpp"
#include "AstCore/Frame.hpp"
#include "AstCore/SpacecraftParam.hpp"
#include <memory>


AST_NAMESPACE_BEGIN

class FuncBlock;
class BlockDrag;
class BlockSRP;
class BlockDerivative;
class HPOPForceModel;

/// @brief     高精度轨道预报方程
/// @details   
/// 该类继承自 OrdinaryDifferentialEquation ，用于求解轨道动力学问题。
/// 其内部包含一个动力学系统 BlockDynamicSystem
/// 动力学系统 BlockDynamicSystem 由多个独立的函数块 FuncBlock 组成。
/// 每个函数块 FuncBlock 负责计算系统的一个或多个状态量或者导数。
/// 函数块之间可以通过输入输出端口进行信号连接，实现复杂的动力学模型。
class AST_CORE_API HPOPEquation : public OrdinaryDifferentialEquation
{
public:
    HPOPEquation();
    ~HPOPEquation();

    A_DISABLE_COPY(HPOPEquation);

    int getDimension() const final;

    errc_t evaluate(const double* y, double* dy, double t) final;

    /// @brief 设置仿真的参考历元
    void setEpoch(const TimePoint& epoch){ epoch_ = epoch; }

    /// @brief 获取动力学系统
    const BlockDynamicSystem& dynamicSystem() const { return dynamicSystem_; }
    BlockDynamicSystem& dynamicSystem() { return dynamicSystem_; }

    /// @brief 初始化仿真引擎（力模型/航天器参数/预报坐标系作为外部配置传入，不存储）
    /// @param[in] forceModel      HPOP力模型配置
    /// @param[in] spacecraftParam 航天器参数
    /// @param[in] frame           预报坐标系（可为空，默认用中心天体惯性系）
    /// @return 错误码
    errc_t initialize(const HPOPForceModel& forceModel, const SpacecraftParam& spacecraftParam, Frame* frame = nullptr);
public:
    BlockDrag* dragBlock() const { return dragBlock_; }
    BlockSRP* srpBlock() const { return srpBlock_; }
private:
    /// @brief 添加函数块
    void addBlock(FuncBlock* block);
    void addBlock(BlockDerivative* block);
    void reset();
    errc_t initBlocks(const HPOPForceModel& forceModel, const SpacecraftParam &spacecraftParam, Frame* frame);
private:
    BlockDynamicSystem      dynamicSystem_{};     ///< 动力学系统
    TimePoint               epoch_{};             ///< 仿真的参考历元
    BlockDrag*              dragBlock_{};         ///< 阻力函数块
    BlockSRP*               srpBlock_{};          ///< SRP光压函数块
};

AST_NAMESPACE_END
