/// @file      MockBuffer.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-23

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN


AST_MOCK_CAPI void aMockBufferMalloc(unsigned int size);


AST_MOCK_CAPI void aMockBufferNew(unsigned int size);


AST_MOCK_CAPI void aMockBufferStack(unsigned int size);


AST_MOCK_CAPI void aMockBufferAlloca(unsigned int size);


AST_NAMESPACE_END
