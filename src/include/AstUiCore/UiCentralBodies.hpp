/// @file      UiCentralBodies.hpp
/// @brief     中心天体列表共享数据
/// @details   提供"中心天体"显示名/标识对，供多个对话框复用。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/// @brief 中心天体列表：显示中文名，底层保留英文标识（与 ast 内部查询键一致）
struct CentralBodyItem
{
    const char* cn;  ///< 中文显示名
    const char* id;  ///< 英文标识（如 "Earth"）
};

const CentralBodyItem kCentralBodies[] = {
    { "地球", "Earth" }, { "月球", "Moon" }, { "太阳", "Sun" },
    { "水星", "Mercury" }, { "金星", "Venus" }, { "火星", "Mars" },
    { "木星", "Jupiter" }, { "土星", "Saturn" }, { "天王星", "Uranus" },
    { "海王星", "Neptune" }, { "冥王星", "Pluto" }
};

AST_NAMESPACE_END
