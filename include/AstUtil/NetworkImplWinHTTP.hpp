/// @file      NetworkImplWinHTTP.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-24

#pragma once

#include "AstUtil/NetworkInterface.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

#ifndef SWIG

/// 网络接口实现，通过WinHTTP API与网络进行交互
/// @details   网络实现，使用 WinHTTP API 与网络进行交互。
/// @warning   该实现仅在 Windows 平台上可用
class NetworkImplWinHTTP : public NetworkInterface
{
public:
    static NetworkImplWinHTTP* Instance();

    NetworkImplWinHTTP();

    NetworkImplWinHTTP(const NetworkImplWinHTTP&) = delete;
    NetworkImplWinHTTP& operator=(const NetworkImplWinHTTP&) = delete;

    virtual ~NetworkImplWinHTTP();

    virtual errc_t requestStream(const NetworkRequest& request, NetworkStreamReceiver& receiver) override;

    /// @brief 检查是否支持该网络实现
    /// @return true 如果支持，false 否则
    bool isSupported() const override;

private:
    class Impl;
    Impl* impl_;
};

#endif


/*! @} */

AST_NAMESPACE_END