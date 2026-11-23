/// @file      BlockThirdBodyPointMass.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/BlockAstro.hpp"
#include "AstCore/BlockDerivative.hpp"
#include "AstMath/Vector.hpp"

AST_NAMESPACE_BEGIN

/// @brief 三体点质量引力函数块
/// @details
/// 计算第三天体的点质量引力摄动加速度（直接引力与间接引力之差）。
///
/// 方程：
///   a = GM₃ · [ (r₃ - r) / |r₃ - r|³  -  r₃ / |r₃|³ ]
///
/// 其中：
///   GM₃ = 第三天体引力常数
///   r   = 航天器相对于中心天体的位置
///   r₃  = 第三天体相对于中心天体的位置
///   第一项为直接引力（第三天体对航天器），第二项为间接引力（第三天体对中心天体）
///
/// 输入端口：
///   - "Pos"：位置向量（3维，预报坐标系下，以中心天体为参考）
///
/// 输出端口：
///   - "AccThirdBody"：三体引力加速度（3维）
///
/// 导数端口：
///   - "Vel"：速度导数（3维），累加三体引力加速度
class AST_CORE_API BlockThirdBodyPointMass : public BlockDerivative
{
public:
    BlockThirdBodyPointMass();

    BlockThirdBodyPointMass(const BlockThirdBodyPointMass&) = delete;
    BlockThirdBodyPointMass& operator=(const BlockThirdBodyPointMass&) = delete;

    explicit BlockThirdBodyPointMass(Point* thirdBody, double thirdBodyGM, Frame* propagationFrame);

    errc_t run(const SimTime& simTime) override;
protected:
    Vector3d* posCBI{};                             ///< 位置（以主要天体为参考）
    Vector3d* accThirdBody{&vectorBuffer};          ///< 三体加速度
    Vector3d* velocityDerivative_{&vectorBuffer};   ///< 速度导数
    Vector3d vectorBuffer{};                        ///< 向量缓冲区
protected:
    Point* thirdBody_{};                    ///< 三体
    double thirdBodyGM_;                    ///< 三体引力常量
    Frame* propagationFrame_{};             ///< 预报系
};  

AST_NAMESPACE_END
