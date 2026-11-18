/// @file      GenericValue.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ParseFormat.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/// @brief 通用值类
/// @details 该类通过字符串存储任意类型的值
/// @todo 考虑参考variant进行存储，保留原始值
/// @ingroup ParseFormat
class GenericValue
{
public:
    GenericValue() = default;
    explicit GenericValue(StringView value)
        : value_(value){}
    // explicit 
    GenericValue(const char* value)
        : value_(value){}
    // explicit 
    GenericValue(const std::string& value)
        : value_(value){}
    explicit GenericValue(int value)
        : value_(aFormatInt(value)){}
    explicit GenericValue(double value)
        : value_(aFormatDouble(value)){}
    explicit GenericValue(bool value)
        : value_(aFormatBool(value)){}
    explicit GenericValue(Color value)
        : value_(aFormatColor(value)){}

    const std::string& value() const { return value_; }
    const char* c_str() const { return value_.c_str(); }
protected:
    std::string value_{};
};

AST_NAMESPACE_END
