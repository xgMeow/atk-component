/// @file      EphemerisSPK.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "BodyEphemeris.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/JplSpk.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/


class AST_CORE_API BodyEphemerisSPK : public BodyEphemeris
{
public:
    AST_OBJECT(BodyEphemerisSPK)
    AST_PROPERT(SpiceIndex)
    BodyEphemerisSPK() = default;

    BodyEphemerisSPK(const BodyEphemerisSPK&) = delete;
    BodyEphemerisSPK& operator=(const BodyEphemerisSPK&) = delete;

    BodyEphemerisSPK(int spiceIndex)
        : spiceIndex_(spiceIndex)
        , spk_()
    {}
    BodyEphemerisSPK(CelestialBody* body)
        : body_(body)
        , spiceIndex_(body->getJplSpiceId())
        , spk_()
    {}

    ~BodyEphemerisSPK() override = default;

    errc_t openSPKFile(StringView spkfile);

    const std::string& getFilePath() const;

    errc_t getPosICRF(const TimePoint& tp, Vector3d& pos) const override;

    errc_t getPosVelICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;

    errc_t getInterval(TimeInterval &interval) const override;
PROPERTIES:
    int getSpiceIndex() const;

    void setSpiceIndex(int spiceIndex){spiceIndex_ = spiceIndex;}
protected:
    CelestialBody* body_{nullptr};
    int            spiceIndex_{-1};
    JplSpk         spk_{};
};


/*! @} */

AST_NAMESPACE_END
