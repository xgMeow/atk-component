/// @file      STKEphemerisFileParser.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-23

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"
#include "AstCore/EphemerisFileParser.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class BKVParser;

/// @brief 加载STK星历文件
/// @param filepath 星历文件路径
/// @param ephemeris 星历对象
/// @return 错误码
AST_CORE_API errc_t aLoadSTKEphemeris(StringView filepath, HEphemeris& ephemeris);

/// @brief 加载STK星历文件
/// @param parser BKV解析器
/// @param ephemeris 星历句柄
/// @return 错误码
AST_CORE_API errc_t aLoadSTKEphemeris(BKVParser& parser, HEphemeris &ephemeris);


/// @brief 加载STK星历文件
/// @param parser BKV解析器
/// @param ephemeris 星历句柄
/// @return 错误码
AST_CORE_API errc_t aLoadSTKEphemeris(BKVParser& parser, ScopedPtr<Ephemeris>& ephemeris);


/// @brief STK星历文件解析器
/// 参考了[Orekit的STKEphemerisFileParser类](https://www.orekit.org/site-orekit-12.0.1/apidocs/org/orekit/files/stk/STKEphemerisFileParser.html)
class AST_CORE_API STKEphemerisFileParser final: public EphemerisFileParser
{
public:
    STKEphemerisFileParser() = default;
    ~STKEphemerisFileParser() override = default;
public:
    using EphemerisFileParser::parse;
    errc_t parse(StringView filepath, HEphemeris& ephemeris) const override;
protected:

};

/*! @} */

AST_NAMESPACE_END
