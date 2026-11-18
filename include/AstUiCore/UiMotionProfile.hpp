/// @file      UiMotionProfile.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-28

#pragma once

#include "AstGlobal.h"
#include "AstUiCore/UiObject.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class MotionProfile;

class AST_UICORE_API UiMotionProfile: public UiObject
{
    Q_OBJECT
public:
    explicit UiMotionProfile(QWidget *parent = nullptr);
    ~UiMotionProfile() = default;

    MotionProfile* getMotionProfile() const;
private:

};



/*! @} */

AST_NAMESPACE_END
