/// @file      AttributeResolve.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-06

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Attribute.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


Attribute aResolveAttribute(Object* obj, StringView attrpath);
Attribute aResolveAttribute(const Attribute& attr, StringView attrpath);

/*! @} */

AST_NAMESPACE_END
