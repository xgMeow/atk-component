/// @file      VolumeGridConstrained.hpp
/// @brief     约束体积网格
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "VolumeGrid.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

class SpatialCondition;

/// @brief 约束体积网格
/// @details 参考另一个 VolumeGrid，仅保留满足 SpatialCondition 的网格点
/// @ingroup Spatial
class AST_CORE_API VolumeGridConstrained final : public VolumeGrid
{
public:
    VolumeGridConstrained();
    ~VolumeGridConstrained() override = default;

    void accept(VolumeGridVisitor& visitor) override { visitor.visit(*this); }

    size_t getGridPointCount() const override;
    void enumerateGridPoints(std::vector<Vector3d>& points) const override;
    void getBoundingBox(Vector3d& minCorner, Vector3d& maxCorner) const override;
    Frame* getFrame() const override;

    /// @name 参考网格
    /// @{
    void setReferenceGrid(VolumeGrid* grid);
    VolumeGrid* getReferenceGrid() const { return refGrid_.get(); }
    /// @}

    /// @name 约束条件
    /// @{
    void setCondition(SpatialCondition* condition);
    SpatialCondition* getCondition() const { return condition_.get(); }
    /// @}

private:
    WeakPtr<VolumeGrid>       refGrid_{};   ///< 参考的体积网格
    WeakPtr<SpatialCondition> condition_{}; ///< 约束的空间条件
};

AST_NAMESPACE_END
