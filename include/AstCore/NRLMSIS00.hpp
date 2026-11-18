/// @file      NRLMSIS00.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-08

#pragma once

#include "AstGlobal.h"
#include "MSISBase.hpp"
#include <type_traits>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class NRLMSISE;

#define _AST_USE_MSIS_VERS_FOR_NRLMSIS00

#ifdef _AST_USE_MSIS_VERS_FOR_NRLMSIS00

/// @brief NRLMSIS00大气模型基类
class AST_CORE_API NRLMSIS00 final: public MSISBase
{
public:
    NRLMSIS00(Frame* frame, BodyShape* bodyShape, double f107Daily, double f107Average, double ap);
    NRLMSIS00(Frame* frame, BodyShape* bodyShape, SpaceWeatherProvider* spaceWeather);

    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override;
};

#else
/// @brief NRLMSIS00大气模型
class AST_CORE_API NRLMSIS00 final: public AtmosphereBase
{
public:
    NRLMSIS00(Frame* ecf, BodyShape* bodyShape, double f107Daily, double f107Average, double ap);
    ~NRLMSIS00() override;

    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override;


private:
    NRLMSISE& nrlmsise() const {return *reinterpret_cast<NRLMSISE*>(&storage_);}
private:
    mutable std::aligned_storage<624>::type storage_;
};

#endif


/*! @} */

AST_NAMESPACE_END

