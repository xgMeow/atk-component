/// @file      ClassRegistry.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-02

#pragma once

#include "AstGlobal.h"
#include <unordered_map>
#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Class;

#ifndef SWIG

/// @brief 类注册器
/// @details 用于注册和查找类的元数据
class ClassRegistry
{
public:
    using ClassMap = std::unordered_map<std::string, Class*>;

    ClassRegistry() = default;
    ~ClassRegistry() = default;
    static ClassRegistry* Instance();

    Class* getClass(StringView name) const;
    void getAllClassNames(std::vector<std::string>& names) const;
    const ClassMap& getAllClasses() const { return classMap_; }
    void registerClass(Class* cls);
    void registerClass(Class* cls, StringView name);
protected:
    ClassMap classMap_{};
};

#endif

/*! @} */

AST_NAMESPACE_END
