/// @file      NetworkInterface.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-24

#pragma once

#include "AstGlobal.h"
#include "NetworkRequest.hpp"
#include "NetworkResponse.hpp"
#include "NetworkStreamReceiver.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class NetworkStreamReceiver;

// 判断 HTTP 方法是否允许携带请求体
AST_UTIL_API bool aMethodAllowsBody(const std::string& method);

// 简单验证端口字符串并转换为整数，非法则返回默认端口
AST_UTIL_API int aParsePort(const std::string& portStr, int defaultPort);


/// 网络抽象接口
/// @details   网络抽象接口，用于与网络进行交互
class NetworkInterface
{
public:
    NetworkInterface() = default;

    virtual ~NetworkInterface() = default;

    /// 发送网络请求
    /// @details   发送网络请求，返回网络响应
    /// @param request 网络请求
    /// @param response 网络响应
    /// @note 该接口会阻塞调用线程，直到网络请求完成或超时为止
    /// @return 错误码
    errc_t request(const NetworkRequest& request, NetworkResponse& response)
    {
        CollectingStreamReceiver collector(response);
        return requestStream(request, collector);
    }

    /// @brief 发送流式网络请求
    /// @details 与 request() 不同，该方法在数据到达时立即通过 receiver 回调
    /// @param request 网络请求
    /// @param receiver 流式数据接收器
    /// @return 错误码
    virtual errc_t requestStream(const NetworkRequest& request,
                                 NetworkStreamReceiver& receiver) = 0;

    /// @brief 检查是否支持该网络实现
    /// @details 检查该网络实现是否在当前操作系统上受支持，例如：
    /// 基于curl命令的实现会检查当前操作系统是否安装了curl 命令行工具
    /// 基于WinHTTP的实现会检查是否是Windows操作系统，且支持加载WinHTTP库
    /// 基于WinINet的实现会检查是否是Windows操作系统，且支持加载WinINet库
    /// @return true 如果支持，false 否则
    virtual bool isSupported() const = 0;
};


/*! @} */

AST_NAMESPACE_END
