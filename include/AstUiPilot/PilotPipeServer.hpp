/// @file      PilotPipeServer.hpp
/// @brief     Named Pipe 服务端 — 在目标进程内接收外部命令
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-13

#pragma once

#include "AstGlobal.h"
#include <string>
#include <atomic>
#include "AstUtil/Thread.hpp"

AST_NAMESPACE_BEGIN

class PilotCommander;

/*!
    @addtogroup UiPilot
    @{
*/

/// @brief Named Pipe 服务端
/// @details 在目标进程中创建 named pipe，等待外部客户端（Injector）连接并发送命令。
///          命令格式：一行文本 + \n，响应以 \0 结尾。
///          Pipe 名称：\\.\pipe\AstUiPilot_{PID}
class AST_UIPILOT_API PilotPipeServer
{
public:
    /// @brief 构造函数
    /// @param commander 命令调度器
    /// @param pid 目标进程 PID（用于构造唯一的 pipe 名称）
    explicit PilotPipeServer(PilotCommander* commander, unsigned long pid);
    PilotPipeServer(const PilotPipeServer&) = delete;
    PilotPipeServer& operator=(const PilotPipeServer&) = delete;

    /// @brief 析构函数，自动停止服务
    ~PilotPipeServer();

    /// @brief 启动 pipe 服务（后台线程）
    void start();

    /// @brief 停止 pipe 服务
    void stop();

    /// @brief 是否正在运行
    bool isRunning() const { return running_; }

    /// @brief 构造 pipe 名称
    static std::string pipeName(unsigned long pid);

private:
    /// @brief 服务线程主循环
    void serverLoop();

    PilotCommander*    commander_{};
    unsigned long      pid_{};
    std::atomic<bool>  running_{false};
    Thread             serverThread_{};
};

/*! @} */

AST_NAMESPACE_END
