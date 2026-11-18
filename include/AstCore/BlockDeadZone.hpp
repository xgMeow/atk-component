/// @file      BlockDeadZone.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 死区块
class AST_CORE_API BlockDeadZone : public FuncBlock
{
public:
    BlockDeadZone();

    BlockDeadZone(const BlockDeadZone&) = delete;
    BlockDeadZone& operator=(const BlockDeadZone&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 设置死区下限
    /// @param lowerLimit 死区下限
    void setLowerLimit(double lowerLimit);

    /// @brief 设置死区上限
    /// @param upperLimit 死区上限
    void setUpperLimit(double upperLimit);

    /// @brief 获取死区下限
    /// @return 死区下限
    double getLowerLimit() const;

    /// @brief 获取死区上限
    /// @return 死区上限
    double getUpperLimit() const;

protected:
    double* input_{nullptr};  // 输入值
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
    double lowerLimit_{-0.1};  // 死区下限，默认为-0.1
    double upperLimit_{0.1};   // 死区上限，默认为0.1
};

AST_NAMESPACE_END