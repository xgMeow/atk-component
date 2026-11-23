/// @file      RepeatingOrbitDesigner.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"
#include "BaseOrbitDesigner.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Orbit
    @{
*/

/// @brief 回归轨道设计器
class AST_CORE_API RepeatingOrbitDesigner final: public BaseOrbitDesigner
{
public:
    enum EPositionType
    {
        eAltitude,
        eRevsPerDay
    };
    RepeatingOrbitDesigner();
    explicit RepeatingOrbitDesigner(CelestialBody *body);
    ~RepeatingOrbitDesigner() = default;

    using BaseOrbitDesigner::getOrbitState;
    errc_t getOrbitState(ModOrbElem &orbElem) const override;

    EPositionType getPositionType() const { return positionType_; }
    void setPositionType(EPositionType type) { positionType_ = type; }

    double  getApproxAltitude() const { return approxAltitude_; }
    errc_t setApproxAltitude(double alt);

    double  getApproxRevsPerDay() const { return approxRevsPerDay_; }
    errc_t setApproxRevsPerDay(double revsPerDay);

    double getInclination() const { return inclination_; }
    void setInclination(double inc) { inclination_ = inc; }

    int  getNumberOfRevsRepeat() const { return numberOfRevsRepeat_; }
    void setNumberOfRevsRepeat(int revs) { numberOfRevsRepeat_ = revs; }

    double getLongitudeOfAscendingNode() const { return longitudeOfAscendingNode_; }
    void setLongitudeOfAscendingNode(double lon) { longitudeOfAscendingNode_ = lon; }
protected:
    EPositionType    positionType_{eAltitude};
    double           approxAltitude_{0};
    double           approxRevsPerDay_{0};
    double           inclination_{0};
    int              numberOfRevsRepeat_{0};
    double           longitudeOfAscendingNode_{0};
};

/*! @} */

AST_NAMESPACE_END
