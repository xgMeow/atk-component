/// @file      Interpreter.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "SymbolTable.hpp"
#include "SymbolScope.hpp"
#include "CallStack.hpp"
#include "ScriptContext.hpp"
#include <memory>
#include <string>

AST_NAMESPACE_BEGIN

class ISymbolScope;

/// @brief 解释器
/// @details
/// 解释器用于解释执行脚本中的代码。
/// @ingroup Script
class AST_SCRIPT_API Interpreter
{
public:
    Interpreter();

    /// @brief 构造函数，指定外部符号作用域
    /// @warning 该构造函数会获得symbolScope所有权，调用者无需释放symbolScope，
    ///          传入栈对象或共享对象将导致未定义行为
    /// @param symbolScope 符号作用域指针（所有权转移）
    explicit Interpreter(ISymbolScope* symbolScope);
    ~Interpreter();

    /// @brief 获取当前作用域
    /// @details
    /// 当前作用域是解释器当前正在执行的代码所在的作用域。
    /// @return 当前作用域
    ISymbolScope* currentScope() { return symbolScope_.get(); }

    /// @brief 解释执行代码
    /// @details
    /// 解释执行代码时，会将代码解析为抽象语法树（AST），
    /// 并根据符号表和调用栈执行代码。
    /// @param code 要解释执行的代码
    void interpret(StringView code);


    /// @brief 获取错误字符串
    /// @details
    /// 获取解释器执行代码时产生的错误字符串。
    /// @return 错误字符串
    const std::string& errString() const { return errString_; }


    /// @brief 设置错误字符串
    /// @details
    /// 设置解释器执行代码时产生的错误字符串。
    /// @param err 错误字符串
    void setErrString(StringView err) { errString_ = std::string(err); }


    /// @brief 清除错误字符串
    /// @details
    /// 清除解释器执行代码时产生的错误字符串。
    void clearErrString() { errString_.clear(); }

protected:
    std::unique_ptr<ISymbolScope> symbolScope_;       ///< 当前作用域
    std::string errString_{};                          ///< 错误字符串
};


/// @brief 创建新的解释器，用于解释执行脚本中的代码。
AST_SCRIPT_API Interpreter* aNewInterpreter();

/// @brief 创建新的解释器，用于解释执行脚本中的代码
/// @warning 该函数会获得symbolScope所有权，调用者无需释放symbolScope
/// @param symbolScope 符号作用域
AST_SCRIPT_API Interpreter* aNewInterpreter(ISymbolScope* symbolScope);


/// @brief 删除解释器，释放其占用的资源。
/// @param interpreter 解释器指针
AST_SCRIPT_API void aDelInterpreter(Interpreter* interpreter);


/// @brief 解释器上下文守卫
/// @details 解释器上下文守卫用于在某个作用域内解释器执行代码时，自动切换到当前解释器。
class InterpreterContext {
public:
    explicit InterpreterContext(Interpreter& interpreter)
        : InterpreterContext(&interpreter)
    {
    }
    explicit InterpreterContext(Interpreter* interpreter)
    {
        oldInterpreter_ = aScript_SwapInterpreter(interpreter);
    }
    ~InterpreterContext()
    {
        aScript_SetInterpreter(oldInterpreter_);
    }
private:
    Interpreter* oldInterpreter_ = nullptr;

    A_DISABLE_COPY(InterpreterContext);
};



AST_NAMESPACE_END