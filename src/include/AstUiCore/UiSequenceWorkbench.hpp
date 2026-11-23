/// @file      UiSequenceWorkbench.hpp
/// @brief     任务序列编辑主面板
/// @details   组装任务树、段编辑器、工具栏和输出区域
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QMenu>

class QSplitter;
class QPlainTextEdit;

AST_NAMESPACE_BEGIN

class Sequence;
class Command;
class UiCommandTree;
class UiCommandEditor;

/// @brief 任务序列编辑主面板（QWidget），由调用方嵌入容器
class AST_UICORE_API UiSequenceWorkbench : public UiObject
{
    Q_OBJECT
public:
    explicit UiSequenceWorkbench(QWidget* parent = nullptr);
    explicit UiSequenceWorkbench(Object* sequence, QWidget* parent = nullptr);
    ~UiSequenceWorkbench() override;
    UiSequenceWorkbench(const UiSequenceWorkbench&) = delete;
    UiSequenceWorkbench& operator=(const UiSequenceWorkbench&) = delete;

    /// @brief 设置外部 MainSequence（裸指针，不持有所有权）
    void setSequence(Sequence* sequence);

    /// @brief 获取当前 MainSequence
    Sequence* sequence() const;


private slots:
    void onCommandSelected(Command* cmd);
    void onAddInitialState();
    void onAddPropagate();
    void onAddManeuver();
    void onAddSequence();
    void onAddTargeterSequence();
    void onAddLandingSite();
    void onDeleteSegment();
    void onOpenFile();
    void onSaveFile();
    void onRun();
    void onStop();

private:
    void setupUi();
    void setupToolBar();
    void setupConnections();
    void appendOutput(const QString& text);

    // 工具栏和动作
    QToolBar*    toolBar_ = nullptr;
    QMenu*       addMenu_ = nullptr;
    QAction*     openAction_ = nullptr;
    QAction*     saveAction_ = nullptr;
    QAction*     deleteAction_ = nullptr;
    QAction*     runAction_ = nullptr;
    QAction*     stopAction_ = nullptr;

    // 子组件
    QSplitter*       mainSplitter_ = nullptr;
    UiCommandTree*   commandTree_ = nullptr;
    UiCommandEditor* commandEditor_ = nullptr;
    QPlainTextEdit*  outputView_ = nullptr;

};

AST_NAMESPACE_END
