/// @file      UiEventDetector.hpp
/// @brief     事件检测器基类编辑器
/// @details   编辑 EventDetector 的公共属性：激活、重复次数、方向、阈值、目标值
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QWidget>

class QComboBox;

AST_NAMESPACE_BEGIN

class EventDetector;
class UiQuantity;

/// @brief 事件检测器基类编辑器 — 编辑公共属性
class UiInteger;

class AST_UICORE_API UiEventDetector : public UiObject
{
    Q_OBJECT
public:
    explicit UiEventDetector(Object* object, QWidget* parent = nullptr);
    explicit UiEventDetector(QWidget* parent = nullptr);
    ~UiEventDetector() override;
    UiEventDetector(const UiEventDetector&) = delete;
    UiEventDetector& operator=(const UiEventDetector&) = delete;

    void setEventDetector(EventDetector* det);
    EventDetector* getEventDetector() const;

signals:
    void detectorChanged(EventDetector* det);

private:
    void setupUi();
    void refreshFromDetector(EventDetector* det);

    UiInteger*  repeatCountEdit_ = nullptr;
    QComboBox*  directionCombo_ = nullptr;
    UiQuantity* thresholdEdit_ = nullptr;
    UiQuantity* goalEdit_ = nullptr;
};

AST_NAMESPACE_END
