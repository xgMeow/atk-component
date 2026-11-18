/// @file      XMLDomSax.hpp
/// @brief     XML DOM SAX解析器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-12

#pragma once

#include "AstGlobal.h"
#include "XMLSax.hpp"
#include "XMLNode.hpp"
#include <stack>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief XML DOM SAX解析器
/// @details 结合了SAX解析和DOM树构建的解析器，通过SAX回调构建DOM树
class AST_UTIL_API XMLDomSax : public XMLSax {
public:
    explicit XMLDomSax(XMLNode& document);
    ~XMLDomSax() override;

    /// @brief 文档开始回调
    void startDocument() override;

    /// @brief 文档结束回调
    void endDocument() override;

    /// @brief 元素开始回调
    void startElement(StringView name, const AttributeList& attributes) override;

    /// @brief 元素结束回调
    void endElement(StringView name) override;

    /// @brief 文本内容回调
    void characters(StringView text) override;

    /// @brief 注释回调
    void comment(StringView text) override;

    /// @brief 错误回调
    void error(StringView msg) override;



private:
    A_DISABLE_COPY(XMLDomSax);
    XMLNode& root_;                      ///< 文档根节点
    std::stack<XMLNode*> nodeStack_;     ///< 节点栈，用于构建DOM树
};

/*! @} */

AST_NAMESPACE_END