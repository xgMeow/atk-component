/// @file      DataGroupVectorPrv.hpp
/// @brief     向量数据组 (派生量)
/// @details   通用向量分量及派生量：模、方向余弦、球面角、方向角、导数
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-08

#pragma once

#include <cmath>

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Vector.hpp"
#include "AstCore/Axes.hpp"
#include "AstUtil/Span.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief 向量数据组 (派生量) — 分量、模、方向余弦、球面角、方向角、导数
class DataGroupVectorPrv : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint time_;
        Vector3d  vector_;   ///< 向量
        Vector3d  velocity_; ///< 向量的时间导数

        const TimePoint& getTime() const { return time_; }

        // 分量 & 模
        double getX() const { return vector_.x(); }
        double getY() const { return vector_.y(); }
        double getZ() const { return vector_.z(); }
        double getMagnitude() const { return vector_.norm(); }

        // 方向余弦
        double getXOverMag() const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : vector_.x() / m; }
        double getYOverMag() const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : vector_.y() / m; }
        double getZOverMag() const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : vector_.z() / m; }

        // 球面角
        double getRightAscension()    const { return std::atan2(vector_.y(), vector_.x()); }
        double getDeclination()       const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : std::asin(vector_.z() / m); }
        double getCoDeclination()     const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : std::acos(vector_.z() / m); }
        double getNegativeDeclination() const { return -getDeclination(); }

        // 方向角 (与各轴的夹角)
        double getDirectionAngleX() const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : std::acos(vector_.x() / m); }
        double getDirectionAngleY() const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : std::acos(vector_.y() / m); }
        double getDirectionAngleZ() const { double m = vector_.norm(); return (m < 1e-12) ? 0.0 : std::acos(vector_.z() / m); }

        // 导数
        double getDerivativeX()         const { return velocity_.x(); }
        double getDerivativeY()         const { return velocity_.y(); }
        double getDerivativeZ()         const { return velocity_.z(); }
        double getDerivativeMagnitude() const { return velocity_.norm(); }
    };
    static DataElements Elements();

    DataGroupVectorPrv() = default;
    ~DataGroupVectorPrv() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Vector* getVector() const { return vector_.get(); }
    Axes*   getAxes()   const { return axes_.get(); }
private:
    WeakPtr<Vector> vector_{};
    WeakPtr<Axes>   axes_;
};


/*! @} */

AST_NAMESPACE_END
