/// @file      Database.hpp
/// @brief     数据库抽象基类
/// @details   作为所有数据库实现类的公共基类，用于类型标识和统一引用。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-23

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 数据库抽象基类
/// @details 作为数据库实现的公共基类，用于类型统一标识。
///          派生类负责实现具体的数据加载和查询功能。
class AST_CORE_API Database
{
public:
    Database() = default;
    virtual ~Database() = default;
};

/*! @} */

AST_NAMESPACE_END
