/// @file      TestWithSTK.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-20

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 从STK文件测试
/// @param filepath STK文件路径
/// @return 错误码
AST_TEST_CAPI errc_t aTestFromSTKFile(StringView filepath);


/*! @} */

AST_NAMESPACE_END
