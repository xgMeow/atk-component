/// @file      UiDouble.hpp
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

/// @brief 双精度浮点数输入框
/// @details 用于输入双精度浮点数值
class AST_UICORE_API UiDouble: public UiValueEdit
{
    Q_OBJECT

public:
    UiDouble(QWidget* parent = nullptr);

    /// @brief 设置双精度浮点数值
    /// @param value 双精度浮点数值
    void setValue(double value);

    /// @brief 获取双精度浮点数值
    /// @return 双精度浮点数值
    double value() const;

signals:
    void valueChanged(double value);
private slots:
    void updateValue();
private:
    double currentValue_{0.0};
};

/*! @} */

AST_NAMESPACE_END