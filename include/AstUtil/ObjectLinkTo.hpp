/// @file      ObjectLinkTo.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-10

#pragma once

#include "AstGlobal.h"
#include "ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 链接到对象
/// @details 用于链接对象
class AST_UTIL_API ObjectLinkTo final: public ObjectNamed
{
public:
    AST_OBJECT(ObjectLinkTo)

    ObjectLinkTo() = default;

    ObjectLinkTo(const ObjectLinkTo&) = delete;
    ObjectLinkTo& operator=(const ObjectLinkTo&) = delete;

    ~ObjectLinkTo() = default;

    void setResolvedName(const std::string& name);
    const std::string& getResolvedName() const;

    void setResolvedType(Class* type);
    Class* getResolvedType() const;

    void setResolvedObject(Object* object){resolvedObject_ = object;}

    Object* resolve() const;
private:
    mutable WeakPtr<Object> resolvedObject_{};        ///< 已解析的对象
    std::string resolvedName_{};                      ///< 用于解析的名称
    Class* resolvedType_{nullptr};                  ///< 用于解析的类型
};


/*! @} */

AST_NAMESPACE_END


