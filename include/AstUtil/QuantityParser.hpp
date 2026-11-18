/// @file      QuantityParser.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-15

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN


/*!
    @addtogroup Quantity
    @{
*/



class Quantity;
class Unit;

/// @brief 解析量字符串，将其解析为数值和单位。
/// @details 例如 "123.456 m/s", "123.456m", "123.456[m/s]"。
/// @param[in] str 量字符串
/// @param[out] magnitude 解析得到的数值
/// @param[out] unit 解析得到的单位
/// @return errc_t 错误码
AST_UTIL_API errc_t aQuantityParse(StringView str, double& magnitude, Unit& unit);



/// @brief 解析量字符串
/// @details 例如 "123.456 m/s", "123.456m", "123.456[m/s]"。
/// @param[in] str 量字符串
/// @param[out] quantity 解析后的量
/// @return errc_t 错误码
AST_UTIL_API errc_t aQuantityParse(StringView str, Quantity& quantity);


/// @brief 解析量字符串
/// @details 例如 "123.456 m/s", "123.456m", "123.456[m/s]"。
/// @param[in] str 量字符串
/// @return Quantity 解析得到的量，如果解析失败返回 Quantity::NaN()
AST_UTIL_API Quantity aQuantityParse(StringView str);


/*! @} */


AST_NAMESPACE_END
