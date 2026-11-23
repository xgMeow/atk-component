/// @file      ExprExpandVisitor.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-04

#pragma once

#include "AstGlobal.h"
#include "ExprVisitor.hpp"
#include "AstScript/Expr.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

#ifndef SWIG

class ExprExpandVisitor final: public ExprVisitor
{
public:
    ExprExpandVisitor() = default;
    ~ExprExpandVisitor() override = default;

    void visit(Symbol& symbol) override;
    void visit(Variable& var) override;
    void visit(ValNull& val) override;
    void visit(ValInt& val) override;
    void visit(ValDouble& val) override;
    void visit(ValString& val) override;
    void visit(ValBool& val) override;
    void visit(ValQuantity& val) override;
    void visit(ValRange& val) override;
    void visit(ValDict& val) override;
    void visit(ValNamedVector& val) override;
    void visit(OpAssign& op) override;
    void visit(OpBin& op) override;
    void visit(OpUnary& op) override;
    void visit(Function& func) override;
    void visit(Macro& macro) override;
    void visit(ExprBlock& block) override;
    void visit(ExprCondition& expr) override;
    void visit(ExprIf& expr) override;
    void visit(ExprWhile& expr) override;
    void visit(ExprForRange& expr) override;
    void visit(ExprRange& expr) override;
    void visit(ExprVector& expr) override;
    void visit(ExprCatHorizontal& expr) override;
    void visit(ExprCatVertical& expr) override;
    void visit(ExprCall& expr) override;
    void visit(ExprMacroExpand& expr) override;
    void visit(ExprAttribute& expr) override;
    void visit(ExprCalculation& expr) override;
    void visit(Expr& expr) override;
public:
    Expr* takeResult()  {return result_.take();}
    void setResult(Expr* result) {result_ = result;}
private:
    void visitValue(Value& value);
    SharedPtr<Expr> result_{};
};

#endif

/*! @} */

AST_NAMESPACE_END

