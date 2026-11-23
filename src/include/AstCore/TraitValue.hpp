/// @file      TraitValue.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      22.11.2025

#pragma once

#include "AstGlobal.h"
#include "TraitObject.hpp"

AST_NAMESPACE_BEGIN

class IValuePrv
{
public:
    virtual ~IValuePrv(){}
    virtual errc_t getValue(const TimePoint& tp, double& value) const = 0;
    virtual Type* type() const = 0;

};

template<typename T>
class ImplFor<IValuePrv, T> : public TraitObject<IValuePrv>
{
public:
    typedef TraitObject<IValuePrv> Base;
    ImplFor(T* obj)
        :Base{ obj }
    {}
    ImplFor(const T& obj)
        :Base{ (void*) & obj}
    {}
    Type* type() const override
    {
        return T::staticType();
    }
    errc_t getPosIn(Frame* frame, const TimePoint& tp, Vector3d& pos) const override
    {
        return get()->getPosIn(frame, tp, pos);
    }
    errc_t getPosVelIn(Frame* frame, const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override
    {
        return get()->getPosVelIn(frame, tp, pos, vel);
    }
    T* get() const
    {
        return (T*)data_;
    }
};



AST_NAMESPACE_END

