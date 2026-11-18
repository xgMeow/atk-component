/// @file      XMLDocument.hpp
/// @brief     XML文档类
/// @details   表示整个XML文档，包含根节点和文档级操作
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-12

#pragma once

#include "AstGlobal.h"
#include "XMLNode.hpp"
#include <memory>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief XML文档类
/// @details 表示整个XML文档，包含根节点和文档级操作
class AST_UTIL_API XMLDocument
{
public:
    XMLDocument();
    ~XMLDocument();

    /// @brief 加载XML文档
    /// @param filepath 文件路径
    /// @return 错误码
    errc_t load(StringView filepath);

    /// @brief 保存XML文档
    /// @param filepath 文件路径
    /// @return 错误码
    errc_t save(StringView filepath);

    /// @brief 获取根节点
    /// @return 根节点指针，如果不存在则返回nullptr
    XMLNode* getRoot() const;

    /// @brief 清除文档内容
    void clear();

private:
    A_DISABLE_COPY(XMLDocument);
    XMLNode root_; ///< 根节点
};

/*! @} */

AST_NAMESPACE_END