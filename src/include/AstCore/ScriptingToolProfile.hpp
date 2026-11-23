/// @file      ScriptingTool.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"
#include "TargeterProfile.hpp"
#include "AstScript/ScriptExecutor.hpp"
#include "AstScript/Variable.hpp"
#include "AstUtil/StringView.hpp"
#include "AstCore/VariableList.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/



/// @brief 脚本工具配置
class AST_CORE_API ScriptingToolProfile : public TargeterProfile
{
public:
    AST_OBJECT(ScriptingToolProfile)

    static ScriptingToolProfile* New();

    /// @brief 执行脚本工具配置
    /// @return errc_t 执行结果
    errc_t execute() override;

    ScriptingToolProfile() = default;
    ~ScriptingToolProfile() override = default;

public:
    EScriptLanguage language() const { return language_; }
    void setLanguage(EScriptLanguage language) { language_ = language; }

    const std::string& scriptStatements() const { return scriptStatements_; }
    void setScriptStatements(StringView scriptStatements) { scriptStatements_ = std::string(scriptStatements); }

    const VariableList& attributes() const { return attributes_; }
    VariableList& attributes() { return attributes_; }

    const VariableList& parameters() const { return parameters_; }
    VariableList& parameters() { return parameters_; }

    const VariableList& calcObjects() const { return calcObjects_; }
    VariableList& calcObjects() { return calcObjects_; }

    /// @brief 获取参数变量
    Variable* getParameter(StringView name) const;

private:
    EScriptLanguage language_{EScriptLanguage::ePython};    ///< 脚本语言
    std::string scriptStatements_{};                          ///< 脚本语句
    VariableList attributes_{};                              ///< 属性变量列表
    VariableList parameters_{};                              ///< 参数变量列表
    VariableList calcObjects_{};                             ///< 计算对象变量列表
};

/*! @} */

AST_NAMESPACE_END


