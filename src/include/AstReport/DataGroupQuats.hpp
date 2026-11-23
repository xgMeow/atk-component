/// @file      DataGroupQuats.hpp
/// @brief     四元数姿态数据组
/// @details   对应 Quats 服务，输出四元数分量 (q1-q4) 及角速度分量 (wx, wy, wz, wmag, RA, Dec)
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-08

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstUtil/Span.hpp"
#include "AstCore/Axes.hpp"
#include "AstMath/Quaternion.hpp"
#include "AstMath/Vector.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief 四元数姿态数据组 — 四元数分量 q1-q4 及角速度分量
class DataGroupQuats : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint  time_;
        Quaternion quat_;    ///< 姿态四元数
        Vector3d   angvel_;  ///< 角速度

        const TimePoint& getTime() const { return time_; }

        // 四元数分量 — q1,q2,q3 为矢量部分, q4 为标量部分
        double getQ1() const { return quat_.qx(); }
        double getQ2() const { return quat_.qy(); }
        double getQ3() const { return quat_.qz(); }
        double getQ4() const { return quat_.qs(); }

        // 角速度分量
        double getWX() const { return angvel_.x(); }
        double getWY() const { return angvel_.y(); }
        double getWZ() const { return angvel_.z(); }

        /// @brief 角速度大小 |w|
        double getWMagnitude() const { return angvel_.norm(); }

        /// @brief 角速度矢量的赤经 RA = atan2(wy, wx)
        double getRightAscensionOfW() const { return atan2(angvel_.y(), angvel_.x()); }

        /// @brief 角速度矢量的赤纬 Dec = asin(wz / |w|)
        double getDeclinationOfW() const
        {
            double mag = angvel_.norm();
            return (mag < 1e-12) ? 0.0 : asin(angvel_.z() / mag);
        }
    };
    static DataElements Elements();

    DataGroupQuats() = default;
    ~DataGroupQuats() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Axes* getAxes() const { return axes_.get(); }
    Axes* getReferenceAxes() const { return referenceAxes_.get(); }
    void setAxes(Axes* a)          { axes_ = a; }
    void setReferenceAxes(Axes* a) { referenceAxes_ = a; }
private:
    WeakPtr<Axes> axes_{};                ///< 姿态轴
    WeakPtr<Axes> referenceAxes_{};       ///< 参考轴
};


/*! @} */

AST_NAMESPACE_END
