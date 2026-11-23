/// @file      UiBurnImpulsive.hpp
/// @brief     脉冲推力参数编辑界面
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"

class QComboBox;

AST_NAMESPACE_BEGIN

class Burn;
class BurnImpulsive;
class UiQuantity;

/// @brief 脉冲推力参数编辑器
class AST_UICORE_API UiBurnImpulsive : public UiObject
{
    Q_OBJECT
public:
    explicit UiBurnImpulsive(Object* object, QWidget* parent = nullptr);
    explicit UiBurnImpulsive(QWidget* parent = nullptr);
    ~UiBurnImpulsive() override = default;
    UiBurnImpulsive(const UiBurnImpulsive&) = delete;
    UiBurnImpulsive& operator=(const UiBurnImpulsive&) = delete;

    void setBurn(Burn* burn);
    BurnImpulsive* getBurnImpulsive() const;
    void refreshUi();
    void apply();
    void applyTo(BurnImpulsive* burn);

signals:
    void burnChanged(BurnImpulsive* burn);

private:
    void setupUi();

    QComboBox*  thrustAxesCombo_ = nullptr;
    UiQuantity* xEdit_ = nullptr;
    UiQuantity* yEdit_ = nullptr;
    UiQuantity* zEdit_ = nullptr;
};

AST_NAMESPACE_END
