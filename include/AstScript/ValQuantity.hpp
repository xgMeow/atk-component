/// @file      ValQuantity.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/Value.hpp"
#include "AstUtil/Quantity.hpp"

AST_NAMESPACE_BEGIN


/// @brief 数量值
/// @ingroup Script
class AST_SCRIPT_API ValQuantity: public Value
{
public:
    AST_EXPR(ValQuantity)

    ValQuantity(const Quantity& q)
        : Value()
        , value_(q)
    {
    }
    std::string getExpression(Object* context=nullptr) const override;
    const Quantity& quantity() const { return value_; }
    const Unit& unit() const { return value_.unit(); }
    double magnitude() const { return value_.magnitude(); }
    EDimension dimension() const { return value_.dimension(); }
private:
    Quantity value_;
};


AST_NAMESPACE_END
