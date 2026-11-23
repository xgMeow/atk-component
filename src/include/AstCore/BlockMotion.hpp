/// @file      BlockMotion.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-20

#pragma once

#include "AstGlobal.h"
#include "AstCore/BlockDerivative.hpp"
#include "AstMath/Vector.hpp"

AST_NAMESPACE_BEGIN

/// @brief 运动学函数块
/// @details
/// 实现最基本的运动学关系：位置导数等于速度。
///
/// 方程：
///   dr/dt = v
///
/// 输入端口：
///   - "Vel"：速度向量（3维）
///
/// 导数端口：
///   - "Pos"：位置导数（3维），直接赋值为当前速度
///
/// @note 当前使用直接赋值（=）而非累加（+=），假设只有此块贡献位置导数
class AST_CORE_API BlockMotion : public BlockDerivative
{
public:
    BlockMotion();

    BlockMotion(const BlockMotion&) = delete;
    BlockMotion& operator=(const BlockMotion&) = delete;

    errc_t run(const SimTime& simTime) override;

protected:
    Vector3d* velocity_{&vectorBuffer};            ///< 速度
    Vector3d* positionDerivative_{&vectorBuffer};  ///< 位置导数
    Vector3d vectorBuffer{};                       ///< 向量缓冲区
};

AST_NAMESPACE_END
