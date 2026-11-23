/// @file      MarkdownHTMLRenderer.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-17

#pragma once

#include "AstGlobal.h"
#include "BaseRenderer.hpp"
#include "MarkdownHTML.hpp"
#include "MarkdownParser.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief     HTML 流式渲染器
/// @details   用于将 Markdown 文本渲染为 HTML 格式
class AST_UTIL_API MarkdownHTMLRenderer : public BaseRenderer
{
public:
    MarkdownHTMLRenderer();
    ~MarkdownHTMLRenderer() = default;

    /// @brief     渲染 Markdown 文本的下一个块
    void feed(StringView chunk, std::string& accumulated) override;
    /// @brief     渲染 Markdown 文本的最后一个块
    void end(std::string& remaining) override;
    void reset() override;
private:
    MarkdownHTML htmlRenderer_;
    MarkdownParser parser_;
};

/*! @} */

AST_NAMESPACE_END
