/// @file      UiStartPage.hpp
/// @brief     SpaceAST 起始页
/// @details   提供启动后的新建、示例和学习入口
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-27

#pragma once

#include "AstGlobal.h"
#include <QString>
#include <QStyle>
#include <QVector>
#include <QWidget>

class QToolButton;

AST_NAMESPACE_BEGIN

class AST_UICORE_API UiStartPage : public QWidget
{
    Q_OBJECT

public:
    explicit UiStartPage(QWidget* parent = nullptr);
    ~UiStartPage() override;

signals:
    void newTaskRequested();
    void openTaskRequested();
    void exampleRequested(const QString& name);
    void cardActivated(const QString& id);

private:
    void setupUi();

    QWidget* createSidebar();
    QWidget* createMainArea();
    QWidget* createNewTab();
    QWidget* createExampleTab();
    QWidget* createLearningTab();
    QWidget* createScrollPage(QWidget* content);
    QWidget* createSection(const QString& title, const QVector<QWidget*>& cards);
    QWidget* createCard(const QString& id, const QString& iconName, QStyle::StandardPixmap fallbackIcon,
                        const QString& title, const QString& description);
    QToolButton* createSidebarButton(const QString& text, const QString& iconName,
                                     QStyle::StandardPixmap fallbackIcon);
};

AST_NAMESPACE_END
