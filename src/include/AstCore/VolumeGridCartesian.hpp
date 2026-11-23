/// @file      VolumeGridCartesian.hpp
/// @brief     笛卡尔体积网格
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "VolumeGrid.hpp"
#include "GridCoord.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

class Frame;

/// @brief 笛卡尔体积网格（X, Y, Z 坐标）
/// @ingroup Spatial
class AST_CORE_API VolumeGridCartesian final : public VolumeGrid
{
public:
    VolumeGridCartesian();
    ~VolumeGridCartesian() override = default;

    void accept(VolumeGridVisitor& visitor) override { visitor.visit(*this); }

    size_t getGridPointCount() const override;
    void enumerateGridPoints(std::vector<Vector3d>& points) const override;
    void getBoundingBox(Vector3d& minCorner, Vector3d& maxCorner) const override;

    /// @name 坐标轴
    /// @{
    GridCoord& xCoord() { return xCoord_; }
    const GridCoord& xCoord() const { return xCoord_; }
    GridCoord& yCoord() { return yCoord_; }
    const GridCoord& yCoord() const { return yCoord_; }
    GridCoord& zCoord() { return zCoord_; }
    const GridCoord& zCoord() const { return zCoord_; }
    /// @}

    /// @name 参考坐标系
    /// @{
    void setReferenceFrame(Frame* frame);
    Frame* getReferenceFrame() const { return refFrame_.get(); }
    Frame* getFrame() const override { return refFrame_.get(); }
    /// @}

private:
    GridCoord       xCoord_{};     ///< X 坐标轴
    GridCoord       yCoord_{};     ///< Y 坐标轴
    GridCoord       zCoord_{};     ///< Z 坐标轴
    WeakPtr<Frame>  refFrame_{};   ///< 参考坐标系
};

AST_NAMESPACE_END
