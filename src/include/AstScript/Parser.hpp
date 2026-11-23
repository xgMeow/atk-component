/// @file      Parser.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/Expr.hpp"
#include "Lexer.hpp"

AST_NAMESPACE_BEGIN

/// @brief 脚本语法解析器
/// @ingroup Script
class AST_SCRIPT_API Parser
{
public:
    explicit Parser(Lexer& lexer);

    /// @brief 获取当前令牌类型
    int currentTokenType() const;

    /// @brief 获取当前令牌的字符串视图
    StringView currentLexeme() const;

    /// @brief 获取当前行号
    // size_t getLine() const;

    /// @brief 前进到下一个令牌
    void advance();

    /// @brief 匹配指定类型的令牌
    bool match(int type);

    /// @brief 检查当前令牌是否为指定类型
    bool check(int type) const;

    /// @brief 解析表达式
    Expr* parseExpression();

    /// @brief 解析语句序列（多个表达式，用分号或换行分隔）
    // Expr* parseStatements();

    /// @brief 解析赋值表达式
    Expr* parseAssignExpr();

    /// @brief 解析条件表达式
    Expr* parseConditionalExpr();

    /// @brief 解析逻辑或表达式
    Expr* parseLogicalOrExpr();

    /// @brief 解析逻辑与表达式
    Expr* parseLogicalAndExpr();

    /// @brief 解析按位或表达式
    Expr* parseBitwiseOrExpr();

    /// @brief 解析按位异或表达式
    Expr* parseBitwiseXorExpr();

    /// @brief 解析按位与表达式
    Expr* parseBitwiseAndExpr();

    /// @brief 解析相等性表达式
    Expr* parseEqualityExpr();

    /// @brief 解析关系表达式
    Expr* parseRelationalExpr();

    /// @brief 解析范围表达式（如 1:10, 1:2:10）
    Expr* parseRangeExpr();

    /// @brief 从给定的起始表达式解析范围表达式
    // Expr* parseRangeExprFrom(Expr* startExpr);

    /// @brief 解析位移表达式
    Expr* parseShiftExpr();

    /// @brief 解析加法表达式
    Expr* parseAdditiveExpr();

    /// @brief 解析乘法表达式
    Expr* parseMultiplicativeExpr();

    /// @brief 解析幂指数表达式
    Expr* parseExponentiationExpr();

    /// @brief 解析一元表达式
    Expr* parseUnaryExpr();

    /// @brief 解析带begin/end的代码块
    Expr* parseBeginEndBlock();

    /// @brief 解析语句序列（多个表达式，用分号或换行分隔）
    Expr* parseStatementSequence();

    /// @brief 解析代码块表达式
    Expr* parseBlockExpr();

    /// @brief 解析基本表达式
    Expr* parsePrimaryExpr();

    /// @brief 解析if条件语句
    Expr* parseIfStatement();

    /// @brief 解析while循环语句
    Expr* parseWhileLoop();

    /// @brief 解析for循环语句（范围风格）
    Expr* parseForRangeLoop();

    /// @brief 检查当前令牌是否可以作为表达式的开始
    /// @return true 如果当前令牌可以作为表达式的开始
    bool canStartExpression() const;

    /// @brief 解析表达式
    /// @param script 脚本文本
    /// @return Expr* 解析得到的表达式对象，解析失败返回nullptr
    static Expr* parseExpr(StringView script);
private:
    Lexer& lexer_;
    Lexer::ETokenType currentTokenType_;
};

AST_NAMESPACE_END