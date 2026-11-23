/// @file      RelativityCorrection.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "ForceModel.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 相对论修正模型
class AST_CORE_API RelativityCorrection: public ForceModel
{
public:
    AST_OBJECT(RelativityCorrection)

};


/*! @} */

AST_NAMESPACE_END
