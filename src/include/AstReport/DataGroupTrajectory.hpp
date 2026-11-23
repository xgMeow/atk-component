/// @file      DataGroupTrajectory.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-06

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


/// @brief 轨迹数据组
class DataGroupTrajectory : public DataGroupTimeVar
{
public:
    struct Data
    {
        Vector3d pos_{};
        Vector3d vel_{};
    };
    static DataElements Elements();
    DataGroupTrajectory() = default;
    ~DataGroupTrajectory() = default;
public:
    errc_t calculate(const TimeList& timeList, VariantVector& result) const override;
    const DataElements& getElements() const override;
public:
    errc_t calculate(const TimeList& timeList, std::vector<Data>& result) const;
    errc_t calculate(const TimeList& timeList, Span<Data> result) const;
public:
    Point* getPoint() const { return point_.get(); }
    Frame* getFrame() const { return frame_.get(); }
private:
    WeakPtr<Point> point_;
    WeakPtr<Frame> frame_;
};

/*! @} */

AST_NAMESPACE_END
