/// @file      UiScenarioWizard.hpp
/// @brief     新建场景向导对话框
/// @details   用于创建新任务场景，包含场景名称、描述、存储目录、
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-07

#pragma once

#include "AstGlobal.h"
#include "AstCore/TimePoint.hpp"
#include <QDialog>
#include <QString>

class QLineEdit;
class QTextEdit;
class QComboBox;
class QPushButton;
class QLabel;

AST_NAMESPACE_BEGIN

class UiTimePoint;

/// @brief 新建场景向导对话框
class AST_UICORE_API UiScenarioWizard : public QDialog
{
    Q_OBJECT

public:
    explicit UiScenarioWizard(QWidget* parent = nullptr);
    ~UiScenarioWizard() override;
    UiScenarioWizard(const UiScenarioWizard&) = delete;
    UiScenarioWizard& operator=(const UiScenarioWizard&) = delete;

    /// @brief 场景名称
    QString scenarioName() const;

    /// @brief 场景描述
    QString scenarioDescription() const;

    /// @brief 场景存储目录
    QString scenarioLocation() const;

    /// @brief 场景起始时间点（绝对时间）
    TimePoint startTime() const;

    /// @brief 场景终止时间点（绝对时间）
    TimePoint stopTime() const;

    /// @brief 中心天体名称（如 "Earth"）
    QString centralBody() const;

private:
    void setupUi();
    void setupConnections();
    void applyTimeDefaults();
    void browseLocation();

private:
    QLineEdit*   nameEdit_ = nullptr;
    QTextEdit*   descEdit_ = nullptr;
    QLineEdit*   locationEdit_ = nullptr;
    UiTimePoint* startEdit_ = nullptr;
    UiTimePoint* stopEdit_ = nullptr;
    QComboBox*   centralBodyCombo_ = nullptr;
    QPushButton* okButton_ = nullptr;
    QPushButton* cancelButton_ = nullptr;
};

AST_NAMESPACE_END
