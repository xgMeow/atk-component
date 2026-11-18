/// @file      VolumeGridCylindrical.hpp
/// @brief     柱面体积网格
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "VolumeGrid.hpp"
#include "GridCoord.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

class Frame;

/// @brief 柱面体积网格（Theta, Radius, Height）
/// @ingroup Spatial
class AST_CORE_API VolumeGridCylindrical final : public VolumeGrid
{
public:
    VolumeGridCylindrical();
    ~VolumeGridCylindrical() override = default;

    void accept(VolumeGridVisitor& visitor) override { visitor.visit(*this); }

    size_t getGridPointCount() const override;
    void enumerateGridPoints(std::vector<Vector3d>& points) const override;
    void getBoundingBox(Vector3d& minCorner, Vector3d& maxCorner) const override;

    /// @name 坐标轴
    /// @{
    GridCoord& theta()  { return theta_; }
    const GridCoord& theta() const { return theta_; }
    GridCoord& radius() { return radius_; }
    const GridCoord& radius() const { return radius_; }
    GridCoord& height() { return height_; }
    const GridCoord& height() const { return height_; }
    /// @}

    /// @name 参考坐标系
    /// @{
    void setReferenceFrame(Frame* frame);
    Frame* getReferenceFrame() const { return refFrame_.get(); }
    Frame* getFrame() const override { return refFrame_.get(); }
    /// @}

private:
    GridCoord       theta_{};    ///< 角度坐标轴
    GridCoord       radius_{};   ///< 半径坐标轴
    GridCoord       height_{};   ///< 高度坐标轴
    WeakPtr<Frame>  refFrame_{}; ///< 参考坐标系
};

AST_NAMESPACE_END
