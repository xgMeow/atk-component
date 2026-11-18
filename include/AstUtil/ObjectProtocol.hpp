/// @file      ObjectProtocol.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

#define _AST_OBJ_CALL static


/// @brief 对象协议
class AST_UTIL_API ObjectProtocol
{
public:
    /// @brief 设置对象属性字符串值
    /// @details id 对象索引/对象ID
    /// @param name 属性名
    /// @param value 属性值
    /// @return 错误码
    _AST_OBJ_CALL errc_t setAttrString(ObjectId id, StringView name, StringView value);

    /// @brief 获取对象属性字符串值
    /// @details id 对象索引/对象ID
    /// @param name 属性名
    /// @param value 属性值
    /// @return 错误码
    _AST_OBJ_CALL errc_t getAttrString(ObjectId id, StringView name, std::string& value);

    /// @brief 创建新对象
    /// @details typeName 对象类型名
    /// @return 对象ID
    _AST_OBJ_CALL ObjectId newObject(StringView typeName);
};

/*! @} */

AST_NAMESPACE_END


