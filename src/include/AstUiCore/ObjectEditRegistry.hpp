/// @file      ObjectEditRegistry.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-02

#pragma once

#include "AstGlobal.h"
#include <unordered_map>

class QWidget;

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Object;
class Class;

typedef QWidget* (*FNewEditWidget)(Object *object);

class AST_UICORE_API ObjectEditRegistry
{
    using EditWidgetMap = std::unordered_map<Class*, FNewEditWidget>;
public:
    ObjectEditRegistry();
    explicit ObjectEditRegistry(bool shouldRegistEditWidget);
    ~ObjectEditRegistry() = default;

    static ObjectEditRegistry& Instance();

    /// @brief     注册编辑控件
    /// @details   ~
    /// @param     cls     类指针
    /// @param     newEditWidget 控件创建函数指针
    void registerEditWidget(Class *cls, FNewEditWidget newEditWidget);

    /// @brief     创建编辑控件
    /// @details   ~
    /// @param     object 要编辑的对象
    /// @return    QWidget*  编辑控件指针
    QWidget* newEditWidget(Object *object);
protected:
    EditWidgetMap editWidgetMap_{};
};


/// @brief     注册编辑控件
/// @details   ~
/// @param     cls     类指针
/// @param     newEditWidget 控件创建函数指针
AST_UICORE_CAPI void aUiRegisterEditWidget(Class *cls, FNewEditWidget newEditWidget);


/// @brief     创建编辑控件
/// @details   ~
/// @param     object 要编辑的对象
/// @return    QWidget*  编辑控件指针
AST_UICORE_CAPI QWidget* aUiNewEditWidget(Object *object);


/*! @} */

AST_NAMESPACE_END
