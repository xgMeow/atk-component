/// @file      MotionProfileVisitor.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-25

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionProfile;
class MotionTwoBody;
class MotionHPOP;
class MotionSPICE;
class MotionGreatArc;
class MotionExternalEphemeris;
class MotionJ2Analytical;
class MotionJ4Analytical;
class MotionSGP4;
class MotionMissionCommand;

class MotionProfileVisitor
{
public:
    virtual ~MotionProfileVisitor() = default;
    virtual void visit(MotionProfile& profile) = 0;
    virtual void visit(MotionTwoBody& profile) = 0;
    virtual void visit(MotionHPOP& profile) = 0;
    virtual void visit(MotionSPICE& profile) = 0;
    virtual void visit(MotionGreatArc& profile) = 0;
    virtual void visit(MotionExternalEphemeris& profile) = 0;
    virtual void visit(MotionJ2Analytical& profile) = 0;
    virtual void visit(MotionJ4Analytical& profile) = 0;
    virtual void visit(MotionSGP4& profile) = 0;
    virtual void visit(MotionMissionCommand& profile) = 0;
};

/*! @} */

AST_NAMESPACE_END
