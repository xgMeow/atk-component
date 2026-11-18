/// @file      AccessLoader.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-08

#pragma once

#include "AstGlobal.h"
#include "AstSim/Access.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/

class Scenario;

/// @brief 加载 Access 对象
/// @details 加载 .sca 文件中的全部 Access 对象，并挂到场景之下
/// @param filepath .sca 文件路径
/// @param scenario 所属场景
/// @return 错误码
AST_LOADER_API errc_t aLoadAccess(StringView filepath, Scenario& scenario);


/// @brief 加载 Access 对象
/// @details 加载 .sca 文件中的全部 Access 对象，并挂到场景之下
/// @param filepath .sca 文件路径
/// @param scenario 所属场景
/// @param accesses 输出参数，本次加载产生的 Access 对象列表（调用时会被清空）
/// @return 错误码
AST_LOADER_API errc_t aLoadAccess(StringView filepath, Scenario& scenario, std::vector<HAccess>& accesses);

/*! @} */

AST_NAMESPACE_END
