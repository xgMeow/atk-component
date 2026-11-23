/// @file      TraitPosVel.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      23.11.2025

#pragma once

#include "AstGlobal.h"
#include "TraitObject.hpp"

AST_NAMESPACE_BEGIN



/// @brief 提供位置速度
class IPosVelPrv
{
public:
    virtual ~IPosVelPrv()
    {};
    virtual Type* type() const = 0;
    virtual errc_t getPosIn(Frame* frame, const TimePoint& tp, Vector3d& pos) const = 0;
    virtual errc_t getPosVelIn(Frame* frame, const TimePoint& tp, Vector3d& pos, Vector3d& vel) const = 0;
};



template<typename T>
class ImplFor<IPosVelPrv, T>: public TraitObject<IPosVelPrv>
{
public:
    typedef TraitObject<IPosVelPrv> Base;
    ImplFor(T* obj)
        :Base{ obj }
    {}
    ImplFor(const T& obj)
        :Base{(void*) & obj}
    {}
    Type* type() const override
    {
        return T::staticType(); 
    }
    errc_t getValue(const TimePoint& tp, double& value) const override
    {
        return get()->getValue(tp, value);
    }

    T* get() const{return (T*) data_; }
};




AST_NAMESPACE_END

