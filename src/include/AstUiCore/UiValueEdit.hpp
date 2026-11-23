/// @file      UiValueEdit.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-04

#pragma once

#include "AstGlobal.h"
#include <QLineEdit>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup GUI
    @{
*/

/// @brief 数值输入框基类
/// @details 提供错误提示和恢复正常的公共逻辑
class AST_UICORE_API UiValueEdit: public QLineEdit
{
public:
    explicit UiValueEdit(QWidget* parent = nullptr);

    /// @brief 设置错误状态
    /// @param errorMessage 错误信息
    void setError(const QString& errorMessage);

    /// @brief 恢复正常状态
    void setNormal();
};

/*! @} */

AST_NAMESPACE_END