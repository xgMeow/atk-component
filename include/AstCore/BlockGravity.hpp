/// @file      BlockGravity.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "BlockAstro.hpp"
#include "AstCore/GravityCalculator.hpp"
#include "AstCore/BlockDerivative.hpp"
#include "AstCore/Axes.hpp"
#include "AstMath/Vector.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/// @brief 重力场函数块
/// @details
/// 使用球谐展开模型计算非球形天体的重力加速度。
///
/// 工作流程：
///   1. 将预报坐标系下的位置旋转变换到重力场固连坐标系
///   2. 调用 GravityCalculator 计算固连系下的重力加速度
///   3. 将加速度逆变换回报坐标系
///   4. 累加到速度导数上
///
/// 输入端口：
///   - "Pos"：位置向量（3维，预报坐标系下）
///
/// 输出端口：
///   - "AccGravity"：重力加速度（3维，预报坐标系下）
///
/// 导数端口：
///   - "Vel"：速度导数（3维），累加重力加速度
///
/// @note 当 degree=0 时退化为二体引力，此时应使用 BlockTwoBody 以提高效率
class AST_CORE_API BlockGravity: public BlockDerivative
{
public:
    BlockGravity();
    BlockGravity(const GravityField &gravityField, int degree, int order, Axes* gravityAxes=nullptr, Axes* propagationAxes=nullptr);
    BlockGravity(GravityField &&gravityField, int degree, int order, Axes* gravityAxes=nullptr, Axes* propagationAxes=nullptr);

    BlockGravity(const BlockGravity&) = delete;
    BlockGravity& operator=(const BlockGravity&) = delete;

    errc_t run(const SimTime& simTime) override;

    /// @brief 设置是否考虑重力场系数变化
    void setConsiderVariations(bool considerVariations){considerVariations_ = considerVariations;}
protected:
    // 运行前的公共参数准备
    errc_t prepare(const SimTime& simTime, Rotation& rotation);

private:
    void init();
protected:
    HAxes                    gravityAxes_;                              ///< 重力坐标系
    HAxes                    propagationAxes_;                          ///< 预报坐标系
    Vector3d*                posPtr_{&vectorBuffer_};                   ///< 位置(预报坐标系下)
    Vector3d*                accGravityPtr_{&vectorBuffer_};            ///< 重力加速度(预报坐标系下)
    Vector3d*                velocityDerivativePtr_{&vectorBuffer_};    ///< 速度导数(预报坐标系下)
    Vector3d                 vectorBuffer_{};                           ///< 向量缓冲区
    GravityCalculatorDefault gravityCalculator_;                        ///< 重力计算器
    bool                     considerVariations_{false};                ///< 是否考虑重力场系数变化
};



AST_NAMESPACE_END
