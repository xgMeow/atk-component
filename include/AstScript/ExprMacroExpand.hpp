/// @file      ExprMacroExpand.hpp
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

class Macro;

/// @brief     宏展开表达式
/// @ingroup Script
class AST_SCRIPT_API ExprMacroExpand: public Expr
{
public:
    AST_EXPR(ExprMacroExpand)

    ExprMacroExpand() = default;
    ~ExprMacroExpand() = default;

    /// @brief 构造函数
    /// @param macro 被展开的宏对象
    /// @param args 宏展开参数列表
    ExprMacroExpand(Expr* macro, const std::vector<SharedPtr<Expr>>& args)
        : macro_(macro), args_(args)
    {}


    /// @brief 求值
    /// @return Value* 求值结果
    Value* eval() const override;

    /// @brief 获取表达式的字符串表示
    /// @param context 可选的上下文对象，用于解析变量等
    /// @return std::string 表达式的字符串表示
    std::string getExpression(Object* context=nullptr) const override;

    /// @brief 获取被展开的宏对象
    /// @return SharedPtr<Macro> 宏对象
    Expr* getMacro() { return macro_; }
    const Expr* getMacro() const { return macro_; }

    /// @brief 获取宏展开参数列表
    /// @return const std::vector<SharedPtr<Expr>>& 参数列表
    const std::vector<SharedPtr<Expr>>& getArgs() const { return args_; }

private:
    SharedPtr<Expr> macro_;           ///< 被展开的宏对象
    std::vector<SharedPtr<Expr>> args_;        ///< 宏展开参数列表
};


AST_NAMESPACE_END