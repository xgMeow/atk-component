/// @file      AxesLinkTo.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-04

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"
#include "AstUtil/Object.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API AxesLinkTo : public Axes
{
public:
    AST_OBJECT(AxesLinkTo)

    static AxesLinkTo* New(StringView objectType, StringView name);

    AxesLinkTo() = default;
    AxesLinkTo(StringView objectType, StringView name);
    ~AxesLinkTo() override = default;
public:
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
public:
    Axes* resolve(Object* scope) const;
private:
    std::string objectType_{};
};

/*! @} */

AST_NAMESPACE_END


