/// @file      UiWorkbenchExprPicker.hpp
/// @brief     从 StudyWorkbench 的输入/输出变量中选择表达式
/// @details   弹出对话框，复用 UiVariableList 表格展示父级 StudyWorkbench
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-11

#pragma once

#include "AstGlobal.h"
#include <QDialog>

class QPushButton;

AST_NAMESPACE_BEGIN

class StudyWorkbench;
class Expr;
class UiVariableList;
class Variable;

/// @brief 从 StudyWorkbench 的输入/输出变量中选择表达式
class AST_UICORE_API UiWorkbenchExprPicker : public QDialog
{
    Q_OBJECT
public:
    /// @param workbench 父级研究工作台
    /// @param parent   父窗口
    explicit UiWorkbenchExprPicker(StudyWorkbench* workbench, QWidget* parent = nullptr);

    UiWorkbenchExprPicker(const UiWorkbenchExprPicker&) = delete;
    UiWorkbenchExprPicker& operator=(const UiWorkbenchExprPicker&) = delete;

    /// @brief 获取用户选中的表达式（Variable 即 Expr）
    Expr* selectedExpr() const { return selectedExpr_; }

private slots:
    void onAdvanced();
    void onVariableSelected(Variable* variable);
    void accept() override;

private:
    void setupUi();

    StudyWorkbench* workbench_;
    Expr*           selectedExpr_ = nullptr;

    UiVariableList* inputList_{};
    UiVariableList* outputList_{};
    QPushButton*    advancedBtn_{};
};

AST_NAMESPACE_END
