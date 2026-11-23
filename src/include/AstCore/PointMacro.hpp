/// @file      PointMacro.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-11

#pragma once

#include "AstGlobal.h"
#include "AstCore/BuiltinFrame.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

#define _AST_DECL_POINT(NAME) \
    class AST_CORE_API Point##NAME : public Point \
    { \
    public: \
        Point##NAME() = default; \
        ~Point##NAME() override= default; \
        static Point##NAME* Instance();\
        Frame* getFrame() const override;\
        errc_t getPos(const TimePoint &tp, Vector3d &pos) const override;\
        errc_t getPosVel(const TimePoint &tp, Vector3d &pos, Vector3d &vel) const override;\
    };\
    A_ALWAYS_INLINE Point* aPoint##NAME()\
    {\
        return Point##NAME::Instance();\
    }\


#define _AST_IMPL_POINT(NAME, FRAME)\
    Point##NAME* Point##NAME::Instance()\
    {\
        static SharedPtr<Point##NAME> instance(new Point##NAME());\
        return instance.get();\
    }\
    Frame* Point##NAME::getFrame() const\
    {\
        return Frame##FRAME::Instance();\
    }\
    errc_t Point##NAME::getPos(const TimePoint &tp, Vector3d &pos) const\
    {\
        return a##NAME##PosIn##FRAME(tp, pos);\
    }\
    errc_t Point##NAME::getPosVel(const TimePoint &tp, Vector3d &pos, Vector3d &vel) const\
    {\
        return a##NAME##PosVelIn##FRAME(tp, pos, vel);\
    }\


/*! @} */

AST_NAMESPACE_END

