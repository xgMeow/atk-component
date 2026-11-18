/// @file      ExprAttribute.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-01

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// 属性表达式
class AST_SCRIPT_API ExprAttribute : public Expr
{
public:
    AST_EXPR(ExprAttribute)

    /// 创建表达式
    /// @param attribute 属性
    /// @details 从属性创建表达式
    static ExprAttribute* New(const Attribute& attribute);

    /// 构造函数
    /// @param attribute 属性
    /// @details 从属性创建表达式
    ExprAttribute(const Attribute& attribute);

    /// 评估表达式
    /// @return 属性值
    /// @details 评估表达式，返回属性值
    Value* eval() const override;

    /// 设置属性值
    /// @param value 属性值
    /// @return 设置结果
    errc_t setValue(Value* value) override;

    errc_t setValueDouble(double val) override;

    errc_t getValueDouble(double& val) const override;

    /// 获取表达式字符串
    /// @return 表达式字符串
    /// @details 获取表达式字符串，用于调试和显示
    std::string getExpression(Object* context=nullptr) const override;


    /// 获取属性
    /// @return 属性
    /// @details 获取表达式中的属性
    const Attribute& attribute() const{return attribute_;}

    /// 设置属性
    /// @param attribute 属性
    /// @details 设置表达式中的属性
    void setAttribute(const Attribute& attribute){attribute_ = attribute;}
private:
    Attribute attribute_;    ///< 属性指针
};


/*! @} */

AST_NAMESPACE_END
