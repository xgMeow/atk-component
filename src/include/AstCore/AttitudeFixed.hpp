/// @file      AttitudeFixed.hpp
/// @brief     固定姿态(Fixed in Axes)
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AttitudeProfile.hpp"
#include "AstMath/Rotation.hpp"
#include "AstCore/AttitudeProfile.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief 固定姿态
/// @details "Fixed in Axes" 
/// 体轴系相对指定的参考坐标系保持恒定取向。
/// 参考坐标系取惯性系时即惯性固定姿态；取固连系时体轴系随地球一起转动。
class AST_CORE_API AttitudeFixed : public AttitudeProfile
{
public:
    AST_OBJECT(AttitudeFixed)

    AttitudeFixed() = default;
    ~AttitudeFixed() override = default;

    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
PROPERTIES:
    const Rotation& rotation() const { return rotation_; }
    const Rotation& getRotation() const { return rotation_; }
    void setRotation(const Rotation& rotation) { rotation_ = rotation; }

    Axes* referenceAxes() const { return referenceAxes_.get(); }
    void setReferenceAxes(Axes* referenceAxes) { referenceAxes_ = referenceAxes; }
protected:
    WeakPtr<Axes> referenceAxes_{};               ///< 参考坐标系轴系
    Rotation rotation_{Rotation::Identity()};     ///< 相对于参考坐标系的指向
};

/*! @} */

AST_NAMESPACE_END
