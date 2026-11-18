/// @file      VariableListLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-30

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class VariableList;


/// @brief 加载参数列表
/// @param value 值
/// @param list 参数列表
/// @return 错误码
/// @note 该函数会清空已有参数列表
errc_t aLoadParameters(const Value& value, VariableList& list);


/// @brief 加载属性列表
/// @param value 值
/// @param list 属性列表
/// @param scope 作用域
/// @return 错误码
/// @note 该函数会清空已有属性列表
errc_t aLoadAttributes(const Value& value, VariableList& list, Object* scope);


/// @brief 加载计算对象列表
/// @param value 值
/// @param list 计算对象列表
/// @param scope 作用域
/// @return 错误码
/// @note 该函数会清空已有计算对象列表
errc_t aLoadCalcObjects(const Value& value, VariableList& list, Object* scope);


/*! @} */

AST_NAMESPACE_END


