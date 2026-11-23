/// @file      UiAnalyzerMainWindow.hpp
/// @brief     Analyzer 模块主窗口（Ribbon 风格菜单）
/// @details   顶部 Ribbon 菜单 + 中央 UiStudyWorkbench 编辑区 + 底部状态栏
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-03

#pragma once

#include "AstGlobal.h"
#include <QIcon>
#include <QMainWindow>
#include <QStyle>

class QTabBar;
class QStackedWidget;
class QToolButton;

AST_NAMESPACE_BEGIN

class UiStudyWorkbench;
class UiSweepStudy;
class StudyWorkbench;
class SweepStudy;

/// @brief Analyzer 模块主窗口，使用 Ribbon 风格菜单
class AST_UICORE_API UiAnalyzerMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit UiAnalyzerMainWindow(QWidget* parent = nullptr);
    ~UiAnalyzerMainWindow() override;

    UiAnalyzerMainWindow(const UiAnalyzerMainWindow&) = delete;
    UiAnalyzerMainWindow& operator=(const UiAnalyzerMainWindow&) = delete;

    /// @brief 获取内部 UiStudyWorkbench 编辑器
    UiStudyWorkbench* studyWorkbenchEditor() const { return basicEditor_; }

    /// @brief 获取内部 UiSweepStudy 编辑器
    UiSweepStudy* sweepStudyEditor() const { return traverseEditor_; }

    /// @brief 设置要编辑的 StudyWorkbench
    void setStudyWorkbench(StudyWorkbench* analyzer);

    /// @brief 设置要编辑的 SweepStudy
    void setSweepStudy(SweepStudy* analyzer);

private:
    void setupUi();

    QWidget* setupRibbon();
    QWidget* createRibbonPage(int index);
    QToolButton* createRibbonButton(const QString& text, QStyle::StandardPixmap icon,
                                     QWidget* parent);
    QToolButton* createRibbonButton(const QString& text, const QIcon& icon,
                                     QWidget* parent);

    // Ribbon
    QTabBar*        ribbonTabBar_ = nullptr;
    QStackedWidget* ribbonStack_ = nullptr;

    // 中央编辑器
    QStackedWidget*        editorStack_ = nullptr;
    UiStudyWorkbench*       basicEditor_ = nullptr;
    UiSweepStudy* traverseEditor_ = nullptr;
};

AST_NAMESPACE_END
