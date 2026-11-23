/// @file      DataGroupCartPos.hpp
/// @brief     笛卡尔位置数据组
/// @details   对应 CartPos 服务，输出 ICRF 坐标系下的笛卡尔位置分量
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-08

#pragma once

#include "AstGlobal.h"
#include "AstReport/DataGroupTimeVar.hpp"
#include "AstCore/Point.hpp"
#include "AstCore/Frame.hpp"
#include "AstMath/Vector.hpp"
#include "AstUtil/Span.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup
    @{
*/


/// @brief 笛卡尔位置数据组 — ICRF 坐标系下的 x, y, z 位置分量
class DataGroupCartPos : public DataGroupTimeVar
{
public:
    struct Data
    {
        TimePoint time_;
        Vector3d  pos_;

        const TimePoint& getTime() const { return time_; }
        double getX() const { return pos_.x(); }
        double getY() const { return pos_.y(); }
        double getZ() const { return pos_.z(); }
    };
    static DataElements Elements();
    DataGroupCartPos() = default;
    ~DataGroupCartPos() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Point* getPoint() const { return point_.get(); }
    Frame* getFrame() const { return frame_.get(); }
    void setPoint(Point* p) { point_ = p; }
    void setFrame(Frame* f) { frame_ = f; }
private:
    WeakPtr<Point> point_{};
    WeakPtr<Frame> frame_{};
};


/*! @} */

AST_NAMESPACE_END
