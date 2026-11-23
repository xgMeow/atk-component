/// @file      UiOperator.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Platform
    @{
*/

class Object;
class Class;




/// @brief     编辑对象
/// @details   ~
/// @param     object 要编辑的对象
/// @return    errc_t  错误码
AST_UTIL_CAPI errc_t aEditObject(Object *object);



/// @brief     选择对象
/// @details   ~
/// @param     typeName 对象类型名
/// @return    Object*  选择的对象指针
AST_UTIL_CAPI Object* aSelectObject(StringView typeName);


/*! @} */


AST_NAMESPACE_END
