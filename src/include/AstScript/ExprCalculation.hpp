/// @file      ExprCalculation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-01

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"
#include "AstUtil/ObjectCalculation.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class AST_SCRIPT_API ExprCalculationBase : public Expr
{
public:


};



class AST_SCRIPT_API ExprCalculation : public ExprCalculationBase
{
public:
    AST_EXPR(ExprCalculation)

    /// @brief 创建新的计算表达式
    /// @param obj 要计算的对象
    /// @param calc 要使用的计算式
    /// @return 计算表达式
    static ExprCalculation* New(Object* obj=nullptr, ObjectCalculation* calc=nullptr);


    ExprCalculation() = default;
    ExprCalculation(Object* obj, ObjectCalculation* calc);
    ~ExprCalculation() = default;

    Value* eval() const override;

    errc_t setValue(Value* val) override;

    errc_t setValueDouble(double val) override;

    errc_t getValueDouble(double& val) const override;

    std::string getExpression(Object* context=nullptr) const override;

public:
    /// @brief 计算表达式
    /// @param val 计算结果
    /// @return 错误码
    errc_t calculate(double& val) const;

public:
    Object* object() const {return object_.get();}
    void setObject(Object* obj);

    ObjectCalculation* calculation() const {return calculation_.get();}
    void setCalculation(ObjectCalculation* calc);
private:
    void syncTypeMatched();
private:
    bool                        typeMatched_{false};    ///< 是否类型匹配
    WeakPtr<Object>             object_;                ///< 对象
    WeakPtr<ObjectCalculation>  calculation_;           ///< 计算式
};

/*! @} */

AST_NAMESPACE_END


