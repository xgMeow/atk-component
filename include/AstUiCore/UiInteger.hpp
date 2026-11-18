/// @file      UiInteger.hpp
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

/// @brief 整数输入框
/// @details 用于输入整数值
class AST_UICORE_API UiInteger: public UiValueEdit
{
    Q_OBJECT

public:
    UiInteger(QWidget* parent = nullptr);

    /// @brief 设置整数值
    /// @param value 整数值
    void setValue(int value);

    /// @brief 获取整数值
    /// @return 整数值
    int value() const;

signals:
    void valueChanged(int value);
private slots:
    void updateValue();
private:
    int currentValue_{0};
};

/*! @} */

AST_NAMESPACE_END