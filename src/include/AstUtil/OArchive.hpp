/// @file      OArchive.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-31

#pragma once

#include "AstGlobal.h"
#include "Archive.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_UTIL_API OArchive: public Archive
{
public:
    using Archive::Archive;
    template<typename T>
    OArchive& operator<<(T& val)
    {
        Archive::operator()(val);
        return *this;
    }
};

/*! @} */

AST_NAMESPACE_END
