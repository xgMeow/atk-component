/// @file      ScenarioLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Scenario;

/// @brief 加载场景
/// @details 从文件加载场景
/// @param filepath 文件路径
/// @param scenario 场景引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadScenario(StringView filepath, Scenario& scenario);


/// @brief 查找场景文件
/// @details dirpath 场景目录路径
/// @param scenarioPath 场景文件路径
/// @return 错误码
AST_LOADER_CAPI errc_t aFindScenarioFile(StringView dirpath, std::string& scenarioPath);

/*! @} */

AST_NAMESPACE_END
