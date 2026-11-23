/// @file      MarkdownRenderer.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-16

#pragma once

#include "AstGlobal.h"
#include "BaseRenderer.hpp"
#include "MarkdownANSI.hpp"
#include "MarkdownParser.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief     ANSI 流式渲染器
/// @details   用于将 Markdown 文本渲染为 ANSI 格式
class AST_UTIL_API MarkdownANSIRenderer : public BaseRenderer
{
public:
    MarkdownANSIRenderer();
    ~MarkdownANSIRenderer() = default;

    /// @brief     渲染 Markdown 文本的下一个块
    void feed(StringView chunk, std::string& accumulated) override;
    /// @brief     渲染 Markdown 文本的最后一个块
    void end(std::string& remaining) override;
    void reset() override;
private:
    MarkdownANSI ansiRenderer_;   // 必须在 parser_ 之前声明（parser_ 引用 ansiRenderer_）
    MarkdownParser parser_;
};



/*! @} */

AST_NAMESPACE_END
