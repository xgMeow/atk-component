/// @file      UiStateEditor.hpp
/// @brief     状态编辑器 — 根据 State RTTI 类型转发到 Cartesian/Keplerian 子编辑器
/// @details   不处理类型切换，不含类型选择控件。仅根据传入的 State* 类型自动
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include <QWidget>

class QStackedWidget;

AST_NAMESPACE_BEGIN

class State;
class StateCartesian;
class StateKeplerian;
class UiStateCartesian;
class UiStateKeplerian;

/// @brief 状态编辑器容器 — RTTI 类型分发 + 信号转发
///
/// 与 UiCommandEditor 模式一致：
///   1. setState(State*) 按 RTTI 切换 Cartesian/Keplerian 页面
///   2. 子编辑器变更信号统一通过 stateChanged(State*) 向外转发
class AST_UICORE_API UiStateEditor : public QWidget
{
    Q_OBJECT
public:
    explicit UiStateEditor(QWidget* parent = nullptr);
    ~UiStateEditor() override;
    UiStateEditor(const UiStateEditor&) = delete;
    UiStateEditor& operator=(const UiStateEditor&) = delete;

    /// @brief 设置要编辑的 State，根据 RTTI 类型切换子编辑器
    void setState(State* state);

    /// @brief 获取当前编辑中的 State（来自活跃的子编辑器）
    State* getState() const;

signals:
    /// @brief 子编辑器内容变更（类型切换不触发）
    void stateChanged(State* state);

private:
    void setupUi();
    void forwardCartesianChanged(StateCartesian* s);
    void forwardKeplerianChanged(StateKeplerian* s);

    QStackedWidget*   stack_ = nullptr;
    UiStateCartesian* cartesianEdit_ = nullptr;
    UiStateKeplerian* keplerianEdit_ = nullptr;
    int cartesianIdx_ = -1;
    int keplerianIdx_ = -1;
};

AST_NAMESPACE_END
