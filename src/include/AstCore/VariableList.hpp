/// @file      VariableList.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-30

#pragma once

#include "AstGlobal.h"
#include "AstScript/Variable.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 变量列表
/// @details 用于存储脚本中的变量
class VariableList
{
public:
    using ListType = std::vector<SharedPtr<Variable>>;
    using iterator = ListType::iterator;
    using const_iterator = ListType::const_iterator;


    VariableList() = default;
    ~VariableList() = default;
    void clear() { variables_.clear(); }
    void append(Variable* var) { variables_.push_back(var); }
    void erase(size_t index) { variables_.erase(variables_.begin() + index); }
    void move(size_t from, size_t to);
    size_t size() const { return variables_.size(); }

    Variable* at(size_t index) { return variables_.at(index).get(); }
    Variable* at(size_t index) const { return variables_.at(index).get(); }
    Variable* operator[](size_t index) { return variables_[index].get(); }
    Variable* operator[](size_t index) const { return variables_[index].get(); }

    iterator begin() { return variables_.begin(); }
    iterator end() { return variables_.end(); }
    const_iterator begin() const { return variables_.begin(); }
    const_iterator end() const { return variables_.end(); }

private:
    ListType variables_{};        ///< 变量列表
};


inline void VariableList::move(size_t from, size_t to)
{
    if (from >= variables_.size() || to >= variables_.size() || from == to)
        return;
    SharedPtr<Variable> var = variables_[from];
    variables_.erase(variables_.begin() + from);
    size_t insertPos = (to > from) ? to - 1 : to;
    variables_.insert(variables_.begin() + insertPos, var);
}

/*! @} */

AST_NAMESPACE_END
