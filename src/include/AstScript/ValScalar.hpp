/// @file      ValScalar.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-22

#pragma once

#include "AstGlobal.h"
#include "AstScript/Value.hpp"
#include "AstUtil/ParseFormat.hpp"

AST_NAMESPACE_BEGIN

/// @brief 标量值类
/// @tparam Scalar 标量类型
/// @ingroup Script
template <typename Scalar>
class ValScalar : public Value
{
public:
    ValScalar()
        : value_(Scalar())
    {}
    ValScalar(Scalar value)
        : value_(value)
    {}

    ~ValScalar(){}

    Scalar value() const{return value_;}

    std::string getExpression(Object* context=nullptr) const override{return aFormatScalar(value_);}
protected:
    Scalar value_;
};


AST_NAMESPACE_END
