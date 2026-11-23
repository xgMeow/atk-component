/// @file      EphemerisFileParser.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-23

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 星历文件解析器接口
/// 参考了Orekit的EphemerisFileParser的接口名称和设计
class AST_CORE_API EphemerisFileParser
{
public:
    virtual ~EphemerisFileParser() = default;
    virtual errc_t parse(StringView filepath, HEphemeris& ephemeris) const = 0;

    inline HEphemeris parse(StringView filepath) const
    {
        HEphemeris ephemeris;
        parse(filepath, ephemeris);
        return ephemeris;
    }
};


/*! @} */

AST_NAMESPACE_END
