/// @file      VisObject.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-06

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class VisObject;
using HVisObject = SharedPtr<VisObject>;

class VisVisitor;


class AST_VISUALIZATION_API VisObject: public ObjectNamed
{
public:
    VisObject() = default;
    virtual ~VisObject() = default;

    /// @brief 访问者分派
    /// @param visitor 访问者；由各具体子类实现，把自身转发给 visitor 的 visit()
    virtual void accept(VisVisitor& visitor) = 0;
};


/*! @} */

AST_NAMESPACE_END
