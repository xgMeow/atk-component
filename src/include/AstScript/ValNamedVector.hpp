/// @file      ValNamedVector.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-01

#pragma once

#include "AstGlobal.h"
#include "Value.hpp"
#include "AstUtil/OrderedMap.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 命名向量值类
/// @todo 完善命名向量值类的实现 
class AST_SCRIPT_API ValNamedVector: public Value
{
public:
    using ItemType = std::pair<std::string, SharedPtr<Value>>;
    using VectorType = std::vector<ItemType>;
    static ValNamedVector* New();

    AST_EXPR(ValNamedVector)

    ValNamedVector() = default;
    ~ValNamedVector() = default;
    /// @brief 获取向量元素数量
    /// @return size_t 向量元素数量
    size_t size() const{return vector_.size();}


    VectorType& getVector() {return vector_;}
    const VectorType& getVector() const {return vector_;}

    std::string getExpression(Object* object) const override;
private:
    VectorType vector_{};
};


/*! @} */

AST_NAMESPACE_END

