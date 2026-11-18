/// @file      ExtractorInterface.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-24

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 解压接口
/// @details 定义了解压器的基本行为，包括解压压缩文件或目录。
class AST_UTIL_API ExtractorInterface
{
public:
    virtual ~ExtractorInterface() = default;

    /// @brief 解压压缩文件或目录
    /// @param source 压缩文件或目录的路径
    /// @param target 解压目标路径
    /// @return errc_t 错误码
    virtual errc_t extract(StringView source, StringView target) const = 0;

    /// @brief 检查该解压实现是否在当前环境中可用
    /// @details 例如：基于 Shell COM 的实现检查是否是 Windows，
    /// 基于系统命令的实现检查是否安装了对应的命令行工具
    /// @return true 如果可用，false 否则
    virtual bool isSupported() const { return true; }

    /// @brief 检查该解压实现是否能处理指定文件
    /// @details 默认返回 true；子类可重写以检查文件扩展名或魔数
    /// @param source 待解压的文件路径
    /// @return true 如果能处理，false 否则
    virtual bool canExtract(StringView source) const;
};


/*! @} */

AST_NAMESPACE_END
