/// @file      UnitParser.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-15

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"       // for StringView

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Quantity
    @{
*/


class Unit;


/// @brief 解析单位字符串
/// @param[in] str 单位字符串
/// @param[out] unit 解析后的单位
/// @return errc_t 错误码
AST_UTIL_API errc_t aUnitParse(StringView str, Unit& unit);


/// @brief 解析单位字符串
/// @param[in] str 单位字符串
/// @return Unit 解析得到的单位，如果解析失败返回 Unit::NaN()
AST_UTIL_API Unit aUnitParse(StringView str);


/*! @} */


AST_NAMESPACE_END

