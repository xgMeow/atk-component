/// @file      OpBin.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "Op.hpp"
#include "AstScript/ScriptAPI.hpp"
#include <mutex>
#include <atomic>

AST_NAMESPACE_BEGIN

/// @brief 二元运算符表达式
/// @ingroup Script
class AST_SCRIPT_API OpBin: public Op
{
public:
    AST_EXPR(OpBin)

public:
    OpBin(EOpBinType op, Expr* left, Expr* right)
        : op_(op), left_(left), right_(right), cache_mutex_()
    {};
    virtual ~OpBin() = default;
    Value* eval() const override;
    std::string getExpression(Object* context=nullptr) const override;
    EOpBinType op() const {return op_;}
    SharedPtr<Expr> left() const {return left_;}
    SharedPtr<Expr> right() const {return right_;}
protected:
    EOpBinType   op_;        ///< 运算符
    SharedPtr<Expr>       left_;      ///< 左操作数
    SharedPtr<Expr>       right_;     ///< 右操作数
private:
    mutable std::atomic<OpBinFunc> func_{nullptr};      ///< 运算符函数指针
    mutable std::atomic<Class*>    leftType_{nullptr};  ///< 左操作数类型
    mutable std::atomic<Class*>    rightType_{nullptr}; ///< 右操作数类型
    mutable std::mutex             cache_mutex_;        ///< 用于保护缓存成员的互斥锁
};



AST_NAMESPACE_END
