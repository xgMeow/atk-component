/// @file      VariableLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-01

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 加载参数
/// @param value 值
/// @param var 参数变量
/// @return 错误码
errc_t aLoadParameter(const Value& value, Variable& var);


/// @brief 加载计算对象
/// @param value 值
/// @param var 计算对象变量
/// @param scope 作用域
/// @return 错误码
errc_t aLoadCalcObject(const Value& value, Variable& var, Object* scope);


/// @brief 加载属性
/// @param value 值
/// @param var 属性变量
/// @param scope 作用域
/// @return 错误码
errc_t aLoadAttribute(const Value& value, Variable& var, Object* scope);


/*! @} */

AST_NAMESPACE_END
