/// @file      UiState.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-28

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class State;

class AST_UICORE_API UiState: public UiObject
{
    Q_OBJECT
public:
    using UiObject::UiObject;
    ~UiState() = default;

    State* getState() const;
private:

};

/*! @} */

AST_NAMESPACE_END
