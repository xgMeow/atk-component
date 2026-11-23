/// @file      UiFuelTank.hpp
/// @brief     燃料储罐编辑器
/// @details   编辑航天器燃料储罐参数（压力、温度、密度、质量等）
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QWidget>

AST_NAMESPACE_BEGIN

class SpacecraftState;
class UiQuantity;

/// @brief 燃料储罐编辑器
class AST_UICORE_API UiFuelTank : public UiObject
{
    Q_OBJECT
public:
    explicit UiFuelTank(Object* object, QWidget* parent = nullptr);
    explicit UiFuelTank(QWidget* parent = nullptr);
    ~UiFuelTank() override;
    UiFuelTank(const UiFuelTank&) = delete;
    UiFuelTank& operator=(const UiFuelTank&) = delete;

    void setSpacecraftState(SpacecraftState* state);
    SpacecraftState* getSpacecraftState() const;

private:
    void setupUi();
    void refreshFromState(SpacecraftState* state);

    // 燃料储罐参数控件
    UiQuantity*     tankPressureEdit_ = nullptr;
    UiQuantity*     tankTemperatureEdit_ = nullptr;
    UiQuantity*     fuelDensityEdit_ = nullptr;
    UiQuantity*     fuelMassEdit_ = nullptr;
};

AST_NAMESPACE_END
