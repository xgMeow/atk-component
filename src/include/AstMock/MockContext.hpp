/// @file      MockContext.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-24

#pragma once

#include "AstGlobal.h"


AST_NAMESPACE_BEGIN

class EOP;

AST_MOCK_CAPI EOP* aMockGetEOP_Extern();
AST_MOCK_CAPI EOP* aMockGetEOP_Static();
AST_MOCK_CAPI EOP* aMockGetEOP_Lazy();
AST_MOCK_CAPI EOP* aMockGetEOP_ContextExtern();
AST_MOCK_CAPI EOP* aMockGetEOP_ContextStatic();
AST_MOCK_CAPI EOP* aMockGetEOP_ContextExternTL();
AST_MOCK_CAPI EOP* aMockGetEOP_ContextStaticTL();

AST_NAMESPACE_END
