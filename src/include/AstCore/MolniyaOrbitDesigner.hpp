/// @file      MolniyaOrbitDesigner.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"
#include "BaseOrbitDesigner.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief      莫尼亚轨道/闪电轨道设计器
class AST_CORE_API MolniyaOrbitDesigner : public BaseOrbitDesigner
{
public:
    MolniyaOrbitDesigner();
    explicit MolniyaOrbitDesigner(CelestialBody* body);
    ~MolniyaOrbitDesigner() = default;
    using BaseOrbitDesigner::getOrbitState;

    errc_t getOrbitState(ModOrbElem& orbElem) const override;

    double getApogeeLongitude() const { return apogeeLongitude_; }
    void setApogeeLongitude(double lon) { apogeeLongitude_ = lon; }

    double getPerigeeAltitude() const { return perigeeAltitude_; }
    void setPerigeeAltitude(double alt) { perigeeAltitude_ = alt; }

    double getArgumentOfPerigee() const { return argumentOfPerigee_; }
    void setArgumentOfPerigee(double arg) { argumentOfPerigee_ = arg; }

protected:
    double apogeeLongitude_{0};
    double perigeeAltitude_{0};
    double argumentOfPerigee_{0};
};


/*! @} */

AST_NAMESPACE_END
