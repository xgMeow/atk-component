/// @file      BlockLogicalOperator.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 逻辑运算符类型枚举
enum class ELogicalOperatorType
{
    eAnd, ///< 逻辑与
    eOr,  ///< 逻辑或
    eNot, ///< 逻辑非
    eXor  ///< 逻辑异或
};

/// @brief 逻辑运算符块
class AST_CORE_API BlockLogicalOperator: public FuncBlock
{
public:
    explicit BlockLogicalOperator(ELogicalOperatorType type = ELogicalOperatorType::eAnd);

    BlockLogicalOperator(const BlockLogicalOperator&) = delete;
    BlockLogicalOperator& operator=(const BlockLogicalOperator&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 设置逻辑运算符类型
    /// @param type 逻辑运算符类型
    void setOperatorType(ELogicalOperatorType type);

    /// @brief 获取逻辑运算符类型
    /// @return 逻辑运算符类型
    ELogicalOperatorType getOperatorType() const;

protected:
    ELogicalOperatorType operatorType_{ELogicalOperatorType::eAnd};
    int* input1_{nullptr};
    int* input2_{nullptr};
    int* output_{&outputBuffer_};
    int outputBuffer_{0};
};

AST_NAMESPACE_END