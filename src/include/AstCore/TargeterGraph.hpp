/// @file      TargeterGraph.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

class TargeterGraphControlOptions;
class TargeterGraphResultOptions;

/// @brief 目标器图形配置
class AST_CORE_API TargeterGraph : public ObjectNamed
{
public:

    TargeterGraph() = default;
    ~TargeterGraph() override = default;

    bool graphWhileRunning_ = false;
    std::string independentVariableSaveName_;
    bool labelIterations_ = false;
    bool showDesired_ = false;
    bool showTolerance_ = false;

    std::vector<SharedPtr<TargeterGraphControlOptions>> controlOptions_;
    std::vector<SharedPtr<TargeterGraphResultOptions>> resultOptions_;
};

/// @brief 目标器图形控制选项
class AST_CORE_API TargeterGraphControlOptions : public ObjectNamed
{
public:

    TargeterGraphControlOptions() = default;
    ~TargeterGraphControlOptions() override = default;

    int graphLineColor_ = 0;
    std::string graphPointStyle_;
    bool graphValue_ = false;
    std::string graphYAxis_;
};

/// @brief 目标器图形结果选项
class AST_CORE_API TargeterGraphResultOptions : public ObjectNamed
{
public:

    TargeterGraphResultOptions() = default;
    ~TargeterGraphResultOptions() override = default;

    bool graphDesired_ = false;
    int graphLineColor_ = 0;
    std::string graphOption_;
    std::string graphPointStyle_;
    bool graphTolerance_ = false;
    std::string graphYAxis_;
};

AST_NAMESPACE_END