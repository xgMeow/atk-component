/// @file      UiVariableList.hpp
/// @brief     脚本变量列表编辑控件
/// @details   用于编辑 VariableList 中的 Variable 对象，以表格形式展示
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-24

#pragma once

#include "AstGlobal.h"
#include "AstCore/VariableList.hpp"
#include "AstCore/Object.hpp"
#include "AstScript/Expr.hpp"
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>
#include <QToolButton>

AST_NAMESPACE_BEGIN

/// @brief 变量列表编辑控件，以表格形式管理脚本变量的增删改
class AST_UICORE_API UiVariableList : public QWidget
{
    Q_OBJECT
public:
    explicit UiVariableList(QWidget* parent = nullptr);
    UiVariableList(const UiVariableList&) = delete;
    UiVariableList& operator=(const UiVariableList&) = delete;

    /// @brief 设置要编辑的变量列表（裸指针，不持有所有权）
    /// @param variableList 要编辑的变量列表，被owner对象持有
    /// @param owner 所有者对象，用于判断变量列表的生命周期是否结束
    void setVariableList(VariableList* variableList, Object* owner);

    /// @brief 设置脚本解释器
    /// @param interpreter 脚本解释器，被owner对象持有
    /// @param owner 所有者对象，用于判断解释器的生命周期是否结束
    void setInterpreter(Interpreter* interpreter, Object* owner);

    /// @brief 设置工具栏可见性
    void setToolbarVisible(bool visible);

    /// @brief 刷新表格显示
    void refreshUi();

    /// @brief 获取当前选中的变量
    Variable* selectedVariable() const;

    /// @brief 获取当前编辑的变量列表
    VariableList* variableList() const;

    /// @brief 获取当前关联的脚本解释器
    Interpreter* interpreter() const;

    /// @brief 输入表达式，新建变量并追加到列表末尾
    /// @param expr 要添加的表达式
    void addExpression(Expr* expr, bool bind);

    /// @brief 输入表达式，新建与表达式双向绑定的变量并追加到列表末尾
    /// @param expr 要添加的表达式
    void addBindExpression(Expr* expr){return addExpression(expr, true);}


    void addExpression(Expr* expr){return addExpression(expr, false);}

signals:
    /// @brief 选中变量变化
    void variableSelected(Variable* variable);

    /// @brief 变量列表已修改（增/删/编辑/拖拽排序）
    void variableListChanged();

    /// @brief 用户选中了变量（用于通知外部联动控件）
    void variableFocused();

    /// @brief 用户双击了某个变量行
    void variableDoubleClicked(Variable* variable);

private slots:
    void onSelectionChanged();
    void onAddVariable();
    void onRemoveVariable();
    void onCellChanged(int row, int column);
    void onRefresh();

private:
    void setupUi();
    bool eventFilter(QObject* obj, QEvent* event) override;
    void syncOrderFromTable();

    QVBoxLayout*    mainLayout_{};
    QTableWidget*   tableWidget_{};
    QHBoxLayout*    buttonLayout_{};
    QToolButton*    addButton_{};
    QToolButton*    removeButton_{};
    QToolButton*    refreshButton_{};
private:
    VariableList*   variableList_ = nullptr;
    WeakPtr<Object> variableListOwner_{};
    Interpreter*    interpreter_ = nullptr;
    WeakPtr<Object> interpreterOwner_{};
};

AST_NAMESPACE_END
