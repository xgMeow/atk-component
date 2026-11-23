/// @file      UiChatEventHandler.hpp
/// @brief     流式聊天事件的 Qt 信号桥接器
/// @details   继承 ChatEventHandler 和 QObject，将 LLM 流式事件转为 Qt 信号。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-17

#pragma once

#include "AstGlobal.h"
#include "AstAI/ChatEventHandler.hpp"
#include "AstUtil/MarkdownHTMLRenderer.hpp"
#include <QObject>
#include <atomic>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup UiAI
    @{
*/

/// @brief 流式聊天事件的 Qt 信号桥接器
/// @details 同时继承 QObject 和 ChatEventHandler。
///          在工作线程中调用 ChatEventHandler 虚方法，
///          内部通过 emit 将事件转发到主线程的槽函数。
///          内置 MarkdownHTMLRenderer 进行流式 Markdown→HTML 转换。
class AST_UIAI_API UiChatEventHandler : public QObject, public ChatEventHandler
{
    Q_OBJECT

public:
    explicit UiChatEventHandler(QObject* parent = nullptr);
    ~UiChatEventHandler() override;

    // —— ChatEventHandler 接口 ——

    void onContentChunk(const std::string& text) override;
    void onContentComplete(const std::string& text) override;
    void onReasoningChunk(const std::string& reasoning) override;
    void onReasoningComplete(const std::string& reasoning) override;
    void onToolCallRequest(const std::string& toolCallId,
                           const std::string& functionName,
                           const std::string& arguments) override;
    void onToolCallResult(const std::string& toolCallId,
                          const std::string& functionName,
                          const std::string& result) override;
    void onComplete() override;
    void onError(const std::string& error) override;

    /// @brief 检查是否被取消（线程安全）
    bool isCancelled() const override;

public Q_SLOTS:
    /// @brief 请求取消当前操作（同时重置渲染器）
    void cancel();

    /// @brief 重置取消状态（同时重置渲染器）
    void reset();

Q_SIGNALS:
    /// @brief 收到原始文本增量（Markdown 原文）
    void contentChunk(const QString& chunk);

    /// @brief 收到转换后的 HTML 增量（Markdown→HTML 流式渲染结果）
    void htmlChunk(const QString& html);

    /// @brief 文本内容完成，携带完整文本
    void contentComplete(const QString& text);

    /// @brief 收到推理内容增量
    void reasoningChunk(const QString& reasoning);

    /// @brief 推理内容完成
    void reasoningComplete(const QString& reasoning);

    /// @brief LLM 请求调用工具
    void toolCallRequest(const QString& callId,
                         const QString& funcName,
                         const QString& args);

    /// @brief 工具执行完毕
    void toolCallResult(const QString& callId,
                        const QString& funcName,
                        const QString& output);

    /// @brief 本轮对话完成
    void completed();

    /// @brief 发生错误
    void errorOccurred(const QString& errMsg);

private:
    std::atomic<bool>       cancelled_{false};
    MarkdownHTMLRenderer    mdRenderer_{};        // 流式 Markdown→HTML 渲染器
};

/*! @} */

AST_NAMESPACE_END
