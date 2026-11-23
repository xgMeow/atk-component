/// @file      TLEDatabase.hpp
/// @brief     TLE 数据库
/// @details   管理和查询 TLE 数据库，支持从 TLE 文本文件（2 行或 3 行格式）加载数据。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-24

#pragma once

#include "AstGlobal.h"
#include "Database.hpp"
#include "AstCore/TLE.hpp"
#include "AstUtil/StringView.hpp"
#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class TLEDatabaseQuery;

/// @brief TLE 数据库
/// @details
/// 继承自 Database，可解析标准 TLE 文本文件（支持 2 行和 3 行格式）。
/// - 3 行格式：名称行 + 第 1 行 + 第 2 行
/// - 2 行格式：第 1 行 + 第 2 行（无名称行）
/// - 格式通过行首字符 '1' / '2' 自动检测
class AST_CORE_API TLEDatabase : public Database
{
public:
    using Entry = TLE;
    using EntryList = std::vector<TLE>;

    TLEDatabase();
    explicit TLEDatabase(StringView filePath);
    ~TLEDatabase() override;

    // -- 加载 --
    errc_t load(StringView filePath);
    errc_t reload();
    bool isLoaded() const { return loaded_; }

    // -- 查询 --
    const EntryList& getEntries() const { return tles_; }
    EntryList getEntries(const TLEDatabaseQuery& query) const;
    size_t size() const { return tles_.size(); }

    const std::string& filePath() const { return filePath_; }

private:
    /// @brief 解析 TLE 文本文件
    errc_t loadTleFile(StringView filePath);

private:
    std::string filePath_{};    ///< 加载的文件路径
    std::vector<TLE> tles_{};   ///< TLE 条目
    bool loaded_{false};        ///< 是否已加载数据
};

/*! @} */

AST_NAMESPACE_END
