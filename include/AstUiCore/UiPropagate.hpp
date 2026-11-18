/// @file      UiPropagate.hpp
/// @brief     Propagate 段编辑器
/// @details   预报器选择、时间设置、事件检测器列表
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include "AstUiCore/UiQuantity.hpp"
#include <QCheckBox>
#include <QComboBox>

class QPushButton;

AST_NAMESPACE_BEGIN

class Propagate;
class HPOP;
class UiEventDetectorList;

/// @brief Propagate 段编辑器
class AST_UICORE_API UiPropagate : public UiObject
{
    Q_OBJECT
public:
    explicit UiPropagate(Object* object, QWidget* parent = nullptr);
    explicit UiPropagate(QWidget* parent = nullptr);
    ~UiPropagate() override;
    UiPropagate(const UiPropagate&) = delete;
    UiPropagate& operator=(const UiPropagate&) = delete;

    void setPropagate(Propagate* prop);
    Propagate* getPropagate() const;

private slots:
    void onMaxTimeChanged();
    void onMaxTimeEnabledChanged(bool checked);
    void onDirectionChanged(int index);
    void onConfigureForceModel();
    void onConfigureIntegrator();

private:
    void setupUi();
    void refreshFromPropagate();

    UiQuantity*  maxTimeEdit_ = nullptr;
    QCheckBox*   useMaxTimeCheck_ = nullptr;
    QComboBox*   directionCombo_ = nullptr;
    QPushButton* forceModelBtn_ = nullptr;
    QPushButton* integratorBtn_ = nullptr;
    UiEventDetectorList* eventDetectorList_ = nullptr;
};

AST_NAMESPACE_END
