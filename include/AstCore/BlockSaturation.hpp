/// @file      BlockSaturation.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 饱和块
class AST_CORE_API BlockSaturation: public FuncBlock
{
public:
    explicit BlockSaturation(double lowerLimit = -1.0, double upperLimit = 1.0);

    BlockSaturation(const BlockSaturation&) = delete;
    BlockSaturation& operator=(const BlockSaturation&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 设置下限
    /// @param lowerLimit 下限值
    void setLowerLimit(double lowerLimit);

    /// @brief 获取下限
    /// @return 下限值
    double getLowerLimit() const;

    /// @brief 设置上限
    /// @param upperLimit 上限值
    void setUpperLimit(double upperLimit);

    /// @brief 获取上限
    /// @return 上限值
    double getUpperLimit() const;

    /// @brief 设置上下限
    /// @param lowerLimit 下限值
    /// @param upperLimit 上限值
    void setLimits(double lowerLimit, double upperLimit);

protected:
    double lowerLimit_{-1.0};
    double upperLimit_{1.0};
    double* input_{nullptr};
    double* output_{&outputBuffer_};
    double outputBuffer_{0.0};
};

AST_NAMESPACE_END