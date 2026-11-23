/// @file      StudyWorkbench.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-03

#pragma once

#include "AstGlobal.h"
#include "AstCore/Command.hpp"
#include "AstCore/VariableList.hpp"
#include "AstScript/Interpreter.hpp"
#include <memory>


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief  研究工作台，用于参数扫描研究、优化研究、不确定性分析、区间分析等分析
class AST_ANALYZER_API StudyWorkbench : public Command
{
public:
    AST_OBJECT(StudyWorkbench)
public:
    StudyWorkbench();

    errc_t execute() override;

    /// @brief 获取输入变量列表
    VariableList& inputs(){return inputs_;}
    const VariableList& inputs() const {return inputs_;}

    /// @brief 获取输出变量列表
    VariableList& outputs(){return outputs_;}
    const VariableList& outputs() const {return outputs_;}

    /// @brief 获取关联的执行命令
    Command* relatedCommand() const {return relatedCommand_.get();}

    /// @brief 设置关联的执行命令
    void setRelatedCommand(Command* command) { relatedCommand_ = command; }

    /// @brief 获取脚本解释器
    Interpreter* interpreter() const {return interpreter_.get();}
private:
    VariableList inputs_{};                               ///< 输入变量列表
    VariableList outputs_{};                              ///< 输出变量列表
    mutable WeakPtr<Command> relatedCommand_{};           ///< 所关联的执行命令
private:
    mutable std::unique_ptr<Interpreter> interpreter_;  ///< 解释器
};



/*! @} */

AST_NAMESPACE_END

