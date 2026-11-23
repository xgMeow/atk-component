/// @file      UiWidget.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include <QWidget>

AST_NAMESPACE_BEGIN


class AST_UICORE_API UiWidget: public QWidget
{
public:
    UiWidget();
    ~UiWidget();
};

AST_NAMESPACE_END