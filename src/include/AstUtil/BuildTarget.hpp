/// @file      BuildTarget.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-30

#pragma once

#include "AstGlobal.h"
#include <vector>
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

using StringVector = std::vector<std::string>;

/// @brief 目标
/// @details 目标类，用于表示构建目标
/// @warning 当前只支持g++编译器，无法切换为其他编译器
class AST_UTIL_API BuildTarget
{
public: // 配置接口

    /// @brief 目标类型
    enum EKind
    {
        eShared,    ///< 共享库目标
        eStatic,    ///< 静态库目标
        eBinary,    ///< 可执行文件目标
    };

    BuildTarget() = default;

    /// @brief 构造函数
    /// @details 构造函数，用于创建目标。
    /// @param name 目标名称
    explicit BuildTarget(StringView name);

    ~BuildTarget() = default;

    /// @brief 获取目标名称
    /// @details 获取目标名称
    /// @return 目标名称
    const std::string& name() const { return name_; }

    /// @brief 设置目标名称
    /// @details 设置目标名称
    /// @param name 目标名称
    BuildTarget& setName(StringView name);

    /// @brief 获取目标类型
    /// @details 获取目标类型
    /// @return 目标类型
    EKind kind() const { return kind_; }

    /// @brief 设置目标类型
    /// @details 设置目标类型
    /// @param kind 目标类型
    BuildTarget& setKind(StringView kind);

    /// @brief 设置目标类型
    /// @details 设置目标类型
    /// @param kind 目标类型
    BuildTarget& setKind(EKind kind);


    /// @brief 获取源文件列表
    /// @details 获取源文件列表
    /// @return 源文件列表
    const StringVector& files() const { return files_; }

    /// @brief 添加源文件
    /// @details 添加源文件到目标中
    /// @param files 文件路径列表
    BuildTarget& addFiles(const std::vector<std::string>& files);


    /// @brief 获取包含目录列表
    /// @details 获取包含目录列表
    /// @return 包含目录列表
    const StringVector& includeDirs() const { return includeDirs_; }

    /// @brief 添加包含目录
    /// @details 添加包含目录到目标中
    /// @param dirs 目录路径列表
    BuildTarget& addIncludeDirs(const std::vector<std::string>& dirs);


    /// @brief 获取链接目录列表
    /// @details 获取链接目录列表
    /// @return 链接目录列表
    const StringVector& linkDirs() const { return linkDirs_; }

    /// @brief 添加链接目录
    /// @details 添加链接目录到目标中
    /// @param dirs 目录路径列表
    BuildTarget& addLinkDirs(const std::vector<std::string>& dirs);


    /// @brief 获取链接库列表
    /// @details 获取链接库列表
    /// @return 链接库列表
    const StringVector& links() const { return links_; }

    /// @brief 添加链接库
    /// @details 添加链接库到目标中
    /// @param libs 库路径列表
    BuildTarget& addLinks(const std::vector<std::string>& libs);


    /// @brief 获取宏定义列表
    /// @details 获取宏定义列表
    /// @return 宏定义列表
    const StringVector& defines() const { return defines_; }

    /// @brief 添加宏定义
    /// @details 添加宏定义到目标中
    /// @param defines 定义列表
    BuildTarget& addDefines(const std::vector<std::string>& defines);

    /// @brief 获取目标文件名
    /// @details 获取目标文件名
    /// @return 目标文件名
    // std::string fileName() const;

    /// @brief 获取目标目录
    // std::string BuildTargetDir() const;

    /// @brief 获取目标文件路径
    /// @details 获取目标文件路径
    /// @return 目标文件路径
    // std::string BuildTargetFile() const;

public: // 编译、链接、构建、运行、打包等接口

    /// @brief 构建目标
    /// @details 构建目标，包括编译、链接等操作
    /// @return 错误码
    errc_t build();

    /// @brief 运行目标
    /// @return 错误码
    errc_t run();

protected:
    std::string name_{};                    ///< 目标名称
    EKind kind_{EKind::eBinary};           ///< 目标类型
    std::vector<std::string> files_{};      ///< 源文件列表
    std::vector<std::string> includeDirs_{};///< 包含目录列表
    std::vector<std::string> linkDirs_{};   ///< 链接目录列表
    std::vector<std::string> defines_{};    ///< 宏定义列表
    std::vector<std::string> links_{};      ///< 链接库列表
};

/*! @} */

AST_NAMESPACE_END
