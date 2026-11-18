/// @file      BlockDerivative.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-20

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

class SimTime;

/// @brief 导数函数块
/// @details
/// 导数函数块在普通函数块的基础上增加了导数端口（derivative ports）。
/// 导数端口用于与动力学系统自动建立连接关系(详细实现机制见BlockDynamicSystem)
/// 
/// 继承关系：
///   FuncBlock → BlockDerivative → 各具体力模型块（BlockTwoBody、BlockDrag 等）
///
/// 工作流程：
///   1. 每个导数块通过 run() 计算其贡献的加速度
///   2. 加速度通过输出端口（outputPorts_）发布
///   3. 同时累加到导数端口（derivativePorts_）对应的速度导数上
///   4. BlockDynamicSystem 自动收集所有导数端口的信号，构建常微分方程组
///
/// @see BlockDynamicSystem
class AST_CORE_API BlockDerivative: public FuncBlock
{
public:
    /// @brief 析构函数
    ~BlockDerivative() override = default;

    /// @brief 获取导数端口
    const std::vector<DataPort>& getDerivativePorts() const { return derivativePorts_; }
    std::vector<DataPort>& getDerivativePorts() { return derivativePorts_; }

protected:
    std::vector<DataPort> derivativePorts_{};  // 导数端口
};

AST_NAMESPACE_END
