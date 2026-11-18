/// @file      UiInitialState.hpp
/// @brief     InitialState 段编辑器
/// @details   含坐标系选择、状态类型切换（基于 UiStateEditor）
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QComboBox>
#include <QTabWidget>

AST_NAMESPACE_BEGIN

class InitialState;
class SpacecraftState;
class State;
class UiStateEditor;
class UiSpacecraftParams;
class UiFuelTank;

/// @brief InitialState 段编辑器
class AST_UICORE_API UiInitialState : public UiObject
{
    Q_OBJECT
public:
    explicit UiInitialState(Object* object, QWidget* parent = nullptr);
    explicit UiInitialState(QWidget* parent = nullptr);
    ~UiInitialState() override;
    UiInitialState(const UiInitialState&) = delete;
    UiInitialState& operator=(const UiInitialState&) = delete;

    void setInitialState(InitialState* state);
    InitialState* getInitialState() const;

private slots:
    void onStateTypeChanged(int index);
    void onStateChanged(State* state);

private:
    void setupUi();
    void setupElementsTab(QWidget* tab);
    void rebuildFromSpacecraftState(SpacecraftState* scState);

    QTabWidget*         tabWidget_ = nullptr;
    QComboBox*          stateTypeCombo_ = nullptr;
    UiStateEditor*      stateEditor_ = nullptr;
    UiSpacecraftParams* scParamsEditor_ = nullptr;
    UiFuelTank*         fuelTankEditor_ = nullptr;
};

AST_NAMESPACE_END
