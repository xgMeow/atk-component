/// @file      Color.hpp
/// @brief     颜色工具类
/// @details   提供颜色值的预定义枚举和常量，方便在代码中使用。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-09

#pragma once

#include "AstGlobal.h"
#include <stdint.h>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Util
	@{
*/

typedef uint32_t color_t;


/// @brief 将 RGB 颜色值转换为 Color 类型
/// @param r 红色分量（0-255）
/// @param g 绿色分量（0-255）
/// @param b 蓝色分量（0-255）
/// @return 对应的 Color 值
constexpr inline color_t rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

/// @brief 将 RGBA 颜色值转换为 Color 类型
/// @param r 红色分量（0-255）
/// @param g 绿色分量（0-255）
/// @param b 蓝色分量（0-255）
/// @param a 透明度分量（0-255）
/// @return 对应的 Color 值
constexpr inline color_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24) | (g << 16) | (b << 8) | a;
}

/// @brief 将 Color 类型转换为 RGB 颜色值
/// @param color 输入 Color 值
/// @param r 输出红色分量（0-255）
/// @param g 输出绿色分量（0-255）
/// @param b 输出蓝色分量（0-255）
A_CONSTEXPR_CXX14 inline void aColorToRGB(color_t color, uint8_t& r, uint8_t& g, uint8_t& b) noexcept
{
	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
}

/// @brief 将 Color 类型转换为 RGBA 颜色值
/// @param color 输入 Color 值
/// @param r 输出红色分量（0-255）
/// @param g 输出绿色分量（0-255）
/// @param b 输出蓝色分量（0-255）
/// @param a 输出透明度分量（0-255）
A_CONSTEXPR_CXX14 inline void aColorToRGBA(color_t color, uint8_t& r, uint8_t& g, uint8_t& b, uint8_t& a) noexcept
{
	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
}


/// @brief 颜色类
/// @details 采用 RGBA 格式存储颜色值，每个分量占用 8 位（共4 字节）
class Color
{
public:
    A_CONSTEXPR_CXX14 Color() noexcept: value_(static_cast<EColor>(0)) {}
    A_CONSTEXPR_CXX14 /*explicit*/ Color(EColor value) noexcept: value_(value) {}
    A_CONSTEXPR_CXX14 /*explicit*/ Color(color_t value) noexcept: Color(EColor(value)) {}
    A_CONSTEXPR_CXX14 Color(uint8_t r, uint8_t g, uint8_t b) noexcept: Color(rgb(r, g, b)) {}
    A_CONSTEXPR_CXX14 Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept: Color(rgba(r, g, b, a)) {}
    A_CONSTEXPR_CXX14 operator EColor() const noexcept { return value_; }
	A_CONSTEXPR_CXX14 EColor value() const noexcept { return value_; }
	A_CONSTEXPR_CXX14 EColor& value() noexcept { return value_; }
private:
    EColor value_;
};


/*! @} */


AST_NAMESPACE_END