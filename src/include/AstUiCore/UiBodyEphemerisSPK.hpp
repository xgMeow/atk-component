/// @file      UiBodyEphemerisSPK.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-04

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"
#include "AstUiCore/UiInteger.hpp"
#include "AstUiCore/UiFilePath.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class BodyEphemerisSPK;

class AST_UICORE_API UiBodyEphemerisSPK: public UiObject
{
    Q_OBJECT
public:
    UiBodyEphemerisSPK(Object* object, QWidget *parent = nullptr);
    UiBodyEphemerisSPK(QWidget *parent = nullptr);
    ~UiBodyEphemerisSPK() = default;
    UiBodyEphemerisSPK(const UiBodyEphemerisSPK&) = delete;
    UiBodyEphemerisSPK& operator=(const UiBodyEphemerisSPK&) = delete;

    void refreshUi();
    void apply();
    void applyTo(BodyEphemerisSPK* ephemeris);

    void setBodyEphemerisSPK(BodyEphemerisSPK* ephemeris);
    BodyEphemerisSPK* getBodyEphemerisSPK() const;
signals:
    void bodyEphemerisSPKChanged(BodyEphemerisSPK* ephemeris);
private slots:
    void onFilePathChanged(const QString& path);
private:
    UiInteger* spiceIndexEdit_{nullptr};
    UiFilePath* filePathEdit_{nullptr};
};


/*! @} */

AST_NAMESPACE_END
