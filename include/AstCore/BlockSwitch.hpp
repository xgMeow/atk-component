/// @file      BlockSwitch.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 开关块
class AST_CORE_API BlockSwitch: public FuncBlock
{
public:
    BlockSwitch();

    BlockSwitch(const BlockSwitch&) = delete;
    BlockSwitch& operator=(const BlockSwitch&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 设置阈值
    /// @param threshold 阈值
    void setThreshold(double threshold);

    /// @brief 获取阈值
    /// @return 阈值
    double getThreshold() const;

protected:
    double threshold_{0.0};
    double* input1_{nullptr};  // 输入1
    double* input2_{nullptr};  // 输入2
    double* control_{nullptr}; // 控制输入
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END