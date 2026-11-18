/// @file      ChatConsole.hpp
/// @brief     终端输出事件处理器
/// @details   ChatEventHandler 的终端输出实现，将流式事件实时打印到 stdout。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-15

#pragma once

#include "AstGlobal.h"
#include "AstAI/ChatEventHandler.hpp"
// #include "AstUtil/Markdown.hpp"
#include "AstUtil/MarkdownRenderer.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Chat
    @{
*/

/// @brief 终端输出事件处理器
/// @details 将流式事件格式化输出到 stdout，支持 Markdown 渲染
class AST_AI_API ChatConsole : public ChatEventHandler
{
public:
    using RendererType = MarkdownRenderer;
    //using RendererType = Markdown;


    ChatConsole() = default;
    ~ChatConsole() = default;

    void onContentChunk(const std::string& text) override;

    void onReasoningChunk(const std::string& reasoning) override;

    void onToolCallRequest(const std::string& /*toolCallId*/,
                           const std::string& functionName,
                           const std::string& arguments) override;

    void onToolCallResult(const std::string& /*toolCallId*/,
                          const std::string& functionName,
                          const std::string& result) override;

    void onComplete() override;

    void onError(const std::string& error) override;

    /// @brief 设置是否以原始 Markdown 原文输出（不做 ANSI 渲染）
    void setRawOutput(bool raw) { rawOutput_ = raw; }

    /// @brief 查询当前是否为原始输出模式
    bool isRawOutput() const { return rawOutput_; }

private:
    void outputText(const std::string& text);

    RendererType renderer_{};
    bool     rawOutput_ = false;
};

/*! @} */

AST_NAMESPACE_END
