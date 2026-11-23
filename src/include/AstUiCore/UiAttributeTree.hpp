/// @file      UiAttributeTree.hpp
/// @brief     属性树控件，以树形显示对象的反射属性列表
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-04

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/Attribute.hpp"
#include <QTreeWidget>

AST_NAMESPACE_BEGIN

class UiAttributeTreeItem;

/// @brief 属性树控件，显示一个 AST 对象的所有反射属性（遍历继承链）
class AST_UICORE_API UiAttributeTree : public QTreeWidget
{
    Q_OBJECT

public:
    explicit UiAttributeTree(QWidget* parent = nullptr);

    /// @brief 设置要显示属性的对象，设为 nullptr 则清空树
    void setObject(Object* object);

    /// @brief 获取当前绑定的对象
    Object* object() const;

    /// @brief 刷新属性树（重新枚举属性并重建树项）
    void refresh();

    /// @brief 获取当前选中项对应的 Attribute，无选中时返回空 Attribute
    Attribute selectedAttribute() const;

signals:
    /// @brief 当用户在树中选中属性时发出
    void attributeSelected(const Attribute& attr);

private:
    /// @brief 递归遍历继承链，收集所有属性
    void collectProperties(Class* type, std::vector<Property*>& out) const;

    WeakPtr<Object> rootObject_{};
};

AST_NAMESPACE_END
