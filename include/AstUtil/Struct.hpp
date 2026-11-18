/// @file      Struct.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-09

#pragma once

#include "AstGlobal.h"
#include "Field.hpp"
#include "AstUtil/Object.hpp"
#include <unordered_map>
#include <vector>


AST_NAMESPACE_BEGIN

class Property;

/// @brief 结构体类
/// @details 结构体类，包含属性的名称、描述等信息
/// @ingroup RTTI
class AST_UTIL_API Struct: public Object
{
public:
    Struct()
        : Object(initial_strong_ref)
        , name_()
        , desc_()
        , properties_()
        , propertyMap_()
    {
        this->setReadOnly(true);
    }

    ~Struct() override;

    // @todo: 考虑使用StringView作为索引
    using PropertyMap = std::unordered_map<std::string, Property*>;
    using PropertyList = std::vector<Property*>;

    /// @brief 获取字段名称
    const std::string& getName() const final {return name_;}

    /// @brief 设置字段名称
    /// @param name 字段名称
    void setName(StringView name) final {name_ = std::string(name);}

    /// @brief 获取字段描述
    const std::string& desc() const{return desc_;}

    /// @brief 设置字段描述
    /// @param desc 字段描述
    void setDesc(StringView desc){desc_ = std::string(desc);}

    /// @brief 添加属性
    /// @param name 属性名
    /// @param property 属性
    /// @return Property* 属性指针
    Property* addProperty(StringView name, Property* property);

    /// @brief 添加属性
    /// @param property 属性
    /// @return Property* 属性指针
    Property* addProperty(Property* property);

    /// @brief 获取属性
    /// @param name 属性名
    /// @return Property* 属性指针
    Property* getProperty(StringView name);

    /// @brief 获取属性列表
    /// @return const PropertyList& 属性列表
    const PropertyList& getProperties() const{return properties_;}

    /// @brief 获取模块名, 不包含调试后缀
    /// @return std::string 模块名
    std::string getModuleName() const;

protected:
    std::string name_;              ///< 名称
    std::string desc_;              ///< 描述
    PropertyList properties_;       ///< 属性列表 
    PropertyMap  propertyMap_;      ///< 属性映射表
};



AST_NAMESPACE_END