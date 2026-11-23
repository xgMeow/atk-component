/// @file      SatelliteDatabaseQuery.hpp
/// @brief     卫星数据库查询条件
/// @details   定义对卫星数据库进行筛选查询的条件，支持按任务类别和通用名称过滤。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-23

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class SatelliteDatabaseEntry;

/// @brief 卫星数据库查询条件
/// @details 支持按任务类别（mission）和通用名称（commonName）进行子串匹配过滤。
///          对应 STK Components 中的 StkSatelliteDatabaseQuery。
class AST_CORE_API SatelliteDatabaseQuery
{
public:
    /// @brief 默认构造（匹配所有条目）
    SatelliteDatabaseQuery();

    /// @brief 析构
    ~SatelliteDatabaseQuery();

    /// @brief 按任务类别过滤
    /// @param pattern 子串匹配模式，空字符串表示不按此字段过滤。
    void setMission(StringView pattern);

    /// @brief 按通用名称过滤
    /// @param pattern 子串匹配模式，空字符串表示不按此字段过滤。
    void setCommonName(StringView pattern);

    /// @brief 获取任务类别过滤模式
    const std::string& mission() const { return mission_; }

    /// @brief 获取通用名称过滤模式
    const std::string& commonName() const { return commonName_; }

    /// @brief 判断给定条目是否匹配当前查询条件
    /// @param entry 待检查的数据库条目
    /// @return 若匹配则返回 true
    bool matches(const SatelliteDatabaseEntry& entry) const;

    /// @brief 查询是否未设置任何过滤条件（匹配所有条目）
    bool isEmpty() const;
private:
    std::string mission_{};               ///< 任务类别过滤模式（空 = 不筛选）
    std::string commonName_{};            ///< 通用名称过滤模式（空 = 不筛选）
};

/*! @} */

AST_NAMESPACE_END
