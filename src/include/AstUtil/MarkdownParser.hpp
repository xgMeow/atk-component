/// @file      MarkdownParser.hpp
/// @brief     Markdown 流式解析器 — SAX 事件驱动
/// @details   块级状态机 + 行内状态机，均为逐字符流式解析。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-15

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "MarkdownBlockParser.hpp"
#include <string>
#include <vector>
#include <memory>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class MarkdownSax;

/// @brief 将 Markdown 文本渲染为带有 ANSI 转义序列的终端输出字符串
/// @param markdown Markdown 源文本（UTF-8 编码）
/// @return 渲染后的字符串，其中已嵌入颜色、加粗等 ANSI 控制码，可直接输出到支持 ANSI 的终端
AST_UTIL_API std::string aMarkdownANSI(StringView markdown);


/// @brief 将 Markdown 文本转换为 HTML 字符串
/// @param markdown Markdown 源文本（UTF-8 编码）
/// @param compact true=紧凑输出（无缩进和换行），false=格式化输出
/// @return HTML 字符串
AST_UTIL_API std::string aMarkdownHTML(StringView markdown, bool compact = false);



/// @brief  Markdown解析器（SAX事件驱动，流式输入）
/// @details 薄封装，组合 MarkdownBlockParser 实现字符级流式解析。
class AST_UTIL_API MarkdownParser {
public:
    MarkdownParser(MarkdownSax& sax)
        : blockSM_(sax)
    {}
    ~MarkdownParser() = default;

    /// @brief  流式输入数据块
    void feed(StringView data) { blockSM_.feed(data); }

    /// @brief  通知输入结束，处理剩余内容
    void finish() { blockSM_.finish(); }

    /// @brief  重置解析器状态
    void reset() { blockSM_.reset(); }

private:
    MarkdownBlockParser blockSM_;
};

/*! @} */

AST_NAMESPACE_END
