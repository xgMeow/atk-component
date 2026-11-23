/// @file      LoaderContext.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-22

#pragma once

#include "AstGlobal.h"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 加载上下文
class LoaderContext
{
public:
    LoaderContext* parent_{nullptr};        ///< 父上下文
    std::string scenarioDir_{};               ///< 场景目录
    std::string filepath_{};                  ///< 文件路径
};


/*! @} */

AST_NAMESPACE_END
