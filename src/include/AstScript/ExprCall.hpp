/// @file      ExprFuncCall.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-24

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"
#include "AstUtil/SharedPtr.hpp"
#include <vector>


AST_NAMESPACE_BEGIN


/// @brief     函数调用表达式
/// @ingroup Script
class AST_SCRIPT_API ExprCall: public Expr
{
public:
    AST_EXPR(ExprCall)

    ExprCall() = default;
    ~ExprCall() = default;

    /// @brief 构造函数
    /// @param func 被调用的函数表达式
    /// @param args 调用参数列表
    ExprCall(Expr* func, const std::vector<SharedPtr<Expr>>& args);

    /// @brief 求值
    /// @return Value* 求值结果
    Value* eval() const override;

    /// @brief 获取表达式的字符串表示
    /// @param context 可选的上下文对象，用于解析变量等
    /// @return std::string 表达式的字符串表示
    std::string getExpression(Object* context=nullptr) const override;

    /// @brief 获取被调用的函数表达式
    /// @return SharedPtr<Expr> 函数表达式
    Expr* getFunc() const { return func_.get(); }

    /// @brief 获取调用参数列表
    /// @return const std::vector<SharedPtr<Expr>>& 参数列表
    const std::vector<SharedPtr<Expr>>& getArgs() const { return args_; }

private:
    SharedPtr<Expr> func_;           ///< 被调用的函数表达式
    std::vector<SharedPtr<Expr>> args_;        ///< 调用参数列表
};

AST_NAMESPACE_END