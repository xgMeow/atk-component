/// @file      ScStateCalcScript.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-12

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class ScriptExecutor;

class AST_CORE_API ScStateCalcScript: public ScStateCalculation
{
public:
    using VariableList = std::vector<HScStateCalculation>;

    errc_t calculate(const SpacecraftState& scState, double& result) override;

    const std::string expression() const {return expression_;}
    void setExpression(StringView expression);

    const VariableList variables() const {return variables_;}
    void setVariables(const VariableList& variableList);
protected:

    /// @brief 创建脚本执行器
    virtual ScriptExecutor* newScriptExecutor() const = 0;
private:
    std::string expression_{};     ///< 脚本表达式
    VariableList variables_{};     ///< 脚本变量列表
};


/*! @} */

AST_NAMESPACE_END

