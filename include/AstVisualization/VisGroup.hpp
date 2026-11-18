/// @file      VisGroup.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "VisObject.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


class AST_VISUALIZATION_API VisGroup final: public VisObject
{
public:
    VisGroup() = default;
    ~VisGroup() = default;
    A_DISABLE_COPY(VisGroup)

    /// @brief 访问者分派
    void accept(VisVisitor& visitor) override;

    /// @brief 添加子对象（拥有权移交给本组）
    /// @param object 子对象指针；可能为 nullptr
    void add(VisObject* object);

    /// @brief 添加子对象
    /// @param object 子对象句柄
    void add(const HVisObject& object);

    /// @brief 子对象列表
    const std::vector<HVisObject>& children() const { return children_; }

    /// @brief 子对象数量
    size_t size() const { return children_.size(); }

    /// @brief 是否为空
    bool empty() const { return children_.empty(); }

    /// @brief 预留子对象容量
    void reserve(size_t count) { children_.reserve(count); }

private:
    std::vector<HVisObject> children_{};
};


/*! @} */

AST_NAMESPACE_END
