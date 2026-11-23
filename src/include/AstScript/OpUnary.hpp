/// @file      OpUnary.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "Op.hpp"
#include "AstScript/ScriptAPI.hpp"
#include <atomic>
#include <mutex>

AST_NAMESPACE_BEGIN

/// @brief 一元运算符表达式
/// @ingroup Script
class AST_SCRIPT_API OpUnary: public Op
{
public:
    AST_EXPR(OpUnary)

    OpUnary(EOpUnaryType op, Expr* expr)
        : op_(op), expr_(expr), cache_mutex_()
    {};
    virtual ~OpUnary() = default;
    Value* eval() const override;
    std::string getExpression(Object* context=nullptr) const override;
    EOpUnaryType op() const {return op_;}
    SharedPtr<Expr> expr() const {return expr_;}
protected:
    EOpUnaryType   op_;                                   ///< 运算符
    SharedPtr<Expr>         expr_;                        ///< 操作数
private:
    mutable std::atomic<OpUnaryFunc> func_{nullptr};      ///< 运算符函数指针
    mutable std::atomic<Class*>  type_{nullptr};          ///< 运算数类型
    mutable std::mutex cache_mutex_;                      ///< 用于保护缓存成员的互斥锁
};



AST_NAMESPACE_END