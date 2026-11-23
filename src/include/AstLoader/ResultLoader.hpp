/// @file      ResultLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectCalculation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/



errc_t aLoadResult(const Value& value, SharedPtr<ObjectCalculation>& result, Object* scope);


errc_t aLoadResults(const Value& dict, Object* scope);

/*! @} */

AST_NAMESPACE_END
