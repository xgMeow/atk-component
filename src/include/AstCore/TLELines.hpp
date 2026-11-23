/// @file      TLELines.hpp
/// @brief     TLE 原始行文本容器
/// @details   存储 NORAD 两行根数（TLE）的原始三行文本：卫星名称、第一行、第二行。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-18

#pragma once

#include "AstGlobal.h"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief TLE 原始行文本
/// @details 存储一组 NORAD 两行根数的原始文本，包含卫星名称和两行轨道数据。
///          TLE 格式规范参见 https://celestrak.org/NORAD/documentation/tle-fmt.php
///          可通过 name()/line1()/line2() 访问，empty() 判断是否有效。
class TLELines
{
public:
    /// 检查是否为空（以 line1 是否为空判断）
    bool empty() const { return line1_.empty(); }

    /// 获取卫星名称（第 0 行）
    const std::string& name() const { return name_; }
    std::string&       name() { return name_; }

    /// 获取 TLE 第一行
    const std::string& line1() const { return line1_; }
    std::string&       line1() { return line1_; }

    /// 获取 TLE 第二行
    const std::string& line2() const { return line2_; }
    std::string&       line2() { return line2_; }

private:
    std::string name_{};     ///< 卫星名称（TLE 第 0 行，最长 24 字符）
    std::string line1_{};    ///< TLE 第一行（69 字符）
    std::string line2_{};    ///< TLE 第二行（69 字符）
};


/*! @} */

AST_NAMESPACE_END
