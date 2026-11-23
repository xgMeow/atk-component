/// @file      AITool.hpp
/// @brief     AI工具定义
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-23

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/JsonValue.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @defgroup Chat
    @brief AI大语言模型相关接口
    @{
*/

class JsonValue;

/// @brief AI工具基类
/// @details 所有AI工具的基类，定义了工具的基本属性和方法
class ChatTool
{
public:
    ChatTool() = default;

    virtual ~ChatTool() = default;
    /// @brief 调用工具
    /// @param arguments 函数参数
    /// @return 执行结果
    virtual std::string call(const JsonValue& arguments) = 0;

    /// @brief 获取工具名称
    /// @return 工具名称
    const std::string& name() const { return name_; }

    /// @brief 设置工具名称
    /// @param name 工具名称
    void setName(StringView name){name_ = std::string(name);}

    /// @brief 获取工具描述
    /// @return 工具描述
    const std::string& description() const { return description_; }

    /// @brief 设置工具描述
    /// @param description 工具描述
    void setDescription(StringView description){description_ = std::string(description);}

    /// @brief 获取工具参数schema
    /// @return 工具参数schema
    const JsonValue& parameters() const { return parameters_; }

    /// @brief 设置工具参数schema
    /// @param parameters 工具参数schema
    void setParameters(const JsonValue& parameters){parameters_ = parameters;}

    /// @brief 转换为JSON值
    /// @return JSON值
    JsonValue toJson() const;
private:
    std::string name_{};              ///< 工具名称
    std::string description_{};       ///< 工具描述
    JsonValue parameters_{};          ///< 工具参数schema
};

/// @brief 通用模板封装
template<typename Func>
class ChatToolGeneric: public ChatTool
{
public:
    ChatToolGeneric(Func func) : func_(std::move(func)) {}
    std::string call(const JsonValue& arguments) override { return func_(arguments); }
private:
    Func func_;
};


/*! @} */


AST_NAMESPACE_END