/// @file      SpiceBodyRegistry.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/SolarSystem.hpp"
#include <unordered_map>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Spice
    @{
*/

class AST_SPICE_API SpiceBodyRegistry
{
public:
    SpiceBodyRegistry();
    explicit SpiceBodyRegistry(bool whetherInit);
    ~SpiceBodyRegistry();
    static SpiceBodyRegistry& Instance();

    PBody findBody(StringView name) const;
    PBody findBody(int id) const;
    errc_t init();
protected:
    SharedPtr<SolarSystem> solarSystem_;
};

/*! @} */

AST_NAMESPACE_END
