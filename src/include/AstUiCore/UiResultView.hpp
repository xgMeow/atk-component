/// @file      UiResultView.hpp
/// @brief     结果表格和进度条组件
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-17

#pragma once

#include "AstGlobal.h"
#include <QWidget>
#include <QTableWidget>
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>
#include <vector>
#include <QStringList>

AST_NAMESPACE_BEGIN

/// @brief 结果表格与进度条组件
class AST_UICORE_API UiResultView : public QWidget
{
    Q_OBJECT
public:
    explicit UiResultView(QWidget* parent = nullptr);
    UiResultView(const UiResultView&) = delete;
    UiResultView& operator=(const UiResultView&) = delete;

    /// @brief 初始化表格列头
    /// @param variableNames 变量名列表
    /// @param responseNames 响应名列表
    void initColumns(const QStringList& variableNames, const QStringList& responseNames);

    /// @brief 追加一行结果
    /// @param runIndex   运行序号
    /// @param varValues  变量值列表
    /// @param respValues 响应值列表
    void appendRow(int runIndex, const std::vector<double>& varValues, const std::vector<double>& respValues);

    /// @brief 清空所有结果
    void clearResults();

    /// @brief 更新进度
    void setProgress(int current, int total);

    /// @brief 设置运行时间
    void setElapsedTime(double seconds);

private:
    void setupUi();

    QVBoxLayout*  layout_{};
    QTableWidget* table_{};
    QProgressBar* progressBar_{};
    QLabel*       progressLabel_{};
    QLabel*       timeLabel_{};
};

AST_NAMESPACE_END
