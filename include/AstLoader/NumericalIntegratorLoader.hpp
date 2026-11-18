/// @file      NumericalIntegratorLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEIntegrator.hpp"
#include "AstUtil/ScopedPtr.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 加载数值积分器
/// @param value 值
/// @param integrator 积分器指针
/// @return 错误码
errc_t aLoadNumericalIntegrator(const Value& value, ScopedPtr<ODEIntegrator> &integrator);


/*! @} */

AST_NAMESPACE_END
