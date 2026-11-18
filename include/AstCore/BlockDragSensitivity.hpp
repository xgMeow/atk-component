/// @file      BlockDragSensitivity.hpp
/// @brief     弹道系数B敏感度传播函数块
/// @details   计算状态对弹道系数B的敏感度向量 Ψ_B = ∂[r,v]/∂B 的时间导数
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/BlockDerivative.hpp"
#include "AstMath/Vector.hpp"
#include "AstMath/Matrix.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup BlockAstro
    @{
*/

/// @brief 弹道系数B敏感度传播函数块
/// @details
/// 计算 Ψ_B = ∂[r,v]/∂B 的时间导数：
///   dΨ_B/dt = A(t) · Ψ_B + [0, 0, 0, ∂a_drag/∂B]ᵀ
///
/// 其中：
///   Ψ_B = 状态对弹道系数 B = Cd·A/m 的偏导数（6×1）
///   A(t) = 动力学雅可比矩阵 ∂f/∂x（6×6）
///   ∂a_drag/∂B = a_drag / B（3维加速度向量，由 BlockDragPartial 提供）
///
/// 输入端口：
///   - "AMatrix"：动力学雅可比矩阵 A(t)（36维，6×6 行优先存储）
///   - "StateSensitivityToDrag"：敏感度向量 Ψ_B（6维）
///   - "AccSensitivityToDrag"：阻力加速度对B的偏导数（3维，由 BlockDragPartial 提供）
///
/// 导数端口：
///   - "StateSensitivityToDrag"：dΨ_B/dt（6维）
///
/// @note 本块读取 AMatrix 输入端口，拓扑排序保证在所有力模型块之后执行
/// @see BlockDragPartial, BlockStateTransitionMatrix
class AST_CORE_API BlockDragSensitivity : public BlockDerivative
{
public:
    BlockDragSensitivity();

    BlockDragSensitivity(const BlockDragSensitivity&) = delete;
    BlockDragSensitivity& operator=(const BlockDragSensitivity&) = delete;

    ~BlockDragSensitivity() override = default;

    errc_t run(const SimTime& simTime) override;

private:
    void init();

    Matrix6d* aMatrixPtr_{&aMatrixBuffer_};             ///< A 矩阵输入（6×6）
    Matrix6d  aMatrixBuffer_{};                         ///< A 矩阵缓冲区

    double* stateSensitivityToDragPtr_{stateSensBuffer_};           ///< Ψ_B 输入（6维）
    double* accSensitivityToDragPtr_{accSensBuffer_};               ///< 强迫项输入 ∂a_drag/∂B（3维）
    double* stateSensitivityToDragDerivativePtr_{stateSensDerivBuffer_}; ///< dΨ_B/dt 输出（6维）

    double stateSensBuffer_[6]{};         ///< Ψ_B 缓冲区
    double accSensBuffer_[3]{};           ///< 强迫项缓冲区
    double stateSensDerivBuffer_[6]{};    ///< dΨ_B/dt 缓冲区
};

/*! @} */

AST_NAMESPACE_END
