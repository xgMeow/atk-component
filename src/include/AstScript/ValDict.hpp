/// @file      ValMap.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "Value.hpp"
#include "AstUtil/OrderedMap.hpp"
#include <string>
#include <map>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 字典值
class AST_SCRIPT_API ValDict: public Value
{
    using MapType = OrderedMap<std::string, SharedPtr<Value>>;
public:
    AST_EXPR(ValDict)
    static ValDict* New();

    ValDict() = default;
    ~ValDict() override = default;
    Value* find(const std::string& name);
    void insert(const std::string& name, Value* value);
    using Value::insert;
    std::string toJsonString() const;
    std::string toJsonString(int indent) const;
    std::string getExpression(Object* context=nullptr) const override;
    const ValueMapType& getMap() const{return map_;}
protected:
    std::string toJsonString(int indent, int currentIndent) const;
protected:
    MapType map_{};
};

/*! @} */

AST_NAMESPACE_END