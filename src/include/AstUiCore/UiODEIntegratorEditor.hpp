/// @file      UiODEIntegratorEditor.hpp
/// @brief     ODE 积分器编辑器 — RTTI 类型分发
/// @details   根据 ODEIntegrator 子类类型自动切换定步长/变步长编辑页面
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include <QWidget>

class QStackedWidget;
class QDoubleSpinBox;

AST_NAMESPACE_BEGIN

class ODEIntegrator;
class ODEVarStepIntegrator;
class UiODEVarStepIntegrator;

/// @brief ODE 积分器编辑器 — RTTI 类型分发 + 信号转发
class AST_UICORE_API UiODEIntegratorEditor : public QWidget
{
    Q_OBJECT
public:
    explicit UiODEIntegratorEditor(QWidget* parent = nullptr);
    ~UiODEIntegratorEditor() override;
    UiODEIntegratorEditor(const UiODEIntegratorEditor&) = delete;
    UiODEIntegratorEditor& operator=(const UiODEIntegratorEditor&) = delete;

    void setIntegrator(ODEIntegrator* integrator);
    ODEIntegrator* getIntegrator() const;
    void apply();
    void clear();

signals:
    void integratorChanged(ODEIntegrator* integrator);

private:
    void setupUi();

    QStackedWidget*         stack_ = nullptr;
    QDoubleSpinBox*         fixedStepEdit_ = nullptr;
    int                     fixedStepIdx_ = -1;
    UiODEVarStepIntegrator* varStepPage_ = nullptr;
    int                     varStepIdx_ = -1;
};

AST_NAMESPACE_END
