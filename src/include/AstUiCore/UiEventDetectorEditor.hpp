/// @file      UiEventDetectorEditor.hpp
/// @brief     事件检测器编辑器 — RTTI 调度
/// @details   根据 EventDetector 子类类型自动切换对应的编辑器页面
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include <QStackedWidget>

AST_NAMESPACE_BEGIN

class EventDetector;
class UiEventDetector;

/// @brief 事件检测器编辑器 — 根据 RTTI 类型切换编辑页面
class AST_UICORE_API UiEventDetectorEditor : public QStackedWidget
{
    Q_OBJECT
public:
    explicit UiEventDetectorEditor(QWidget* parent = nullptr);
    ~UiEventDetectorEditor() override;
    UiEventDetectorEditor(const UiEventDetectorEditor&) = delete;
    UiEventDetectorEditor& operator=(const UiEventDetectorEditor&) = delete;

    void setDetector(EventDetector* det);
    EventDetector* getDetector() const;
    void clear();

signals:
    void detectorChanged(EventDetector* det);

private:
    void setupUi();

    UiEventDetector* basePage_ = nullptr;
    int baseIdx_ = -1;
};

AST_NAMESPACE_END
