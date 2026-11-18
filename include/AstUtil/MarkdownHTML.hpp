/// @file      MarkdownHTML.hpp
/// @brief     Markdown HTML 渲染器 — SAX 事件驱动，输出 HTML 标签
/// @details   将 MarkdownSax 事件转为 HTML 标签输出。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-16

#pragma once

#include "AstGlobal.h"
#include "MarkdownSax.hpp"
#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief Markdown SAX → HTML 渲染器
/// @details 实现 MarkdownSax 接口，将 SAX 事件转换为 HTML 标签输出。
///          与 MarkdownParser 配合使用：
///          @code
///          MarkdownHTML renderer;
///          MarkdownParser parser(renderer);
///          parser.feed(markdownText);
///          parser.finish();
///          std::string html = renderer.output();
///          @endcode
class AST_UTIL_API MarkdownHTML: public MarkdownSax
{
public:
    /// @brief 构造函数
    /// @param compact true=紧凑输出（无缩进和换行），false=格式化输出（默认）
    explicit MarkdownHTML(bool compact = false)
        : compact_(compact) {}
    ~MarkdownHTML() = default;

    /// @brief 设置紧凑/格式化输出模式
    void setCompact(bool compact) { compact_ = compact; }
    /// @brief 获取当前是否为紧凑输出模式
    bool isCompact() const { return compact_; }

    // 文档生命周期
    void startDocument() override;
    void endDocument() override;

    // 块级元素
    void startHeading(int level) override;
    void endHeading(int level) override;

    void startParagraph() override;
    void endParagraph() override;

    void startCodeBlock(StringView language) override;
    void codeLine(StringView line) override;  // 代码行
    void endCodeBlock() override;

    void startList(bool ordered) override;   // true: 有序, false: 无序
    void startListItem() override;
    void endListItem() override;
    void endList() override;

    void startBlockquote() override;
    void endBlockquote() override;

    void horizontalRule() override;

    // 表格
    void startTable() override;
    void startTableHead() override;
    void endTableHead() override;
    void startTableBody() override;
    void endTableBody() override;
    void startTableRow() override;
    void endTableRow() override;
    void startTableCell(ETableAlign align) override;
    void endTableCell() override;
    void endTable() override;

    // 行内元素
    void text(StringView txt) override;
    void startEmphasis() override;     // 斜体
    void endEmphasis() override;
    void startStrong() override;       // 粗体
    void endStrong() override;
    void startDelete() override;         // 删除线
    void endDelete() override;
    void codeSpan(StringView code) override;
    void startLink(StringView url) override;
    void endLink() override;
    void image(StringView alt, StringView url) override;

public:
    /// @brief 获取输出的 HTML 字符串
    std::string& output() { return output_; }
    const std::string& output() const { return output_; }
    void clearOutput() { output_.clear(); }

private:
    /// @brief 将文本中的 HTML 特殊字符转义后追加到输出
    static void appendEscaped(std::string& out, StringView text);

    /// @brief 向输出追加 depth*2 个空格缩进（紧凑模式下不追加）
    void appendIndent(size_t depth);

    /// @brief 向输出追加格式化换行（紧凑模式下不追加）
    void appendNewline();

    // ---- 输出缓冲 ----
    std::string output_{};

    // ---- 格式化控制 ----
    bool compact_ = false;              ///< true=紧凑输出，false=格式化输出

    // ---- 块级状态 ----
    std::vector<bool> listStack_{}; ///< 列表类型栈: true=有序, false=无序
    int  blockquoteDepth_ = 0;      ///< 块引用嵌套深度
    int  lastEndListDepth_ = -1;    ///< 最近一次 endList 后的栈深度，用于 endListItem 判断子列表换行

    // ---- 表格状态 ----
    bool inTableHead_ = false;      ///< 当前是否在表头区域内

    // ---- 链接状态 ----
    std::string linkUrl_{};
};


/*! @} */

AST_NAMESPACE_END
