/// @file      TestJson.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-24

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 测试 JSON 解析
/// @return 错误码
AST_TEST_CAPI errc_t aTestJsonParse(StringView json);


/*! @} */

AST_NAMESPACE_END
