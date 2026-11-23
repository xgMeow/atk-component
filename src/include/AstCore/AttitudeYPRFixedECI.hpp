/// @file      AttitudeYPRFixedECI.hpp
/// @brief     偏航-俯仰-滚转固定姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AttitudeFixed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief 偏航-俯仰-滚转固定姿态剖面 (YPRFixedECI)
class AST_CORE_API AttitudeYPRFixedECI : public AttitudeFixed
{
public:
    AST_OBJECT(AttitudeYPRFixedECI)

    AttitudeYPRFixedECI() = default;
    AttitudeYPRFixedECI(Body* body);
    ~AttitudeYPRFixedECI() override = default;
private:
    // 屏蔽父类的setReferenceAxes方法
    void setReferenceAxes(Axes* referenceAxes) = delete;
public:
    void setBody(Body* body);
};

/*! @} */

AST_NAMESPACE_END
