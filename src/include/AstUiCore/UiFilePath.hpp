/// @file      UiFilePath.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-04

#pragma once

#include "AstGlobal.h"
#include "UiValueEdit.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup GUI
    @{
*/

/// @brief 文件路径输入框
/// @details 用于输入文件路径，支持通过文件对话框选择文件
class AST_UICORE_API UiFilePath: public QWidget
{
    Q_OBJECT

public:
    UiFilePath(const UiFilePath&) = delete;
    UiFilePath& operator=(const UiFilePath&) = delete;
    UiFilePath(QWidget* parent = nullptr);

    /// @brief 设置文件路径
    /// @param path 文件路径
    void setPath(const QString& path);

    /// @brief 设置文件路径
    /// @param path 文件路径
    void setPath(StringView path);


    /// @brief 获取文件路径
    /// @return 文件路径
    QString path() const;

    /// @brief 设置文件过滤器
    /// @param filter 文件过滤器，例如 "SPK文件 (*.bsp);;所有文件 (*.*)"
    void setFilter(const QString& filter);

    /// @brief 获取文件过滤器
    /// @return 文件过滤器
    QString filter() const;

signals:
    void pathChanged(const QString& path);
private slots:
    void onBrowse();
    void onEditingFinished();
private:
    UiValueEdit* lineEdit_{nullptr};
    QString currentPath_{};
    QString filter_{};
};

/*! @} */

AST_NAMESPACE_END