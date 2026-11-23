/// @file      NetworkImplCurlCmd.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-24

#pragma once

#include "AstGlobal.h"
#include "AstUtil/NetworkInterface.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

#ifndef SWIG

/// 网络接口实现，通过curl命令与网络进行交互
/// @details 该实现使用curl命令行工具与网络进行交互，支持GET、POST、PUT、DELETE等HTTP方法
/// @note 该实现需要已安装curl命令行工具，一般操作系统已默认安装
/// @warning 注意不要通过该实现发送敏感数据，如密码、API密钥等
/// 因为该实现使用了临时文件与curl命令行工具交互
class NetworkImplCurlCmd : public NetworkInterface
{
public:
    static NetworkImplCurlCmd* Instance();

    NetworkImplCurlCmd() = default;

    virtual ~NetworkImplCurlCmd() = default;

    virtual errc_t requestStream(const NetworkRequest& request, NetworkStreamReceiver& receiver) override;

    /// @brief 检查是否支持该网络实现
    /// @return true 如果支持，false 否则
    virtual bool isSupported() const override;
};

#endif

/*! @} */

AST_NAMESPACE_END
