/// @file      UiBurnEditor.hpp
/// @brief     发动机点火编辑器 — RTTI 类型分发
/// @details   根据 Burn 子类类型自动切换脉冲/有限推力编辑页面
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include <QWidget>

class QStackedWidget;

AST_NAMESPACE_BEGIN

class Burn;
class BurnImpulsive;
class UiBurnImpulsive;

/// @brief 发动机点火编辑器 — RTTI 类型分发
class AST_UICORE_API UiBurnEditor : public QWidget
{
    Q_OBJECT
public:
    explicit UiBurnEditor(QWidget* parent = nullptr);
    ~UiBurnEditor() override;
    UiBurnEditor(const UiBurnEditor&) = delete;
    UiBurnEditor& operator=(const UiBurnEditor&) = delete;

    void setBurn(Burn* burn);
    void clear();

signals:
    void burnChanged(Burn* burn);

private:
    void setupUi();

    QStackedWidget* stack_ = nullptr;
    UiBurnImpulsive* impulsivePage_ = nullptr;
    int              impulsiveIdx_ = -1;
};

AST_NAMESPACE_END
