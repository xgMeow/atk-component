/// @file      UiObjectTreeItem.hpp
/// @brief     对象树控件项，关联一个 Object 并可递归构建子节点
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-28

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include <QTreeWidget>
#include <vector>

AST_NAMESPACE_BEGIN

/// @brief 对象树构建选项
struct TreeBuildOptions
{
    bool showComponents = true;  ///< 是否显示组件节点，默认 true
};

class AST_UICORE_API UiObjectTreeItem : public QTreeWidgetItem
{
public:
    UiObjectTreeItem();

    explicit UiObjectTreeItem(Object* obj);

    /// 递归构建子节点
    void buildChildren(const TreeBuildOptions& options = {});

    /// 获取关联的对象
    Object* object() const { return object_.get(); }

    template<typename T>
    T getObject() const { return aobject_cast<T>(object()); }

    UiObjectTreeItem* clone() const override;

    /// 创建子节点列表，子类可重写以实现自定义的层级关系和 item 类型
    virtual QList<UiObjectTreeItem*> createChildItems(const TreeBuildOptions& options = {}) const;
private:
    /// 配置 item 的基本属性（关联对象、文本、图标、tooltip）
    void configure(Object* obj);
private:
    WeakPtr<Object> object_ = nullptr;
};

AST_NAMESPACE_END
