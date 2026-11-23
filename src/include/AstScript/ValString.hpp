/// @file      ValString.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "Value.hpp"
#include <string>

AST_NAMESPACE_BEGIN


/// @brief 字符串值
/// @ingroup Script
class AST_SCRIPT_API ValString: public Value
{
public:
    AST_EXPR(ValString)

    ValString(StringView value)
        :value_{value}
    {}
    ValString(): value_{}{}
    std::string getExpression(Object* context=nullptr) const override;
    const std::string& value() const{return value_;}
protected:
    std::string value_;
};

AST_NAMESPACE_END
