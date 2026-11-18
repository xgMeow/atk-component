/// @file      Expr.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstScript/ScriptAPI.hpp"

AST_NAMESPACE_BEGIN

class Value;   

/// @brief 表达式基类
/// @details 
/// 表达式是脚本语言中的基本构造单元，可以是常量、变量、运算符表达式、函数调用等
/// 不同类型的表达式通过继承自Expr类来实现多态行为
/// 表达式可以嵌套组合，形成复杂的计算逻辑
/// 表达式的特点是“可以求值”，即每个表达式在求值后都会产生一个结果值
/// @ingroup Script
class AST_SCRIPT_API Expr: public ObjectNamed  // 表达式需要名称吗??
{
public:
    using ObjectNamed::ObjectNamed;
    ~Expr() override = default;

    /// @brief 接受表达式访问者
    /// @param visitor 表达式访问者对象
    virtual void accept(ExprVisitor& visitor) = 0;

    /// @brief 求值
    /// @return Value* 求值结果
    virtual Value* eval() const = 0;

    Expr* expand() const;

    /// @brief 设置表达式的值
    virtual errc_t setValue(Value* val) {return eErrorReadonly;};

    /// @brief 设置表达式的双精度值
    virtual errc_t setValueDouble(double val);

    /// @brief 获取表达式的双精度值
    virtual errc_t getValueDouble(double& val) const;

    /// @brief 获取表达式的字符串表示
    /// @param context 可选的上下文对象，用于解析变量等
    /// @return std::string 表达式的字符串表示
    virtual std::string getExpression(Object* context=nullptr) const = 0;
};


AST_NAMESPACE_END
