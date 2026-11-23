/// @file      UiStudyWorkbench.hpp
/// @brief     StudyWorkbench 编辑界面
/// @details   提供两个 Tab 页：变量编辑（inputs/outputs）和执行命令编辑
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-03

#pragma once

#include "AstGlobal.h"
#include "AstAnalyzer/StudyWorkbench.hpp"
#include <QWidget>

class QTabWidget;
class QSplitter;
class QStackedWidget;
class QLabel;

AST_NAMESPACE_BEGIN

class StudyWorkbench;
class UiExpressionBrowser;
class UiVariableList;

/// @brief StudyWorkbench 编辑界面
class AST_UICORE_API UiStudyWorkbench : public QWidget
{
    Q_OBJECT
public:
    explicit UiStudyWorkbench(QWidget* parent = nullptr);

    UiStudyWorkbench(const UiStudyWorkbench&) = delete;
    UiStudyWorkbench& operator=(const UiStudyWorkbench&) = delete;

    /// @brief 绑定要编辑的 StudyWorkbench
    void setStudyWorkbench(StudyWorkbench* analyzer);

    /// @brief 获取当前绑定的 StudyWorkbench
    StudyWorkbench* studyWorkbench() const { return analyzer_.get(); }

    /// @brief 刷新界面
    void refreshUi();

private:
    void setupUi();
    void rebuildCommandEditor();

    WeakPtr<StudyWorkbench> analyzer_{};

    QSplitter*           varSplitter_{};
    UiExpressionBrowser* expressionBrowser_{};
    QTabWidget*          tabWidget_{};
    QSplitter*           splitter_{};
    UiVariableList*      inputsEditor_{};
    UiVariableList*      outputsEditor_{};
    QStackedWidget*      commandStack_{};
    QLabel*              placeholderLabel_{};
};

AST_NAMESPACE_END
