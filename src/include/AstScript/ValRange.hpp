/// @file      ValRange.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-26

#pragma once

#include "AstGlobal.h"
#include "Value.hpp"

AST_NAMESPACE_BEGIN


/// @brief     范围值
/// @details   表示一个范围值，包含起始值、结束值和步长。
/// @todo      目前只支持浮点数类型的范围值
/// @ingroup Script
class AST_SCRIPT_API ValRange : public Value
{
public:
    AST_EXPR(ValRange)
    /// @brief     构造函数
    /// @param     start 范围的起始值
    /// @param     stop 范围的结束值
    /// @param     step 范围的步长，默认值为1.0
    ValRange(double start, double stop, double step=1.0);
    ~ValRange() override = default;

    /// @brief     获取范围的起始值
    /// @return    范围的起始值
    double start() const { return start_; }

    /// @brief     获取范围的结束值
    /// @return    范围的结束值
    double stop() const { return stop_; }

    /// @brief     获取范围的步长
    /// @return    范围的步长
    double step() const { return step_; }

    /// @brief     获取范围的元素数量
    /// @return    范围的元素数量
    int size() const { return (int)((stop_ - start_) / step_) + 1; }

    /// @brief     获取范围的表达式
    /// @param     context 上下文对象
    /// @return    范围的表达式字符串
    std::string getExpression(Object* context) const override;

protected:
    double start_;
    double stop_;
    double step_;
};


AST_NAMESPACE_END
