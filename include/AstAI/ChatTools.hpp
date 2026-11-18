/// @file      ChatTools.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-27

#pragma once

#include "AstGlobal.h"
#include "ChatTool.hpp"
#include <vector>
#include <memory>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief AI工具集合
/// @details 所有AI工具的集合，用于管理工具的添加、删除和调用
class ChatTools
{
public:
    ChatTools() = default;
    ChatTools(bool initAsDefault);
    ~ChatTools() = default;
    ChatTools(ChatTools&&) = default;
    ChatTools& operator=(ChatTools&&) = default;
public:
    /// @brief 处理工具调用
    /// @param toolCall 工具调用参数
    /// @return 工具调用结果
    std::string handleToolCall(const JsonValue& toolCall);

    /// @brief 添加工具
    /// @param tool 工具指针
    void addTool(std::unique_ptr<ChatTool>&& tool){tools_.push_back(std::move(tool));}

    template<typename Func>
    ChatTool* addTool(Func func)
    {
        ChatTool* tool = new ChatToolGeneric<Func>(func);
        addTool(std::unique_ptr<ChatTool>(tool));
        return tool;
    }

    /// @brief 清除所有工具
    void clearTools(){tools_.clear();}

    /// @brief 将工具集合转换为JSON格式
    /// @return JSON值
    JsonValue toJson() const;

    /// @brief 检查工具集合是否为空
    bool empty() const {return tools_.empty();}
private:
    A_DISABLE_COPY(ChatTools);
    std::vector<std::unique_ptr<ChatTool>> tools_{};
};


/*! @} */

AST_NAMESPACE_END
