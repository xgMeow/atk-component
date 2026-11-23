/// @file      SpiceParser.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-05

#pragma once

#include "AstGlobal.h"
#include "AstUtil/BaseParser.hpp"
#include "AstUtil/BKVItemView.hpp"
#include "AstUtil/KernelPool.hpp"
#include <cstdio>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup ParseFormat
    @{
*/

class BKVItemView;

/// @brief SPICE文本内核文件解析器(parser for SPICE text kernel file)
class AST_UTIL_API PCKParser: public BaseParser
{
public:
    PCKParser();
    explicit PCKParser(StringView filepath);
    ~PCKParser() = default;

    /// @brief 获取下一个键值对项
    /// @param item 输出参数，用于存储获取到的键值对项
    /// @return 错误码，-1(EOF) 表示文件结束
    errc_t   getNext(BKVItemView& item);

    /// @brief 读取SPICE内核文件数据
    /// @param kernelPool 输出参数，用于存储读取到的SPICE内核数据
    /// @return 错误码，-1(EOF) 表示文件结束
    errc_t   readData(KernelPool& kernelPool);

protected:
    std::vector<char>  keyBuffer_;              ///< 键缓冲区
    std::string        valueBuffer_;            ///< 值缓冲区
    bool               inDataBlock_{false};     ///< 是否在数据块中
};

/*! @} */

AST_NAMESPACE_END
