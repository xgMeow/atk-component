/// @file      UiManeuver.hpp
/// @brief     Maneuver 段编辑器
/// @details   发动机选择、姿态设置
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"

AST_NAMESPACE_BEGIN

class Maneuver;
class Burn;
class UiBurnEditor;

/// @brief Maneuver 段编辑器
class AST_UICORE_API UiManeuver : public UiObject
{
    Q_OBJECT
public:
    explicit UiManeuver(Object* object, QWidget* parent = nullptr);
    explicit UiManeuver(QWidget* parent = nullptr);
    ~UiManeuver() override;
    UiManeuver(const UiManeuver&) = delete;
    UiManeuver& operator=(const UiManeuver&) = delete;

    void setManeuver(Maneuver* maneuver);
    Maneuver* getManeuver() const;

private:
    void setupUi();

    UiBurnEditor* burnEditor_ = nullptr;
};

AST_NAMESPACE_END
