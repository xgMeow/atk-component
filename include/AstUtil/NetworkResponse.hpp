/// @file      NetworkResponse.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-23

#pragma once

#include "AstGlobal.h"
#include <string>
#include <map>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// 网络响应
/// @details   网络响应，包含状态码、体和头。
class NetworkResponse
{
public:
    NetworkResponse() = default;
    ~NetworkResponse() = default;

    /// 获取网络响应状态码
    int statusCode() const { return statusCode_; }

    /// 设置网络响应状态码
    void setStatusCode(int statusCode) { statusCode_ = statusCode; }

    /// 获取网络响应体
    const std::string& body() const { return body_; }

    /// 设置网络响应体
    void setBody(const std::string& body) { body_ = body; }

    /// 设置网络响应体为 JSON 格式
    AST_UTIL_API
    void setJson(const JsonValue& json);

    AST_UTIL_API
    errc_t toJson(JsonValue& json) const;

    /// 获取网络响应体为 JSON 格式
    /// @warning 内部会进行一次 JSON 解析操作
    AST_UTIL_API
    JsonValue toJson() const;

    /// 获取网络响应头
    const std::map<std::string, std::string>& headers() const { return headers_; }

    /// 设置网络响应头
    void setHeaders(const std::map<std::string, std::string>& headers) { headers_ = headers; }

    /// 添加网络响应头
    void addHeader(const std::string& key, const std::string& value) { headers_[key] = value; }

private:
    int statusCode_ = 0;                         ///< 网络响应状态码码
    std::string body_{};                          ///< 网络响应体
    std::map<std::string, std::string> headers_{}; ///< 网络响应头
};

/*! @} */

AST_NAMESPACE_END