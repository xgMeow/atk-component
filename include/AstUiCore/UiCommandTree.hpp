/// @file      UiCommandTree.hpp
/// @brief     任务命令树控件，显示和编辑任务命令序列层级
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-03

#pragma once

#include "UiObjectTree.hpp"
#include "AstCore/MissionCommand.hpp"
#include "AstCore/MainSequence.hpp"

AST_NAMESPACE_BEGIN

class Segment;
class UiCommandTreeItem;

/// @brief 任务段树控件，继承 UiObjectTree，支持拖拽排序、右键菜单、序列同步
class AST_UICORE_API UiCommandTree : public UiObjectTree
{
    Q_OBJECT

public:
    explicit UiCommandTree(QWidget* parent = nullptr);

    /// @brief 设置主序列并刷新树，设为 nullptr 则清空
    void setSequence(MainSequence* sequence);

    /// @brief 获取树中当前选中的任务命令，无选中时返回 nullptr
    Command* selectedCommand() const;

    /// @brief 删除当前选中的命令（树节点 + 同步内核）
    void removeSelectedCommand();

signals:
    /// @brief 当用户在树中选中任务命令时发出
    void commandSelected(Command* command);

    /// @brief 当树结构被拖拽或删除修改后发出
    void treeModified();

    /// @brief 当通过右键菜单插入新命令后发出
    void commandInserted(Command* command);

    /// @brief 当用户通过右键菜单请求命令概要时发出
    void commandSummaryRequested(Command* command);

protected:
    void dropEvent(QDropEvent* event) override;
    void contextMenuEvent(QContextMenuEvent* event) override;

private:
    /// @brief 在选定项的上方或下方插入指定类型的新命令
    void insertCommandRelativeToItem(UiCommandTreeItem* item, const QString& typeName, bool above);

    /// @brief 创建并设置插入子菜单
    QMenu* createInsertMenu(const QString& title);

    /// @brief 处理插入子菜单的动作
    void handleInsertAction(QAction* action, UiCommandTreeItem* item, bool above);

    WeakPtr<Sequence> sequence_ = nullptr;
};

AST_NAMESPACE_END
