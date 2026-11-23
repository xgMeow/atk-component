/// @file      VolumeGridSurfaceBearing.hpp
/// @brief     方位角体积网格
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "VolumeGrid.hpp"
#include "GridCoord.hpp"
#include "AstCore/WeakPtr.hpp"

AST_NAMESPACE_BEGIN

class CelestialBody;

/// @brief 方位角体积网格（AlongBearing, CrossBearing, Altitude）
/// @ingroup Spatial
class AST_CORE_API VolumeGridSurfaceBearing final : public VolumeGrid
{
public:
    VolumeGridSurfaceBearing();
    ~VolumeGridSurfaceBearing() override = default;

    void accept(VolumeGridVisitor& visitor) override { visitor.visit(*this); }

    size_t getGridPointCount() const override;
    void enumerateGridPoints(std::vector<Vector3d>& points) const override;
    void getBoundingBox(Vector3d& minCorner, Vector3d& maxCorner) const override;
    Frame* getFrame() const override { return nullptr; }

    /// @name 坐标轴
    /// @{
    GridCoord& alongBearing()  { return alongBearing_; }
    const GridCoord& alongBearing() const { return alongBearing_; }
    GridCoord& crossBearing()  { return crossBearing_; }
    const GridCoord& crossBearing() const { return crossBearing_; }
    GridCoord& altitude()      { return altitude_; }
    const GridCoord& altitude() const { return altitude_; }
    /// @}

    /// @name 参考位置
    /// @{
    void setReferenceLocation(double lat, double lon) { refLat_ = lat; refLon_ = lon; }
    double getReferenceLatitude() const { return refLat_; }
    double getReferenceLongitude() const { return refLon_; }
    /// @}

    /// @name 方位角
    /// @{
    void setBearing(double bearingDeg) { bearing_ = bearingDeg; }
    double getBearing() const { return bearing_; }
    /// @}

    /// @name 中心天体
    /// @{
    void setCentralBody(CelestialBody* body);
    CelestialBody* getCentralBody() const { return body_.get(); }
    /// @}

    /// @name 自适应拟合
    /// @{
    void setAutoFit(bool fit) { autoFit_ = fit; }
    bool getAutoFit() const { return autoFit_; }
    /// @}

private:
    GridCoord              alongBearing_{};  ///< 沿方位向坐标轴
    GridCoord              crossBearing_{};  ///< 垂直方位向坐标轴
    GridCoord              altitude_{};      ///< 高度坐标轴
    double                 refLat_{0.0};     ///< 参考点纬度（度）
    double                 refLon_{0.0};     ///< 参考点经度（度）
    double                 bearing_{90.0};   ///< 方位角（度）
    WeakPtr<CelestialBody> body_{};          ///< 中心天体
    bool                   autoFit_{false};  ///< 是否自动拟合网格范围
};

AST_NAMESPACE_END
