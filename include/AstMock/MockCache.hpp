/// @file      MockCache.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-24

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


AST_MOCK_CAPI int aMockCacheStatic(int k);


AST_MOCK_CAPI int aMockCacheExtern(int k);


AST_MOCK_CAPI int aMockCacheStaticTL(int k);


AST_MOCK_CAPI int aMockCacheExternTL(int k);

AST_NAMESPACE_END
