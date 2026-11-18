/// @file      Value.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/Expr.hpp"
#include "AstScript/ScriptAPI.hpp"
#include "AstUtil/OrderedMap.hpp"
#include <map>

AST_NAMESPACE_BEGIN


class ValDict;
using ValueMapType = OrderedMap<std::string, SharedPtr<Value>>;
using NamedValueVector = std::vector<std::pair<std::string, SharedPtr<Value>>>;

/// @brief 值对象基类
/// @details 
/// 所有值对象的基类，包含值对象的公共接口。
/// 值对象用于表示表达式的求值结果，可以是各种类型的数据，如整数、浮点数、字符串、布尔值等。
/// 值对象的特点是“求值的结果等于自身”
/// @ingroup Script
class AST_SCRIPT_API Value: public Expr
{
public:
    static Value& NullValue();

    using Expr::Expr;
    ~Value() override = default;

    /// @brief 求值表达式
    Value* eval() const final{return const_cast<Value*>(this);}

    /// @brief 设置值
    errc_t setValue(Value*) final{return eErrorReadonly;}
public:
    void insert(const std::string& name, Value* value);
    template<typename T>
    void insert(const std::string& name, T value)
    {
        insert(name, aNewValue(value));
    }
    Value& operator[](const std::string& name);
    const Value& operator[](const std::string& name) const;
    Value& operator[](const char* name);
    const Value& operator[](const char* name) const;
    Value& operator[](size_t index);
    const Value& operator[](size_t index) const;

    bool isNull() const;
    bool isBool() const;
    bool isInt() const;
    bool isDouble() const;
    bool isQuantity() const;
    bool isString() const;

    std::string toString() const;
    Quantity toQuantity() const;
    double toDouble() const;
    int toInt() const;
    bool toBool() const;

    operator std::string() const;
    operator Quantity() const;
    operator double() const;
    operator int() const;
    operator bool() const;

    ValDict* toValDict() const;
    const NamedValueVector& items() const;

    const Value& operator>>(bool& val) const;
    const Value& operator>>(int& val) const;
    const Value& operator>>(double& val) const;

private:

};

AST_NAMESPACE_END
