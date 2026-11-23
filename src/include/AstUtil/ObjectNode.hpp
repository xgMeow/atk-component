/// @file      ObjectNode.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-02

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include <memory>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 对象节点
/// @details 对象节点用于表示RTTI中的对象，每个对象都有一个父对象和多个子对象。
class AST_UTIL_API ObjectNode
{
public:
    ObjectNode() = default;

    ObjectNode(const ObjectNode&) = delete;
    ObjectNode& operator=(const ObjectNode&) = delete;

    explicit ObjectNode(Object* object)
        : object_(object)
        , children_()
    {}
    friend class ObjectManager;
    ~ObjectNode() = default;

    /// @brief 获取对象节点的对象
    /// @return Object* 对象指针
    Object* getObject() const {return object_.get();}

    /// @brief 检查节点的对象是否过期
    /// @return bool 是否过期
    bool expired() const {return object_.expired();}

    /// @brief 获取对象节点的父对象
    /// @return Object* 父对象指针
    Object* getParentScope() const;

    /// @brief 获取对象节点的父对象的父节点
    /// @return ObjectNode* 父对象的父节点指针
    ObjectNode* getParentNode() const {return parentNode_;}

    /// @brief 获取对象节点的子节点
    /// @return std::vector<ObjectNode*>& 子节点列表
    std::vector<ObjectNode*>& getChildren(){return children_;}

    /// @brief 添加子节点
    /// @param child 子节点指针
    errc_t addChild(ObjectNode* child);

    /// @brief 设置对象节点的父节点
    /// @param parent 父节点指针
    errc_t setParent(ObjectNode* parent);

    /// @brief 移除子节点
    /// @param child 子节点指针
    errc_t removeChild(ObjectNode* child);

    /// @brief 清除对象节点的所有子节点
    void clearChildren();

    /// @brief 清除对象节点的所有子节点和引用计数
    void clear();

protected:
    void incRef();
    void decRef();
protected:
    WeakPtr<Object> object_;
    ObjectNode* parentNode_{nullptr};
    std::vector<ObjectNode*> children_;
};

/*! @} */

AST_NAMESPACE_END
