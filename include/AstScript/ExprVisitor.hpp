/// @file      ExprVisitor.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-21

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class Expr; 
class Symbol; 
class Variable; 
class ValNull; 
class ValBool; 
class ValInt; 
class ValDouble; 
class ValString; 
class ValQuantity; 
class ValRange;
class ValDict;
class ValNamedVector;
class OpAssign; 
class OpBin; 
class OpUnary; 
class Function; 
class Macro; 
class ExprBlock; 
class ExprCondition; 
class ExprIf; 
class ExprWhile; 
class ExprForRange;
class ExprRange;
class ExprVector;
class ExprCatHorizontal;
class ExprCatVertical;
class ExprCall;
class ExprMacroExpand;
class ExprAttribute;
class ExprCalculation;



/// @brief 表达式访问器
/// @details 用于遍历表达式树的访问器。
class ExprVisitor{
public:
    virtual ~ExprVisitor() = default;

    virtual void visit(Symbol& symbol) = 0;

    virtual void visit(Variable& var) = 0;
    virtual void visit(ValNull& val) = 0;
    virtual void visit(ValInt& val) = 0;
    virtual void visit(ValDouble& val) = 0;
    virtual void visit(ValString& val) = 0;
    virtual void visit(ValBool& val) = 0;
    virtual void visit(ValQuantity& val) = 0;
    virtual void visit(ValRange& val) = 0;
    virtual void visit(ValDict& val) = 0;
    virtual void visit(ValNamedVector& val) = 0;

    virtual void visit(OpAssign& op) = 0;
    virtual void visit(OpBin& op) = 0;
    virtual void visit(OpUnary& op) = 0;

    virtual void visit(Function& func) = 0;
    virtual void visit(Macro& macro) = 0;

    virtual void visit(ExprBlock& block) = 0;
    virtual void visit(ExprCondition& expr) = 0;
    virtual void visit(ExprIf& expr) = 0;
    virtual void visit(ExprWhile& expr) = 0;
    virtual void visit(ExprForRange& expr) = 0;
    virtual void visit(ExprRange& expr) = 0;
    virtual void visit(ExprVector& expr) = 0;
    virtual void visit(ExprCatHorizontal& expr) = 0;
    virtual void visit(ExprCatVertical& expr) = 0;
    virtual void visit(ExprCall& expr) = 0;
    virtual void visit(ExprMacroExpand& expr) = 0;
    virtual void visit(ExprAttribute& expr) = 0;
    virtual void visit(ExprCalculation& expr) = 0;
protected:
    virtual void visit(Expr& expr) = 0;
public:
    void visitExpr(Expr& expr){visit(expr);}
};

AST_NAMESPACE_END