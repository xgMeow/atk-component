/// @file      Receiver.hpp
/// @brief     接收器对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 接收器对象
class AST_SIM_API Receiver: public ObjectNamed
{
public:
    Receiver() = default;
    ~Receiver() override = default;

    AST_OBJECT(Receiver)
};

/*! @} */

AST_NAMESPACE_END