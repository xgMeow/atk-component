/// @file      SweepStudy.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/Command.hpp"
#include "AstScript/Expr.hpp"
#include <memory>

AST_NAMESPACE_BEGIN

class Interpreter;

/*!
    @addtogroup
    @{
*/


class AST_ANALYZER_API SweepVariable : public ObjectNamed
{
public:
    AST_OBJECT(SweepVariable)

    double startValue() const { return startValue_; }
    void setStartValue(double value) { startValue_ = value; }

    double endValue() const { return endValue_; }
    void setEndValue(double value) { endValue_ = value; }

    double stepSize() const { return stepSize_; }
    void setStepSize(double value) { stepSize_ = value; }

    Expr* expr() const { return expr_.get(); }
    void setExpr(Expr* expr) { expr_ = expr; }

    errc_t getValue(double& value) const;
    errc_t setValue(double value);

    std::vector<double>& values() { return values_; }
    const std::vector<double>& values() const { return values_; }
private:
    double startValue_{0.0};        ///< 变量的起始值
    double endValue_{0.0};          ///< 变量的结束值
    double stepSize_{0.0};          ///< 分析步长
    SharedPtr<Expr> expr_{};         ///< 遍历表达式
    std::vector<double> values_{};   ///< 值列表
};


class AST_ANALYZER_API SweepOutput : public ObjectNamed
{
public:
    AST_OBJECT(SweepOutput)

    errc_t getValue(double& value) const;

    Expr* expr() const { return expr_.get(); }
    void setExpr(Expr* expr) { expr_ = expr; }

    std::vector<double>& values() {return values_;}
    const std::vector<double>& values() const {return values_;}

private:
    SharedPtr<Expr> expr_{};          ///< 结果表达式
    std::vector<double> values_{};    ///< 约束值列表
};




/// @brief 遍历搜索分析器（参数化扫描），对变量进行嵌套循环遍历并执行仿真命令
class AST_ANALYZER_API SweepStudy : public Command
{
public:
    AST_OBJECT(SweepStudy)
public:
    SweepStudy();
    ~SweepStudy() override;

    using VariableType = SweepVariable;
    using OutputType = SweepOutput;

    using VariableList = std::vector<SharedPtr<VariableType>>;
    using OutputList = std::vector<SharedPtr<OutputType>>;

    errc_t execute() override;

    /// @brief 获取变量列表
    VariableList& variables() { return variables_; }
    const VariableList& variables() const { return variables_; }

    /// @brief 获取输出列表
    OutputList& outputs() { return outputs_; }
    const OutputList& outputs() const { return outputs_; }

    /// @brief 添加变量
    void addVariable(VariableType* variable);

    /// @brief 移除变量
    void removeVariable(VariableType* variable);

    /// @brief 添加输出
    void addOutput(OutputType* output);

    /// @brief 移除输出
    void removeOutput(OutputType* output);

    /// @brief 获取关联的执行命令
    Command* relatedCommand() const { return relatedCommand_.get(); }

    /// @brief 设置关联的执行命令
    void setRelatedCommand(Command* command) { relatedCommand_ = command; }

    /// @brief 计算总运行次数
    int totalRuns() const;

    /// @brief 执行单步分析
    errc_t executeStep(int stepIndex);

private:
    /// @brief 生成所有变量的值列表
    void generateValueLists();

    /// @brief 将步索引转换为各变量索引
    void stepIndexToVarIndices(int stepIndex, std::vector<int>& indices) const;

    VariableList variables_{};                            ///< 变量列表
    OutputList outputs_{};                                ///< 输出列表
    mutable WeakPtr<Command> relatedCommand_{};           ///< 关联的执行命令
};

/*! @} */

AST_NAMESPACE_END

