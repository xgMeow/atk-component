/// @file      DataUpdater.hpp
/// @brief     动态数据更新器
/// @details   管理动态数据文件的下载、校验、备份和更新。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-30

#pragma once

#include "AstDataUpdateGlobal.hpp"
#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup DataUpdate
    @{
*/

/// @brief 动态数据更新器
/// @details
/// 管理动态数据文件（EOP、空间天气等）的在线更新。
/// 负责下载、校验、备份和替换数据文件。
///
/// 使用示例：
/// @code
/// DataUpdater updater;
/// auto files = updater.refreshFileList();
/// for (auto& f : files) {
///     if (f.isOutdated) {
///         updater.updateFile(f);
///     }
/// }
/// @endcode
class AST_DATAUPDATE_API DataUpdater
{
public:
    /// @brief 数据文件条目信息
    struct DataFileEntry
    {
        std::string name{};          ///< 显示名称，如 "EOP (地球定向参数)"
        std::string description{};   ///< 详细说明
        std::string url{};           ///< 下载 URL（Celestrak）
        std::string localPath{};     ///< 本地文件绝对路径（来自 InitalizeConfig）
        std::string fileDate{};      ///< 文件内部记录的数据日期（UPDATED 字段）
        int         backupCount{};   ///< 已有备份数量
        int         maxAgeDays{};    ///< 过期阈值（天数）
        bool        isOutdated{};    ///< 是否建议更新
        errc_t      lastError{};     ///< 上次更新错误码（eNoError 表示成功）
    };

    DataUpdater() = default;
    ~DataUpdater() = default;

    /// @brief 刷新数据文件列表
    /// @details 扫描本地数据文件，读取各文件的日期和备份数，判断是否过期。
    /// @return 数据文件条目列表
    std::vector<DataFileEntry> refreshFileList() const;

    /// @brief 获取指定数据文件的所有备份路径
    /// @param entry 数据文件条目
    /// @return 备份文件路径列表（按时间排序，最新的在最后）
    std::vector<std::string> listBackups(const DataFileEntry& entry) const;

    /// @brief 更新指定数据文件
    /// @details 从 Celestrak 下载最新数据，校验后写入本地文件。
    ///          更新前旧文件会被备份到 data/.backups/ 目录。
    /// @param[in,out] entry 数据文件条目，更新成功后 fileDate/isOutdated/lastError 会被刷新
    /// @return eNoError 表示更新成功
    errc_t updateFile(DataFileEntry& entry);

    /// @brief 更新所有过期文件
    /// @return 成功更新的文件数量（0 表示无需更新或全部失败）
    int updateAllOutdated();

private:
    /// @brief 解析数据文件头部的 UPDATED 字段
    static std::string readUpdatedField(const std::string& filepath);

    /// @brief 计算备份目录路径
    static std::string backupDir();

    /// @brief 生成备份文件名（含时间戳）
    static std::string makeBackupName(const std::string& filename);
};

/*! @} */

AST_NAMESPACE_END
