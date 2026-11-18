/// @file      CommandRouting.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-11

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/ValueView.hpp"
#include "CommandUtil.hpp"
#include <vector>
#include <memory>


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/



/// @brief 命令参数
class CommandParams: public std::vector<ValueView>
{
public:
    // todo 
};


/// 命令处理接口
class CommandHandler
{
public:
    /// 处理命令
    /// @param params 命令参数
    /// @param result 命令结果
    /// @return 错误码
    virtual errc_t handle(const CommandParams& params, CommandResult& result) const = 0;

    virtual ~CommandHandler() = default;
};


/// @brief 路由结果
class RoutingHandleResult
{
public:
    CommandParams& params() { return params_; }
    CommandHandler* handler() { return handler_; }
    void setHandler(CommandHandler* handler) { handler_ = handler; }
private:
    CommandParams params_{};             ///< 命令参数
    CommandHandler* handler_{nullptr};  ///< 命令处理函数
};



/// @brief 路由树
class AST_CMD_API CommandTrie
{
public:
    class Node
    {
    public:
        Node() = default;
        Node(StringView key) 
            : key_(key) 
        {}
        /// @brief 查找子节点
        const Node* findChild(StringView key) const
        {
            for(auto& child : children_)
            {
                if (key == child.key_)
                    return &child;
            }
            return nullptr;
        }
        /// @brief 确保子节点存在
        Node& ensureChild(StringView key)
        {
            for (auto& child : children_)
            {
                if (key == child.key_)
                    return child;
            }
            children_.emplace_back(key);
            auto& child = children_.back();
            return child;
        }
    public:
        int                             numParams_{-1};     ///< 该键值之后的参数数量， -1 表示未初始化
        std::string                     key_{};              ///< 键值
        std::shared_ptr<CommandHandler> handler_{};          ///< 命令处理函数
        std::vector<Node>               children_{};         ///< 子节点
    };
    Node& addRule(StringView tmpl);
    void addRule(StringView tmpl, std::shared_ptr<CommandHandler> handler);
    errc_t find(StringView text, RoutingHandleResult& result) const;
private:
    Node root_{};
};


/*! @} */

AST_NAMESPACE_END
