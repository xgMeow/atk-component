/// @file      PythonExecutor.hpp
/// @brief     Python 脚本执行器
/// @details   基于 PythonAPI 单例，实现 ScriptExecutor 接口，
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-16

#pragma once

#include "AstGlobal.h"
#include "ScriptExecutor.hpp"

struct _object;
typedef struct _object PyObject;

AST_NAMESPACE_BEGIN

class PythonAPI;

/// @brief Python 脚本执行器
/// @details 通过 PythonAPI 单例驱动 CPython 解释器，
///          多个 PythonExecutor 实例共享同一解释器状态。
class AST_SCRIPT_API PythonExecutor : public ScriptExecutor
{
public:
    PythonExecutor();

    PythonExecutor(const PythonExecutor&) = delete;
    PythonExecutor& operator=(const PythonExecutor&) = delete;

    ~PythonExecutor() override;

    errc_t initialize() override;
    void finalize() override;
    errc_t execute(StringView script, ScriptResult* resultOut = nullptr) override;
    errc_t evaluate(StringView expression, ScriptResult* resultOut = nullptr) override;
    std::string getLastError() const override;

    // 下面这些重载会隐藏基类同名的其他重载（含字符串字面量重载与类型护栏），需要显式引回
    using ScriptExecutor::setVariable;

    errc_t setVariable(StringView name, StringView value) override;
    errc_t setVariable(StringView name, double value) override;
    errc_t setVariable(StringView name, int value) override;
    errc_t setVariable(StringView name, bool value) override;

    errc_t getVariable(StringView name, std::string& value) const override;
    errc_t getVariable(StringView name, double& value) const override;
    errc_t getVariable(StringView name, int& value) const override;
    errc_t getVariable(StringView name, bool& value) const override;

protected:
    std::string captureError() const;

protected:
    PythonAPI* api_;
    PyObject* globals_{nullptr};  // 私有无名 dict，每个 executor 独立命名空间
    mutable std::string lastError_{};
};

AST_NAMESPACE_END
