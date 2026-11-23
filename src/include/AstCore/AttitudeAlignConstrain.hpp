/// @file      AttitudeAlignConstrain.hpp
/// @brief     对齐/约束姿态(Aligned and Constrained)
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AstCore/AttitudeProfile.hpp"
#include "AstCore/Vector.hpp"
#include "AstMath/Rotation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/


/// @brief 对齐/约束姿态(Aligned and Constrained)
/// @details 
/// 用一对"对齐"矢量和一对"约束"矢量来定姿：
/// 体系下的对齐矢量与参考系下的对齐矢量严格对齐，
/// 在此前提下让体系下的约束矢量尽可能接近参考系下的约束矢量
class AST_CORE_API AttitudeAlignConstrain : public AttitudeProfile
{
public:
    AST_OBJECT(AttitudeAlignConstrain)

    AttitudeAlignConstrain() = default;
    ~AttitudeAlignConstrain() override = default;
public:
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
public:
    const Vector3d& alignedAxis() const{return alignedAxis_;}
    void setAlignedAxis(const Vector3d& axis){alignedAxis_ = axis;}

    const Vector3d& constrainedAxis() const{return constrainedAxis_;}
    void setConstrainedAxis(const Vector3d& axis){constrainedAxis_ = axis;}

    Vector* alignedVector() const{return alignedVector_.get();}
    void setAlignedVector(Vector* vector){alignedVector_ = vector;}

    Vector* constrainedVector() const{return constrainedVector_.get();}
    void setConstrainedVector(Vector* vector){constrainedVector_ = vector;}
private:
    Vector3d alignedAxis_{};
    Vector3d constrainedAxis_{};
    WeakPtr<Vector> alignedVector_{};
    WeakPtr<Vector> constrainedVector_{};
};

/*! @} */

AST_NAMESPACE_END
