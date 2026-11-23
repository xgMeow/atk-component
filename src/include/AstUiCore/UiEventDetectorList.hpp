/// @file      UiEventDetectorList.hpp
/// @brief     事件检测器列表管理组件
/// @details   表格显示激活/名称/类型，支持添加删除，即时同步到 Propagate
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include <QWidget>

class QTableWidget;
class QPushButton;

AST_NAMESPACE_BEGIN

class Propagate;
class EventDetector;
class UiEventDetectorEditor;

/// @brief 事件检测器列表管理组件
class AST_UICORE_API UiEventDetectorList : public UiObject
{
    Q_OBJECT
public:
    explicit UiEventDetectorList(Object* object, QWidget* parent = nullptr);
    explicit UiEventDetectorList(QWidget* parent = nullptr);
    ~UiEventDetectorList() override;
    UiEventDetectorList(const UiEventDetectorList&) = delete;
    UiEventDetectorList& operator=(const UiEventDetectorList&) = delete;

    void setPropagate(Propagate* prop);
    Propagate* getPropagate() const;

signals:
    void detectorSelected(EventDetector* det);

private slots:
    void onAddDetector(const QString& className);
    void onRemoveDetector();
    void onActiveToggled(int row, bool checked);
    void onNameChanged(int row, int col);

private:
    void setupUi();
    void refreshList();
    QString typeDisplayName(EventDetector* det) const;

    QTableWidget* table_ = nullptr;
    UiEventDetectorEditor* editor_ = nullptr;
    QPushButton*  addBtn_ = nullptr;
    QPushButton*  removeBtn_ = nullptr;
};

AST_NAMESPACE_END
