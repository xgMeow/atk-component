/// @file      FieldOfViewVisitor.hpp
/// @brief     视场访问者接口
/// @details   定义视场访问者的接口，用于访问不同类型的视场
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class FieldOfView;
class FOVSimpleCone;
class FOVConical;
class FOVHalfPower;
class FOVRectangular;
class FOVSAR;
class FOVCustom;

class FieldOfViewVisitor
{
public:
    virtual ~FieldOfViewVisitor() = default;
    virtual void visit(FieldOfView& fov) = 0;
    virtual void visit(FOVSimpleCone& fov) = 0;
    virtual void visit(FOVConical& fov) = 0;
    virtual void visit(FOVHalfPower& fov) = 0;
    virtual void visit(FOVRectangular& fov) = 0;
    virtual void visit(FOVSAR& fov) = 0;
    virtual void visit(FOVCustom& fov) = 0;
};

/*! @} */

AST_NAMESPACE_END