/// @file      EphemerisFileWriter.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-04

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 星历文件写入器
/// 参考了Orekit的EphemerisFileWriter的接口名称和设计
class AST_CORE_API EphemerisFileWriter
{
public:
    EphemerisFileWriter() = default;
    virtual ~EphemerisFileWriter() = default;

    /// @brief 写入星历文件
    /// @param filename 文件名
    /// @param ephemeris 星历
    /// @return 错误码
    virtual errc_t write(StringView filename, const Ephemeris& ephemeris) const = 0;

};




/*! @} */

AST_NAMESPACE_END
