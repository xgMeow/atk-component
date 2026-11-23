/// @file      XMLSax.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-11

#pragma once
#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/BKVItemView.hpp"
#include <vector>


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief XML SAX解析器的回调接口
class AST_UTIL_API XMLSax {
public:
    class AttributeList;
    virtual ~XMLSax() = default;
    /// @brief 文档开始回调
    virtual void startDocument() = 0;
    /// @brief 文档结束回调
    virtual void endDocument() = 0;
    /// @brief 元素开始回调
    virtual void startElement(StringView name, const AttributeList& attributes) = 0;
    /// @brief 元素结束回调
    virtual void endElement(StringView name) = 0;
    /// @brief 文本内容回调
    virtual void characters(StringView text) = 0;
    /// @brief 注释回调
    virtual void comment(StringView text){};
    /// @brief 错误回调
    /// @param msg 错误消息
    virtual void error(StringView msg){};
public:
    /// @brief XML SAX解析器的属性列表
    /// @details 用于存储元素的属性，每个属性是一个键值对。
    class AttributeList: public std::vector<BKVItemView>
    {
    public:
        ValueView get(StringView name) const
        {
            for(const auto& item: *this)
            {
                if(item.key() == name)
                {
                    return item.value();
                }
            }
            return {};
        }
    };

};



/*! @} */

AST_NAMESPACE_END