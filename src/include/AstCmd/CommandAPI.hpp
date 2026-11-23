/// @file      CommandAPI.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-11

#pragma once

#include "AstGlobal.h"
#include <vector>
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


// class CommandResult: public std::vector<std::string>{};
class CommandResult: public std::vector<std::string>
{
public:
    using Parent = std::vector<std::string>;
    using Parent::Parent;
    using Parent::operator=;

    AST_CMD_API void debugPrint() const;
};

/// @brief 执行命令
/// @param cmd 命令字符串
/// @return 错误码
AST_CMD_API errc_t aExecuteCommand(StringView cmd);

/// @brief 执行命令并返回结果
/// @param cmd 命令字符串
/// @param result 命令执行结果
/// @return 错误码
AST_CMD_API errc_t aExecuteCommand(StringView cmd, CommandResult& result);


/*! @} */

AST_NAMESPACE_END

