/// @file      UiBodyEphemerisDE.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-04

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include "AstUiCore/UiInteger.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class BodyEphemerisDE;

class AST_UICORE_API UiBodyEphemerisDE: public UiObject
{
    Q_OBJECT
public:
    explicit UiBodyEphemerisDE(Object* object, QWidget *parent = nullptr);
    UiBodyEphemerisDE(const UiBodyEphemerisDE&) = delete;
    UiBodyEphemerisDE& operator=(const UiBodyEphemerisDE&) = delete;
    explicit UiBodyEphemerisDE(QWidget *parent = nullptr);
    ~UiBodyEphemerisDE() = default;

    void refreshUi();
    void apply();
    void applyTo(BodyEphemerisDE* ephemeris);

    void setBodyEphemerisDE(BodyEphemerisDE* ephemeris);
    BodyEphemerisDE* getBodyEphemerisDE() const;
signals:
    void bodyEphemerisDEChanged(BodyEphemerisDE* ephemeris);
private:
    UiInteger* jplIndexEdit_{nullptr};
};


/*! @} */

AST_NAMESPACE_END