/// @file      ObjectAccessConstraints.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"
#include "ObjectAccessConstraint.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_SIM_API ObjectAccessConstraints: public ObjectNamed
{
public:
    AST_OBJECT(ObjectAccessConstraints)
    A_DISABLE_COPY(ObjectAccessConstraints)

    using ConstraintList = std::vector<ObjectAccessConstraint*>;

    ObjectAccessConstraints() = default;
    ~ObjectAccessConstraints();
public:
    ObjectAccessConstraint* addConstraint(EAccessConstraint type);
    ObjectAccessConstraint* addConstraint(StringView name);
    const ConstraintList& constraints() const { return constraints_; }
public:
    ConstraintList::iterator begin() { return constraints_.begin(); }
    ConstraintList::iterator end() { return constraints_.end(); }
    size_t size() const { return constraints_.size(); }
private:
    ConstraintList constraints_{};
};

/*! @} */

AST_NAMESPACE_END
