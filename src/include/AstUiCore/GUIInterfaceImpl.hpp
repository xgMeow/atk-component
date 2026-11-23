/// @file      GUIInterfaceImpl.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-02

#pragma once

#include "AstGlobal.h"
#include "AstUtil/GUIInterface.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief GUI接口实现类
class GUIInterfaceImpl : public GUIInterface
{
public:
    GUIInterfaceImpl();
    ~GUIInterfaceImpl() override = default;
    static GUIInterfaceImpl* Instance();

    errc_t editObject(Object* object) override;
    Object* selectObject(StringView typeName) override;
    const char* translate(const char* msgctxt, const char* msgid) override;
};


/// @brief 获取GUI接口实现类实例
/// @return GUI接口实现类实例
AST_UICORE_CAPI GUIInterface* aGUIInterfaceImpl();



/*! @} */

AST_NAMESPACE_END
