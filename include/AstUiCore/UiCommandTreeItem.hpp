/// @file      UiSequenceTreeItem.hpp
/// @brief     序列对象树项，通过 Sequence::getCommands() 获取子对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-28

#pragma once

#include "UiObjectTreeItem.hpp"
#include "AstCore/Segment.hpp"

AST_NAMESPACE_BEGIN

class Segment;
class Command;

/// @brief Segment 对象树项
class AST_UICORE_API UiCommandTreeItem : public UiObjectTreeItem
{
public:
    using UiObjectTreeItem::UiObjectTreeItem;

    UiCommandTreeItem* clone() const override;

    QList<UiObjectTreeItem*> createChildItems(const TreeBuildOptions& options = {}) const override;

    /// @brief 获取 Segment 对象
    Segment* segment() const { return getObject<Segment*>(); }

    Command* command() const { return getObject<Command*>(); }

    /// @brief 从父序列移除 Command 对象
    errc_t removeCommand();

    /// @brief 从父序列移除 Command 对象并删除树项
    void removeCommandAndDeleteItem();
};

AST_NAMESPACE_END
