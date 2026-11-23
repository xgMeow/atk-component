/// @file      LLMConfig.hpp
/// @brief     LLM请求配置
/// @details   封装模型名称、温度等LLM请求参数，支持提供者特有的额外请求字段
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-26

#pragma once

#include "AstGlobal.h"
#include "AstUtil/JsonValue.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Chat
    @{
*/

class JsonValue;

/// @brief LLM请求配置
/// @details 封装模型名称、温度、以及提供者特有的额外请求体字段
class AST_AI_API LLMConfig
{
public:
    LLMConfig() = default;
    ~LLMConfig() = default;

    /// @brief 设置模型名称
    void setModel(const std::string& model) { model_ = model; }
    /// @brief 获取模型名称
    const std::string& model() const { return model_; }

    /// @brief 设置温度参数
    void setTemperature(float temperature) { temperature_ = temperature; }
    /// @brief 获取温度参数
    float temperature() const { return temperature_; }

    /// @brief 设置提供者特有的额外请求体字段（如DeepSeek的thinking）
    void setExtraBody(const JsonValue& extra) { extraBody_ = extra; }
    /// @brief 获取提供者特有的额外请求体字段
    const JsonValue& extraBody() const { return extraBody_; }

private:
    std::string model_ = "deepseek-v4-flash";
    float temperature_ = 0.2f;
    JsonValue extraBody_{}; ///< 提供者特有的额外请求体字段
};

/*! @} */

AST_NAMESPACE_END
