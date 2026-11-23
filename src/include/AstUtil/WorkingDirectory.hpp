/// @file      WorkingDirectory.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-19

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/PosixExt.hpp"
#include "AstUtil/Logger.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Util
    @{
*/


/// @brief 工作目录切换器
/// @details 用于在作用域内临时切换工作目录，退出作用域后自动恢复原目录。
class WorkingDirectory
{
public:
    explicit WorkingDirectory(StringView path)
        : oldpath_(), curpath_()
    {
        oldpath_ = posix::getcwd();
        /// @todo 需要考虑如何避免创建临时std::string对象 
        int rc = posix::chdir(std::string(path).c_str());
        if(rc != 0){
            aError(_("切换到工作目录 %.*s 失败"), path.size(), path.data());
        }else{
            curpath_ = path;
        }
    }
    ~WorkingDirectory()
    {
        int rc = posix::chdir(oldpath_.c_str());
        if(rc != 0){
            aError(_("切换到工作目录 %s 失败"), oldpath_.c_str());
        }
    }
    /// @brief 检查是否成功切换工作目录
    operator bool() const { return isChanged(); }

    /// @brief 检查是否成功切换工作目录
    bool isChanged() const { return !curpath_.empty(); }

    /// @brief 获取切换后的工作目录
    StringView getCurrentPath() const { return curpath_; }
protected:
    A_DISABLE_COPY(WorkingDirectory);
    std::string oldpath_;
    StringView curpath_;
};


/*! @} */

AST_NAMESPACE_END
