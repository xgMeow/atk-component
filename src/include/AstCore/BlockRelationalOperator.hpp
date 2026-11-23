/// @file      BlockRelationalOperator.hpp
/// @brief     ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/FuncBlock.hpp"

AST_NAMESPACE_BEGIN

/// @brief 关系运算符类型枚举
enum class ERelationalOperatorType
{
    eEqual,             ///< 等于
    eNotEqual,         ///< 不等于
    eGreaterThan,      ///< 大于
    eLessThan,         ///< 小于
    eGreaterOrEqual,  ///< 大于等于
    eLessOrEqual      ///< 小于等于
};

/// @brief 关系运算符块
class AST_CORE_API BlockRelationalOperator: public FuncBlock
{
public:
    explicit BlockRelationalOperator(ERelationalOperatorType type = ERelationalOperatorType::eEqual);

    BlockRelationalOperator(const BlockRelationalOperator&) = delete;
    BlockRelationalOperator& operator=(const BlockRelationalOperator&) = delete;

    errc_t run(const SimTime &simTime) override;

    /// @brief 设置关系运算符类型
    /// @param type 关系运算符类型
    void setOperatorType(ERelationalOperatorType type);

    /// @brief 获取关系运算符类型
    /// @return 关系运算符类型
    ERelationalOperatorType getOperatorType() const;

protected:
    ERelationalOperatorType operatorType_{ERelationalOperatorType::eEqual};
    double* input1_{nullptr};
    double* input2_{nullptr};
    int* output_{&outputBuffer_};
    int outputBuffer_{0};
};

AST_NAMESPACE_END