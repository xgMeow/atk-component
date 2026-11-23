/// @file      IArchive.hpp
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

class AST_UTIL_API IArchive: public Archive
{
public:
    using Archive::Archive;

    IArchive& operator()(Attribute& attr) override;

    template<typename T>
    IArchive& operator>>(T& val)
    {
        Archive::operator&(val);
        return *this;
    }
};

/*! @} */

AST_NAMESPACE_END
