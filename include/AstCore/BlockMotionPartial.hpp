/// @file      BlockMotionPartial.hpp
/// @brief     运动学偏导数函数块
/// @details   在 BlockMotion 基础上向 A 矩阵写入位置运动学偏导数 ∂(dr/dt)/∂v = I
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-11

#pragma once

#include "AstGlobal.h"
#include "BlockMotion.hpp"
#include "AstMath/Matrix.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup BlockAstro
    @{
*/

/// @brief 运动学偏导数函数块
/// @details
/// 继承 BlockMotion，在其基础上向 A 矩阵写入位置运动学偏导数。
/// 重写 run()：计算 dr/dt = v 的同时，将 ∂(dr/dt)/∂v = I 写入 A 矩阵。
///
/// A 矩阵布局（6×6，行优先）：
///           位置导数与位置无关，∂(dr/dt)/∂r = 0（无需写入）
///         ↓ 本块写入 I (rows 0-2, cols 3-5)
///   ┌         ┐
///   │ 0   I   │  rows 0-2: 位置运动学
///   │ ∂a/∂r ∂a/∂v │  rows 3-5: 加速度偏导数
///   └         ┘
///
/// 输入端口（继承）：
///   - "Vel"：速度向量（3维，继承自 BlockMotion）
///
/// 输出端口（新增）：
///   - "AMatrix"：动力学雅可比矩阵 A(t)（36维，本块写入 ∂(dr/dt)/∂v = I）
///
/// 导数端口（继承）：
///   - "Pos"：位置导数（3维），赋值为当前速度
///
/// @note 可替换 BlockMotion 使用，提供偏导数计算的同时保持原有运动学关系
/// @see BlockMotion, BlockStateTransitionMatrix
class AST_CORE_API BlockMotionPartial : public BlockMotion
{
public:
    BlockMotionPartial();

    BlockMotionPartial(const BlockMotionPartial&) = delete;
    BlockMotionPartial& operator=(const BlockMotionPartial&) = delete;

    errc_t run(const SimTime& simTime) override;
private:
    void init();
private:
    Matrix6d* aMatrixPtr_{&aMatrixBuffer_};   ///< A 矩阵指针（6×6）
    Matrix6d  aMatrixBuffer_{};               ///< A 矩阵缓冲区
};

/*! @} */

AST_NAMESPACE_END
