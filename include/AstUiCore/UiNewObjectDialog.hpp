/// @file      UiNewObjectDialog.hpp
/// @brief     新建对象对话框，列出可创建的对象类型供用户选择
/// @details   从 ClassRegistry 获取所有已注册的非虚类，展示图标和类型名，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-05

#pragma once

#include "AstGlobal.h"
#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <string>

AST_NAMESPACE_BEGIN

class Class;

/// @brief 新建对象对话框
/// @details 展示所有可实例化（非虚）的类型，支持搜索过滤，
///          选中类型后显示描述，自动生成唯一对象名
class AST_UICORE_API UiNewObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UiNewObjectDialog(QWidget* parent = nullptr);
    ~UiNewObjectDialog() override;
    UiNewObjectDialog(const UiNewObjectDialog&) = delete;
    UiNewObjectDialog& operator=(const UiNewObjectDialog&) = delete;

    /// @brief 获取用户选择的类型名
    QString selectedTypeName() const;

    /// @brief 获取自动生成的对象名
    QString objectName() const;

private:
    void setupUi();
    void populateTypeList(const QString& filter = QString());
    void updateDescription();
    QString generateUniqueName(const QString& typeName) const;

    struct ClassInfo
    {
        std::string name{}; 
        std::string desc{}; 
        Class*      cls{}; 
    };

    std::vector<ClassInfo> allClasses_{}; ///< 全部可创建的类型（未过滤）
    mutable QString         generatedName_{}; ///< 自动生成的对象名（延迟计算，故为 mutable）

    QLineEdit*   searchEdit_ = nullptr;
    QListWidget* typeList_ = nullptr;
    QLabel*      descLabel_ = nullptr;
    QPushButton* okButton_ = nullptr;
    QPushButton* cancelButton_ = nullptr;
};

AST_NAMESPACE_END
