/// @file      VolumeGridSpherical.hpp
/// @brief     球面体积网格
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "VolumeGrid.hpp"
#include "GridCoord.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

class Frame;

/// @brief 球面体积网格（Azimuth, Elevation, Range）
/// @ingroup Spatial
class AST_CORE_API VolumeGridSpherical final : public VolumeGrid
{
public:
    VolumeGridSpherical();
    ~VolumeGridSpherical() override = default;

    void accept(VolumeGridVisitor& visitor) override { visitor.visit(*this); }

    size_t getGridPointCount() const override;
    void enumerateGridPoints(std::vector<Vector3d>& points) const override;
    void getBoundingBox(Vector3d& minCorner, Vector3d& maxCorner) const override;

    /// @name 坐标轴
    /// @{
    GridCoord& azimuth()  { return azimuth_; }
    const GridCoord& azimuth() const { return azimuth_; }
    GridCoord& elevation() { return elevation_; }
    const GridCoord& elevation() const { return elevation_; }
    GridCoord& range()    { return range_; }
    const GridCoord& range() const { return range_; }
    /// @}

    /// @name 参考坐标系
    /// @{
    void setReferenceFrame(Frame* frame);
    Frame* getReferenceFrame() const { return refFrame_.get(); }
    Frame* getFrame() const override { return refFrame_.get(); }
    /// @}

private:
    GridCoord       azimuth_{};   ///< 方位角坐标轴
    GridCoord       elevation_{}; ///< 仰角坐标轴
    GridCoord       range_{};     ///< 距离坐标轴
    WeakPtr<Frame>  refFrame_{};  ///< 参考坐标系
};

AST_NAMESPACE_END
