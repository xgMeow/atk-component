/// @file      UiCommon.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-04

#pragma once

#include "AstGlobal.h"
#include <QString>
#include <QIcon>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 获取对象的显示名称
AST_UICORE_API QString aUiObjectDisplayName(Object* obj);

AST_UICORE_API QIcon aUiIcon(const QString& name);

AST_UICORE_API QIcon aUiObjectIcon(const Object* obj);

AST_UICORE_API QIcon aUiClassIcon(const QString& className);

A_ALWAYS_INLINE QIcon objectIcon(const Object* obj)
{
    return aUiObjectIcon(obj);
}


/*! @} */

AST_NAMESPACE_END

