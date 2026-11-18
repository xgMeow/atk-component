/// @file      AxesBodyRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/
class CelestialBody;
class BodyOrientation;

/// @brief  天体相关的轴系
class AST_CORE_API AxesBodyRelated : public Axes
{
public:
    explicit AxesBodyRelated(CelestialBody* body);
    ~AxesBodyRelated() override = default;

    AxesBodyRelated(const AxesBodyRelated&) = delete;
    AxesBodyRelated& operator=(const AxesBodyRelated&) = delete;
protected:
    /// @brief 获取天体的姿态/指向
    BodyOrientation* getBodyOrientation() const;
protected:
    CelestialBody* body_;       ///< 天体
};

/*! @} */

AST_NAMESPACE_END
