/// @file      KVParser.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-20

#pragma once

#include "AstGlobal.h"
#include "AstUtil/BaseParser.hpp"
#include "AstUtil/BKVItemView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ValueView;

class AST_UTIL_API KVParser : public BaseParser
{
public:
    KVParser() = default;
    ~KVParser() = default;
    enum EToken{
        eEqual,
        eAddEqual,
        eError,
        eEOF = EOF,
    };

    EToken getNext(BKVItemView &item);

};


/*! @} */

AST_NAMESPACE_END
