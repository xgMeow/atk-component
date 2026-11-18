/// @file      ReturnLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-04

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class Return;

errc_t aLoadReturn(const Value& value, Return& ret);

/*! @} */

AST_NAMESPACE_END
