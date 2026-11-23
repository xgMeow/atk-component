/// @file      NetworkRequest.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-23

#pragma once

#include "AstGlobal.h"
#include "AstUtil/JsonValue.hpp"
#include <string>
#include <map>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// 网络请求方法
/// @details   定义了网络请求的方法，如 GET、POST、PUT、DELETE 等。
enum class ENetworkRequestMethod
{
    eGet,
    eHead,
    ePost,
    ePut,
    eDelete,
    eOptions,
    eTrace,
    eConnect,
    ePatch,
    eUnknown=-1,
};


/// 网络请求
/// @details   网络请求，包含方法、URL、体和头
/// @todo 网络请求体作为std::string进行存储，在传输大文件时会占用过多内存，需要考虑使用流式传输机制
class NetworkRequest
{
public:
    NetworkRequest() = default;
    ~NetworkRequest() = default;

    /// 获取网络请求方法
    ENetworkRequestMethod method() const { return method_; }

    /// 设置网络请求方法
    void setMethod(ENetworkRequestMethod method) { method_ = method; }

    /// 设置网络请求方法
    /// @details   从字符串视图设置网络请求方法，支持 GET、POST、PUT、DELETE 等方法。
    AST_UTIL_API
    void setMethod(StringView method);

    /// 获取网络请求 URL
    const std::string& url() const { return url_; }

    /// 设置网络请求 URL
    void setUrl(const std::string& url) { url_ = url; }

    /// 获取网络请求体
    const std::string& body() const { return body_; }

    /// 设置网络请求体
    void setBody(const std::string& body) { body_ = body; }

    /// 设置网络请求体为 JSON 格式
    AST_UTIL_API
    void setJson(const JsonValue& json);

    /// 获取网络请求体为 JSON 格式
    /// @warning 内部会进行一次 JSON 解析操作
    AST_UTIL_API
    errc_t toJson(JsonValue& json) const;

    /// 获取网络请求体为 JSON 格式
    /// @warning 内部会进行一次 JSON 解析操作
    AST_UTIL_API
    JsonValue toJson() const;

    /// 获取网络请求头
    const std::map<std::string, std::string>& headers() const { return headers_; }

    /// 设置网络请求头
    void setHeaders(const std::map<std::string, std::string>& headers) { headers_ = headers; }

    /// 添加网络请求头
    void addHeader(const std::string& key, const std::string& value) { headers_[key] = value; }

private:
    ENetworkRequestMethod method_{ENetworkRequestMethod::eGet};      ///< 网络请求方法
    std::string url_{};                                               ///< 网络请求 URL
    std::string body_{};                                              ///< 网络请求体
    std::map<std::string, std::string> headers_{};                    ///< 网络请求头
};

/*! @} */

AST_NAMESPACE_END