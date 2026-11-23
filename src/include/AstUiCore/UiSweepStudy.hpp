/// @file      UiSweepStudy.hpp
/// @brief     SweepStudy 编辑界面
/// @details   提供两个 Tab 页：变量与输出（左右分栏内嵌表格编辑）和任务模型编辑
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-05

#pragma once

#include "AstGlobal.h"
#include "AstAnalyzer/SweepStudy.hpp"
#include <QWidget>

class QTabWidget;
class QSplitter;
class QStackedWidget;
class QLabel;
class QPushButton;

AST_NAMESPACE_BEGIN

class SweepStudy;
class UiSweepVariableList;
class UiSweepOutputList;

/// @brief SweepStudy 编辑界面
class AST_UICORE_API UiSweepStudy : public QWidget
{
    Q_OBJECT
public:
    explicit UiSweepStudy(QWidget* parent = nullptr);
    UiSweepStudy(const UiSweepStudy&) = delete;
    UiSweepStudy& operator=(const UiSweepStudy&) = delete;

    /// @brief 绑定要编辑的 SweepStudy
    void setAnalyzer(SweepStudy* analyzer);

    /// @brief 获取当前绑定的 SweepStudy
    SweepStudy* analyzer() const { return analyzer_.get(); }

    /// @brief 刷新界面
    void refreshUi();

private slots:
    void onExecute();

private:
    void setupUi();
    void rebuildCommandEditor();

    WeakPtr<SweepStudy> analyzer_{}; 

    QTabWidget*        tabWidget_{}; 

    // 变量与输出 Tab（同页左右分栏）
    QSplitter*           studySplitter_{}; 
    UiSweepVariableList* varList_{}; 
    UiSweepOutputList*   outputList_{}; 

    // 任务模型 Tab
    QStackedWidget*      commandStack_{}; 
    QLabel*              placeholderLabel_{}; 

    // 执行按钮
    QPushButton*         executeBtn_{};
};

AST_NAMESPACE_END
