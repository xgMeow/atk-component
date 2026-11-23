/// @file      DetectorUserSelect.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-03

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"
#include "AstCore/EventDetector.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API DetectorUserSelect : public EventDetector
{
public:
    static DetectorUserSelect* New();

    AST_OBJECT(DetectorUserSelect)
    AST_PROPERT(calculation)
    DetectorUserSelect() = default;
    ~DetectorUserSelect() = default;

    double getValue(const SpacecraftState& state, double t) const override;
    Dimension getDimension() const override; 
PROPERTIES:
    ScStateCalculation* calculation() const{return calculation_.get();}
    void setCalculation(ScStateCalculation* calculation){calculation_ = calculation;}
private:
    WeakPtr<ScStateCalculation> calculation_{};
};

/*! @} */

AST_NAMESPACE_END
